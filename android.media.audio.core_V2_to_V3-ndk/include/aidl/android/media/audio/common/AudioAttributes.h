/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioAttributes.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioAttributes.aidl
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
#include <aidl/android/media/audio/common/AudioContentType.h>
#include <aidl/android/media/audio/common/AudioFlag.h>
#include <aidl/android/media/audio/common/AudioSource.h>
#include <aidl/android/media/audio/common/AudioUsage.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioAttributes {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::audio::common::AudioContentType contentType = ::aidl::android::media::audio::common::AudioContentType::UNKNOWN;
  ::aidl::android::media::audio::common::AudioUsage usage = ::aidl::android::media::audio::common::AudioUsage::UNKNOWN;
  ::aidl::android::media::audio::common::AudioSource source = ::aidl::android::media::audio::common::AudioSource::DEFAULT;
  int32_t flags = 0;
  std::vector<std::string> tags;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioAttributes& _rhs) const {
    return std::tie(contentType, usage, source, flags, tags) == std::tie(_rhs.contentType, _rhs.usage, _rhs.source, _rhs.flags, _rhs.tags);
  }
  inline bool operator<(const AudioAttributes& _rhs) const {
    return std::tie(contentType, usage, source, flags, tags) < std::tie(_rhs.contentType, _rhs.usage, _rhs.source, _rhs.flags, _rhs.tags);
  }
  inline bool operator!=(const AudioAttributes& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioAttributes& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioAttributes& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioAttributes& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioAttributes{";
    _aidl_os << "contentType: " << ::android::internal::ToString(contentType);
    _aidl_os << ", usage: " << ::android::internal::ToString(usage);
    _aidl_os << ", source: " << ::android::internal::ToString(source);
    _aidl_os << ", flags: " << ::android::internal::ToString(flags);
    _aidl_os << ", tags: " << ::android::internal::ToString(tags);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
