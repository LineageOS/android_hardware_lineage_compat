/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/HfpConfiguration.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/HfpConfiguration.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/bluetooth/audio/CodecId.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class HfpConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::hardware::bluetooth::audio::CodecId codecId;
  int32_t connectionHandle = 0;
  bool nrec = false;
  bool controllerCodec = false;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const HfpConfiguration& _rhs) const {
    return std::tie(codecId, connectionHandle, nrec, controllerCodec) == std::tie(_rhs.codecId, _rhs.connectionHandle, _rhs.nrec, _rhs.controllerCodec);
  }
  inline bool operator<(const HfpConfiguration& _rhs) const {
    return std::tie(codecId, connectionHandle, nrec, controllerCodec) < std::tie(_rhs.codecId, _rhs.connectionHandle, _rhs.nrec, _rhs.controllerCodec);
  }
  inline bool operator!=(const HfpConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const HfpConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const HfpConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const HfpConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "HfpConfiguration{";
    _aidl_os << "codecId: " << ::android::internal::ToString(codecId);
    _aidl_os << ", connectionHandle: " << ::android::internal::ToString(connectionHandle);
    _aidl_os << ", nrec: " << ::android::internal::ToString(nrec);
    _aidl_os << ", controllerCodec: " << ::android::internal::ToString(controllerCodec);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
