/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/MetadataLtv.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/MetadataLtv.aidl
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
#include <aidl/android/hardware/bluetooth/audio/AudioContext.h>
#include <aidl/android/hardware/bluetooth/audio/MetadataLtv.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::bluetooth::audio {
class AudioContext;
}  // namespace aidl::android::hardware::bluetooth::audio
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class MetadataLtv {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class PreferredAudioContexts {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::bluetooth::audio::AudioContext values;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const PreferredAudioContexts& _rhs) const {
      return std::tie(values) == std::tie(_rhs.values);
    }
    inline bool operator<(const PreferredAudioContexts& _rhs) const {
      return std::tie(values) < std::tie(_rhs.values);
    }
    inline bool operator!=(const PreferredAudioContexts& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const PreferredAudioContexts& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const PreferredAudioContexts& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const PreferredAudioContexts& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "PreferredAudioContexts{";
      _aidl_os << "values: " << ::android::internal::ToString(values);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class StreamingAudioContexts {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::bluetooth::audio::AudioContext values;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const StreamingAudioContexts& _rhs) const {
      return std::tie(values) == std::tie(_rhs.values);
    }
    inline bool operator<(const StreamingAudioContexts& _rhs) const {
      return std::tie(values) < std::tie(_rhs.values);
    }
    inline bool operator!=(const StreamingAudioContexts& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const StreamingAudioContexts& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const StreamingAudioContexts& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const StreamingAudioContexts& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "StreamingAudioContexts{";
      _aidl_os << "values: " << ::android::internal::ToString(values);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class VendorSpecific {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t companyId = 0;
    std::vector<uint8_t> opaqueValue;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const VendorSpecific& _rhs) const {
      return std::tie(companyId, opaqueValue) == std::tie(_rhs.companyId, _rhs.opaqueValue);
    }
    inline bool operator<(const VendorSpecific& _rhs) const {
      return std::tie(companyId, opaqueValue) < std::tie(_rhs.companyId, _rhs.opaqueValue);
    }
    inline bool operator!=(const VendorSpecific& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const VendorSpecific& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const VendorSpecific& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const VendorSpecific& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "VendorSpecific{";
      _aidl_os << "companyId: " << ::android::internal::ToString(companyId);
      _aidl_os << ", opaqueValue: " << ::android::internal::ToString(opaqueValue);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Tag : int32_t {
    preferredAudioContexts = 0,
    streamingAudioContexts = 1,
    vendorSpecific = 2,
  };

  // Expose tag symbols for legacy code
  static const inline Tag preferredAudioContexts = Tag::preferredAudioContexts;
  static const inline Tag streamingAudioContexts = Tag::streamingAudioContexts;
  static const inline Tag vendorSpecific = Tag::vendorSpecific;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, MetadataLtv>;

  MetadataLtv() : _value(std::in_place_index<static_cast<size_t>(preferredAudioContexts)>, ::aidl::android::hardware::bluetooth::audio::MetadataLtv::PreferredAudioContexts()) { }

  template <typename _Tp, typename = std::enable_if_t<
      _not_self<_Tp> &&
      std::is_constructible_v<std::variant<::aidl::android::hardware::bluetooth::audio::MetadataLtv::PreferredAudioContexts, ::aidl::android::hardware::bluetooth::audio::MetadataLtv::StreamingAudioContexts, ::aidl::android::hardware::bluetooth::audio::MetadataLtv::VendorSpecific>, _Tp>
    >>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr MetadataLtv(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit MetadataLtv(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static MetadataLtv make(_Tp&&... _args) {
    return MetadataLtv(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static MetadataLtv make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return MetadataLtv(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const MetadataLtv& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const MetadataLtv& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const MetadataLtv& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const MetadataLtv& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const MetadataLtv& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const MetadataLtv& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "MetadataLtv{";
    switch (getTag()) {
    case preferredAudioContexts: os << "preferredAudioContexts: " << ::android::internal::ToString(get<preferredAudioContexts>()); break;
    case streamingAudioContexts: os << "streamingAudioContexts: " << ::android::internal::ToString(get<streamingAudioContexts>()); break;
    case vendorSpecific: os << "vendorSpecific: " << ::android::internal::ToString(get<vendorSpecific>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::bluetooth::audio::MetadataLtv::PreferredAudioContexts, ::aidl::android::hardware::bluetooth::audio::MetadataLtv::StreamingAudioContexts, ::aidl::android::hardware::bluetooth::audio::MetadataLtv::VendorSpecific> _value;
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
[[nodiscard]] static inline std::string toString(MetadataLtv::Tag val) {
  switch(val) {
  case MetadataLtv::Tag::preferredAudioContexts:
    return "preferredAudioContexts";
  case MetadataLtv::Tag::streamingAudioContexts:
    return "streamingAudioContexts";
  case MetadataLtv::Tag::vendorSpecific:
    return "vendorSpecific";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::MetadataLtv::Tag, 3> enum_values<aidl::android::hardware::bluetooth::audio::MetadataLtv::Tag> = {
  aidl::android::hardware::bluetooth::audio::MetadataLtv::Tag::preferredAudioContexts,
  aidl::android::hardware::bluetooth::audio::MetadataLtv::Tag::streamingAudioContexts,
  aidl::android::hardware::bluetooth::audio::MetadataLtv::Tag::vendorSpecific,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
