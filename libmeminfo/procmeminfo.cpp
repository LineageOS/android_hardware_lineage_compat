/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <meminfo/procmeminfo.h>

using android::meminfo::Vma;
using android::meminfo::VmaCallback;

extern "C" {
bool _ZN7android7meminfo11ProcMemInfo18ForEachVmaFromMapsERKNSt3__18functionIFbRNS0_3VmaEEEE(
        const VmaCallback& callback);

bool _ZN7android7meminfo11ProcMemInfo18ForEachVmaFromMapsERKNSt3__18functionIFvRKNS0_3VmaEEEE(
        std::function<void(const Vma&)> const& callback) {
    auto translatedCallback = [&callback](const Vma& vma) -> bool {
        callback(vma);
        return true;
    };

    return _ZN7android7meminfo11ProcMemInfo18ForEachVmaFromMapsERKNSt3__18functionIFbRNS0_3VmaEEEE(
            translatedCallback);
}
}
