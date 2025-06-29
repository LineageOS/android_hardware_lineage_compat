/*
 * Copyright (C) The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android/media/audio/common/AudioPort.h>
#include <system/audio.h>
#include <system/audio_policy.h>
#include <utils/Errors.h>

namespace android {
namespace AudioSystem {

status_t setDeviceConnectionState(audio_policy_dev_state_t state,
                                  const android::media::audio::common::AudioPort& port,
                                  audio_format_t encodedFormat, bool deviceSwitch);
status_t setDeviceConnectionState(audio_policy_dev_state_t state,
                                  const android::media::audio::common::AudioPort& port,
                                  audio_format_t encodedFormat);

}  // namespace AudioSystem
}  // namespace android
