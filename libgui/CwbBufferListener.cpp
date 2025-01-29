/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/Status.h>

using android::binder::Status;

namespace android {
namespace gui {

enum {
    NOTIFY_CWB_BUFFER_DONE = IBinder::FIRST_CALL_TRANSACTION,
};

class CwbResults {
  private:
    const void* mBuffer;
    size_t mBufferSize;

  public:
    CwbResults();
    virtual ~CwbResults() = default;

    status_t writeToParcel(Parcel* parcel) const {
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
};

CwbResults::CwbResults() : mBuffer(nullptr), mBufferSize(0) {}

class ICwbBufferListener : public IInterface {
  public:
    DECLARE_META_INTERFACE(CwbBufferListener);
    virtual Status notifyCWBBufferDone(const CwbResults& results) = 0;
};

class BpCwbBufferListener : public BpInterface<ICwbBufferListener> {
  public:
    explicit BpCwbBufferListener(const sp<IBinder>& impl) : BpInterface<ICwbBufferListener>(impl) {}

    virtual Status notifyCWBBufferDone(const CwbResults& results) override;
};

Status BpCwbBufferListener::notifyCWBBufferDone(const CwbResults& results) {
    Parcel data, reply;
    Status status;

    data.writeInterfaceToken(getInterfaceDescriptor());

    status_t err = results.writeToParcel(&data);
    if (err != OK) {
        return Status::fromStatusT(err);
    }

    err = remote()->transact(NOTIFY_CWB_BUFFER_DONE, data, &reply);
    if (err != OK) {
        return Status::fromStatusT(err);
    }

    if (!status.readFromParcel(reply)) {
        return Status::fromStatusT(BAD_VALUE);
    }

    return Status::ok();
}

IMPLEMENT_META_INTERFACE(CwbBufferListener, "android.gui.ICwbBufferListener");

}  // namespace gui
}  // namespace android
