/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include "include/lineage_bta/SessionBackend.h"

#include <aidl/android/hardware/bluetooth/audio/AudioConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/BluetoothAudioStatus.h>
#include <aidl/android/hardware/bluetooth/audio/LatencyMode.h>
#include <aidl/android/hardware/bluetooth/audio/PresentationPosition.h>
#include <hardware/audio.h>
#include <system/audio.h>

#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <vector>

#include "SessionSymbols.h"
#include "include/BluetoothAudioSession.h"

#define BACKEND_VERSION 6

namespace lineage::bluetooth::audio {
namespace {

using ::aidl::android::hardware::bluetooth::audio::AudioConfiguration;
using ::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus;

using HalCallbacks = ::aidl::android::hardware::bluetooth::audio::PortStatusCallbacks;

using GetAudioConfigFn = AudioConfiguration (*)(SessionObject*);

struct Resolved {
    GetSessionInstanceFn get_instance;
    ReadyCurrentFn is_ready;
    RegisterCbackFn register_cback;
    UnregisterCbackFn unregister_cback;
    GetAudioConfigFn get_audio_config;
    StartStreamFn start_stream;
    SuspendStreamFn suspend_stream;
    StopStreamFn stop_stream;
    GetPositionFn get_position;
    UpdateMetadataFn update_source;
    UpdateMetadataFn update_sink;
    GetLatencyModesFn get_latency_modes;
    SetLatencyModeFn set_latency_mode;
    WritePcmFn write_pcm;
    ReadPcmFn read_pcm;
};

struct Context {
    Resolved resolved;
    std::mutex mutex;
    std::map<int32_t, std::shared_ptr<SessionObject>> sessions;
    Backend api;
};

Context* Of(void* context) {
    return static_cast<Context*>(context);
}

SessionObject* Session(Context* ctx, int32_t session_type) {
    std::lock_guard<std::mutex> guard(ctx->mutex);
    auto found = ctx->sessions.find(session_type);
    if (found == ctx->sessions.end()) {
        found = ctx->sessions.emplace(session_type, ctx->resolved.get_instance(&session_type))
                        .first;
    }
    return found->second.get();
}

bool IsSessionReady(void* context, int32_t session_type) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    return session != nullptr && ctx->resolved.is_ready(session, true);
}

uint16_t RegisterCbacks(void* context, int32_t session_type, const Callbacks* callbacks) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session == nullptr) {
        return 0;
    }
    Callbacks cbacks = *callbacks;
    HalCallbacks hal;
    hal.control_result_cb_ = [cbacks](uint16_t cookie, bool start_resp,
                                      BluetoothAudioStatus status) {
        cbacks.control_result(cbacks.context, cookie, start_resp, static_cast<int32_t>(status));
    };
    hal.session_changed_cb_ = [cbacks](uint16_t cookie) {
        cbacks.session_changed(cbacks.context, cookie);
    };
    hal.audio_configuration_changed_cb_ = [cbacks](uint16_t cookie) {
        cbacks.audio_config_changed(cbacks.context, cookie);
    };
    hal.low_latency_mode_allowed_cb_ = [cbacks](uint16_t cookie, bool allowed) {
        cbacks.low_latency_allowed(cbacks.context, cookie, allowed);
    };
    return ctx->resolved.register_cback(session, &hal);
}

void UnregisterCbacks(void* context, int32_t session_type, uint16_t cookie) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session != nullptr) {
        ctx->resolved.unregister_cback(session, cookie);
    }
}

bool GetPcmConfig(void* context, int32_t session_type, PcmConfig* config) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    config->is_pcm = false;
    if (session == nullptr) {
        return false;
    }
    AudioConfiguration hal_config = ctx->resolved.get_audio_config(session);
    if (hal_config.getTag() != AudioConfiguration::pcmConfig) {
        return false;
    }
    const auto& pcm = hal_config.get<AudioConfiguration::pcmConfig>();
    config->is_pcm = true;
    config->sample_rate_hz = pcm.sampleRateHz;
    config->channel_mode = static_cast<int32_t>(pcm.channelMode);
    config->bits_per_sample = pcm.bitsPerSample;
    config->data_interval_us = pcm.dataIntervalUs;
    return true;
}

bool StartStream(void* context, int32_t session_type, bool low_latency) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    return session != nullptr && ctx->resolved.start_stream(session, low_latency);
}

bool SuspendStream(void* context, int32_t session_type) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    return session != nullptr && ctx->resolved.suspend_stream(session);
}

void StopStream(void* context, int32_t session_type) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session != nullptr) {
        ctx->resolved.stop_stream(session);
    }
}

bool GetPresentationPosition(void* context, int32_t session_type, PresentationPosition* position) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session == nullptr || ctx->resolved.get_position == nullptr) {
        return false;
    }
    ::aidl::android::hardware::bluetooth::audio::PresentationPosition hal_position{};
    if (!ctx->resolved.get_position(session, &hal_position)) {
        return false;
    }
    position->remote_delay_ns = hal_position.remoteDeviceAudioDelayNanos;
    position->transmitted_octets = hal_position.transmittedOctets;
    position->timestamp_sec = hal_position.transmittedOctetsTimestamp.tvSec;
    position->timestamp_nsec = hal_position.transmittedOctetsTimestamp.tvNSec;
    return true;
}

