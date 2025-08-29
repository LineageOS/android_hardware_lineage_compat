// SPDX-FileCopyrightText: The LineageOS Project
// SPDX-License-Identifier: Apache-2.0

#include <media/AudioSystem.h>

namespace android {

#define setDeviceConnectionStateFn \
    _ZN7android11AudioSystem24setDeviceConnectionStateE24audio_policy_dev_state_tRKNS_5media5audio6common9AudioPortE14audio_format_t

extern "C" status_t setDeviceConnectionStateFn(AudioSystem *thisptr, audio_policy_dev_state_t state,
                                               const android::media::audio::common::AudioPort& port,
                                               audio_format_t encodedFormat) {
    return thisptr->setDeviceConnectionState(state, port, encodedFormat, false);
}

} // namespace android
