/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/CodecId.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/CodecId.aidl
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
#include <aidl/android/hardware/bluetooth/audio/CodecId.h>
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
class CodecId {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum class A2dp : int8_t {
    SBC = 0,
    AAC = 2,
  };

  enum class Core : int8_t {
    CVSD = 2,
    MSBC = 5,
    LC3 = 6,
  };

  class Vendor {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t id = 0;
    int32_t codecId = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Vendor& _rhs) const {
      return std::tie(id, codecId) == std::tie(_rhs.id, _rhs.codecId);
    }
    inline bool operator<(const Vendor& _rhs) const {
      return std::tie(id, codecId) < std::tie(_rhs.id, _rhs.codecId);
    }
    inline bool operator!=(const Vendor& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Vendor& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Vendor& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Vendor& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Vendor{";
      _aidl_os << "id: " << ::android::internal::ToString(id);
      _aidl_os << ", codecId: " << ::android::internal::ToString(codecId);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Tag : int32_t {
    a2dp = 0,
    core = 1,
    vendor = 2,
  };

  // Expose tag symbols for legacy code
  static const inline Tag a2dp = Tag::a2dp;
  static const inline Tag core = Tag::core;
  static const inline Tag vendor = Tag::vendor;

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, CodecId>;

  CodecId() : _value(std::in_place_index<static_cast<size_t>(a2dp)>, ::aidl::android::hardware::bluetooth::audio::CodecId::A2dp(::aidl::android::hardware::bluetooth::audio::CodecId::A2dp::SBC)) { }

  template <typename _Tp, typename = std::enable_if_t<
      _not_self<_Tp> &&
      std::is_constructible_v<std::variant<::aidl::android::hardware::bluetooth::audio::CodecId::A2dp, ::aidl::android::hardware::bluetooth::audio::CodecId::Core, ::aidl::android::hardware::bluetooth::audio::CodecId::Vendor>, _Tp>
    >>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr CodecId(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit CodecId(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static CodecId make(_Tp&&... _args) {
    return CodecId(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static CodecId make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return CodecId(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

  inline bool operator==(const CodecId& _rhs) const {
    return _value == _rhs._value;
  }
  inline bool operator<(const CodecId& _rhs) const {
    return _value < _rhs._value;
  }
  inline bool operator!=(const CodecId& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const CodecId& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const CodecId& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const CodecId& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "CodecId{";
    switch (getTag()) {
    case a2dp: os << "a2dp: " << ::android::internal::ToString(get<a2dp>()); break;
    case core: os << "core: " << ::android::internal::ToString(get<core>()); break;
    case vendor: os << "vendor: " << ::android::internal::ToString(get<vendor>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::bluetooth::audio::CodecId::A2dp, ::aidl::android::hardware::bluetooth::audio::CodecId::Core, ::aidl::android::hardware::bluetooth::audio::CodecId::Vendor> _value;
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
[[nodiscard]] static inline std::string toString(CodecId::A2dp val) {
  switch(val) {
  case CodecId::A2dp::SBC:
    return "SBC";
  case CodecId::A2dp::AAC:
    return "AAC";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecId::A2dp, 2> enum_values<aidl::android::hardware::bluetooth::audio::CodecId::A2dp> = {
  aidl::android::hardware::bluetooth::audio::CodecId::A2dp::SBC,
  aidl::android::hardware::bluetooth::audio::CodecId::A2dp::AAC,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(CodecId::Core val) {
  switch(val) {
  case CodecId::Core::CVSD:
    return "CVSD";
  case CodecId::Core::MSBC:
    return "MSBC";
  case CodecId::Core::LC3:
    return "LC3";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecId::Core, 3> enum_values<aidl::android::hardware::bluetooth::audio::CodecId::Core> = {
  aidl::android::hardware::bluetooth::audio::CodecId::Core::CVSD,
  aidl::android::hardware::bluetooth::audio::CodecId::Core::MSBC,
  aidl::android::hardware::bluetooth::audio::CodecId::Core::LC3,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(CodecId::Tag val) {
  switch(val) {
  case CodecId::Tag::a2dp:
    return "a2dp";
  case CodecId::Tag::core:
    return "core";
  case CodecId::Tag::vendor:
    return "vendor";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecId::Tag, 3> enum_values<aidl::android::hardware::bluetooth::audio::CodecId::Tag> = {
  aidl::android::hardware::bluetooth::audio::CodecId::Tag::a2dp,
  aidl::android::hardware::bluetooth::audio::CodecId::Tag::core,
  aidl::android::hardware::bluetooth::audio::CodecId::Tag::vendor,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
