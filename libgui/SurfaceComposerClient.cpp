/*
 * Copyright (C) 2022-2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "SurfaceComposerClient.h"

namespace android {
namespace SurfaceComposerClient {

std::string kEmpty;

sp<IBinder> createDisplay(const std::string& displayName, bool isSecure,
                          float requestedRefreshRate) {
    return createVirtualDisplay(displayName, isSecure, kEmpty, requestedRefreshRate);
}

status_t destroyDisplay(const sp<IBinder>& displayToken) {
    return destroyVirtualDisplay(displayToken);
}

status_t Transaction::apply(bool synchronous) {
    return apply(synchronous, false);
}

}  // namespace SurfaceComposerClient
}  // namespace android
