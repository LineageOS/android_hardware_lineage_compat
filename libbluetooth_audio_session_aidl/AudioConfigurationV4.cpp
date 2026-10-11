/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <aidl/lineage/compat/bluetooth/audio/v4/AudioConfiguration.h>

#include "AudioConfiguration.h"

namespace legacy = aidl::lineage::compat::bluetooth::audio::v4;

extern const legacy::AudioConfiguration getLegacyAudioConfigV4(void* session) asm(
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14GetAudioConfV4Ev");

const legacy::AudioConfiguration getLegacyAudioConfigV4(void* session) {
    return bluetooth_audio_compat::getAudioConfig<legacy::AudioConfiguration>(
            session, legacy::AudioConfiguration::Tag::a2dp, 4);
}
