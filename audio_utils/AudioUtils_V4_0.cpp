/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android/hardware/audio/common/4.0/types.h>
#include <system/audio.h>

namespace android {
namespace hardware {
namespace audio {
namespace common {
namespace V4_0 {
namespace implementation {

// android::hardware::audio::common::V4_0::implementation::HidlUtils
extern "C" void*
_ZN7android8hardware5audio6common4V4_014implementation9HidlUtils18audioConfigFromHalERK12audio_configbPNS3_11AudioConfigE(
        void* thisptr, const audio_config_t& halConfig, bool, AudioConfig* config);

extern "C" void*
_ZN7android8hardware5audio6common4V4_014implementation9HidlUtils18audioConfigFromHalERK12audio_configPNS3_11AudioConfigE(
        void* thisptr, const audio_config_t& halConfig, AudioConfig* config) {
    return _ZN7android8hardware5audio6common4V4_014implementation9HidlUtils18audioConfigFromHalERK12audio_configbPNS3_11AudioConfigE(
                thisptr, halConfig, true /*isInput*/, config);
}

// android::hardware::audio::common::V4_0::implementation::UuidUtils
extern "C" void*
_ZN7android8hardware5audio6common4V4_014implementation9UuidUtils11uuidFromHalERK12audio_uuid_sPNS3_4UuidE(
        void* thisptr, const audio_uuid_t& halUuid, Uuid* uuid);

extern "C" void*
_ZN7android8hardware5audio6common4V4_014implementation9HidlUtils11uuidFromHalERK12audio_uuid_sPNS3_4UuidE(
        void* thisptr, const audio_uuid_t& halUuid, Uuid* uuid) {
    return _ZN7android8hardware5audio6common4V4_014implementation9UuidUtils11uuidFromHalERK12audio_uuid_sPNS3_4UuidE(
                thisptr, halUuid, uuid);
}

extern "C" void*
_ZN7android8hardware5audio6common4V4_014implementation9UuidUtils9uuidToHalERKNS3_4UuidEP12audio_uuid_s(
        void* thisptr, const Uuid& uuid, audio_uuid_t* halUuid);

extern "C" void*
_ZN7android8hardware5audio6common4V4_014implementation9HidlUtils9uuidToHalERKNS3_4UuidEP12audio_uuid_s(
        void* thisptr, const Uuid& uuid, audio_uuid_t* halUuid) {
    return _ZN7android8hardware5audio6common4V4_014implementation9UuidUtils9uuidToHalERKNS3_4UuidEP12audio_uuid_s(
                thisptr, uuid, halUuid);
}

}  // namespace implementation
}  // namespace V4_0
}  // namespace common
}  // namespace audio
}  // namespace hardware
}  // namespace android
