/*
 * Copyright (C) 2022-2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <utils/Errors.h>

using android::status_t;

extern "C" status_t _ZN7android21SurfaceComposerClient11Transaction5applyEbb(void* thisptr,
                                                                             bool synchronous,
                                                                             bool oneWay);

extern "C" void*
_ZN7android21SurfaceComposerClient20createVirtualDisplayERKNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEbS9_f(
        void* displayName, bool isSecure, void* uniqueId, float requestedRefreshRate);

extern "C" void* _ZN7android21SurfaceComposerClient6kEmptyE;

extern "C" void _ZN7android21SurfaceComposerClient21destroyVirtualDisplayERKNS_2spINS_7IBinderEEE(
        void* displayToken);

extern "C" status_t _ZN7android21SurfaceComposerClient11Transaction5applyEb(void* thisptr,
                                                                            bool synchronous) {
    return _ZN7android21SurfaceComposerClient11Transaction5applyEbb(thisptr, synchronous, false);
}

extern "C" void* _ZN7android21SurfaceComposerClient13createDisplayERKNS_7String8Ebf(
        void* displayName, bool isSecure, float requestedRefreshRate) {
    return _ZN7android21SurfaceComposerClient20createVirtualDisplayERKNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEbS9_f(
            displayName, isSecure, _ZN7android21SurfaceComposerClient6kEmptyE,
            requestedRefreshRate);
}

extern "C" void _ZN7android21SurfaceComposerClient14destroyDisplayERKNS_2spINS_7IBinderEEE(
        void* displayToken) {
    _ZN7android21SurfaceComposerClient21destroyVirtualDisplayERKNS_2spINS_7IBinderEEE(displayToken);
}
