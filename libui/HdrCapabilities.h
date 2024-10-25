/*
 * Copyright (C) 2024 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ui/GraphicTypes.h>

namespace android {

class HdrCapabilities {
  public:
    HdrCapabilities() = delete;
    ~HdrCapabilities();

    size_t getFlattenedSize() const;
    status_t flatten(void* buffer, size_t size) const;
    status_t unflatten(void const* buffer, size_t size);

  private:
    std::vector<ui::Hdr> mSupportedHdrTypes;
    float mMaxLuminance;
    float mMaxAverageLuminance;
    float mMinLuminance;
};

}  // namespace android
