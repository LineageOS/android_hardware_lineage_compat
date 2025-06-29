/*
 * Copyright (C) The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "AudioSystem.h"

namespace android {
namespace AudioSystem {

status_t setDeviceConnectionState(audio_policy_dev_state_t state,
                                  const android::media::audio::common::AudioPort& port,
                                  audio_format_t encodedFormat) {
    return setDeviceConnectionState(state, port, encodedFormat, false);
}

}  // namespace AudioSystem
}  // namespace android
