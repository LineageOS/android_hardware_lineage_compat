/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/CodecInfo.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/CodecInfo.aidl
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
#include <aidl/android/hardware/bluetooth/audio/ChannelMode.h>
#include <aidl/android/hardware/bluetooth/audio/CodecId.h>
#include <aidl/android/hardware/bluetooth/audio/CodecInfo.h>
#include <aidl/android/hardware/bluetooth/audio/ConfigurationFlags.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::bluetooth::audio {
class ConfigurationFlags;
}  // namespace aidl::android::hardware::bluetooth::audio
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class CodecInfo {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class A2dp {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<uint8_t> capabilities;
    std::vector<::aidl::android::hardware::bluetooth::audio::ChannelMode> channelMode;
    std::vector<int32_t> samplingFrequencyHz;
    std::vector<int32_t> bitdepth;
    bool lossless = false;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const A2dp& _rhs) const {
      return std::tie(capabilities, channelMode, samplingFrequencyHz, bitdepth, lossless) == std::tie(_rhs.capabilities, _rhs.channelMode, _rhs.samplingFrequencyHz, _rhs.bitdepth, _rhs.lossless);
    }
    inline bool operator<(const A2dp& _rhs) const {
      return std::tie(capabilities, channelMode, samplingFrequencyHz, bitdepth, lossless) < std::tie(_rhs.capabilities, _rhs.channelMode, _rhs.samplingFrequencyHz, _rhs.bitdepth, _rhs.lossless);
    }
    inline bool operator!=(const A2dp& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const A2dp& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const A2dp& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const A2dp& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "A2dp{";
      _aidl_os << "capabilities: " << ::android::internal::ToString(capabilities);
      _aidl_os << ", channelMode: " << ::android::internal::ToString(channelMode);
      _aidl_os << ", samplingFrequencyHz: " << ::android::internal::ToString(samplingFrequencyHz);
      _aidl_os << ", bitdepth: " << ::android::internal::ToString(bitdepth);
      _aidl_os << ", lossless: " << ::android::internal::ToString(lossless);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class Hfp {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t inputDataPath = 1;
    int32_t outputDataPath = 1;
    bool useControllerCodec = true;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Hfp& _rhs) const {
      return std::tie(inputDataPath, outputDataPath, useControllerCodec) == std::tie(_rhs.inputDataPath, _rhs.outputDataPath, _rhs.useControllerCodec);
    }
    inline bool operator<(const Hfp& _rhs) const {
      return std::tie(inputDataPath, outputDataPath, useControllerCodec) < std::tie(_rhs.inputDataPath, _rhs.outputDataPath, _rhs.useControllerCodec);
    }
    inline bool operator!=(const Hfp& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Hfp& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Hfp& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Hfp& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Hfp{";
      _aidl_os << "inputDataPath: " << ::android::internal::ToString(inputDataPath);
      _aidl_os << ", outputDataPath: " << ::android::internal::ToString(outputDataPath);
      _aidl_os << ", useControllerCodec: " << ::android::internal::ToString(useControllerCodec);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudio {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::hardware::bluetooth::audio::ChannelMode> channelMode;
    std::vector<int32_t> samplingFrequencyHz;
    std::vector<int32_t> frameDurationUs;
    std::vector<int32_t> bitdepth;
    std::optional<::aidl::android::hardware::bluetooth::audio::ConfigurationFlags> flags;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudio& _rhs) const {
      return std::tie(channelMode, samplingFrequencyHz, frameDurationUs, bitdepth, flags) == std::tie(_rhs.channelMode, _rhs.samplingFrequencyHz, _rhs.frameDurationUs, _rhs.bitdepth, _rhs.flags);
    }
    inline bool operator<(const LeAudio& _rhs) const {
      return std::tie(channelMode, samplingFrequencyHz, frameDurationUs, bitdepth, flags) < std::tie(_rhs.channelMode, _rhs.samplingFrequencyHz, _rhs.frameDurationUs, _rhs.bitdepth, _rhs.flags);
    }
    inline bool operator!=(const LeAudio& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudio& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudio& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudio& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudio{";
      _aidl_os << "channelMode: " << ::android::internal::ToString(channelMode);
      _aidl_os << ", samplingFrequencyHz: " << ::android::internal::ToString(samplingFrequencyHz);
      _aidl_os << ", frameDurationUs: " << ::android::internal::ToString(frameDurationUs);
      _aidl_os << ", bitdepth: " << ::android::internal::ToString(bitdepth);
      _aidl_os << ", flags: " << ::android::internal::ToString(flags);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class Transport {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      leAudio = 0,
      a2dp = 1,
      hfp = 2,
    };

    // Expose tag symbols for legacy code
    static const inline Tag leAudio = Tag::leAudio;
    static const inline Tag a2dp = Tag::a2dp;
    static const inline Tag hfp = Tag::hfp;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, Transport>;

    Transport() : _value(std::in_place_index<static_cast<size_t>(leAudio)>, ::aidl::android::hardware::bluetooth::audio::CodecInfo::LeAudio()) { }

    template <typename _Tp, typename = std::enable_if_t<
        _not_self<_Tp> &&
        std::is_constructible_v<std::variant<::aidl::android::hardware::bluetooth::audio::CodecInfo::LeAudio, ::aidl::android::hardware::bluetooth::audio::CodecInfo::A2dp, ::aidl::android::hardware::bluetooth::audio::CodecInfo::Hfp>, _Tp>
      >>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr Transport(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit Transport(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static Transport make(_Tp&&... _args) {
      return Transport(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static Transport make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return Transport(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

    inline bool operator==(const Transport& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const Transport& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const Transport& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Transport& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Transport& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Transport& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "Transport{";
      switch (getTag()) {
      case leAudio: os << "leAudio: " << ::android::internal::ToString(get<leAudio>()); break;
      case a2dp: os << "a2dp: " << ::android::internal::ToString(get<a2dp>()); break;
      case hfp: os << "hfp: " << ::android::internal::ToString(get<hfp>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::bluetooth::audio::CodecInfo::LeAudio, ::aidl::android::hardware::bluetooth::audio::CodecInfo::A2dp, ::aidl::android::hardware::bluetooth::audio::CodecInfo::Hfp> _value;
  };
  ::aidl::android::hardware::bluetooth::audio::CodecId id;
  std::string name;
  ::aidl::android::hardware::bluetooth::audio::CodecInfo::Transport transport;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const CodecInfo& _rhs) const {
    return std::tie(id, name, transport) == std::tie(_rhs.id, _rhs.name, _rhs.transport);
  }
  inline bool operator<(const CodecInfo& _rhs) const {
    return std::tie(id, name, transport) < std::tie(_rhs.id, _rhs.name, _rhs.transport);
  }
  inline bool operator!=(const CodecInfo& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const CodecInfo& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const CodecInfo& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const CodecInfo& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "CodecInfo{";
    _aidl_os << "id: " << ::android::internal::ToString(id);
    _aidl_os << ", name: " << ::android::internal::ToString(name);
    _aidl_os << ", transport: " << ::android::internal::ToString(transport);
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
[[nodiscard]] static inline std::string toString(CodecInfo::Transport::Tag val) {
  switch(val) {
  case CodecInfo::Transport::Tag::leAudio:
    return "leAudio";
  case CodecInfo::Transport::Tag::a2dp:
    return "a2dp";
  case CodecInfo::Transport::Tag::hfp:
    return "hfp";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecInfo::Transport::Tag, 3> enum_values<aidl::android::hardware::bluetooth::audio::CodecInfo::Transport::Tag> = {
  aidl::android::hardware::bluetooth::audio::CodecInfo::Transport::Tag::leAudio,
  aidl::android::hardware::bluetooth::audio::CodecInfo::Transport::Tag::a2dp,
  aidl::android::hardware::bluetooth::audio::CodecInfo::Transport::Tag::hfp,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
