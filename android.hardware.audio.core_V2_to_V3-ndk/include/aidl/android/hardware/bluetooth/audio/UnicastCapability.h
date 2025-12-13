/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/UnicastCapability.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/UnicastCapability.aidl
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
#include <aidl/android/hardware/bluetooth/audio/AptxAdaptiveLeCapabilities.h>
#include <aidl/android/hardware/bluetooth/audio/AudioLocation.h>
#include <aidl/android/hardware/bluetooth/audio/CodecSpecificConfigurationLtv.h>
#include <aidl/android/hardware/bluetooth/audio/CodecType.h>
#include <aidl/android/hardware/bluetooth/audio/Lc3Capabilities.h>
#include <aidl/android/hardware/bluetooth/audio/OpusCapabilities.h>
#include <aidl/android/hardware/bluetooth/audio/UnicastCapability.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::bluetooth::audio {
class AptxAdaptiveLeCapabilities;
class Lc3Capabilities;
class OpusCapabilities;
}  // namespace aidl::android::hardware::bluetooth::audio
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class UnicastCapability {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class VendorCapabilities {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::ndk::AParcelableHolder extension{::ndk::STABILITY_VINTF};

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VendorCapabilities& _rhs) const {
      return std::tie(extension) == std::tie(_rhs.extension);
    }
    inline bool operator<(const VendorCapabilities& _rhs) const {
      return std::tie(extension) < std::tie(_rhs.extension);
    }
    inline bool operator!=(const VendorCapabilities& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VendorCapabilities& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VendorCapabilities& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VendorCapabilities& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VendorCapabilities{";
      _aidl_os << "extension: " << ::android::internal::ToString(extension);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioCodecCapabilities {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      lc3Capabilities = 0,
      vendorCapabillities = 1,
      aptxAdaptiveLeCapabilities = 2,
      opusCapabilities = 3,
    };

    // Expose tag symbols for legacy code
    static const inline Tag lc3Capabilities = Tag::lc3Capabilities;
    static const inline Tag vendorCapabillities = Tag::vendorCapabillities;
    static const inline Tag aptxAdaptiveLeCapabilities = Tag::aptxAdaptiveLeCapabilities;
    static const inline Tag opusCapabilities = Tag::opusCapabilities;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, LeAudioCodecCapabilities>;

    LeAudioCodecCapabilities() : _value(std::in_place_index<static_cast<size_t>(lc3Capabilities)>, ::aidl::android::hardware::bluetooth::audio::Lc3Capabilities()) { }

    template <typename _Tp, typename = std::enable_if_t<
        _not_self<_Tp> &&
        std::is_constructible_v<std::variant<::aidl::android::hardware::bluetooth::audio::Lc3Capabilities, ::aidl::android::hardware::bluetooth::audio::UnicastCapability::VendorCapabilities, ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveLeCapabilities, ::aidl::android::hardware::bluetooth::audio::OpusCapabilities>, _Tp>
      >>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr LeAudioCodecCapabilities(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit LeAudioCodecCapabilities(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static LeAudioCodecCapabilities make(_Tp&&... _args) {
      return LeAudioCodecCapabilities(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static LeAudioCodecCapabilities make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return LeAudioCodecCapabilities(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

    inline bool operator==(const LeAudioCodecCapabilities& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const LeAudioCodecCapabilities& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const LeAudioCodecCapabilities& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioCodecCapabilities& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioCodecCapabilities& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioCodecCapabilities& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "LeAudioCodecCapabilities{";
      switch (getTag()) {
      case lc3Capabilities: os << "lc3Capabilities: " << ::android::internal::ToString(get<lc3Capabilities>()); break;
      case vendorCapabillities: os << "vendorCapabillities: " << ::android::internal::ToString(get<vendorCapabillities>()); break;
      case aptxAdaptiveLeCapabilities: os << "aptxAdaptiveLeCapabilities: " << ::android::internal::ToString(get<aptxAdaptiveLeCapabilities>()); break;
      case opusCapabilities: os << "opusCapabilities: " << ::android::internal::ToString(get<opusCapabilities>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::bluetooth::audio::Lc3Capabilities, ::aidl::android::hardware::bluetooth::audio::UnicastCapability::VendorCapabilities, ::aidl::android::hardware::bluetooth::audio::AptxAdaptiveLeCapabilities, ::aidl::android::hardware::bluetooth::audio::OpusCapabilities> _value;
  };
  ::aidl::android::hardware::bluetooth::audio::CodecType codecType = ::aidl::android::hardware::bluetooth::audio::CodecType(0);
  ::aidl::android::hardware::bluetooth::audio::AudioLocation supportedChannel = ::aidl::android::hardware::bluetooth::audio::AudioLocation(0);
  int32_t deviceCount = 0;
  int32_t channelCountPerDevice = 0;
  ::aidl::android::hardware::bluetooth::audio::UnicastCapability::LeAudioCodecCapabilities leAudioCodecCapabilities;
  std::optional<::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::AudioChannelAllocation> audioLocation;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const UnicastCapability& _rhs) const {
    return std::tie(codecType, supportedChannel, deviceCount, channelCountPerDevice, leAudioCodecCapabilities, audioLocation) == std::tie(_rhs.codecType, _rhs.supportedChannel, _rhs.deviceCount, _rhs.channelCountPerDevice, _rhs.leAudioCodecCapabilities, _rhs.audioLocation);
  }
  inline bool operator<(const UnicastCapability& _rhs) const {
    return std::tie(codecType, supportedChannel, deviceCount, channelCountPerDevice, leAudioCodecCapabilities, audioLocation) < std::tie(_rhs.codecType, _rhs.supportedChannel, _rhs.deviceCount, _rhs.channelCountPerDevice, _rhs.leAudioCodecCapabilities, _rhs.audioLocation);
  }
  inline bool operator!=(const UnicastCapability& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const UnicastCapability& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const UnicastCapability& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const UnicastCapability& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "UnicastCapability{";
    _aidl_os << "codecType: " << ::android::internal::ToString(codecType);
    _aidl_os << ", supportedChannel: " << ::android::internal::ToString(supportedChannel);
    _aidl_os << ", deviceCount: " << ::android::internal::ToString(deviceCount);
    _aidl_os << ", channelCountPerDevice: " << ::android::internal::ToString(channelCountPerDevice);
    _aidl_os << ", leAudioCodecCapabilities: " << ::android::internal::ToString(leAudioCodecCapabilities);
    _aidl_os << ", audioLocation: " << ::android::internal::ToString(audioLocation);
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
[[nodiscard]] static inline std::string toString(UnicastCapability::LeAudioCodecCapabilities::Tag val) {
  switch(val) {
  case UnicastCapability::LeAudioCodecCapabilities::Tag::lc3Capabilities:
    return "lc3Capabilities";
  case UnicastCapability::LeAudioCodecCapabilities::Tag::vendorCapabillities:
    return "vendorCapabillities";
  case UnicastCapability::LeAudioCodecCapabilities::Tag::aptxAdaptiveLeCapabilities:
    return "aptxAdaptiveLeCapabilities";
  case UnicastCapability::LeAudioCodecCapabilities::Tag::opusCapabilities:
    return "opusCapabilities";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::UnicastCapability::LeAudioCodecCapabilities::Tag, 4> enum_values<aidl::android::hardware::bluetooth::audio::UnicastCapability::LeAudioCodecCapabilities::Tag> = {
  aidl::android::hardware::bluetooth::audio::UnicastCapability::LeAudioCodecCapabilities::Tag::lc3Capabilities,
  aidl::android::hardware::bluetooth::audio::UnicastCapability::LeAudioCodecCapabilities::Tag::vendorCapabillities,
  aidl::android::hardware::bluetooth::audio::UnicastCapability::LeAudioCodecCapabilities::Tag::aptxAdaptiveLeCapabilities,
  aidl::android::hardware::bluetooth::audio::UnicastCapability::LeAudioCodecCapabilities::Tag::opusCapabilities,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
