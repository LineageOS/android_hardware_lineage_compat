/*
 * Copyright (C) 2024 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#define HdrCapabilities HdrCapabilitiesOrig
#define private public
#include <ui/HdrCapabilities.h>
#undef private
#undef HdrCapabilities

namespace android {

class HdrCapabilities : HdrCapabilitiesOrig {
  public:
    ~HdrCapabilities();

    size_t getFlattenedSize() const;
    status_t flatten(void* buffer, size_t size) const;
    status_t unflatten(void const* buffer, size_t size);
};

}  // namespace android
