/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/CodecSpecificConfigurationLtv.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/CodecSpecificConfigurationLtv.aidl
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
#include <aidl/android/hardware/bluetooth/audio/CodecSpecificConfigurationLtv.h>
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
class CodecSpecificConfigurationLtv {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class SamplingFrequency : int8_t {
    HZ8000 = 1,
    HZ11025 = 2,
    HZ16000 = 3,
    HZ22050 = 4,
    HZ24000 = 5,
    HZ32000 = 6,
    HZ44100 = 7,
    HZ48000 = 8,
    HZ88200 = 9,
    HZ96000 = 10,
    HZ176400 = 11,
    HZ192000 = 12,
    HZ384000 = 13,
  };

  enum class FrameDuration : int8_t {
    US7500 = 0,
    US10000 = 1,
    US20000 = 2,
  };

  class AudioChannelAllocation {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t bitmask = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const AudioChannelAllocation& _rhs) const {
      return std::tie(bitmask) == std::tie(_rhs.bitmask);
    }
    inline bool operator<(const AudioChannelAllocation& _rhs) const {
      return std::tie(bitmask) < std::tie(_rhs.bitmask);
    }
    inline bool operator!=(const AudioChannelAllocation& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const AudioChannelAllocation& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const AudioChannelAllocation& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const AudioChannelAllocation& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int32_t { NOT_ALLOWED = 0 };
    enum : int32_t { FRONT_LEFT = 1 };
    enum : int32_t { FRONT_RIGHT = 2 };
    enum : int32_t { FRONT_CENTER = 4 };
    enum : int32_t { LOW_FREQUENCY_EFFECTS_1 = 8 };
    enum : int32_t { BACK_LEFT = 16 };
    enum : int32_t { BACK_RIGHT = 32 };
    enum : int32_t { FRONT_LEFT_OF_CENTER = 64 };
    enum : int32_t { FRONT_RIGHT_OF_CENTER = 128 };
    enum : int32_t { BACK_CENTER = 256 };
    enum : int32_t { LOW_FREQUENCY_EFFECTS_2 = 512 };
    enum : int32_t { SIDE_LEFT = 1024 };
    enum : int32_t { SIDE_RIGHT = 2048 };
    enum : int32_t { TOP_FRONT_LEFT = 4096 };
    enum : int32_t { TOP_FRONT_RIGHT = 8192 };
    enum : int32_t { TOP_FRONT_CENTER = 16384 };
    enum : int32_t { TOP_CENTER = 32768 };
    enum : int32_t { TOP_BACK_LEFT = 65536 };
    enum : int32_t { TOP_BACK_RIGHT = 131072 };
    enum : int32_t { TOP_SIDE_LEFT = 262144 };
    enum : int32_t { TOP_SIDE_RIGHT = 524288 };
    enum : int32_t { TOP_BACK_CENTER = 1048576 };
    enum : int32_t { BOTTOM_FRONT_CENTER = 2097152 };
    enum : int32_t { BOTTOM_FRONT_LEFT = 4194304 };
    enum : int32_t { BOTTOM_FRONT_RIGHT = 8388608 };
    enum : int32_t { FRONT_LEFT_WIDE = 16777216 };
    enum : int32_t { FRONT_RIGHT_WIDE = 33554432 };
    enum : int32_t { LEFT_SURROUND = 67108864 };
    enum : int32_t { RIGHT_SURROUND = 134217728 };
    enum : int32_t { MONO = 0 };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "AudioChannelAllocation{";
      _aidl_os << "bitmask: " << ::android::internal::ToString(bitmask);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class OctetsPerCodecFrame {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t value = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const OctetsPerCodecFrame& _rhs) const {
      return std::tie(value) == std::tie(_rhs.value);
    }
    inline bool operator<(const OctetsPerCodecFrame& _rhs) const {
      return std::tie(value) < std::tie(_rhs.value);
    }
    inline bool operator!=(const OctetsPerCodecFrame& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const OctetsPerCodecFrame& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const OctetsPerCodecFrame& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const OctetsPerCodecFrame& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "OctetsPerCodecFrame{";
      _aidl_os << "value: " << ::android::internal::ToString(value);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class CodecFrameBlocksPerSDU {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t value = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const CodecFrameBlocksPerSDU& _rhs) const {
      return std::tie(value) == std::tie(_rhs.value);
    }
    inline bool operator<(const CodecFrameBlocksPerSDU& _rhs) const {
      return std::tie(value) < std::tie(_rhs.value);
    }
    inline bool operator!=(const CodecFrameBlocksPerSDU& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const CodecFrameBlocksPerSDU& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const CodecFrameBlocksPerSDU& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const CodecFrameBlocksPerSDU& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "CodecFrameBlocksPerSDU{";
      _aidl_os << "value: " << ::android::internal::ToString(value);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Tag : int32_t {
    codecFrameBlocksPerSDU = 0,
    samplingFrequency = 1,
    frameDuration = 2,
    audioChannelAllocation = 3,
    octetsPerCodecFrame = 4,
  };

  // Expose tag symbols for legacy code
  static const inline Tag codecFrameBlocksPerSDU = Tag::codecFrameBlocksPerSDU;
  static const inline Tag samplingFrequency = Tag::samplingFrequency;
  static const inline Tag frameDuration = Tag::frameDuration;
  static const inline Tag audioChannelAllocation = Tag::audioChannelAllocation;
  static const inline Tag octetsPerCodecFrame = Tag::octetsPerCodecFrame;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, CodecSpecificConfigurationLtv>;

  CodecSpecificConfigurationLtv() : _value(std::in_place_index<static_cast<size_t>(codecFrameBlocksPerSDU)>, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::CodecFrameBlocksPerSDU()) { }

  template <typename _Tp, typename = std::enable_if_t<
      _not_self<_Tp> &&
      std::is_constructible_v<std::variant<::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::CodecFrameBlocksPerSDU, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::FrameDuration, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::AudioChannelAllocation, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::OctetsPerCodecFrame>, _Tp>
    >>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr CodecSpecificConfigurationLtv(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit CodecSpecificConfigurationLtv(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static CodecSpecificConfigurationLtv make(_Tp&&... _args) {
    return CodecSpecificConfigurationLtv(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static CodecSpecificConfigurationLtv make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return CodecSpecificConfigurationLtv(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const CodecSpecificConfigurationLtv& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const CodecSpecificConfigurationLtv& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const CodecSpecificConfigurationLtv& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const CodecSpecificConfigurationLtv& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const CodecSpecificConfigurationLtv& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const CodecSpecificConfigurationLtv& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "CodecSpecificConfigurationLtv{";
    switch (getTag()) {
    case codecFrameBlocksPerSDU: os << "codecFrameBlocksPerSDU: " << ::android::internal::ToString(get<codecFrameBlocksPerSDU>()); break;
    case samplingFrequency: os << "samplingFrequency: " << ::android::internal::ToString(get<samplingFrequency>()); break;
    case frameDuration: os << "frameDuration: " << ::android::internal::ToString(get<frameDuration>()); break;
    case audioChannelAllocation: os << "audioChannelAllocation: " << ::android::internal::ToString(get<audioChannelAllocation>()); break;
    case octetsPerCodecFrame: os << "octetsPerCodecFrame: " << ::android::internal::ToString(get<octetsPerCodecFrame>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::CodecFrameBlocksPerSDU, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::FrameDuration, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::AudioChannelAllocation, ::aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::OctetsPerCodecFrame> _value;
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
[[nodiscard]] static inline std::string toString(CodecSpecificConfigurationLtv::SamplingFrequency val) {
  switch(val) {
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ8000:
    return "HZ8000";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ11025:
    return "HZ11025";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ16000:
    return "HZ16000";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ22050:
    return "HZ22050";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ24000:
    return "HZ24000";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ32000:
    return "HZ32000";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ44100:
    return "HZ44100";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ48000:
    return "HZ48000";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ88200:
    return "HZ88200";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ96000:
    return "HZ96000";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ176400:
    return "HZ176400";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ192000:
    return "HZ192000";
  case CodecSpecificConfigurationLtv::SamplingFrequency::HZ384000:
    return "HZ384000";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency, 13> enum_values<aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency> = {
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ8000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ11025,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ16000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ22050,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ24000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ32000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ44100,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ48000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ88200,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ96000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ176400,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ192000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::SamplingFrequency::HZ384000,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(CodecSpecificConfigurationLtv::FrameDuration val) {
  switch(val) {
  case CodecSpecificConfigurationLtv::FrameDuration::US7500:
    return "US7500";
  case CodecSpecificConfigurationLtv::FrameDuration::US10000:
    return "US10000";
  case CodecSpecificConfigurationLtv::FrameDuration::US20000:
    return "US20000";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::FrameDuration, 3> enum_values<aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::FrameDuration> = {
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::FrameDuration::US7500,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::FrameDuration::US10000,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::FrameDuration::US20000,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(CodecSpecificConfigurationLtv::Tag val) {
  switch(val) {
  case CodecSpecificConfigurationLtv::Tag::codecFrameBlocksPerSDU:
    return "codecFrameBlocksPerSDU";
  case CodecSpecificConfigurationLtv::Tag::samplingFrequency:
    return "samplingFrequency";
  case CodecSpecificConfigurationLtv::Tag::frameDuration:
    return "frameDuration";
  case CodecSpecificConfigurationLtv::Tag::audioChannelAllocation:
    return "audioChannelAllocation";
  case CodecSpecificConfigurationLtv::Tag::octetsPerCodecFrame:
    return "octetsPerCodecFrame";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::Tag, 5> enum_values<aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::Tag> = {
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::Tag::codecFrameBlocksPerSDU,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::Tag::samplingFrequency,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::Tag::frameDuration,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::Tag::audioChannelAllocation,
  aidl::android::hardware::bluetooth::audio::CodecSpecificConfigurationLtv::Tag::octetsPerCodecFrame,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
