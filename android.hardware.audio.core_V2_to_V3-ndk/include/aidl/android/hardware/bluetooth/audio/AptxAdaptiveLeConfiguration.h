/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/AptxAdaptiveLeConfiguration.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/AptxAdaptiveLeConfiguration.aidl
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
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class AptxAdaptiveLeConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int8_t pcmBitDepth = 0;
  int32_t samplingFrequencyHz = 0;
  int32_t frameDurationUs = 0;
  int32_t octetsPerFrame = 0;
  int8_t blocksPerSdu = 0;
  int32_t codecMode = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AptxAdaptiveLeConfiguration& _rhs) const {
    return std::tie(pcmBitDepth, samplingFrequencyHz, frameDurationUs, octetsPerFrame, blocksPerSdu, codecMode) == std::tie(_rhs.pcmBitDepth, _rhs.samplingFrequencyHz, _rhs.frameDurationUs, _rhs.octetsPerFrame, _rhs.blocksPerSdu, _rhs.codecMode);
  }
  inline bool operator<(const AptxAdaptiveLeConfiguration& _rhs) const {
    return std::tie(pcmBitDepth, samplingFrequencyHz, frameDurationUs, octetsPerFrame, blocksPerSdu, codecMode) < std::tie(_rhs.pcmBitDepth, _rhs.samplingFrequencyHz, _rhs.frameDurationUs, _rhs.octetsPerFrame, _rhs.blocksPerSdu, _rhs.codecMode);
  }
  inline bool operator!=(const AptxAdaptiveLeConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AptxAdaptiveLeConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AptxAdaptiveLeConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AptxAdaptiveLeConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AptxAdaptiveLeConfiguration{";
    _aidl_os << "pcmBitDepth: " << ::android::internal::ToString(pcmBitDepth);
    _aidl_os << ", samplingFrequencyHz: " << ::android::internal::ToString(samplingFrequencyHz);
    _aidl_os << ", frameDurationUs: " << ::android::internal::ToString(frameDurationUs);
    _aidl_os << ", octetsPerFrame: " << ::android::internal::ToString(octetsPerFrame);
    _aidl_os << ", blocksPerSdu: " << ::android::internal::ToString(blocksPerSdu);
    _aidl_os << ", codecMode: " << ::android::internal::ToString(codecMode);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
