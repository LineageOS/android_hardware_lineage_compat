/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <C2Buffer.h>

extern "C" C2Fence _ZN15_C2FenceFactory15CreateSyncFenceEib(void* thisptr, int fenceFd, bool validate);

extern "C" C2Fence _ZN15_C2FenceFactory15CreateSyncFenceEi(void* thisptr, int fenceFd) {
    return _ZN15_C2FenceFactory15CreateSyncFenceEib(thisptr, fenceFd, true);
}
