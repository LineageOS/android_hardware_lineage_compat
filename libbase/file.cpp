/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/file.h>
#include <android-base/strings.h>

namespace android {
namespace base {

std::string Basename(const std::string& path) {
    return Basename(std::string_view(path));
}

std::string Dirname(const std::string& path) {
    return Dirname(std::string_view(path));
}

}  // namespace base
}  // namespace android
