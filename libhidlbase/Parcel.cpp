/*
 * Copyright (C) 2005 The Android Open Source Project
 *               2024 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "hw-Parcel"

#include <utils/Log.h>

#include "Parcel.h"

#define LOG_ALLOC(...)
//#define LOG_ALLOC(...) ALOG(LOG_DEBUG, LOG_TAG, __VA_ARGS__)

// ---------------------------------------------------------------------------

namespace android {
namespace hardware {

static std::atomic<size_t> gParcelGlobalAllocCount;
static std::atomic<size_t> gParcelGlobalAllocSize;

status_t Parcel::setData(const uint8_t* buffer, size_t len)
{
    if (len > INT32_MAX) {
        // don't accept size_t values which may have come from an
        // inadvertent conversion from a negative int.
        return BAD_VALUE;
    }

    status_t err = restartWrite(len);
    if (err == NO_ERROR) {
        memcpy(const_cast<uint8_t*>(data()), buffer, len);
        mDataSize = len;
        mFdsKnown = false;
    }
    return err;
}

extern void zeroMemory(uint8_t* data, size_t size);

static uint8_t* reallocZeroFree(uint8_t* data, size_t oldCapacity, size_t newCapacity, bool zero) {
    if (!zero) {
        return (uint8_t*)realloc(data, newCapacity);
    }
    uint8_t* newData = (uint8_t*)malloc(newCapacity);
    if (!newData) {
        return nullptr;
    }

    memcpy(newData, data, std::min(oldCapacity, newCapacity));
    zeroMemory(data, oldCapacity);
    free(data);
    return newData;
}

status_t Parcel::restartWrite(size_t desired)
{
    if (desired > INT32_MAX) {
        // don't accept size_t values which may have come from an
        // inadvertent conversion from a negative int.
        return BAD_VALUE;
    }

    if (mOwner) {
        freeData();
        return continueWrite(desired);
    }

    uint8_t* data = reallocZeroFree(mData, mDataCapacity, desired, mDeallocZero);
    if (!data && desired > mDataCapacity) {
        mError = NO_MEMORY;
        return NO_MEMORY;
    }

    releaseObjects();

    if (data || desired == 0) {
        LOG_ALLOC("Parcel %p: restart from %zu to %zu capacity", this, mDataCapacity, desired);
        if (mDataCapacity > desired) {
            gParcelGlobalAllocSize -= (mDataCapacity - desired);
        } else {
            gParcelGlobalAllocSize += (desired - mDataCapacity);
        }

        if (!mData) {
            gParcelGlobalAllocCount++;
        }
        mData = data;
        mDataCapacity = desired;
    }

    mDataSize = mDataPos = 0;
    ALOGV("restartWrite Setting data size of %p to %zu", this, mDataSize);
    ALOGV("restartWrite Setting data pos of %p to %zu", this, mDataPos);

    free(mObjects);
    mObjects = nullptr;
    mObjectsSize = mObjectsCapacity = 0;
    mNextObjectHint = 0;
    mHasFds = false;
    clearCache();
    mFdsKnown = true;
    mAllowFds = true;

    return NO_ERROR;
}

} // namespace hardware
} // namespace android
