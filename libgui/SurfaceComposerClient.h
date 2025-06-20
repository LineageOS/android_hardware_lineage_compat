/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <binder/IBinder.h>

namespace android {
namespace SurfaceComposerClient {

sp<IBinder> createVirtualDisplay(const std::string& displayName, bool isSecure,
                                 bool optimizeForPower, const std::string& uniqueId,
                                 float requestedRefreshRate);
sp<IBinder> createVirtualDisplay(const std::string& displayName, bool isSecure,
                                 const std::string& uniqueId, float requestedRefreshRate);
sp<IBinder> createDisplay(const android::String8& displayName, bool isSecure,
                          float requestedRefreshRate);

status_t destroyVirtualDisplay(const sp<IBinder>& displayToken);
status_t destroyDisplay(const sp<IBinder>& displayToken);

class Transaction {
  public:
    status_t apply(bool synchronous, bool oneWay);
    status_t apply(bool synchronous);
};

}  // namespace SurfaceComposerClient
}  // namespace android
