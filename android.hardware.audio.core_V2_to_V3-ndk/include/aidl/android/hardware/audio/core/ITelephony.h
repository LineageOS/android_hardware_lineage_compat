/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/ITelephony.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/ITelephony.aidl
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
#include <aidl/android/hardware/audio/core/ITelephony.h>
#include <aidl/android/media/audio/common/AudioMode.h>
#include <aidl/android/media/audio/common/Boolean.h>
#include <aidl/android/media/audio/common/Float.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class Boolean;
class Float;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class ITelephonyDelegator;

class ITelephony : public ::ndk::ICInterface {
public:
  typedef ITelephonyDelegator DefaultDelegator;
  static const char* descriptor;
  ITelephony();
  virtual ~ITelephony();

  class TelecomConfig {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class TtyMode : int32_t {
      UNSPECIFIED = -1,
      OFF = 0,
      FULL = 1,
      HCO = 2,
      VCO = 3,
    };

    std::optional<::aidl::android::media::audio::common::Float> voiceVolume;
    ::aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode ttyMode = ::aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode::UNSPECIFIED;
    std::optional<::aidl::android::media::audio::common::Boolean> isHacEnabled;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const TelecomConfig& _rhs) const {
      return std::tie(voiceVolume, ttyMode, isHacEnabled) == std::tie(_rhs.voiceVolume, _rhs.ttyMode, _rhs.isHacEnabled);
    }
    inline bool operator<(const TelecomConfig& _rhs) const {
      return std::tie(voiceVolume, ttyMode, isHacEnabled) < std::tie(_rhs.voiceVolume, _rhs.ttyMode, _rhs.isHacEnabled);
    }
    inline bool operator!=(const TelecomConfig& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const TelecomConfig& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const TelecomConfig& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const TelecomConfig& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int32_t { VOICE_VOLUME_MIN = 0 };
    enum : int32_t { VOICE_VOLUME_MAX = 1 };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "TelecomConfig{";
      _aidl_os << "voiceVolume: " << ::android::internal::ToString(voiceVolume);
      _aidl_os << ", ttyMode: " << ::android::internal::ToString(ttyMode);
      _aidl_os << ", isHacEnabled: " << ::android::internal::ToString(isHacEnabled);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  static inline const int32_t version = 3;
  static inline const std::string hash = "eb5f1f5af402830af56b50eb66bdd60fd8cc774e";
  static constexpr uint32_t TRANSACTION_getSupportedAudioModes = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_switchAudioMode = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_setTelecomConfig = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<ITelephony> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITelephony>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITelephony>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ITelephony>& impl);
  static const std::shared_ptr<ITelephony>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getSupportedAudioModes(std::vector<::aidl::android::media::audio::common::AudioMode>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus switchAudioMode(::aidl::android::media::audio::common::AudioMode in_mode) = 0;
  virtual ::ndk::ScopedAStatus setTelecomConfig(const ::aidl::android::hardware::audio::core::ITelephony::TelecomConfig& in_config, ::aidl::android::hardware::audio::core::ITelephony::TelecomConfig* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<ITelephony> default_impl;
};
class ITelephonyDefault : public ITelephony {
public:
  ::ndk::ScopedAStatus getSupportedAudioModes(std::vector<::aidl::android::media::audio::common::AudioMode>* _aidl_return) override;
  ::ndk::ScopedAStatus switchAudioMode(::aidl::android::media::audio::common::AudioMode in_mode) override;
  ::ndk::ScopedAStatus setTelecomConfig(const ::aidl::android::hardware::audio::core::ITelephony::TelecomConfig& in_config, ::aidl::android::hardware::audio::core::ITelephony::TelecomConfig* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
[[nodiscard]] static inline std::string toString(ITelephony::TelecomConfig::TtyMode val) {
  switch(val) {
  case ITelephony::TelecomConfig::TtyMode::UNSPECIFIED:
    return "UNSPECIFIED";
  case ITelephony::TelecomConfig::TtyMode::OFF:
    return "OFF";
  case ITelephony::TelecomConfig::TtyMode::FULL:
    return "FULL";
  case ITelephony::TelecomConfig::TtyMode::HCO:
    return "HCO";
  case ITelephony::TelecomConfig::TtyMode::VCO:
    return "VCO";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode, 5> enum_values<aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode> = {
  aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode::UNSPECIFIED,
  aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode::OFF,
  aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode::FULL,
  aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode::HCO,
  aidl::android::hardware::audio::core::ITelephony::TelecomConfig::TtyMode::VCO,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
