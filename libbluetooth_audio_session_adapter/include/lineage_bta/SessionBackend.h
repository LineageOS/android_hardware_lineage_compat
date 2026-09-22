/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <cstddef>
#include <cstdint>

namespace lineage::bluetooth::audio {

struct PcmConfig {
    bool is_pcm;
    int32_t sample_rate_hz;
    int32_t channel_mode;
    int8_t bits_per_sample;
    int32_t data_interval_us;
};

struct PresentationPosition {
    int64_t remote_delay_ns;
    uint64_t transmitted_octets;
    int64_t timestamp_sec;
    int32_t timestamp_nsec;
};

struct PlaybackTrack {
    int32_t usage;
    int32_t content_type;
    float gain;
};

struct RecordTrack {
    int32_t source;
    float gain;
};

struct Callbacks {
    void* context;
    void (*control_result)(void* context, uint16_t cookie, bool start_resp, int32_t status);
    void (*session_changed)(void* context, uint16_t cookie);
    void (*audio_config_changed)(void* context, uint16_t cookie);
    void (*low_latency_allowed)(void* context, uint16_t cookie, bool allowed);
};

struct Backend {
    int version;
    void* context;

    bool (*is_session_ready)(void* context, int32_t session_type);
    uint16_t (*register_cbacks)(void* context, int32_t session_type, const Callbacks* cbacks);
    void (*unregister_cbacks)(void* context, int32_t session_type, uint16_t cookie);
    bool (*get_pcm_config)(void* context, int32_t session_type, PcmConfig* config);
    bool (*start_stream)(void* context, int32_t session_type, bool low_latency);
    bool (*suspend_stream)(void* context, int32_t session_type);
    void (*stop_stream)(void* context, int32_t session_type);
    bool (*get_presentation_position)(void* context, int32_t session_type,
                                      PresentationPosition* position);
    void (*update_source_metadata)(void* context, int32_t session_type, const PlaybackTrack* tracks,
                                   size_t count);
    void (*update_sink_metadata)(void* context, int32_t session_type, const RecordTrack* tracks,
                                 size_t count);
    size_t (*supported_latency_modes)(void* context, int32_t session_type, int32_t* modes,
                                      size_t capacity);
    void (*set_latency_mode)(void* context, int32_t session_type, int32_t latency_mode);
    size_t (*out_write_pcm)(void* context, int32_t session_type, const void* buffer, size_t bytes);
    size_t (*in_read_pcm)(void* context, int32_t session_type, void* buffer, size_t bytes);
    void (*close)(void* context);
};

using OpenBackendFn = const Backend* (*)(void* library);

constexpr char kOpenBackendSymbol[] = "lineage_bta_open_backend";
constexpr char kBackendCurrent[] = "libbluetooth_audio_session_backend_current.so";

}  // namespace lineage::bluetooth::audio
