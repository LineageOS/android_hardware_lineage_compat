/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <binder/Trace.h>

namespace android {
namespace binder {

void atrace_begin(uint64_t tag, const char* name) {
    os::trace_begin(tag, name);
};

void atrace_end(uint64_t tag) {
    os::trace_end(tag);
};

}  // namespace binder
}  // namespace android
