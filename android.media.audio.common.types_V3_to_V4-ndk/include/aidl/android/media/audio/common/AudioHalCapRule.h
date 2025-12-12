/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioHalCapRule.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioHalCapRule.aidl
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
#include <aidl/android/media/audio/common/AudioHalCapCriterionV2.h>
#include <aidl/android/media/audio/common/AudioHalCapRule.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioHalCapRule;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioHalCapRule {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class CompoundRule : int8_t {
    INVALID = 0,
    ANY = 1,
    ALL = 2,
  };

  enum class MatchingRule : int8_t {
    INVALID = -1,
    IS = 0,
    IS_NOT = 1,
    INCLUDES = 2,
    EXCLUDES = 3,
  };

  class CriterionRule {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::media::audio::common::AudioHalCapRule::MatchingRule matchingRule = ::aidl::android::media::audio::common::AudioHalCapRule::MatchingRule::INVALID;
    ::aidl::android::media::audio::common::AudioHalCapCriterionV2 criterionAndValue;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const CriterionRule& _rhs) const {
      return std::tie(matchingRule, criterionAndValue) == std::tie(_rhs.matchingRule, _rhs.criterionAndValue);
    }
    inline bool operator<(const CriterionRule& _rhs) const {
      return std::tie(matchingRule, criterionAndValue) < std::tie(_rhs.matchingRule, _rhs.criterionAndValue);
    }
    inline bool operator!=(const CriterionRule& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const CriterionRule& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const CriterionRule& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const CriterionRule& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "CriterionRule{";
      _aidl_os << "matchingRule: " << ::android::internal::ToString(matchingRule);
      _aidl_os << ", criterionAndValue: " << ::android::internal::ToString(criterionAndValue);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  ::aidl::android::media::audio::common::AudioHalCapRule::CompoundRule compoundRule = ::aidl::android::media::audio::common::AudioHalCapRule::CompoundRule::INVALID;
  std::vector<::aidl::android::media::audio::common::AudioHalCapRule::CriterionRule> criterionRules;
  std::vector<::aidl::android::media::audio::common::AudioHalCapRule> nestedRules;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioHalCapRule& _rhs) const {
    return std::tie(compoundRule, criterionRules, nestedRules) == std::tie(_rhs.compoundRule, _rhs.criterionRules, _rhs.nestedRules);
  }
  inline bool operator<(const AudioHalCapRule& _rhs) const {
    return std::tie(compoundRule, criterionRules, nestedRules) < std::tie(_rhs.compoundRule, _rhs.criterionRules, _rhs.nestedRules);
  }
  inline bool operator!=(const AudioHalCapRule& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioHalCapRule& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioHalCapRule& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioHalCapRule& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioHalCapRule{";
    _aidl_os << "compoundRule: " << ::android::internal::ToString(compoundRule);
    _aidl_os << ", criterionRules: " << ::android::internal::ToString(criterionRules);
    _aidl_os << ", nestedRules: " << ::android::internal::ToString(nestedRules);
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
[[nodiscard]] static inline std::string toString(AudioHalCapRule::CompoundRule val) {
  switch(val) {
  case AudioHalCapRule::CompoundRule::INVALID:
    return "INVALID";
  case AudioHalCapRule::CompoundRule::ANY:
    return "ANY";
  case AudioHalCapRule::CompoundRule::ALL:
    return "ALL";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioHalCapRule::CompoundRule, 3> enum_values<aidl::android::media::audio::common::AudioHalCapRule::CompoundRule> = {
  aidl::android::media::audio::common::AudioHalCapRule::CompoundRule::INVALID,
  aidl::android::media::audio::common::AudioHalCapRule::CompoundRule::ANY,
  aidl::android::media::audio::common::AudioHalCapRule::CompoundRule::ALL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioHalCapRule::MatchingRule val) {
  switch(val) {
  case AudioHalCapRule::MatchingRule::INVALID:
    return "INVALID";
  case AudioHalCapRule::MatchingRule::IS:
    return "IS";
  case AudioHalCapRule::MatchingRule::IS_NOT:
    return "IS_NOT";
  case AudioHalCapRule::MatchingRule::INCLUDES:
    return "INCLUDES";
  case AudioHalCapRule::MatchingRule::EXCLUDES:
    return "EXCLUDES";
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
constexpr inline std::array<aidl::android::media::audio::common::AudioHalCapRule::MatchingRule, 5> enum_values<aidl::android::media::audio::common::AudioHalCapRule::MatchingRule> = {
  aidl::android::media::audio::common::AudioHalCapRule::MatchingRule::INVALID,
  aidl::android::media::audio::common::AudioHalCapRule::MatchingRule::IS,
  aidl::android::media::audio::common::AudioHalCapRule::MatchingRule::IS_NOT,
  aidl::android::media::audio::common::AudioHalCapRule::MatchingRule::INCLUDES,
  aidl::android::media::audio::common::AudioHalCapRule::MatchingRule::EXCLUDES,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
