/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <dlfcn.h>
#include <media/AudioSystem.h>
#include <media/DeviceDescriptorBase.h>

#include "WiFiDisplaySession.h"

using android::AudioSystem;
using android::DeviceDescriptorBase;
using android::sp;
using android::media::AudioPortFw;
using android::media::audio::common::AudioPort;

extern "C" int _ZN18WiFiDisplaySession31broadcastWifiDisplayAudioIntentEb(
        WiFiDisplaySession* thisptr, bool enabled) {
    if (thisptr->flags == 0 || thisptr->flags == 2) {
        return 0;
    }

    if (enabled && !thisptr->ready) {
        return -1;
    }

    thisptr->enabled = enabled;

    AudioPortFw audioPortFw;
    const auto devDescr = sp<DeviceDescriptorBase>::make(AUDIO_DEVICE_OUT_PROXY, "");
    devDescr->setName("WFD proxy device");
    devDescr->writeToParcelable(&audioPortFw);

    AudioSystem::setDeviceConnectionState(
            enabled ? AUDIO_POLICY_DEVICE_STATE_AVAILABLE : AUDIO_POLICY_DEVICE_STATE_UNAVAILABLE,
            audioPortFw.hal, AUDIO_FORMAT_PCM, false);

    return 0;
}
