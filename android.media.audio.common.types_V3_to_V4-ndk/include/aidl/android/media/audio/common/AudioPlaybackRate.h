/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioPlaybackRate.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioPlaybackRate.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/media/audio/common/AudioPlaybackRate.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioPlaybackRate {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class TimestretchMode : int32_t {
    DEFAULT = 0,
    VOICE = 1,
  };

  enum class TimestretchFallbackMode : int32_t {
    SYS_RESERVED_CUT_REPEAT = -1,
    SYS_RESERVED_DEFAULT = 0,
    MUTE = 1,
    FAIL = 2,
  };

  float speed = 0.000000f;
  float pitch = 0.000000f;
  ::aidl::android::media::audio::common::AudioPlaybackRate::TimestretchMode timestretchMode = ::aidl::android::media::audio::common::AudioPlaybackRate::TimestretchMode::DEFAULT;
  ::aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode fallbackMode = ::aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode::SYS_RESERVED_DEFAULT;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioPlaybackRate& _rhs) const {
    return std::tie(speed, pitch, timestretchMode, fallbackMode) == std::tie(_rhs.speed, _rhs.pitch, _rhs.timestretchMode, _rhs.fallbackMode);
  }
  inline bool operator<(const AudioPlaybackRate& _rhs) const {
    return std::tie(speed, pitch, timestretchMode, fallbackMode) < std::tie(_rhs.speed, _rhs.pitch, _rhs.timestretchMode, _rhs.fallbackMode);
  }
  inline bool operator!=(const AudioPlaybackRate& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioPlaybackRate& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioPlaybackRate& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioPlaybackRate& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioPlaybackRate{";
    _aidl_os << "speed: " << ::android::internal::ToString(speed);
    _aidl_os << ", pitch: " << ::android::internal::ToString(pitch);
    _aidl_os << ", timestretchMode: " << ::android::internal::ToString(timestretchMode);
    _aidl_os << ", fallbackMode: " << ::android::internal::ToString(fallbackMode);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioPlaybackRate::TimestretchMode val) {
  switch(val) {
  case AudioPlaybackRate::TimestretchMode::DEFAULT:
    return "DEFAULT";
  case AudioPlaybackRate::TimestretchMode::VOICE:
    return "VOICE";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::audio::common::AudioPlaybackRate::TimestretchMode, 2> enum_values<aidl::android::media::audio::common::AudioPlaybackRate::TimestretchMode> = {
  aidl::android::media::audio::common::AudioPlaybackRate::TimestretchMode::DEFAULT,
  aidl::android::media::audio::common::AudioPlaybackRate::TimestretchMode::VOICE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioPlaybackRate::TimestretchFallbackMode val) {
  switch(val) {
  case AudioPlaybackRate::TimestretchFallbackMode::SYS_RESERVED_CUT_REPEAT:
    return "SYS_RESERVED_CUT_REPEAT";
  case AudioPlaybackRate::TimestretchFallbackMode::SYS_RESERVED_DEFAULT:
    return "SYS_RESERVED_DEFAULT";
  case AudioPlaybackRate::TimestretchFallbackMode::MUTE:
    return "MUTE";
  case AudioPlaybackRate::TimestretchFallbackMode::FAIL:
    return "FAIL";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode, 4> enum_values<aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode> = {
  aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode::SYS_RESERVED_CUT_REPEAT,
  aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode::SYS_RESERVED_DEFAULT,
  aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode::MUTE,
  aidl::android::media::audio::common::AudioPlaybackRate::TimestretchFallbackMode::FAIL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
