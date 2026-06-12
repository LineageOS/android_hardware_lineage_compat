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
  std::string_view sv(s);

  // Skip initial whitespace.
  while (!sv.empty() && isspace(static_cast<unsigned char>(sv.front()))) {
    sv.remove_prefix(1);
  }

  // Skip terminating whitespace.
  while (!sv.empty() && isspace(static_cast<unsigned char>(sv.back()))) {
    sv.remove_suffix(1);
  }

  return std::string(sv);
}
}  // namespace base
}  // namespace android
