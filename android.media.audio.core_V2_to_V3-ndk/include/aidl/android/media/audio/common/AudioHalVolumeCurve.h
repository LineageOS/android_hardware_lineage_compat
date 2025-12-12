/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioHalVolumeCurve.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioHalVolumeCurve.aidl
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
#include <aidl/android/media/audio/common/AudioHalVolumeCurve.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioHalVolumeCurve {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class DeviceCategory : int8_t {
    HEADSET = 0,
    SPEAKER = 1,
    EARPIECE = 2,
    EXT_MEDIA = 3,
    HEARING_AID = 4,
  };

  class CurvePoint {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int8_t index = 0;
    int32_t attenuationMb = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const CurvePoint& _rhs) const {
      return std::tie(index, attenuationMb) == std::tie(_rhs.index, _rhs.attenuationMb);
    }
    inline bool operator<(const CurvePoint& _rhs) const {
      return std::tie(index, attenuationMb) < std::tie(_rhs.index, _rhs.attenuationMb);
    }
    inline bool operator!=(const CurvePoint& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const CurvePoint& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const CurvePoint& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const CurvePoint& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int8_t { MIN_INDEX = 0 };
    enum : int8_t { MAX_INDEX = 100 };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "CurvePoint{";
      _aidl_os << "index: " << ::android::internal::ToString(index);
      _aidl_os << ", attenuationMb: " << ::android::internal::ToString(attenuationMb);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  ::aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory deviceCategory = ::aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory::SPEAKER;
  std::vector<::aidl::android::media::audio::common::AudioHalVolumeCurve::CurvePoint> curvePoints;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioHalVolumeCurve& _rhs) const {
    return std::tie(deviceCategory, curvePoints) == std::tie(_rhs.deviceCategory, _rhs.curvePoints);
  }
  inline bool operator<(const AudioHalVolumeCurve& _rhs) const {
    return std::tie(deviceCategory, curvePoints) < std::tie(_rhs.deviceCategory, _rhs.curvePoints);
  }
  inline bool operator!=(const AudioHalVolumeCurve& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioHalVolumeCurve& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioHalVolumeCurve& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioHalVolumeCurve& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioHalVolumeCurve{";
    _aidl_os << "deviceCategory: " << ::android::internal::ToString(deviceCategory);
    _aidl_os << ", curvePoints: " << ::android::internal::ToString(curvePoints);
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
[[nodiscard]] static inline std::string toString(AudioHalVolumeCurve::DeviceCategory val) {
  switch(val) {
  case AudioHalVolumeCurve::DeviceCategory::HEADSET:
    return "HEADSET";
  case AudioHalVolumeCurve::DeviceCategory::SPEAKER:
    return "SPEAKER";
  case AudioHalVolumeCurve::DeviceCategory::EARPIECE:
    return "EARPIECE";
  case AudioHalVolumeCurve::DeviceCategory::EXT_MEDIA:
    return "EXT_MEDIA";
  case AudioHalVolumeCurve::DeviceCategory::HEARING_AID:
    return "HEARING_AID";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory, 5> enum_values<aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory> = {
  aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory::HEADSET,
  aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory::SPEAKER,
  aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory::EARPIECE,
  aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory::EXT_MEDIA,
  aidl::android::media::audio::common::AudioHalVolumeCurve::DeviceCategory::HEARING_AID,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
