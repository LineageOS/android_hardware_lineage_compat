/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <dlfcn.h>
#include <media/AudioSystem.h>
#include <media/DeviceDescriptorBase.h>

using android::AudioSystem;
using android::DeviceDescriptorBase;
using android::sp;
using android::media::AudioPortFw;

struct WiFiDisplaySession {
#ifdef __LP64__
    char _pad1[30];
#else
    char _pad1[16];
#endif
    int a;
#ifdef __LP64__
    char _pad2[90];
#else
    char _pad2[48];
#endif
    bool b;
    bool c;
} __attribute__((packed));

AudioPortFw aidlPort() {
    AudioPortFw ret;
    const auto devDescr = sp<DeviceDescriptorBase>::make(AUDIO_DEVICE_OUT_PROXY, "");
    devDescr->setName("WFD proxy device");
    devDescr->writeToParcelable(&ret);
    return ret;
}

extern "C" int _ZN18WiFiDisplaySession31broadcastWifiDisplayAudioIntentEb(
        WiFiDisplaySession* thisptr, bool enabled) {
    if ((thisptr->a | 2) == 2) {
        return 0;
    }

    if (enabled) {
        if (!thisptr->b) {
            return -1;
        }

        thisptr->c = true;

        AudioSystem::setDeviceConnectionState(AUDIO_POLICY_DEVICE_STATE_AVAILABLE, aidlPort().hal,
                                              AUDIO_FORMAT_PCM);
    } else {
        thisptr->c = false;

        AudioSystem::setDeviceConnectionState(AUDIO_POLICY_DEVICE_STATE_UNAVAILABLE, aidlPort().hal,
                                              AUDIO_FORMAT_PCM);
    }

    return 0;
}
