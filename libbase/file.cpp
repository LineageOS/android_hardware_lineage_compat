/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/file.h>
#include <android-base/strings.h>
#include <android-base/unique_fd.h>

namespace android {
namespace base {

bool WriteStringToFd(const std::string& content, borrowed_fd fd) {
    return WriteStringToFd(std::string_view(content), fd);
}

std::string Basename(const std::string& path) {
    return Basename(std::string_view(path));
}

std::string Dirname(const std::string& path) {
    return Dirname(std::string_view(path));
}

}  // namespace base
}  // namespace android
