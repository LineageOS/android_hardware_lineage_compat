#define LOG_TAG "android.hardware.radio.config@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/radio/config/1.0/types.h>
#include <android/hardware/radio/config/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const SimSlotStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.atr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, atr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.iccid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, iccid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SimSlotStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.atr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, atr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.iccid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, iccid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
