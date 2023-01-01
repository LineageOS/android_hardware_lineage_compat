/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <dlfcn.h>
#include <stdio.h>

extern "C" void* dlopen(const char* filename, int flag) {
    static auto dlopen_orig = reinterpret_cast<typeof(dlopen)*>(dlsym(RTLD_NEXT, "dlopen"));

    auto ret = dlopen_orig(filename, flag);
    printf("dlopen(%s) -> %p, errno: %s\n", filename, ret, dlerror());

    return ret;
}
