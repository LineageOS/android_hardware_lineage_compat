/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/android/hardware/bluetooth/audio/AudioConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/BluetoothAudioStatus.h>
#include <aidl/android/hardware/bluetooth/audio/SessionType.h>

#include <cstdint>
#include <functional>

namespace aidl::android::hardware::bluetooth::audio {

static constexpr uint16_t kObserversCookieUndefined = 0x0000;

struct PortStatusCallbacks {
    std::function<void(uint16_t cookie, bool start_resp, BluetoothAudioStatus status)>
            control_result_cb_;
    std::function<void(uint16_t cookie)> session_changed_cb_;
    std::function<void(uint16_t cookie)> audio_configuration_changed_cb_;
    std::function<void(uint16_t cookie, bool allowed)> low_latency_mode_allowed_cb_;
};

class BluetoothAudioSession {
  public:
    static bool IsAidlAvailable();
};

}  // namespace aidl::android::hardware::bluetooth::audio
