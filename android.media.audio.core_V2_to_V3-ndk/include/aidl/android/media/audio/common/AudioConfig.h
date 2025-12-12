/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioConfig.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioConfig.aidl
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
#include <aidl/android/media/audio/common/AudioConfigBase.h>
#include <aidl/android/media/audio/common/AudioOffloadInfo.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioConfigBase;
class AudioOffloadInfo;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioConfig {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::media::audio::common::AudioConfigBase base;
  ::aidl::android::media::audio::common::AudioOffloadInfo offloadInfo;
  int64_t frameCount = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioConfig& _rhs) const {
    return std::tie(base, offloadInfo, frameCount) == std::tie(_rhs.base, _rhs.offloadInfo, _rhs.frameCount);
  }
  inline bool operator<(const AudioConfig& _rhs) const {
    return std::tie(base, offloadInfo, frameCount) < std::tie(_rhs.base, _rhs.offloadInfo, _rhs.frameCount);
  }
  inline bool operator!=(const AudioConfig& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioConfig& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioConfig& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioConfig& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioConfig{";
    _aidl_os << "base: " << ::android::internal::ToString(base);
    _aidl_os << ", offloadInfo: " << ::android::internal::ToString(offloadInfo);
    _aidl_os << ", frameCount: " << ::android::internal::ToString(frameCount);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
