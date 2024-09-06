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

#ifndef ANDROID_HARDWARE_PARCEL_H
#define ANDROID_HARDWARE_PARCEL_H

#include <string>
#include <vector>

#include <cutils/native_handle.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/String16.h>

#include <hwbinder/IInterface.h>


namespace android {
namespace hardware {

// TODO this is never defined
#ifdef BINDER_IPC_32BIT
typedef unsigned int binder_size_t;
typedef unsigned int binder_uintptr_t;
#else
typedef unsigned long long binder_size_t;
typedef unsigned long long binder_uintptr_t;
#endif

// This is a minimal copy of the class which adds setData back
class Parcel {
    friend class IPCThreadState;
public:
    const uint8_t*      data() const;
    status_t            setData(const uint8_t* buffer, size_t len);
    void                freeData();

private:
    typedef void        (*release_func)(Parcel* parcel,
                                        const uint8_t* data, size_t dataSize,
                                        const binder_size_t* objects, size_t objectsSize,
                                        void* cookie);

    void                releaseObjects();
    status_t            restartWrite(size_t desired);
    status_t            continueWrite(size_t desired);

    void                clearCache() const;

    status_t            mError;
    uint8_t*            mData;
    size_t              mDataSize;
    size_t              mDataCapacity;
    mutable size_t      mDataPos;
    binder_size_t*      mObjects;
    size_t              mObjectsSize;
    size_t              mObjectsCapacity;
    mutable size_t      mNextObjectHint;

    mutable bool        mFdsKnown;
    mutable bool        mHasFds;
    bool                mAllowFds;

    // if this parcelable is involved in a secure transaction, force the
    // data to be overridden with zero when deallocated
    mutable bool        mDeallocZero;

    release_func        mOwner;

};

} // namespace hardware
} // namespace android

#endif // ANDROID_HARDWARE_PARCEL_H
