/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string>

extern "C" bool
_Z23CgroupGetControllerPathRKNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPS5_(
        const std::string& cgroup_name, std::string* path);

extern "C" bool CgroupGetControllerPath(const std::string& cgroup_name, std::string* path) {
    return _Z23CgroupGetControllerPathRKNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPS5_(
            cgroup_name, path);
}
