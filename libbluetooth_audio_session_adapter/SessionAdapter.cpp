/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <aidl/android/hardware/bluetooth/audio/ChannelMode.h>
#include <aidl/android/hardware/bluetooth/audio/PcmConfiguration.h>
#include <android-base/logging.h>
#include <link.h>

#include <algorithm>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

#include "SessionSymbols.h"
#include "include/BluetoothAudioSessionControl.h"
#include "include/lineage_bta/SessionBackend.h"

namespace aidl::android::hardware::bluetooth::audio {
namespace {

using ::lineage::bluetooth::audio::Backend;
using ::lineage::bluetooth::audio::Callbacks;
using ::lineage::bluetooth::audio::PcmConfig;

constexpr const char kFallbackLibrary[] = "libbluetooth_audio_session_aidl.so";

struct Candidate {
    const Backend* backend;
    std::string name;
};

std::mutex gMutex;
const Backend* gSelected = nullptr;
std::vector<Candidate> gCandidates;
std::vector<std::string> gLookedAt;

std::vector<std::string> LoadedLibraries() {
    std::vector<std::string> names;
    dl_iterate_phdr(
            [](struct dl_phdr_info* info, size_t, void* data) {
                auto* out = static_cast<std::vector<std::string>*>(data);
                if (info->dlpi_name != nullptr && info->dlpi_name[0] != '\0') {
                    out->emplace_back(info->dlpi_name);
                }
                return 0;
            },
            &names);
    return names;
}

void* BackendLibrary(const char* name) {
    static std::vector<std::pair<std::string, void*>> opened;
    for (const auto& [was, handle] : opened) {
        if (was == name) {
            return handle;
        }
    }
    void* handle = dlopen(name, RTLD_NOW | RTLD_LOCAL);
    if (handle == nullptr) {
        LOG(ERROR) << "bluetooth audio session: cannot load " << name << ": " << dlerror();
        return nullptr;
    }
    opened.emplace_back(name, handle);
    return handle;
}

const Backend* BackendFor(void* session_library) {
    namespace lba = ::lineage::bluetooth::audio;
    if (dlsym(session_library, lba::symbols::kIsSessionReadyCurrent) == nullptr) {
        return nullptr;
    }
    void* backend_library = BackendLibrary(lba::kBackendCurrent);
    if (backend_library == nullptr) {
        return nullptr;
    }
    auto open_backend =
            reinterpret_cast<lba::OpenBackendFn>(dlsym(backend_library, lba::kOpenBackendSymbol));
    return open_backend == nullptr ? nullptr : open_backend(session_library);
}

bool Consider(void* library, const std::string& name) {
    const Backend* backend = BackendFor(library);
    if (backend == nullptr) {
        return false;
    }
    LOG(INFO) << "bluetooth audio session: " << name << " carries a generation " << backend->version
              << " session store";
    gCandidates.push_back({backend, name});
    return true;
}

void Probe() {
    namespace lba = ::lineage::bluetooth::audio;
    for (const std::string& name : LoadedLibraries()) {
        if (std::find(gLookedAt.begin(), gLookedAt.end(), name) != gLookedAt.end()) {
            continue;
        }
        gLookedAt.push_back(name);
        void* library = dlopen(name.c_str(), RTLD_NOW | RTLD_LOCAL | RTLD_NOLOAD);
        if (library == nullptr) {
            continue;
        }
        if (dlsym(library, lba::symbols::kGetSessionInstance) == nullptr ||
            !Consider(library, name)) {
            dlclose(library);
        }
    }
    if (gCandidates.empty()) {
        void* library = dlopen(kFallbackLibrary, RTLD_NOW | RTLD_LOCAL);
        if (library != nullptr && !Consider(library, kFallbackLibrary)) {
            dlclose(library);
        }
    }
}

const Backend* Select(int32_t session_type) {
    std::lock_guard<std::mutex> guard(gMutex);
    if (gSelected != nullptr && gSelected->is_session_ready(gSelected->context, session_type)) {
        return gSelected;
    }
    Probe();
    for (const Candidate& candidate : gCandidates) {
        const Backend* backend = candidate.backend;
        if (!backend->is_session_ready(backend->context, session_type)) {
            LOG(VERBOSE) << "bluetooth audio session: " << candidate.name
                         << " has no session for type " << session_type;
            continue;
        }
        if (backend != gSelected) {
            LOG(INFO) << "bluetooth audio session: bound " << candidate.name;
        }
        gSelected = backend;
        return backend;
    }
    return nullptr;
}

constexpr size_t kInlineLatencyModes = 8;

std::mutex gHeldMutex;
std::map<std::pair<int32_t, uint16_t>, std::unique_ptr<PortStatusCallbacks>> gHeld;

const PortStatusCallbacks& Held(void* context) {
    return *static_cast<const PortStatusCallbacks*>(context);
}

void ControlResult(void* context, uint16_t cookie, bool start_resp, int32_t status) {
    const auto& callback = Held(context).control_result_cb_;
    if (callback) {
        callback(cookie, start_resp, static_cast<BluetoothAudioStatus>(status));
    }
}

void SessionChanged(void* context, uint16_t cookie) {
    const auto& callback = Held(context).session_changed_cb_;
    if (callback) {
        callback(cookie);
    }
}

void AudioConfigChanged(void* context, uint16_t cookie) {
    const auto& callback = Held(context).audio_configuration_changed_cb_;
    if (callback) {
        callback(cookie);
    }
}

void LowLatencyAllowed(void* context, uint16_t cookie, bool allowed) {
    const auto& callback = Held(context).low_latency_mode_allowed_cb_;
    if (callback) {
        callback(cookie, allowed);
    }
}

int32_t Raw(const SessionType& session_type) {
    return static_cast<int32_t>(session_type);
}

}  // namespace

bool BluetoothAudioSession::IsAidlAvailable() {
    std::lock_guard<std::mutex> guard(gMutex);
    Probe();
    return !gCandidates.empty();
}

bool BluetoothAudioSessionControl::IsSessionReady(const SessionType& session_type,
                                                  bool /* is_primary_hal */) {
    return Select(Raw(session_type)) != nullptr;
}

uint16_t BluetoothAudioSessionControl::RegisterControlResultCback(
        const SessionType& session_type, const PortStatusCallbacks& cbacks) {
    const Backend* backend = Select(Raw(session_type));
    if (backend == nullptr) {
        return kObserversCookieUndefined;
    }
    auto held = std::make_unique<PortStatusCallbacks>(cbacks);
    Callbacks neutral{
            .context = held.get(),
            .control_result = ControlResult,
            .session_changed = SessionChanged,
            .audio_config_changed = AudioConfigChanged,
            .low_latency_allowed = LowLatencyAllowed,
    };
    uint16_t cookie = backend->register_cbacks(backend->context, Raw(session_type), &neutral);
    if (cookie == kObserversCookieUndefined) {
        return cookie;
    }
    std::lock_guard<std::mutex> guard(gHeldMutex);
    gHeld[{Raw(session_type), cookie}] = std::move(held);
    return cookie;
}

void BluetoothAudioSessionControl::UnregisterControlResultCback(const SessionType& session_type,
                                                                uint16_t cookie) {
    const Backend* backend = Select(Raw(session_type));
    if (backend != nullptr) {
        backend->unregister_cbacks(backend->context, Raw(session_type), cookie);
    }
    std::lock_guard<std::mutex> guard(gHeldMutex);
    gHeld.erase({Raw(session_type), cookie});
}

const AudioConfiguration BluetoothAudioSessionControl::GetAudioConfig(
        const SessionType& session_type) {
    const Backend* backend = Select(Raw(session_type));
    PcmConfig pcm{};
    if (backend == nullptr || !backend->get_pcm_config(backend->context, Raw(session_type), &pcm)) {
        return AudioConfiguration();
    }
    PcmConfiguration config;
    config.sampleRateHz = pcm.sample_rate_hz;
    config.channelMode = static_cast<ChannelMode>(pcm.channel_mode);
    config.bitsPerSample = pcm.bits_per_sample;
    config.dataIntervalUs = pcm.data_interval_us;
    return AudioConfiguration::make<AudioConfiguration::pcmConfig>(config);
}

bool BluetoothAudioSessionControl::StartStream(const SessionType& session_type, bool low_latency) {
    const Backend* backend = Select(Raw(session_type));
    return backend != nullptr &&
           backend->start_stream(backend->context, Raw(session_type), low_latency);
}

bool BluetoothAudioSessionControl::SuspendStream(const SessionType& session_type) {
    const Backend* backend = Select(Raw(session_type));
    return backend != nullptr && backend->suspend_stream(backend->context, Raw(session_type));
}

void BluetoothAudioSessionControl::StopStream(const SessionType& session_type) {
    const Backend* backend = Select(Raw(session_type));
    if (backend != nullptr) {
        backend->stop_stream(backend->context, Raw(session_type));
    }
}

bool BluetoothAudioSessionControl::GetPresentationPosition(const SessionType& session_type,
                                                           PresentationPosition& position) {
    const Backend* backend = Select(Raw(session_type));
    ::lineage::bluetooth::audio::PresentationPosition neutral{};
    if (backend == nullptr ||
        !backend->get_presentation_position(backend->context, Raw(session_type), &neutral)) {
        return false;
    }
    position.remoteDeviceAudioDelayNanos = neutral.remote_delay_ns;
    position.transmittedOctets = neutral.transmitted_octets;
    position.transmittedOctetsTimestamp.tvSec = neutral.timestamp_sec;
    position.transmittedOctetsTimestamp.tvNSec = neutral.timestamp_nsec;
    return true;
}

void BluetoothAudioSessionControl::UpdateSourceMetadata(const SessionType& session_type,
                                                        const struct source_metadata& metadata) {
    const Backend* backend = Select(Raw(session_type));
    if (backend == nullptr) {
        return;
    }
    std::vector<::lineage::bluetooth::audio::PlaybackTrack> tracks(metadata.track_count);
    for (size_t i = 0; i < metadata.track_count; i++) {
        tracks[i].usage = metadata.tracks[i].usage;
        tracks[i].content_type = metadata.tracks[i].content_type;
        tracks[i].gain = metadata.tracks[i].gain;
    }
    backend->update_source_metadata(backend->context, Raw(session_type), tracks.data(),
                                    tracks.size());
}

void BluetoothAudioSessionControl::UpdateSinkMetadata(const SessionType& session_type,
                                                      const struct sink_metadata& metadata) {
    const Backend* backend = Select(Raw(session_type));
    if (backend == nullptr) {
        return;
    }
    std::vector<::lineage::bluetooth::audio::RecordTrack> tracks(metadata.track_count);
    for (size_t i = 0; i < metadata.track_count; i++) {
        tracks[i].source = metadata.tracks[i].source;
        tracks[i].gain = metadata.tracks[i].gain;
    }
    backend->update_sink_metadata(backend->context, Raw(session_type), tracks.data(),
                                  tracks.size());
}

bool BluetoothAudioSessionControl::UpdateSourceMetadata(
        const SessionType& session_type,
        const ::aidl::android::hardware::audio::common::SourceMetadata& metadata) {
    const Backend* backend = Select(Raw(session_type));
    if (backend == nullptr) {
        return false;
    }
    std::vector<::lineage::bluetooth::audio::PlaybackTrack> tracks(metadata.tracks.size());
    for (size_t i = 0; i < metadata.tracks.size(); i++) {
        tracks[i].usage = static_cast<int32_t>(metadata.tracks[i].usage);
        tracks[i].content_type = static_cast<int32_t>(metadata.tracks[i].contentType);
        tracks[i].gain = metadata.tracks[i].gain;
    }
    backend->update_source_metadata(backend->context, Raw(session_type), tracks.data(),
                                    tracks.size());
    return true;
}

bool BluetoothAudioSessionControl::UpdateSinkMetadata(
        const SessionType& session_type,
        const ::aidl::android::hardware::audio::common::SinkMetadata& metadata) {
    const Backend* backend = Select(Raw(session_type));
    if (backend == nullptr) {
        return false;
    }
    std::vector<::lineage::bluetooth::audio::RecordTrack> tracks(metadata.tracks.size());
    for (size_t i = 0; i < metadata.tracks.size(); i++) {
        tracks[i].source = static_cast<int32_t>(metadata.tracks[i].source);
        tracks[i].gain = metadata.tracks[i].gain;
    }
    backend->update_sink_metadata(backend->context, Raw(session_type), tracks.data(),
                                  tracks.size());
    return true;
}

std::vector<LatencyMode> BluetoothAudioSessionControl::GetSupportedLatencyModes(
        const SessionType& session_type) {
    const Backend* backend = Select(Raw(session_type));
    std::vector<LatencyMode> modes;
    if (backend == nullptr) {
        return modes;
    }
    int32_t held[kInlineLatencyModes];
    size_t count = backend->supported_latency_modes(backend->context, Raw(session_type), held,
                                                    kInlineLatencyModes);
    if (count <= kInlineLatencyModes) {
        for (size_t i = 0; i < count; i++) {
            modes.push_back(static_cast<LatencyMode>(held[i]));
        }
        return modes;
    }
    std::vector<int32_t> spilled(count);
    count = backend->supported_latency_modes(backend->context, Raw(session_type), spilled.data(),
                                             spilled.size());
    for (size_t i = 0; i < count && i < spilled.size(); i++) {
        modes.push_back(static_cast<LatencyMode>(spilled[i]));
    }
    return modes;
}

void BluetoothAudioSessionControl::SetLatencyMode(const SessionType& session_type,
                                                  const LatencyMode& latency_mode) {
    const Backend* backend = Select(Raw(session_type));
    if (backend != nullptr) {
        backend->set_latency_mode(backend->context, Raw(session_type),
                                  static_cast<int32_t>(latency_mode));
    }
}

size_t BluetoothAudioSessionControl::OutWritePcmData(const SessionType& session_type,
                                                     const void* buffer, size_t bytes) {
    const Backend* backend = Select(Raw(session_type));
    if (backend == nullptr) {
        return 0;
    }
    return backend->out_write_pcm(backend->context, Raw(session_type), buffer, bytes);
}

size_t BluetoothAudioSessionControl::InReadPcmData(const SessionType& session_type, void* buffer,
                                                   size_t bytes) {
    const Backend* backend = Select(Raw(session_type));
    if (backend == nullptr) {
        return 0;
    }
    return backend->in_read_pcm(backend->context, Raw(session_type), buffer, bytes);
}

}  // namespace aidl::android::hardware::bluetooth::audio
