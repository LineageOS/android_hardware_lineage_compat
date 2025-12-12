/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash bfeb16c941085370dc6b68bcd7aec2dbb9435f49 -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types_interface/1/preprocessed.aidl -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging/android/hardware/audio/effect/IEffect.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3/android/hardware/audio/effect/IEffect.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/audio/effect/CommandId.h>
#include <aidl/android/hardware/audio/effect/Descriptor.h>
#include <aidl/android/hardware/audio/effect/IEffect.h>
#include <aidl/android/hardware/audio/effect/Parameter.h>
#include <aidl/android/hardware/audio/effect/State.h>
#include <aidl/android/hardware/common/fmq/MQDescriptor.h>
#include <aidl/android/hardware/common/fmq/SynchronizedReadWrite.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::audio::effect {
class Descriptor;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl::android::hardware::common::fmq {
template <typename T, typename Flavor>
class MQDescriptor;
}  // namespace aidl::android::hardware::common::fmq
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class IEffectDelegator;

class IEffect : public ::ndk::ICInterface {
public:
  typedef IEffectDelegator DefaultDelegator;
  static const char* descriptor;
  IEffect();
  virtual ~IEffect();

  class Status {
  public:
    typedef std::true_type fixed_size;
    static const char* descriptor;

    int32_t status __attribute__((aligned (4))) = 0;
    int32_t fmqConsumed __attribute__((aligned (4))) = 0;
    int32_t fmqProduced __attribute__((aligned (4))) = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const Status& _rhs) const {
      return std::tie(status, fmqConsumed, fmqProduced) == std::tie(_rhs.status, _rhs.fmqConsumed, _rhs.fmqProduced);
    }
    inline bool operator<(const Status& _rhs) const {
      return std::tie(status, fmqConsumed, fmqProduced) < std::tie(_rhs.status, _rhs.fmqConsumed, _rhs.fmqProduced);
    }
    inline bool operator!=(const Status& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const Status& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const Status& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const Status& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "Status{";
      _aidl_os << "status: " << ::android::internal::ToString(status);
      _aidl_os << ", fmqConsumed: " << ::android::internal::ToString(fmqConsumed);
      _aidl_os << ", fmqProduced: " << ::android::internal::ToString(fmqProduced);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  static_assert(offsetof(Status, status) == 0);
  static_assert(sizeof(int32_t) == 4);
  static_assert(offsetof(Status, fmqConsumed) == 4);
  static_assert(sizeof(int32_t) == 4);
  static_assert(offsetof(Status, fmqProduced) == 8);
  static_assert(sizeof(int32_t) == 4);
  static_assert(alignof(Status) == 4);
  static_assert(sizeof(Status) == 12);
  class OpenEffectReturn {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::common::fmq::MQDescriptor<::aidl::android::hardware::audio::effect::IEffect::Status, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite> statusMQ;
    ::aidl::android::hardware::common::fmq::MQDescriptor<float, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite> inputDataMQ;
    ::aidl::android::hardware::common::fmq::MQDescriptor<float, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite> outputDataMQ;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const OpenEffectReturn& _rhs) const {
      return std::tie(statusMQ, inputDataMQ, outputDataMQ) == std::tie(_rhs.statusMQ, _rhs.inputDataMQ, _rhs.outputDataMQ);
    }
    inline bool operator<(const OpenEffectReturn& _rhs) const {
      return std::tie(statusMQ, inputDataMQ, outputDataMQ) < std::tie(_rhs.statusMQ, _rhs.inputDataMQ, _rhs.outputDataMQ);
    }
    inline bool operator!=(const OpenEffectReturn& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const OpenEffectReturn& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const OpenEffectReturn& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const OpenEffectReturn& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "OpenEffectReturn{";
      _aidl_os << "statusMQ: " << ::android::internal::ToString(statusMQ);
      _aidl_os << ", inputDataMQ: " << ::android::internal::ToString(inputDataMQ);
      _aidl_os << ", outputDataMQ: " << ::android::internal::ToString(outputDataMQ);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  static inline const int32_t version = 3;
  static inline const std::string hash = "bfeb16c941085370dc6b68bcd7aec2dbb9435f49";
  static constexpr uint32_t TRANSACTION_open = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_close = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getDescriptor = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_command = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getState = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setParameter = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getParameter = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_reopen = FIRST_CALL_TRANSACTION + 7;

  static std::shared_ptr<IEffect> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IEffect>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IEffect>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IEffect>& impl);
  static const std::shared_ptr<IEffect>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus open(const ::aidl::android::hardware::audio::effect::Parameter::Common& in_common, const std::optional<::aidl::android::hardware::audio::effect::Parameter::Specific>& in_specific, ::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus close() = 0;
  virtual ::ndk::ScopedAStatus getDescriptor(::aidl::android::hardware::audio::effect::Descriptor* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus command(::aidl::android::hardware::audio::effect::CommandId in_commandId) = 0;
  virtual ::ndk::ScopedAStatus getState(::aidl::android::hardware::audio::effect::State* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setParameter(const ::aidl::android::hardware::audio::effect::Parameter& in_param) = 0;
  virtual ::ndk::ScopedAStatus getParameter(const ::aidl::android::hardware::audio::effect::Parameter::Id& in_paramId, ::aidl::android::hardware::audio::effect::Parameter* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus reopen(::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IEffect> default_impl;
};
class IEffectDefault : public IEffect {
public:
  ::ndk::ScopedAStatus open(const ::aidl::android::hardware::audio::effect::Parameter::Common& in_common, const std::optional<::aidl::android::hardware::audio::effect::Parameter::Specific>& in_specific, ::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn* _aidl_return) override;
  ::ndk::ScopedAStatus close() override;
  ::ndk::ScopedAStatus getDescriptor(::aidl::android::hardware::audio::effect::Descriptor* _aidl_return) override;
  ::ndk::ScopedAStatus command(::aidl::android::hardware::audio::effect::CommandId in_commandId) override;
  ::ndk::ScopedAStatus getState(::aidl::android::hardware::audio::effect::State* _aidl_return) override;
  ::ndk::ScopedAStatus setParameter(const ::aidl::android::hardware::audio::effect::Parameter& in_param) override;
  ::ndk::ScopedAStatus getParameter(const ::aidl::android::hardware::audio::effect::Parameter::Id& in_paramId, ::aidl::android::hardware::audio::effect::Parameter* _aidl_return) override;
  ::ndk::ScopedAStatus reopen(::aidl::android::hardware::audio::effect::IEffect::OpenEffectReturn* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
