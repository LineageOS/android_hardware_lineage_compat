/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/AptxAdaptiveConfiguration.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/AptxAdaptiveConfiguration.aidl
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
#include <aidl/android/hardware/bluetooth/audio/AptxAdaptiveChannelMode.h>
#include <aidl/android/hardware/bluetooth/audio/AptxAdaptiveInputMode.h>
#include <aidl/android/hardware/bluetooth/audio/AptxAdaptiveTimeToPlay.h>
#include <aidl/android/hardware/bluetooth/audio/AptxMode.h>
#include <aidl/android/hardware/bluetooth/audio/AptxSinkBuffering.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::bluetooth::audio {
class AptxAdaptiveTimeToPlay;
class AptxSinkBuffering;
}  // namespace aidl::android::hardware::bluetooth::audio
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class AptxAdaptiveConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t sampleRateHz = 0;
  ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode channelMode = ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode(0);
  int8_t bitsPerSample = 0;
  ::aidl::android::hardware::bluetooth::audio::AptxMode aptxMode = ::aidl::android::hardware::bluetooth::audio::AptxMode(0);
  ::aidl::android::hardware::bluetooth::audio::AptxSinkBuffering sinkBufferingMs;
  ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveTimeToPlay ttp;
  ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveInputMode inputMode = ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveInputMode(0);
  int32_t inputFadeDurationMs = 0;
  std::vector<uint8_t> aptxAdaptiveConfigStream;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AptxAdaptiveConfiguration& _rhs) const {
    return std::tie(sampleRateHz, channelMode, bitsPerSample, aptxMode, sinkBufferingMs, ttp, inputMode, inputFadeDurationMs, aptxAdaptiveConfigStream) == std::tie(_rhs.sampleRateHz, _rhs.channelMode, _rhs.bitsPerSample, _rhs.aptxMode, _rhs.sinkBufferingMs, _rhs.ttp, _rhs.inputMode, _rhs.inputFadeDurationMs, _rhs.aptxAdaptiveConfigStream);
  }
  inline bool operator<(const AptxAdaptiveConfiguration& _rhs) const {
    return std::tie(sampleRateHz, channelMode, bitsPerSample, aptxMode, sinkBufferingMs, ttp, inputMode, inputFadeDurationMs, aptxAdaptiveConfigStream) < std::tie(_rhs.sampleRateHz, _rhs.channelMode, _rhs.bitsPerSample, _rhs.aptxMode, _rhs.sinkBufferingMs, _rhs.ttp, _rhs.inputMode, _rhs.inputFadeDurationMs, _rhs.aptxAdaptiveConfigStream);
  }
  inline bool operator!=(const AptxAdaptiveConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AptxAdaptiveConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AptxAdaptiveConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AptxAdaptiveConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AptxAdaptiveConfiguration{";
    _aidl_os << "sampleRateHz: " << ::android::internal::ToString(sampleRateHz);
    _aidl_os << ", channelMode: " << ::android::internal::ToString(channelMode);
    _aidl_os << ", bitsPerSample: " << ::android::internal::ToString(bitsPerSample);
    _aidl_os << ", aptxMode: " << ::android::internal::ToString(aptxMode);
    _aidl_os << ", sinkBufferingMs: " << ::android::internal::ToString(sinkBufferingMs);
    _aidl_os << ", ttp: " << ::android::internal::ToString(ttp);
    _aidl_os << ", inputMode: " << ::android::internal::ToString(inputMode);
    _aidl_os << ", inputFadeDurationMs: " << ::android::internal::ToString(inputFadeDurationMs);
    _aidl_os << ", aptxAdaptiveConfigStream: " << ::android::internal::ToString(aptxAdaptiveConfigStream);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
