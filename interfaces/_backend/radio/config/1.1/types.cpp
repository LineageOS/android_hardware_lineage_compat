#define LOG_TAG "android.hardware.radio.config@1.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/radio/config/1.1/types.h>
#include <android/hardware/radio/config/1.1/hwtypes.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_1 {

::android::status_t readEmbeddedFromParcel(
        const PhoneCapability &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_logicalModemList_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::config::V1_1::ModemInfo> &>(obj.logicalModemList),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::config::V1_1::PhoneCapability, logicalModemList), &_hidl_logicalModemList_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhoneCapability &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_logicalModemList_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.logicalModemList,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::config::V1_1::PhoneCapability, logicalModemList), &_hidl_logicalModemList_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
