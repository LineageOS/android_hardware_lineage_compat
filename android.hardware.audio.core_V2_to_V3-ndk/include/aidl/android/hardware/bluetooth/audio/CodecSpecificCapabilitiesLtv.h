/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/CodecSpecificCapabilitiesLtv.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/CodecSpecificCapabilitiesLtv.aidl
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
#include <aidl/android/hardware/bluetooth/audio/CodecSpecificCapabilitiesLtv.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class CodecSpecificCapabilitiesLtv {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class SupportedSamplingFrequencies {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t bitmask = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SupportedSamplingFrequencies& _rhs) const {
      return std::tie(bitmask) == std::tie(_rhs.bitmask);
    }
    inline bool operator<(const SupportedSamplingFrequencies& _rhs) const {
      return std::tie(bitmask) < std::tie(_rhs.bitmask);
    }
    inline bool operator!=(const SupportedSamplingFrequencies& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SupportedSamplingFrequencies& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SupportedSamplingFrequencies& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SupportedSamplingFrequencies& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int32_t { HZ8000 = 1 };
    enum : int32_t { HZ11025 = 2 };
    enum : int32_t { HZ16000 = 4 };
    enum : int32_t { HZ22050 = 8 };
    enum : int32_t { HZ24000 = 16 };
    enum : int32_t { HZ32000 = 32 };
    enum : int32_t { HZ44100 = 64 };
    enum : int32_t { HZ48000 = 128 };
    enum : int32_t { HZ88200 = 256 };
    enum : int32_t { HZ96000 = 512 };
    enum : int32_t { HZ176400 = 1024 };
    enum : int32_t { HZ192000 = 2048 };
    enum : int32_t { HZ384000 = 4096 };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SupportedSamplingFrequencies{";
      _aidl_os << "bitmask: " << ::android::internal::ToString(bitmask);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class SupportedFrameDurations {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t bitmask = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SupportedFrameDurations& _rhs) const {
      return std::tie(bitmask) == std::tie(_rhs.bitmask);
    }
    inline bool operator<(const SupportedFrameDurations& _rhs) const {
      return std::tie(bitmask) < std::tie(_rhs.bitmask);
    }
    inline bool operator!=(const SupportedFrameDurations& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SupportedFrameDurations& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SupportedFrameDurations& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SupportedFrameDurations& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int32_t { US7500 = 1 };
    enum : int32_t { US10000 = 2 };
    enum : int32_t { US20000 = 4 };
    enum : int32_t { US7500PREFERRED = 16 };
    enum : int32_t { US10000PREFERRED = 32 };
    enum : int32_t { US20000PREFERRED = 64 };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SupportedFrameDurations{";
      _aidl_os << "bitmask: " << ::android::internal::ToString(bitmask);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class SupportedAudioChannelCounts {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t bitmask = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SupportedAudioChannelCounts& _rhs) const {
      return std::tie(bitmask) == std::tie(_rhs.bitmask);
    }
    inline bool operator<(const SupportedAudioChannelCounts& _rhs) const {
      return std::tie(bitmask) < std::tie(_rhs.bitmask);
    }
    inline bool operator!=(const SupportedAudioChannelCounts& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SupportedAudioChannelCounts& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SupportedAudioChannelCounts& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SupportedAudioChannelCounts& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int32_t { ONE = 1 };
    enum : int32_t { TWO = 2 };
    enum : int32_t { THREE = 4 };
    enum : int32_t { FOUR = 8 };
    enum : int32_t { FIVE = 16 };
    enum : int32_t { SIX = 32 };
    enum : int32_t { SEVEN = 64 };
    enum : int32_t { EIGHT = 128 };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SupportedAudioChannelCounts{";
      _aidl_os << "bitmask: " << ::android::internal::ToString(bitmask);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class SupportedOctetsPerCodecFrame {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t min = 0;
    int32_t max = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SupportedOctetsPerCodecFrame& _rhs) const {
      return std::tie(min, max) == std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator<(const SupportedOctetsPerCodecFrame& _rhs) const {
      return std::tie(min, max) < std::tie(_rhs.min, _rhs.max);
    }
    inline bool operator!=(const SupportedOctetsPerCodecFrame& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SupportedOctetsPerCodecFrame& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SupportedOctetsPerCodecFrame& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SupportedOctetsPerCodecFrame& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SupportedOctetsPerCodecFrame{";
      _aidl_os << "min: " << ::android::internal::ToString(min);
      _aidl_os << ", max: " << ::android::internal::ToString(max);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class SupportedMaxCodecFramesPerSDU {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t value = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SupportedMaxCodecFramesPerSDU& _rhs) const {
      return std::tie(value) == std::tie(_rhs.value);
    }
    inline bool operator<(const SupportedMaxCodecFramesPerSDU& _rhs) const {
      return std::tie(value) < std::tie(_rhs.value);
    }
    inline bool operator!=(const SupportedMaxCodecFramesPerSDU& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SupportedMaxCodecFramesPerSDU& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SupportedMaxCodecFramesPerSDU& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SupportedMaxCodecFramesPerSDU& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SupportedMaxCodecFramesPerSDU{";
      _aidl_os << "value: " << ::android::internal::ToString(value);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Tag : int32_t {
    supportedSamplingFrequencies = 0,
    supportedFrameDurations = 1,
    supportedAudioChannelCounts = 2,
    supportedOctetsPerCodecFrame = 3,
    supportedMaxCodecFramesPerSDU = 4,
  };

  // Expose tag symbols for legacy code
  static const inline Tag supportedSamplingFrequencies = Tag::supportedSamplingFrequencies;
  static const inline Tag supportedFrameDurations = Tag::supportedFrameDurations;
  static const inline Tag supportedAudioChannelCounts = Tag::supportedAudioChannelCounts;
  static const inline Tag supportedOctetsPerCodecFrame = Tag::supportedOctetsPerCodecFrame;
  static const inline Tag supportedMaxCodecFramesPerSDU = Tag::supportedMaxCodecFramesPerSDU;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, CodecSpecificCapabilitiesLtv>;

  CodecSpecificCapabilitiesLtv() : _value(std::in_place_index<static_cast<size_t>(supportedSamplingFrequencies)>, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedSamplingFrequencies()) { }

  template <typename _Tp, typename = std::enable_if_t<
      _not_self<_Tp> &&
      std::is_constructible_v<std::variant<::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedSamplingFrequencies, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedFrameDurations, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedAudioChannelCounts, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedOctetsPerCodecFrame, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedMaxCodecFramesPerSDU>, _Tp>
    >>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr CodecSpecificCapabilitiesLtv(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit CodecSpecificCapabilitiesLtv(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static CodecSpecificCapabilitiesLtv make(_Tp&&... _args) {
    return CodecSpecificCapabilitiesLtv(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static CodecSpecificCapabilitiesLtv make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return CodecSpecificCapabilitiesLtv(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const CodecSpecificCapabilitiesLtv& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const CodecSpecificCapabilitiesLtv& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const CodecSpecificCapabilitiesLtv& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const CodecSpecificCapabilitiesLtv& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const CodecSpecificCapabilitiesLtv& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const CodecSpecificCapabilitiesLtv& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "CodecSpecificCapabilitiesLtv{";
    switch (getTag()) {
    case supportedSamplingFrequencies: os << "supportedSamplingFrequencies: " << ::android::internal::ToString(get<supportedSamplingFrequencies>()); break;
    case supportedFrameDurations: os << "supportedFrameDurations: " << ::android::internal::ToString(get<supportedFrameDurations>()); break;
    case supportedAudioChannelCounts: os << "supportedAudioChannelCounts: " << ::android::internal::ToString(get<supportedAudioChannelCounts>()); break;
    case supportedOctetsPerCodecFrame: os << "supportedOctetsPerCodecFrame: " << ::android::internal::ToString(get<supportedOctetsPerCodecFrame>()); break;
    case supportedMaxCodecFramesPerSDU: os << "supportedMaxCodecFramesPerSDU: " << ::android::internal::ToString(get<supportedMaxCodecFramesPerSDU>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedSamplingFrequencies, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedFrameDurations, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedAudioChannelCounts, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedOctetsPerCodecFrame, ::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::SupportedMaxCodecFramesPerSDU> _value;
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
[[nodiscard]] static inline std::string toString(CodecSpecificCapabilitiesLtv::Tag val) {
  switch(val) {
  case CodecSpecificCapabilitiesLtv::Tag::supportedSamplingFrequencies:
    return "supportedSamplingFrequencies";
  case CodecSpecificCapabilitiesLtv::Tag::supportedFrameDurations:
    return "supportedFrameDurations";
  case CodecSpecificCapabilitiesLtv::Tag::supportedAudioChannelCounts:
    return "supportedAudioChannelCounts";
  case CodecSpecificCapabilitiesLtv::Tag::supportedOctetsPerCodecFrame:
    return "supportedOctetsPerCodecFrame";
  case CodecSpecificCapabilitiesLtv::Tag::supportedMaxCodecFramesPerSDU:
    return "supportedMaxCodecFramesPerSDU";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::Tag, 5> enum_values<aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::Tag> = {
  aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::Tag::supportedSamplingFrequencies,
  aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::Tag::supportedFrameDurations,
  aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::Tag::supportedAudioChannelCounts,
  aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::Tag::supportedOctetsPerCodecFrame,
  aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv::Tag::supportedMaxCodecFramesPerSDU,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
