/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioProfile.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioProfile.aidl
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
#include <aidl/android/media/audio/common/AudioEncapsulationType.h>
#include <aidl/android/media/audio/common/AudioFormatDescription.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioFormatDescription;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioProfile {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::string name;
  ::aidl::android::media::audio::common::AudioFormatDescription format;
  std::vector<::aidl::android::media::audio::common::AudioChannelLayout> channelMasks;
  std::vector<int32_t> sampleRates;
  ::aidl::android::media::audio::common::AudioEncapsulationType encapsulationType = ::aidl::android::media::audio::common::AudioEncapsulationType::NONE;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioProfile& _rhs) const {
    return std::tie(name, format, channelMasks, sampleRates, encapsulationType) == std::tie(_rhs.name, _rhs.format, _rhs.channelMasks, _rhs.sampleRates, _rhs.encapsulationType);
  }
  inline bool operator<(const AudioProfile& _rhs) const {
    return std::tie(name, format, channelMasks, sampleRates, encapsulationType) < std::tie(_rhs.name, _rhs.format, _rhs.channelMasks, _rhs.sampleRates, _rhs.encapsulationType);
  }
  inline bool operator!=(const AudioProfile& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioProfile& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioProfile& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioProfile& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioProfile{";
    _aidl_os << "name: " << ::android::internal::ToString(name);
    _aidl_os << ", format: " << ::android::internal::ToString(format);
    _aidl_os << ", channelMasks: " << ::android::internal::ToString(channelMasks);
    _aidl_os << ", sampleRates: " << ::android::internal::ToString(sampleRates);
    _aidl_os << ", encapsulationType: " << ::android::internal::ToString(encapsulationType);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
