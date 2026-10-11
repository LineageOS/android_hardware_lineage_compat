/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <aidl/lineage/compat/bluetooth/audio/v3/AudioConfiguration.h>

#include "AudioConfiguration.h"

namespace legacy = aidl::lineage::compat::bluetooth::audio::v3;

extern const legacy::AudioConfiguration getLegacyAudioConfig(void* session) asm(
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14GetAudioConfV3Ev");

const legacy::AudioConfiguration getLegacyAudioConfig(void* session) {
    return bluetooth_audio_compat::getAudioConfig<legacy::AudioConfiguration>(
            session, legacy::AudioConfiguration::Tag::leAudioBroadcastConfig, 3);
}
