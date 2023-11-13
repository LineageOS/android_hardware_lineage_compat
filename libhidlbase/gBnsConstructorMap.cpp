/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <hidl/Static.h>

namespace android {
namespace hardware {
namespace details {

// Deprecated; kept for ABI compatibility. Use getBnConstructorMap.
auto gBnConstructorMap = &getBnConstructorMap();

// Deprecated; kept for ABI compatibility. Use getBsConstructorMap.
auto gBsConstructorMap = &getBsConstructorMap();

}  // namespace details
}  // namespace hardware
}  // namespace android
