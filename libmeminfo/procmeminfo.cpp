/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <meminfo/procmeminfo.h>

using android::meminfo::VmaCallback;

extern "C" {
bool _ZN7android7meminfo11ProcMemInfo18ForEachVmaFromMapsERKNSt3__18functionIFbRNS0_3VmaEEEE(
        const VmaCallback& callback);

bool _ZN7android7meminfo11ProcMemInfo18ForEachVmaFromMapsERKNSt3__18functionIFvRKNS0_3VmaEEEE(
        const VmaCallback& callback) {
    return _ZN7android7meminfo11ProcMemInfo18ForEachVmaFromMapsERKNSt3__18functionIFbRNS0_3VmaEEEE(
            callback);
}
}
