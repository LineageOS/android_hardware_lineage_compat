/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IBluetooth.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IBluetooth.aidl
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
#include <aidl/android/hardware/audio/core/IBluetooth.h>
#include <aidl/android/media/audio/common/Boolean.h>
#include <aidl/android/media/audio/common/Float.h>
#include <aidl/android/media/audio/common/Int.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class Boolean;
class Float;
class Int;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class IBluetoothDelegator;

class IBluetooth : public ::ndk::ICInterface {
public:
  typedef IBluetoothDelegator DefaultDelegator;
  static const char* descriptor;
  IBluetooth();
  virtual ~IBluetooth();

  class ScoConfig {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Mode : int8_t {
      UNSPECIFIED = 0,
      SCO = 1,
      SCO_WB = 2,
      SCO_SWB = 3,
    };

    std::optional<::aidl::android::media::audio::common::Boolean> isEnabled;
    std::optional<::aidl::android::media::audio::common::Boolean> isNrecEnabled;
    ::aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode mode = ::aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode::UNSPECIFIED;
    std::optional<std::string> debugName;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const ScoConfig& _rhs) const {
      return std::tie(isEnabled, isNrecEnabled, mode, debugName) == std::tie(_rhs.isEnabled, _rhs.isNrecEnabled, _rhs.mode, _rhs.debugName);
    }
    inline bool operator<(const ScoConfig& _rhs) const {
      return std::tie(isEnabled, isNrecEnabled, mode, debugName) < std::tie(_rhs.isEnabled, _rhs.isNrecEnabled, _rhs.mode, _rhs.debugName);
    }
    inline bool operator!=(const ScoConfig& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const ScoConfig& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const ScoConfig& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const ScoConfig& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "ScoConfig{";
      _aidl_os << "isEnabled: " << ::android::internal::ToString(isEnabled);
      _aidl_os << ", isNrecEnabled: " << ::android::internal::ToString(isNrecEnabled);
      _aidl_os << ", mode: " << ::android::internal::ToString(mode);
      _aidl_os << ", debugName: " << ::android::internal::ToString(debugName);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class HfpConfig {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::optional<::aidl::android::media::audio::common::Boolean> isEnabled;
    std::optional<::aidl::android::media::audio::common::Int> sampleRate;
    std::optional<::aidl::android::media::audio::common::Float> volume;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const HfpConfig& _rhs) const {
      return std::tie(isEnabled, sampleRate, volume) == std::tie(_rhs.isEnabled, _rhs.sampleRate, _rhs.volume);
    }
    inline bool operator<(const HfpConfig& _rhs) const {
      return std::tie(isEnabled, sampleRate, volume) < std::tie(_rhs.isEnabled, _rhs.sampleRate, _rhs.volume);
    }
    inline bool operator!=(const HfpConfig& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const HfpConfig& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const HfpConfig& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const HfpConfig& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int32_t { VOLUME_MIN = 0 };
    enum : int32_t { VOLUME_MAX = 1 };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "HfpConfig{";
      _aidl_os << "isEnabled: " << ::android::internal::ToString(isEnabled);
      _aidl_os << ", sampleRate: " << ::android::internal::ToString(sampleRate);
      _aidl_os << ", volume: " << ::android::internal::ToString(volume);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  static inline const int32_t version = 3;
  static inline const std::string hash = "eb5f1f5af402830af56b50eb66bdd60fd8cc774e";
  static constexpr uint32_t TRANSACTION_setScoConfig = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_setHfpConfig = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<IBluetooth> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetooth>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetooth>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IBluetooth>& impl);
  static const std::shared_ptr<IBluetooth>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus setScoConfig(const ::aidl::android::hardware::audio::core::IBluetooth::ScoConfig& in_config, ::aidl::android::hardware::audio::core::IBluetooth::ScoConfig* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setHfpConfig(const ::aidl::android::hardware::audio::core::IBluetooth::HfpConfig& in_config, ::aidl::android::hardware::audio::core::IBluetooth::HfpConfig* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IBluetooth> default_impl;
};
class IBluetoothDefault : public IBluetooth {
public:
  ::ndk::ScopedAStatus setScoConfig(const ::aidl::android::hardware::audio::core::IBluetooth::ScoConfig& in_config, ::aidl::android::hardware::audio::core::IBluetooth::ScoConfig* _aidl_return) override;
  ::ndk::ScopedAStatus setHfpConfig(const ::aidl::android::hardware::audio::core::IBluetooth::HfpConfig& in_config, ::aidl::android::hardware::audio::core::IBluetooth::HfpConfig* _aidl_return) override;
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
[[nodiscard]] static inline std::string toString(IBluetooth::ScoConfig::Mode val) {
  switch(val) {
  case IBluetooth::ScoConfig::Mode::UNSPECIFIED:
    return "UNSPECIFIED";
  case IBluetooth::ScoConfig::Mode::SCO:
    return "SCO";
  case IBluetooth::ScoConfig::Mode::SCO_WB:
    return "SCO_WB";
  case IBluetooth::ScoConfig::Mode::SCO_SWB:
    return "SCO_SWB";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode, 4> enum_values<aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode> = {
  aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode::UNSPECIFIED,
  aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode::SCO,
  aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode::SCO_WB,
  aidl::android::hardware::audio::core::IBluetooth::ScoConfig::Mode::SCO_SWB,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
