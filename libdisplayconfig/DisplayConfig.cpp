/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <vendor/display/config/2.0/IDisplayConfig.h>
#include <stdint.h>

using vendor::display::config::V2_0::IDisplayConfig;
using android::sp;

extern "C" void* _ZN6vendor7display6config4V2_014IDisplayConfig10getServiceERKNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEb(void* thisptr,
        const std::string& serviceName, bool getStub);

extern "C" void* _ZN6vendor7display6config4V1_014IDisplayConfig10getServiceERKNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEb(void* thisptr,
        const std::string& serviceName, bool getStub) {
    return _ZN6vendor7display6config4V2_014IDisplayConfig10getServiceERKNSt3__112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEb(
            thisptr, serviceName, getStub);
}
