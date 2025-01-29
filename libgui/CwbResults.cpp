/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <binder/Parcel.h>

namespace android {
namespace gui {

class CwbResults {
  public:
    CwbResults();
    virtual ~CwbResults() = default;

    status_t writeToParcel(Parcel* parcel) const;
    status_t readFromParcel(const Parcel* parcel);

  private:
    const void* mBuffer{nullptr};
    size_t mBufferSize{0};
};

CwbResults::CwbResults() = default;

status_t CwbResults::writeToParcel(Parcel* parcel) const {
    if (!parcel) return BAD_VALUE;

    status_t err = parcel->writeBool(mBuffer != nullptr);
    if (err != OK) return err;

    if (mBuffer != nullptr) {
        err = parcel->write(mBuffer, mBufferSize);
        if (err != OK) {
            return err;
        }
    }

    return OK;
}

status_t CwbResults::readFromParcel(const Parcel* parcel) {
    if (!parcel) return BAD_VALUE;

    bool hasGraphicBuffer = false;
    status_t err = parcel->readBool(&hasGraphicBuffer);

    return err;
}

}  // namespace gui
}  // namespace android
