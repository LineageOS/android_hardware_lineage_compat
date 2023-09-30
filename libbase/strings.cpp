/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/strings.h>
#include <string>

namespace android {
namespace base {
bool StartsWith(const std::string& str, const char* prefix) {
    return StartsWith((std::string_view)str, prefix);
}
}  // namespace base
}  // namespace android
