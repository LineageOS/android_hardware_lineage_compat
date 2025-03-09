/*
 * Copyright (C) 2023-2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/strings.h>

namespace android {
namespace base {
bool StartsWith(const std::string& s, const char* prefix) {
    return strncmp(s.c_str(), prefix, strlen(prefix)) == 0;
}

std::string Trim(const std::string& s) {
    return Trim(std::string_view(s));
}
}  // namespace base
}  // namespace android
