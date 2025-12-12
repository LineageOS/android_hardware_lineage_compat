/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/LeAudioAseConfiguration.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/LeAudioAseConfiguration.aidl
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
#include <aidl/android/hardware/bluetooth/audio/CodecId.h>
#include <aidl/android/hardware/bluetooth/audio/CodecSpecificConfigurationLtv.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioAseConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/MetadataLtv.h>
#include <aidl/android/hardware/bluetooth/audio/Phy.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class LeAudioAseConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class TargetLatency : int8_t {
    UNDEFINED = 0,
    LOWER = 1,
    BALANCED_LATENCY_RELIABILITY = 2,
    HIGHER_RELIABILITY = 3,
  };

  ::aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency targetLatency = ::aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency(0);
  ::aidl::android::hardware::bluetooth::audio::Phy targetPhy = ::aidl::android::hardware::bluetooth::audio::Phy(0);
  std::optional<::aidl::android::hardware::bluetooth::audio::CodecId> codecId;
  std::vector<::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv> codecConfiguration;
  std::optional<std::vector<uint8_t>> vendorCodecConfiguration;
  std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>> metadata;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const LeAudioAseConfiguration& _rhs) const {
    return std::tie(targetLatency, targetPhy, codecId, codecConfiguration, vendorCodecConfiguration, metadata) == std::tie(_rhs.targetLatency, _rhs.targetPhy, _rhs.codecId, _rhs.codecConfiguration, _rhs.vendorCodecConfiguration, _rhs.metadata);
  }
  inline bool operator<(const LeAudioAseConfiguration& _rhs) const {
    return std::tie(targetLatency, targetPhy, codecId, codecConfiguration, vendorCodecConfiguration, metadata) < std::tie(_rhs.targetLatency, _rhs.targetPhy, _rhs.codecId, _rhs.codecConfiguration, _rhs.vendorCodecConfiguration, _rhs.metadata);
  }
  inline bool operator!=(const LeAudioAseConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const LeAudioAseConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const LeAudioAseConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const LeAudioAseConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "LeAudioAseConfiguration{";
    _aidl_os << "targetLatency: " << ::android::internal::ToString(targetLatency);
    _aidl_os << ", targetPhy: " << ::android::internal::ToString(targetPhy);
    _aidl_os << ", codecId: " << ::android::internal::ToString(codecId);
    _aidl_os << ", codecConfiguration: " << ::android::internal::ToString(codecConfiguration);
    _aidl_os << ", vendorCodecConfiguration: " << ::android::internal::ToString(vendorCodecConfiguration);
    _aidl_os << ", metadata: " << ::android::internal::ToString(metadata);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(LeAudioAseConfiguration::TargetLatency val) {
  switch(val) {
  case LeAudioAseConfiguration::TargetLatency::UNDEFINED:
    return "UNDEFINED";
  case LeAudioAseConfiguration::TargetLatency::LOWER:
    return "LOWER";
  case LeAudioAseConfiguration::TargetLatency::BALANCED_LATENCY_RELIABILITY:
    return "BALANCED_LATENCY_RELIABILITY";
  case LeAudioAseConfiguration::TargetLatency::HIGHER_RELIABILITY:
    return "HIGHER_RELIABILITY";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency, 4> enum_values<aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency> = {
  aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency::UNDEFINED,
  aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency::LOWER,
  aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency::BALANCED_LATENCY_RELIABILITY,
  aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration::TargetLatency::HIGHER_RELIABILITY,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
