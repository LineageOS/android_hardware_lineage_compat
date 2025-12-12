/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioHalEngineConfig.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioHalEngineConfig.aidl
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
#include <aidl/android/media/audio/common/AudioHalCapCriterion.h>
#include <aidl/android/media/audio/common/AudioHalCapCriterionType.h>
#include <aidl/android/media/audio/common/AudioHalCapCriterionV2.h>
#include <aidl/android/media/audio/common/AudioHalCapDomain.h>
#include <aidl/android/media/audio/common/AudioHalEngineConfig.h>
#include <aidl/android/media/audio/common/AudioHalProductStrategy.h>
#include <aidl/android/media/audio/common/AudioHalVolumeGroup.h>
#include <aidl/android/media/audio/common/AudioProductStrategyType.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioHalCapCriterion;
class AudioHalCapCriterionType;
class AudioHalCapDomain;
class AudioHalProductStrategy;
class AudioHalVolumeGroup;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioHalEngineConfig {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class CapSpecificConfig {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::media::audio::common::AudioHalCapCriterion> criteria;
    std::vector<::aidl::android::media::audio::common::AudioHalCapCriterionType> criterionTypes;
    std::optional<std::vector<std::optional<::aidl::android::media::audio::common::AudioHalCapCriterionV2>>> criteriaV2;
    std::optional<std::vector<std::optional<::aidl::android::media::audio::common::AudioHalCapDomain>>> domains;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const CapSpecificConfig& _rhs) const {
      return std::tie(criteria, criterionTypes, criteriaV2, domains) == std::tie(_rhs.criteria, _rhs.criterionTypes, _rhs.criteriaV2, _rhs.domains);
    }
    inline bool operator<(const CapSpecificConfig& _rhs) const {
      return std::tie(criteria, criterionTypes, criteriaV2, domains) < std::tie(_rhs.criteria, _rhs.criterionTypes, _rhs.criteriaV2, _rhs.domains);
    }
    inline bool operator!=(const CapSpecificConfig& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const CapSpecificConfig& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const CapSpecificConfig& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const CapSpecificConfig& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "CapSpecificConfig{";
      _aidl_os << "criteria: " << ::android::internal::ToString(criteria);
      _aidl_os << ", criterionTypes: " << ::android::internal::ToString(criterionTypes);
      _aidl_os << ", criteriaV2: " << ::android::internal::ToString(criteriaV2);
      _aidl_os << ", domains: " << ::android::internal::ToString(domains);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  int32_t defaultProductStrategyId = -1;
  std::vector<::aidl::android::media::audio::common::AudioHalProductStrategy> productStrategies;
  std::vector<::aidl::android::media::audio::common::AudioHalVolumeGroup> volumeGroups;
  std::optional<::aidl::android::media::audio::common::AudioHalEngineConfig::CapSpecificConfig> capSpecificConfig;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioHalEngineConfig& _rhs) const {
    return std::tie(defaultProductStrategyId, productStrategies, volumeGroups, capSpecificConfig) == std::tie(_rhs.defaultProductStrategyId, _rhs.productStrategies, _rhs.volumeGroups, _rhs.capSpecificConfig);
  }
  inline bool operator<(const AudioHalEngineConfig& _rhs) const {
    return std::tie(defaultProductStrategyId, productStrategies, volumeGroups, capSpecificConfig) < std::tie(_rhs.defaultProductStrategyId, _rhs.productStrategies, _rhs.volumeGroups, _rhs.capSpecificConfig);
  }
  inline bool operator!=(const AudioHalEngineConfig& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioHalEngineConfig& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioHalEngineConfig& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioHalEngineConfig& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioHalEngineConfig{";
    _aidl_os << "defaultProductStrategyId: " << ::android::internal::ToString(defaultProductStrategyId);
    _aidl_os << ", productStrategies: " << ::android::internal::ToString(productStrategies);
    _aidl_os << ", volumeGroups: " << ::android::internal::ToString(volumeGroups);
    _aidl_os << ", capSpecificConfig: " << ::android::internal::ToString(capSpecificConfig);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
