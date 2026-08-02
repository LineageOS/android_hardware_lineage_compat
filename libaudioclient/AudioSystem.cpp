/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <media/AudioSystem.h>

android::String8
AudioSystem_getParameters(
        audio_io_handle_t ioHandle,
        const android::String8& keys)
        asm("_ZN7android11AudioSystem13getParametersEiRKNS_7String8E");

android::String8
AudioSystem_getParameters(
        audio_io_handle_t ioHandle,
        const android::String8& keys)
{
    return android::AudioSystem::getParameters(ioHandle, keys);
}

extern "C" uintptr_t
_ZN7android11AudioSystem16addErrorCallbackEPFviE(
    android::audio_error_callback callback)
{
    return android::AudioSystem::addErrorCallback(callback);
}

extern "C" void
_ZN7android11AudioSystem19removeErrorCallbackEm(
    uintptr_t cb)
{
    android::AudioSystem::removeErrorCallback(cb);
}

extern "C" int32_t
_ZN7android11AudioSystem24setDeviceConnectionStateE24audio_policy_dev_state_tRKNS_5media5audio6common9AudioPortE14audio_format_tb(
    audio_policy_dev_state_t state,
    const android::media::audio::common::AudioPort& port,
    audio_format_t encodedFormat,
    bool deviceSwitch)
{
    return android::AudioSystem::setDeviceConnectionState(
        state, port, encodedFormat, deviceSwitch);
}

extern "C" int32_t
_ZN7android11AudioSystem13setParametersEiRKNS_7String8E(
    audio_io_handle_t ioHandle,
    const android::String8& keyValuePairs)
{
    return android::AudioSystem::setParameters(
        ioHandle, keyValuePairs);
}