void UpdateSourceMetadata(void* context, int32_t session_type, const PlaybackTrack* tracks,
                          size_t count) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session == nullptr || ctx->resolved.update_source == nullptr) {
        return;
    }
    std::vector<playback_track_metadata> hal_tracks(count);
    for (size_t i = 0; i < count; i++) {
        hal_tracks[i].usage = static_cast<audio_usage_t>(tracks[i].usage);
        hal_tracks[i].content_type = static_cast<audio_content_type_t>(tracks[i].content_type);
        hal_tracks[i].gain = tracks[i].gain;
    }
    source_metadata metadata = {.track_count = hal_tracks.size(), .tracks = hal_tracks.data()};
    ctx->resolved.update_source(session, &metadata);
}

void UpdateSinkMetadata(void* context, int32_t session_type, const RecordTrack* tracks,
                        size_t count) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session == nullptr || ctx->resolved.update_sink == nullptr) {
        return;
    }
    std::vector<record_track_metadata> hal_tracks(count);
    for (size_t i = 0; i < count; i++) {
        hal_tracks[i].source = static_cast<audio_source_t>(tracks[i].source);
        hal_tracks[i].gain = tracks[i].gain;
    }
    sink_metadata metadata = {.track_count = hal_tracks.size(), .tracks = hal_tracks.data()};
    ctx->resolved.update_sink(session, &metadata);
}

size_t SupportedLatencyModes(void* context, int32_t session_type, int32_t* modes, size_t capacity) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session == nullptr || ctx->resolved.get_latency_modes == nullptr) {
        return 0;
    }
    std::vector<int32_t> found = ctx->resolved.get_latency_modes(session);
    for (size_t i = 0; i < found.size() && i < capacity; i++) {
        modes[i] = found[i];
    }
    return found.size();
}

void SetLatencyMode(void* context, int32_t session_type, int32_t latency_mode) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session != nullptr && ctx->resolved.set_latency_mode != nullptr) {
        ctx->resolved.set_latency_mode(session, &latency_mode);
    }
}

size_t OutWritePcm(void* context, int32_t session_type, const void* buffer, size_t bytes) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session == nullptr) {
        return 0;
    }
    return ctx->resolved.write_pcm(session, buffer, bytes);
}

size_t InReadPcm(void* context, int32_t session_type, void* buffer, size_t bytes) {
    Context* ctx = Of(context);
    SessionObject* session = Session(ctx, session_type);
    if (session == nullptr || ctx->resolved.read_pcm == nullptr) {
        return 0;
    }
    return ctx->resolved.read_pcm(session, buffer, bytes);
}

void Close(void* context) {
    delete Of(context);
}

}  // namespace

extern "C" __attribute__((visibility("default"))) const Backend* lineage_bta_open_backend(
        void* library) {
    auto ctx = std::make_unique<Context>();
    Resolved& resolved = ctx->resolved;

    resolved.get_instance = Lookup<GetSessionInstanceFn>(library, symbols::kGetSessionInstance);
    resolved.is_ready = Lookup<ReadyCurrentFn>(library, symbols::kIsSessionReadyCurrent);
    resolved.update_source = Lookup<UpdateMetadataFn>(library, symbols::kUpdateSourceMetadata);
    resolved.update_sink = Lookup<UpdateMetadataFn>(library, symbols::kUpdateSinkMetadata);
    resolved.register_cback = Lookup<RegisterCbackFn>(library, symbols::kRegisterStatusCback);
    resolved.unregister_cback = Lookup<UnregisterCbackFn>(library, symbols::kUnregisterStatusCback);
    resolved.get_audio_config = Lookup<GetAudioConfigFn>(library, symbols::kGetAudioConfig);
    resolved.start_stream = Lookup<StartStreamFn>(library, symbols::kStartStream);
    resolved.suspend_stream = Lookup<SuspendStreamFn>(library, symbols::kSuspendStream);
    resolved.stop_stream = Lookup<StopStreamFn>(library, symbols::kStopStream);
    resolved.get_position = Lookup<GetPositionFn>(library, symbols::kGetPresentationPosition);
    resolved.get_latency_modes =
            Lookup<GetLatencyModesFn>(library, symbols::kGetSupportedLatencyModes);
    resolved.set_latency_mode = Lookup<SetLatencyModeFn>(library, symbols::kSetLatencyMode);
    resolved.write_pcm = Lookup<WritePcmFn>(library, symbols::kOutWritePcmData);
    resolved.read_pcm = Lookup<ReadPcmFn>(library, symbols::kInReadPcmData);

    if (resolved.get_instance == nullptr || resolved.is_ready == nullptr ||
        resolved.register_cback == nullptr || resolved.unregister_cback == nullptr ||
        resolved.get_audio_config == nullptr || resolved.start_stream == nullptr ||
        resolved.suspend_stream == nullptr || resolved.stop_stream == nullptr ||
        resolved.write_pcm == nullptr) {
        return nullptr;
    }

    ctx->api = Backend{
            .version = BACKEND_VERSION,
            .context = ctx.get(),
            .is_session_ready = IsSessionReady,
            .register_cbacks = RegisterCbacks,
            .unregister_cbacks = UnregisterCbacks,
            .get_pcm_config = GetPcmConfig,
            .start_stream = StartStream,
            .suspend_stream = SuspendStream,
            .stop_stream = StopStream,
            .get_presentation_position = GetPresentationPosition,
            .update_source_metadata = UpdateSourceMetadata,
            .update_sink_metadata = UpdateSinkMetadata,
            .supported_latency_modes = SupportedLatencyModes,
            .set_latency_mode = SetLatencyMode,
            .out_write_pcm = OutWritePcm,
            .in_read_pcm = InReadPcm,
            .close = Close,
    };
    return &ctx.release()->api;
}

}  // namespace lineage::bluetooth::audio
