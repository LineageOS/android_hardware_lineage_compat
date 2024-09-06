/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {

extern "C" status_t _ZN7android8hardware6Parcel7setDataEPKhm(Parcel* thisptr, const uint8_t* buffer,
                                                             size_t len) {
    thisptr->freeData();
    status_t err = thisptr->setDataSize(len);
    if (err == NO_ERROR) {
        memcpy(const_cast<uint8_t*>(thisptr->data()), buffer, len);
    }
    return err;
}

}  // namespace hardware
}  // namespace android
