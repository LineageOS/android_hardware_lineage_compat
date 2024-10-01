/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

extern "C" void* _ZN15_C2FenceFactory15CreateSyncFenceEib(int fenceFd, bool validate);

extern "C" void* _ZN15_C2FenceFactory15CreateSyncFenceEi(int fenceFd) {
    return _ZN15_C2FenceFactory15CreateSyncFenceEib(fenceFd, true);
}
