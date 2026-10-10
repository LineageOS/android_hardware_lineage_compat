/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <aidl/android/hardware/bluetooth/audio/AudioConfiguration.h>
#include <aidl/lineage/compat/bluetooth/audio/v3/AudioConfiguration.h>
#include <android/binder_parcel.h>
#include <log/log.h>
#include <memory>

namespace current = aidl::android::hardware::bluetooth::audio;
namespace legacy = aidl::lineage::compat::bluetooth::audio::v3;

// Avoid depending on the private session object's layout.
extern const current::AudioConfiguration getCurrentAudioConfig(void* session) asm(
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14GetAudioConfigEv");

extern const legacy::AudioConfiguration getLegacyAudioConfig(void* session) asm(
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14GetAudioConfV3Ev");

const legacy::AudioConfiguration getLegacyAudioConfig(void* session) {
    const auto config = getCurrentAudioConfig(session);
    legacy::AudioConfiguration result;
    // New union alternatives have no V3 representation. A zero-rate PCM
    // configuration makes the legacy software audio path reject the format.
    if (static_cast<int>(config.getTag()) >
        static_cast<int>(legacy::AudioConfiguration::Tag::leAudioBroadcastConfig)) {
        ALOGE("Bluetooth audio configuration has no V3 representation");
        return result;
    }
    // Stable AIDL parcel encoding provides field conversion without sharing
    // the incompatible std::variant layout across the native ABI boundary.
    std::unique_ptr<AParcel, decltype(&AParcel_delete)> parcel(AParcel_create(), AParcel_delete);
    if (!parcel || config.writeToParcel(parcel.get()) != STATUS_OK ||
        AParcel_setDataPosition(parcel.get(), 0) != STATUS_OK ||
        result.readFromParcel(parcel.get()) != STATUS_OK) {
        ALOGE("Failed to convert Bluetooth audio configuration to V3");
        return legacy::AudioConfiguration{};
    }
    return result;
}
