/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/android/hardware/audio/common/SinkMetadata.h>
#include <aidl/android/hardware/audio/common/SourceMetadata.h>
#include <aidl/android/hardware/bluetooth/audio/LatencyMode.h>
#include <aidl/android/hardware/bluetooth/audio/PresentationPosition.h>
#include <hardware/audio.h>
#include <system/audio.h>

#include <vector>

#include "BluetoothAudioSession.h"

namespace aidl::android::hardware::bluetooth::audio {

// Upstream declares this class with every body inline, each one calling
// BluetoothAudioSessionInstance::GetSessionInstance itself, which binds a
// caller to the store in whichever library it was linked against. Declaring
// the same calls without bodies leaves a symbol for this library to define,
// which is the whole point of it. Keep the signatures a drop-in for the ones
// upstream carries.
class BluetoothAudioSessionControl {
  public:
    static bool IsSessionReady(const SessionType& session_type, bool is_primary_hal = true);
    static uint16_t RegisterControlResultCback(const SessionType& session_type,
                                               const PortStatusCallbacks& cbacks);
    static void UnregisterControlResultCback(const SessionType& session_type, uint16_t cookie);
    static const AudioConfiguration GetAudioConfig(const SessionType& session_type);
    static bool StartStream(const SessionType& session_type, bool low_latency = false);
    static bool SuspendStream(const SessionType& session_type);
    static void StopStream(const SessionType& session_type);
    static bool GetPresentationPosition(const SessionType& session_type,
                                        PresentationPosition& position);
    static void UpdateSourceMetadata(const SessionType& session_type,
                                     const struct source_metadata& metadata);
    static void UpdateSinkMetadata(const SessionType& session_type,
                                   const struct sink_metadata& metadata);
    static bool UpdateSourceMetadata(
            const SessionType& session_type,
            const ::aidl::android::hardware::audio::common::SourceMetadata& metadata);
    static bool UpdateSinkMetadata(
            const SessionType& session_type,
            const ::aidl::android::hardware::audio::common::SinkMetadata& metadata);
    static std::vector<LatencyMode> GetSupportedLatencyModes(const SessionType& session_type);
    static void SetLatencyMode(const SessionType& session_type, const LatencyMode& latency_mode);
    static size_t OutWritePcmData(const SessionType& session_type, const void* buffer,
                                  size_t bytes);
    static size_t InReadPcmData(const SessionType& session_type, void* buffer, size_t bytes);
};

}  // namespace aidl::android::hardware::bluetooth::audio
