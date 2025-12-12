/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/CodecConfiguration.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/CodecConfiguration.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/bluetooth/audio/AacConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/AptxAdaptiveConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/AptxConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/CodecConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/CodecType.h>
#include <aidl/android/hardware/bluetooth/audio/Lc3Configuration.h>
#include <aidl/android/hardware/bluetooth/audio/LdacConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/OpusConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/SbcConfiguration.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::bluetooth::audio {
class AacConfiguration;
class AptxAdaptiveConfiguration;
class AptxConfiguration;
class Lc3Configuration;
class LdacConfiguration;
class OpusConfiguration;
class SbcConfiguration;
}  // namespace aidl::android::hardware::bluetooth::audio
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class CodecConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class VendorConfiguration {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t vendorId = 0;
    char16_t codecId = '\0';
    ::ndk::AParcelableHolder codecConfig{::ndk::STABILITY_VINTF};

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VendorConfiguration& _rhs) const {
      return std::tie(vendorId, codecId, codecConfig) == std::tie(_rhs.vendorId, _rhs.codecId, _rhs.codecConfig);
    }
    inline bool operator<(const VendorConfiguration& _rhs) const {
      return std::tie(vendorId, codecId, codecConfig) < std::tie(_rhs.vendorId, _rhs.codecId, _rhs.codecConfig);
    }
    inline bool operator!=(const VendorConfiguration& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VendorConfiguration& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VendorConfiguration& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VendorConfiguration& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VendorConfiguration{";
      _aidl_os << "vendorId: " << ::android::internal::ToString(vendorId);
      _aidl_os << ", codecId: " << ::android::internal::ToString(codecId);
      _aidl_os << ", codecConfig: " << ::android::internal::ToString(codecConfig);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class CodecSpecific {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      sbcConfig = 0,
      aacConfig = 1,
      ldacConfig = 2,
      aptxConfig = 3,
      aptxAdaptiveConfig = 4,
      lc3Config = 5,
      vendorConfig = 6,
      opusConfig = 7,
    };

    // Expose tag symbols for legacy code
    static const inline Tag sbcConfig = Tag::sbcConfig;
    static const inline Tag aacConfig = Tag::aacConfig;
    static const inline Tag ldacConfig = Tag::ldacConfig;
    static const inline Tag aptxConfig = Tag::aptxConfig;
    static const inline Tag aptxAdaptiveConfig = Tag::aptxAdaptiveConfig;
    static const inline Tag lc3Config = Tag::lc3Config;
    static const inline Tag vendorConfig = Tag::vendorConfig;
    static const inline Tag opusConfig = Tag::opusConfig;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, CodecSpecific>;

    CodecSpecific() : _value(std::in_place_index<static_cast<size_t>(sbcConfig)>, ::aidl::android::hardware::bluetooth::audio::SbcConfiguration()) { }

    template <typename _Tp, typename = std::enable_if_t<
        _not_self<_Tp> &&
        std::is_constructible_v<std::variant<::aidl::android::hardware::bluetooth::audio::SbcConfiguration, ::aidl::android::hardware::bluetooth::audio::AacConfiguration, ::aidl::android::hardware::bluetooth::audio::LdacConfiguration, ::aidl::android::hardware::bluetooth::audio::AptxConfiguration, ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveConfiguration, ::aidl::android::hardware::bluetooth::audio::Lc3Configuration, ::aidl::android::hardware::bluetooth::audio::CodecConfiguration::VendorConfiguration, std::optional<::aidl::android::hardware::bluetooth::audio::OpusConfiguration>>, _Tp>
      >>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr CodecSpecific(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit CodecSpecific(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static CodecSpecific make(_Tp&&... _args) {
      return CodecSpecific(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static CodecSpecific make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return CodecSpecific(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
    }

    Tag getTag() const {
      return static_cast<Tag>(_value.index());
    }

    template <Tag _tag>
    const auto& get() const {
      if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
      return std::get<static_cast<size_t>(_tag)>(_value);
    }

    template <Tag _tag>
    auto& get() {
      if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
      return std::get<static_cast<size_t>(_tag)>(_value);
    }

    template <Tag _tag, typename... _Tp>
    void set(_Tp&&... _args) {
      _value.emplace<static_cast<size_t>(_tag)>(std::forward<_Tp>(_args)...);
    }

    binder_status_t readFromParcel(const AParcel* _parcel);
    binder_status_t writeToParcel(AParcel* _parcel) const;

    inline bool operator==(const CodecSpecific& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const CodecSpecific& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const CodecSpecific& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const CodecSpecific& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const CodecSpecific& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const CodecSpecific& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "CodecSpecific{";
      switch (getTag()) {
      case sbcConfig: os << "sbcConfig: " << ::android::internal::ToString(get<sbcConfig>()); break;
      case aacConfig: os << "aacConfig: " << ::android::internal::ToString(get<aacConfig>()); break;
      case ldacConfig: os << "ldacConfig: " << ::android::internal::ToString(get<ldacConfig>()); break;
      case aptxConfig: os << "aptxConfig: " << ::android::internal::ToString(get<aptxConfig>()); break;
      case aptxAdaptiveConfig: os << "aptxAdaptiveConfig: " << ::android::internal::ToString(get<aptxAdaptiveConfig>()); break;
      case lc3Config: os << "lc3Config: " << ::android::internal::ToString(get<lc3Config>()); break;
      case vendorConfig: os << "vendorConfig: " << ::android::internal::ToString(get<vendorConfig>()); break;
      case opusConfig: os << "opusConfig: " << ::android::internal::ToString(get<opusConfig>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::bluetooth::audio::SbcConfiguration, ::aidl::android::hardware::bluetooth::audio::AacConfiguration, ::aidl::android::hardware::bluetooth::audio::LdacConfiguration, ::aidl::android::hardware::bluetooth::audio::AptxConfiguration, ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveConfiguration, ::aidl::android::hardware::bluetooth::audio::Lc3Configuration, ::aidl::android::hardware::bluetooth::audio::CodecConfiguration::VendorConfiguration, std::optional<::aidl::android::hardware::bluetooth::audio::OpusConfiguration>> _value;
  };
  ::aidl::android::hardware::bluetooth::audio::CodecType codecType = ::aidl::android::hardware::bluetooth::audio::CodecType(0);
  int32_t encodedAudioBitrate = 0;
  int32_t peerMtu = 0;
  bool isScmstEnabled = false;
  ::aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific config;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const CodecConfiguration& _rhs) const {
    return std::tie(codecType, encodedAudioBitrate, peerMtu, isScmstEnabled, config) == std::tie(_rhs.codecType, _rhs.encodedAudioBitrate, _rhs.peerMtu, _rhs.isScmstEnabled, _rhs.config);
  }
  inline bool operator<(const CodecConfiguration& _rhs) const {
    return std::tie(codecType, encodedAudioBitrate, peerMtu, isScmstEnabled, config) < std::tie(_rhs.codecType, _rhs.encodedAudioBitrate, _rhs.peerMtu, _rhs.isScmstEnabled, _rhs.config);
  }
  inline bool operator!=(const CodecConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const CodecConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const CodecConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const CodecConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "CodecConfiguration{";
    _aidl_os << "codecType: " << ::android::internal::ToString(codecType);
    _aidl_os << ", encodedAudioBitrate: " << ::android::internal::ToString(encodedAudioBitrate);
    _aidl_os << ", peerMtu: " << ::android::internal::ToString(peerMtu);
    _aidl_os << ", isScmstEnabled: " << ::android::internal::ToString(isScmstEnabled);
    _aidl_os << ", config: " << ::android::internal::ToString(config);
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
[[nodiscard]] static inline std::string toString(CodecConfiguration::CodecSpecific::Tag val) {
  switch(val) {
  case CodecConfiguration::CodecSpecific::Tag::sbcConfig:
    return "sbcConfig";
  case CodecConfiguration::CodecSpecific::Tag::aacConfig:
    return "aacConfig";
  case CodecConfiguration::CodecSpecific::Tag::ldacConfig:
    return "ldacConfig";
  case CodecConfiguration::CodecSpecific::Tag::aptxConfig:
    return "aptxConfig";
  case CodecConfiguration::CodecSpecific::Tag::aptxAdaptiveConfig:
    return "aptxAdaptiveConfig";
  case CodecConfiguration::CodecSpecific::Tag::lc3Config:
    return "lc3Config";
  case CodecConfiguration::CodecSpecific::Tag::vendorConfig:
    return "vendorConfig";
  case CodecConfiguration::CodecSpecific::Tag::opusConfig:
    return "opusConfig";
  default:
    return std::to_string(static_cast<int32_t>(val));
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag, 8> enum_values<aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag> = {
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::sbcConfig,
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::aacConfig,
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::ldacConfig,
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::aptxConfig,
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::aptxAdaptiveConfig,
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::lc3Config,
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::vendorConfig,
  aidl::android::hardware::bluetooth::audio::CodecConfiguration::CodecSpecific::Tag::opusConfig,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
