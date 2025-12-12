/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioGain.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioGain.aidl
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
#include <aidl/android/media/audio/common/AudioChannelLayout.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioGain {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t mode = 0;
  ::aidl::android::media::audio::common::AudioChannelLayout channelMask;
  int32_t minValue = 0;
  int32_t maxValue = 0;
  int32_t defaultValue = 0;
  int32_t stepValue = 0;
  int32_t minRampMs = 0;
  int32_t maxRampMs = 0;
  bool useForVolume = false;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioGain& _rhs) const {
    return std::tie(mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs, useForVolume) == std::tie(_rhs.mode, _rhs.channelMask, _rhs.minValue, _rhs.maxValue, _rhs.defaultValue, _rhs.stepValue, _rhs.minRampMs, _rhs.maxRampMs, _rhs.useForVolume);
  }
  inline bool operator<(const AudioGain& _rhs) const {
    return std::tie(mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs, useForVolume) < std::tie(_rhs.mode, _rhs.channelMask, _rhs.minValue, _rhs.maxValue, _rhs.defaultValue, _rhs.stepValue, _rhs.minRampMs, _rhs.maxRampMs, _rhs.useForVolume);
  }
  inline bool operator!=(const AudioGain& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioGain& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioGain& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioGain& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioGain{";
    _aidl_os << "mode: " << ::android::internal::ToString(mode);
    _aidl_os << ", channelMask: " << ::android::internal::ToString(channelMask);
    _aidl_os << ", minValue: " << ::android::internal::ToString(minValue);
    _aidl_os << ", maxValue: " << ::android::internal::ToString(maxValue);
    _aidl_os << ", defaultValue: " << ::android::internal::ToString(defaultValue);
    _aidl_os << ", stepValue: " << ::android::internal::ToString(stepValue);
    _aidl_os << ", minRampMs: " << ::android::internal::ToString(minRampMs);
    _aidl_os << ", maxRampMs: " << ::android::internal::ToString(maxRampMs);
    _aidl_os << ", useForVolume: " << ::android::internal::ToString(useForVolume);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
