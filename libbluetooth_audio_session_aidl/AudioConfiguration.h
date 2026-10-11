/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/android/hardware/bluetooth/audio/AudioConfiguration.h>
#include <android/binder_parcel.h>
#include <log/log.h>
#include <memory>

namespace bluetooth_audio_compat {

// Avoid depending on the private session object's layout.
extern const aidl::android::hardware::bluetooth::audio::AudioConfiguration
getCurrentAudioConfig(void* session) asm(
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14GetAudioConfigEv");

template <typename LegacyConfig>
LegacyConfig getAudioConfig(void* session, typename LegacyConfig::Tag maxTag, int version) {
    const auto config = getCurrentAudioConfig(session);
    LegacyConfig result;
    // New union alternatives have no legacy representation. A zero-rate PCM
    // configuration makes the legacy software audio path reject the format.
    if (static_cast<int>(config.getTag()) > static_cast<int>(maxTag)) {
        ALOGE("Bluetooth audio configuration has no V%d representation", version);
        return result;
    }
    // Stable AIDL parcel encoding provides field conversion without sharing
    // the incompatible std::variant layout across the native ABI boundary.
    std::unique_ptr<AParcel, decltype(&AParcel_delete)> parcel(AParcel_create(), AParcel_delete);
    if (!parcel || config.writeToParcel(parcel.get()) != STATUS_OK ||
        AParcel_setDataPosition(parcel.get(), 0) != STATUS_OK ||
        result.readFromParcel(parcel.get()) != STATUS_OK) {
        ALOGE("Failed to convert Bluetooth audio configuration to V%d", version);
        return LegacyConfig{};
    }
    return result;
}

}  // namespace bluetooth_audio_compat
