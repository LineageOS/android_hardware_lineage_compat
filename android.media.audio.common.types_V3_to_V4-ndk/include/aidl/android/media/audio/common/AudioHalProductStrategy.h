/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioHalProductStrategy.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioHalProductStrategy.aidl
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
#include <aidl/android/media/audio/common/AudioHalAttributesGroup.h>
#include <aidl/android/media/audio/common/AudioHalProductStrategy.h>
#include <aidl/android/media/audio/common/AudioProductStrategyType.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioHalAttributesGroup;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioHalProductStrategy {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class ZoneId : int32_t {
    DEFAULT = 0,
  };

  int32_t id = -1;
  std::vector<::aidl::android::media::audio::common::AudioHalAttributesGroup> attributesGroups;
  std::optional<std::string> name;
  int32_t zoneId = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioHalProductStrategy& _rhs) const {
    return std::tie(id, attributesGroups, name, zoneId) == std::tie(_rhs.id, _rhs.attributesGroups, _rhs.name, _rhs.zoneId);
  }
  inline bool operator<(const AudioHalProductStrategy& _rhs) const {
    return std::tie(id, attributesGroups, name, zoneId) < std::tie(_rhs.id, _rhs.attributesGroups, _rhs.name, _rhs.zoneId);
  }
  inline bool operator!=(const AudioHalProductStrategy& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioHalProductStrategy& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioHalProductStrategy& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioHalProductStrategy& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  enum : int32_t { VENDOR_STRATEGY_ID_START = 1000 };
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioHalProductStrategy{";
    _aidl_os << "id: " << ::android::internal::ToString(id);
    _aidl_os << ", attributesGroups: " << ::android::internal::ToString(attributesGroups);
    _aidl_os << ", name: " << ::android::internal::ToString(name);
    _aidl_os << ", zoneId: " << ::android::internal::ToString(zoneId);
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
[[nodiscard]] static inline std::string toString(AudioHalProductStrategy::ZoneId val) {
  switch(val) {
  case AudioHalProductStrategy::ZoneId::DEFAULT:
    return "DEFAULT";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioHalProductStrategy::ZoneId, 1> enum_values<aidl::android::media::audio::common::AudioHalProductStrategy::ZoneId> = {
  aidl::android::media::audio::common::AudioHalProductStrategy::ZoneId::DEFAULT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
