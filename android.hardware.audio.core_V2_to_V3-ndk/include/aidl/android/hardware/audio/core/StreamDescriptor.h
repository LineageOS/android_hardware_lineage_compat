/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/StreamDescriptor.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/StreamDescriptor.aidl
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
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/audio/core/MmapBufferDescriptor.h>
#include <aidl/android/hardware/audio/core/StreamDescriptor.h>
#include <aidl/android/hardware/common/fmq/MQDescriptor.h>
#include <aidl/android/hardware/common/fmq/SynchronizedReadWrite.h>
#include <aidl/android/media/audio/common/Void.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl::android::hardware::audio::core {
class MmapBufferDescriptor;
}  // namespace aidl::android::hardware::audio::core
namespace aidl::android::hardware::common::fmq {
template <typename T, typename Flavor>
class MQDescriptor;
}  // namespace aidl::android::hardware::common::fmq
namespace aidl::android::media::audio::common {
class Void;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class StreamDescriptor {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class Position {
  public:
    typedef std::true_type fixed_size;
    static const char* descriptor;

    int64_t frames __attribute__((aligned (8))) = -1L;
    int64_t timeNs __attribute__((aligned (8))) = -1L;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Position& _rhs) const {
      return std::tie(frames, timeNs) == std::tie(_rhs.frames, _rhs.timeNs);
    }
    inline bool operator<(const Position& _rhs) const {
      return std::tie(frames, timeNs) < std::tie(_rhs.frames, _rhs.timeNs);
    }
    inline bool operator!=(const Position& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Position& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Position& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Position& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    enum : int64_t { UNKNOWN = -1L };
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Position{";
      _aidl_os << "frames: " << ::android::internal::ToString(frames);
      _aidl_os << ", timeNs: " << ::android::internal::ToString(timeNs);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  static_assert(offsetof(Position, frames) == 0);
  static_assert(sizeof(int64_t) == 8);
  static_assert(offsetof(Position, timeNs) == 8);
  static_assert(sizeof(int64_t) == 8);
  static_assert(alignof(Position) == 8);
  static_assert(sizeof(Position) == 16);
  enum class State : int32_t {
    STANDBY = 1,
    IDLE = 2,
    ACTIVE = 3,
    PAUSED = 4,
    DRAINING = 5,
    DRAIN_PAUSED = 6,
    TRANSFERRING = 7,
    TRANSFER_PAUSED = 8,
    ERROR = 100,
  };

  enum class DrainMode : int8_t {
    DRAIN_UNSPECIFIED = 0,
    DRAIN_ALL = 1,
    DRAIN_EARLY_NOTIFY = 2,
  };

  class Command {
  public:
    typedef std::true_type fixed_size;
    static const char* descriptor;

    enum class Tag : int8_t {
      halReservedExit = 0,
      getStatus = 1,
      start = 2,
      burst = 3,
      drain = 4,
      standby = 5,
      pause = 6,
      flush = 7,
    };

    // Expose tag symbols for legacy code
    static const inline Tag halReservedExit = Tag::halReservedExit;
    static const inline Tag getStatus = Tag::getStatus;
    static const inline Tag start = Tag::start;
    static const inline Tag burst = Tag::burst;
    static const inline Tag drain = Tag::drain;
    static const inline Tag standby = Tag::standby;
    static const inline Tag pause = Tag::pause;
    static const inline Tag flush = Tag::flush;

    template <Tag _Tag>
    using _at = typename std::tuple_element<static_cast<size_t>(_Tag), std::tuple<int32_t, ::aidl::android::media::audio::common::Void, ::aidl::android::media::audio::common::Void, int32_t, ::aidl::android::hardware::audio::core::StreamDescriptor::DrainMode, ::aidl::android::media::audio::common::Void, ::aidl::android::media::audio::common::Void, ::aidl::android::media::audio::common::Void>>::type;
    template <Tag _Tag, typename _Type>
    static Command make(_Type&& _arg) {
      Command _inst;
      _inst.set<_Tag>(std::forward<_Type>(_arg));
      return _inst;
    }
    constexpr Tag getTag() const {
      return _tag;
    }
    template <Tag _Tag>
    const _at<_Tag>& get() const {
      if (_Tag != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
      return *(_at<_Tag>*)(&_value);
    }
    template <Tag _Tag>
    _at<_Tag>& get() {
      if (_Tag != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
      return *(_at<_Tag>*)(&_value);
    }
    template <Tag _Tag, typename _Type>
    void set(_Type&& _arg) {
      _tag = _Tag;
      get<_Tag>() = std::forward<_Type>(_arg);
    }
    binder_status_t readFromParcel(const AParcel* _parcel);
    binder_status_t writeToParcel(AParcel* _parcel) const;

    static int _cmp(const Command& _lhs, const Command& _rhs) {
      return _cmp_value(_lhs.getTag(), _rhs.getTag()) || _cmp_value_at<flush>(_lhs, _rhs);
    }
    template <Tag _Tag>
    static int _cmp_value_at(const Command& _lhs, const Command& _rhs) {
      if constexpr (_Tag == halReservedExit) {
        return _cmp_value(_lhs.get<_Tag>(), _rhs.get<_Tag>());
      } else {
        return (_lhs.getTag() == _Tag)
          ? _cmp_value(_lhs.get<_Tag>(), _rhs.get<_Tag>())
          : _cmp_value_at<static_cast<Tag>(static_cast<size_t>(_Tag)-1)>(_lhs, _rhs);
      }
    }
    template <typename _Type>
    static int _cmp_value(const _Type& _lhs, const _Type& _rhs) {
      return (_lhs == _rhs) ? 0 : (_lhs < _rhs) ? -1 : 1;
    }
    inline bool operator!=(const Command&_rhs) const {
      return _cmp(*this, _rhs) != 0;
    }
    inline bool operator<(const Command&_rhs) const {
      return _cmp(*this, _rhs) < 0;
    }
    inline bool operator<=(const Command&_rhs) const {
      return _cmp(*this, _rhs) <= 0;
    }
    inline bool operator==(const Command&_rhs) const {
      return _cmp(*this, _rhs) == 0;
    }
    inline bool operator>(const Command&_rhs) const {
      return _cmp(*this, _rhs) > 0;
    }
    inline bool operator>=(const Command&_rhs) const {
      return _cmp(*this, _rhs) >= 0;
    }
    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "Command{";
      switch (getTag()) {
      case halReservedExit: os << "halReservedExit: " << ::android::internal::ToString(get<halReservedExit>()); break;
      case getStatus: os << "getStatus: " << ::android::internal::ToString(get<getStatus>()); break;
      case start: os << "start: " << ::android::internal::ToString(get<start>()); break;
      case burst: os << "burst: " << ::android::internal::ToString(get<burst>()); break;
      case drain: os << "drain: " << ::android::internal::ToString(get<drain>()); break;
      case standby: os << "standby: " << ::android::internal::ToString(get<standby>()); break;
      case pause: os << "pause: " << ::android::internal::ToString(get<pause>()); break;
      case flush: os << "flush: " << ::android::internal::ToString(get<flush>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    Tag _tag = halReservedExit;
    union _value_t {
      _value_t() {}
      ~_value_t() {}
      int32_t halReservedExit __attribute__((aligned (4))) = int32_t(0);
      ::aidl::android::media::audio::common::Void getStatus __attribute__((aligned (1)));
      ::aidl::android::media::audio::common::Void start __attribute__((aligned (1)));
      int32_t burst __attribute__((aligned (4)));
      ::aidl::android::hardware::audio::core::StreamDescriptor::DrainMode drain __attribute__((aligned (1)));
      ::aidl::android::media::audio::common::Void standby __attribute__((aligned (1)));
      ::aidl::android::media::audio::common::Void pause __attribute__((aligned (1)));
      ::aidl::android::media::audio::common::Void flush __attribute__((aligned (1)));
    } _value;
  };
  static_assert(sizeof(int32_t) == 4);
  static_assert(sizeof(::aidl::android::media::audio::common::Void) == 1);
  static_assert(sizeof(::aidl::android::media::audio::common::Void) == 1);
  static_assert(sizeof(int32_t) == 4);
  static_assert(sizeof(::aidl::android::hardware::audio::core::StreamDescriptor::DrainMode) == 1);
  static_assert(sizeof(::aidl::android::media::audio::common::Void) == 1);
  static_assert(sizeof(::aidl::android::media::audio::common::Void) == 1);
  static_assert(sizeof(::aidl::android::media::audio::common::Void) == 1);
  static_assert(alignof(Command) == 4);
  static_assert(sizeof(Command) == 8);
  class Reply {
  public:
    typedef std::true_type fixed_size;
    static const char* descriptor;

    int32_t status __attribute__((aligned (4))) = 0;
    int32_t fmqByteCount __attribute__((aligned (4))) = 0;
    ::aidl::android::hardware::audio::core::StreamDescriptor::Position observable __attribute__((aligned (8)));
    ::aidl::android::hardware::audio::core::StreamDescriptor::Position hardware __attribute__((aligned (8)));
    int32_t latencyMs __attribute__((aligned (4))) = 0;
    int32_t xrunFrames __attribute__((aligned (4))) = 0;
    ::aidl::android::hardware::audio::core::StreamDescriptor::State state __attribute__((aligned (4))) = ::aidl::android::hardware::audio::core::StreamDescriptor::State::STANDBY;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Reply& _rhs) const {
      return std::tie(status, fmqByteCount, observable, hardware, latencyMs, xrunFrames, state) == std::tie(_rhs.status, _rhs.fmqByteCount, _rhs.observable, _rhs.hardware, _rhs.latencyMs, _rhs.xrunFrames, _rhs.state);
    }
    inline bool operator<(const Reply& _rhs) const {
      return std::tie(status, fmqByteCount, observable, hardware, latencyMs, xrunFrames, state) < std::tie(_rhs.status, _rhs.fmqByteCount, _rhs.observable, _rhs.hardware, _rhs.latencyMs, _rhs.xrunFrames, _rhs.state);
    }
    inline bool operator!=(const Reply& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Reply& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Reply& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Reply& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Reply{";
      _aidl_os << "status: " << ::android::internal::ToString(status);
      _aidl_os << ", fmqByteCount: " << ::android::internal::ToString(fmqByteCount);
      _aidl_os << ", observable: " << ::android::internal::ToString(observable);
      _aidl_os << ", hardware: " << ::android::internal::ToString(hardware);
      _aidl_os << ", latencyMs: " << ::android::internal::ToString(latencyMs);
      _aidl_os << ", xrunFrames: " << ::android::internal::ToString(xrunFrames);
      _aidl_os << ", state: " << ::android::internal::ToString(state);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  static_assert(offsetof(Reply, status) == 0);
  static_assert(sizeof(int32_t) == 4);
  static_assert(offsetof(Reply, fmqByteCount) == 4);
  static_assert(sizeof(int32_t) == 4);
  static_assert(offsetof(Reply, observable) == 8);
  static_assert(sizeof(::aidl::android::hardware::audio::core::StreamDescriptor::Position) == 16);
  static_assert(offsetof(Reply, hardware) == 24);
  static_assert(sizeof(::aidl::android::hardware::audio::core::StreamDescriptor::Position) == 16);
  static_assert(offsetof(Reply, latencyMs) == 40);
  static_assert(sizeof(int32_t) == 4);
  static_assert(offsetof(Reply, xrunFrames) == 44);
  static_assert(sizeof(int32_t) == 4);
  static_assert(offsetof(Reply, state) == 48);
  static_assert(sizeof(::aidl::android::hardware::audio::core::StreamDescriptor::State) == 4);
  static_assert(alignof(Reply) == 8);
  static_assert(sizeof(Reply) == 56);
  class AudioBuffer {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    enum class Tag : int32_t {
      fmq = 0,
      mmap = 1,
    };

    // Expose tag symbols for legacy code
    static const inline Tag fmq = Tag::fmq;
    static const inline Tag mmap = Tag::mmap;

    template<typename _Tp>
    static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioBuffer>;

    AudioBuffer() : _value(std::in_place_index<static_cast<size_t>(fmq)>, ::aidl::android::hardware::common::fmq::MQDescriptor<int8_t, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>()) { }

    template <typename _Tp, typename = std::enable_if_t<
        _not_self<_Tp> &&
        std::is_constructible_v<std::variant<::aidl::android::hardware::common::fmq::MQDescriptor<int8_t, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>, ::aidl::android::hardware::audio::core::MmapBufferDescriptor>, _Tp>
      >>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr AudioBuffer(_Tp&& _arg)
        : _value(std::forward<_Tp>(_arg)) {}

    template <size_t _Np, typename... _Tp>
    constexpr explicit AudioBuffer(std::in_place_index_t<_Np>, _Tp&&... _args)
        : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

    template <Tag _tag, typename... _Tp>
    static AudioBuffer make(_Tp&&... _args) {
      return AudioBuffer(std::in_place_index<static_cast<size_t>(_tag)>, std::forward<_Tp>(_args)...);
    }

    template <Tag _tag, typename _Tp, typename... _Up>
    static AudioBuffer make(std::initializer_list<_Tp> _il, _Up&&... _args) {
      return AudioBuffer(std::in_place_index<static_cast<size_t>(_tag)>, std::move(_il), std::forward<_Up>(_args)...);
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

    inline bool operator==(const AudioBuffer& _rhs) const {
      return _value == _rhs._value;
    }
    inline bool operator<(const AudioBuffer& _rhs) const {
      return _value < _rhs._value;
    }
    inline bool operator!=(const AudioBuffer& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const AudioBuffer& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const AudioBuffer& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const AudioBuffer& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream os;
      os << "AudioBuffer{";
      switch (getTag()) {
      case fmq: os << "fmq: " << ::android::internal::ToString(get<fmq>()); break;
      case mmap: os << "mmap: " << ::android::internal::ToString(get<mmap>()); break;
      }
      os << "}";
      return os.str();
    }
  private:
    std::variant<::aidl::android::hardware::common::fmq::MQDescriptor<int8_t, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>, ::aidl::android::hardware::audio::core::MmapBufferDescriptor> _value;
  };
  ::aidl::android::hardware::common::fmq::MQDescriptor<::aidl::android::hardware::audio::core::StreamDescriptor::Command, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite> command;
  ::aidl::android::hardware::common::fmq::MQDescriptor<::aidl::android::hardware::audio::core::StreamDescriptor::Reply, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite> reply;
  int32_t frameSizeBytes = 0;
  int64_t bufferSizeFrames = 0L;
  ::aidl::android::hardware::audio::core::StreamDescriptor::AudioBuffer audio;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const StreamDescriptor& _rhs) const {
    return std::tie(command, reply, frameSizeBytes, bufferSizeFrames, audio) == std::tie(_rhs.command, _rhs.reply, _rhs.frameSizeBytes, _rhs.bufferSizeFrames, _rhs.audio);
  }
  inline bool operator<(const StreamDescriptor& _rhs) const {
    return std::tie(command, reply, frameSizeBytes, bufferSizeFrames, audio) < std::tie(_rhs.command, _rhs.reply, _rhs.frameSizeBytes, _rhs.bufferSizeFrames, _rhs.audio);
  }
  inline bool operator!=(const StreamDescriptor& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const StreamDescriptor& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const StreamDescriptor& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const StreamDescriptor& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  enum : int32_t { LATENCY_UNKNOWN = -1 };
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "StreamDescriptor{";
    _aidl_os << "command: " << ::android::internal::ToString(command);
    _aidl_os << ", reply: " << ::android::internal::ToString(reply);
    _aidl_os << ", frameSizeBytes: " << ::android::internal::ToString(frameSizeBytes);
    _aidl_os << ", bufferSizeFrames: " << ::android::internal::ToString(bufferSizeFrames);
    _aidl_os << ", audio: " << ::android::internal::ToString(audio);
    _aidl_os << "}";
    return _aidl_os.str();
  }
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
[[nodiscard]] static inline std::string toString(StreamDescriptor::State val) {
  switch(val) {
  case StreamDescriptor::State::STANDBY:
    return "STANDBY";
  case StreamDescriptor::State::IDLE:
    return "IDLE";
  case StreamDescriptor::State::ACTIVE:
    return "ACTIVE";
  case StreamDescriptor::State::PAUSED:
    return "PAUSED";
  case StreamDescriptor::State::DRAINING:
    return "DRAINING";
  case StreamDescriptor::State::DRAIN_PAUSED:
    return "DRAIN_PAUSED";
  case StreamDescriptor::State::TRANSFERRING:
    return "TRANSFERRING";
  case StreamDescriptor::State::TRANSFER_PAUSED:
    return "TRANSFER_PAUSED";
  case StreamDescriptor::State::ERROR:
    return "ERROR";
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
constexpr inline std::array<aidl::android::hardware::audio::core::StreamDescriptor::State, 9> enum_values<aidl::android::hardware::audio::core::StreamDescriptor::State> = {
  aidl::android::hardware::audio::core::StreamDescriptor::State::STANDBY,
  aidl::android::hardware::audio::core::StreamDescriptor::State::IDLE,
  aidl::android::hardware::audio::core::StreamDescriptor::State::ACTIVE,
  aidl::android::hardware::audio::core::StreamDescriptor::State::PAUSED,
  aidl::android::hardware::audio::core::StreamDescriptor::State::DRAINING,
  aidl::android::hardware::audio::core::StreamDescriptor::State::DRAIN_PAUSED,
  aidl::android::hardware::audio::core::StreamDescriptor::State::TRANSFERRING,
  aidl::android::hardware::audio::core::StreamDescriptor::State::TRANSFER_PAUSED,
  aidl::android::hardware::audio::core::StreamDescriptor::State::ERROR,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
[[nodiscard]] static inline std::string toString(StreamDescriptor::DrainMode val) {
  switch(val) {
  case StreamDescriptor::DrainMode::DRAIN_UNSPECIFIED:
    return "DRAIN_UNSPECIFIED";
  case StreamDescriptor::DrainMode::DRAIN_ALL:
    return "DRAIN_ALL";
  case StreamDescriptor::DrainMode::DRAIN_EARLY_NOTIFY:
    return "DRAIN_EARLY_NOTIFY";
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
constexpr inline std::array<aidl::android::hardware::audio::core::StreamDescriptor::DrainMode, 3> enum_values<aidl::android::hardware::audio::core::StreamDescriptor::DrainMode> = {
  aidl::android::hardware::audio::core::StreamDescriptor::DrainMode::DRAIN_UNSPECIFIED,
  aidl::android::hardware::audio::core::StreamDescriptor::DrainMode::DRAIN_ALL,
  aidl::android::hardware::audio::core::StreamDescriptor::DrainMode::DRAIN_EARLY_NOTIFY,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
[[nodiscard]] static inline std::string toString(StreamDescriptor::Command::Tag val) {
  switch(val) {
  case StreamDescriptor::Command::Tag::halReservedExit:
    return "halReservedExit";
  case StreamDescriptor::Command::Tag::getStatus:
    return "getStatus";
  case StreamDescriptor::Command::Tag::start:
    return "start";
  case StreamDescriptor::Command::Tag::burst:
    return "burst";
  case StreamDescriptor::Command::Tag::drain:
    return "drain";
  case StreamDescriptor::Command::Tag::standby:
    return "standby";
  case StreamDescriptor::Command::Tag::pause:
    return "pause";
  case StreamDescriptor::Command::Tag::flush:
    return "flush";
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
constexpr inline std::array<aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag, 8> enum_values<aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag> = {
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::halReservedExit,
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::getStatus,
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::start,
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::burst,
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::drain,
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::standby,
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::pause,
  aidl::android::hardware::audio::core::StreamDescriptor::Command::Tag::flush,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
[[nodiscard]] static inline std::string toString(StreamDescriptor::AudioBuffer::Tag val) {
  switch(val) {
  case StreamDescriptor::AudioBuffer::Tag::fmq:
    return "fmq";
  case StreamDescriptor::AudioBuffer::Tag::mmap:
    return "mmap";
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
constexpr inline std::array<aidl::android::hardware::audio::core::StreamDescriptor::AudioBuffer::Tag, 2> enum_values<aidl::android::hardware::audio::core::StreamDescriptor::AudioBuffer::Tag> = {
  aidl::android::hardware::audio::core::StreamDescriptor::AudioBuffer::Tag::fmq,
  aidl::android::hardware::audio::core::StreamDescriptor::AudioBuffer::Tag::mmap,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
