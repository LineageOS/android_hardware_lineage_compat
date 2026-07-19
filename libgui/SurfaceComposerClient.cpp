/*
 * Copyright (C) 2022-2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "SurfaceComposerClient.h"

extern "C" void*
_ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjiiRKNS_2spINS_7IBinderEEERKNS_3gui13LayerMetadataEPj(
        void* thisptr, const void* name, uint32_t w, uint32_t h, int32_t format, int32_t flags,
        const void* parentHandle, const void* metadata, uint32_t* outTransformHint);

extern "C" void*
_ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjiiRKNS_2spINS_7IBinderEEENS_3gui13LayerMetadataEPj(
        void* thisptr, const void* name, uint32_t w, uint32_t h, int32_t format, int32_t flags,
        const void* parentHandle, const void* metadata, uint32_t* outTransformHint) {
    return _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjiiRKNS_2spINS_7IBinderEEERKNS_3gui13LayerMetadataEPj(
            thisptr, name, w, h, format, flags, parentHandle, metadata, outTransformHint);
}

namespace android {
namespace SurfaceComposerClient {

std::string kEmpty;

sp<IBinder> createVirtualDisplay(const std::string& displayName, bool isSecure,
                                 bool optimizeForPower, const std::string& uniqueId,
                                 float requestedRefreshRate) {
    return createVirtualDisplay(displayName, isSecure, optimizeForPower, uniqueId,
                                static_cast<uid_t>(-1), requestedRefreshRate);
}

sp<IBinder> createVirtualDisplay(const std::string& displayName, bool isSecure,
                                 const std::string& uniqueId, float requestedRefreshRate) {
    return createVirtualDisplay(displayName, isSecure, true, uniqueId, static_cast<uid_t>(-1),
                                requestedRefreshRate);
}

sp<IBinder> createDisplay(const android::String8& displayName, bool isSecure,
                          float requestedRefreshRate) {
    return createVirtualDisplay(displayName.c_str(), isSecure, kEmpty, requestedRefreshRate);
}

status_t destroyDisplay(const sp<IBinder>& displayToken) {
    return destroyVirtualDisplay(displayToken);
}

Transaction::~Transaction() = default;

status_t Transaction::apply(bool synchronous) {
    return apply(synchronous, false);
}

}  // namespace SurfaceComposerClient
}  // namespace android
