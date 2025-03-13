/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string>
#include <vector>

extern "C" {
bool _Z23CgroupGetControllerPathRKNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPS5_(
        const std::string& cgroup_name, std::string* path);

bool CgroupGetControllerPath(const std::string& cgroup_name, std::string* path) {
    return _Z23CgroupGetControllerPathRKNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPS5_(
            cgroup_name, path);
}

bool _Z15SetTaskProfilesiRKNSt3__16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEEEb(
        pid_t tid, const std::vector<std::string>& profiles, bool use_fd_cache = false);

bool SetTaskProfiles(pid_t tid, const std::vector<std::string>& profiles,
                     bool use_fd_cache = false) {
    return _Z15SetTaskProfilesiRKNSt3__16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEEEb(
            tid, profiles, use_fd_cache);
}
}
