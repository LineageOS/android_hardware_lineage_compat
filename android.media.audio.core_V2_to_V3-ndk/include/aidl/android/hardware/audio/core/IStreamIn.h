/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IStreamIn.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IStreamIn.aidl
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
#include <aidl/android/hardware/audio/common/SinkMetadata.h>
#include <aidl/android/hardware/audio/core/IStreamCommon.h>
#include <aidl/android/hardware/audio/core/IStreamIn.h>
#include <aidl/android/media/audio/common/MicrophoneDynamicInfo.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::audio::common {
class SinkMetadata;
}  // namespace aidl::android::hardware::audio::common
namespace aidl::android::hardware::audio::core {
class IStreamCommon;
}  // namespace aidl::android::hardware::audio::core
namespace aidl::android::media::audio::common {
class MicrophoneDynamicInfo;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class IStreamInDelegator;

class IStreamIn : public ::ndk::ICInterface {
public:
  typedef IStreamInDelegator DefaultDelegator;
  static const char* descriptor;
  IStreamIn();
  virtual ~IStreamIn();

  enum class MicrophoneDirection : int32_t {
    UNSPECIFIED = 0,
    FRONT = 1,
    BACK = 2,
    EXTERNAL = 3,
  };

  enum : int32_t { MIC_FIELD_DIMENSION_WIDE_ANGLE = -1 };
  enum : int32_t { MIC_FIELD_DIMENSION_NO_ZOOM = 0 };
  enum : int32_t { MIC_FIELD_DIMENSION_MAX_ZOOM = 1 };
  enum : int32_t { HW_GAIN_MIN = 0 };
  enum : int32_t { HW_GAIN_MAX = 1 };
  static inline const int32_t version = 3;
  static inline const std::string hash = "eb5f1f5af402830af56b50eb66bdd60fd8cc774e";
  static constexpr uint32_t TRANSACTION_getStreamCommon = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getActiveMicrophones = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getMicrophoneDirection = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_setMicrophoneDirection = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getMicrophoneFieldDimension = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setMicrophoneFieldDimension = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_updateMetadata = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getHwGain = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_setHwGain = FIRST_CALL_TRANSACTION + 8;

  static std::shared_ptr<IStreamIn> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IStreamIn>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IStreamIn>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IStreamIn>& impl);
  static const std::shared_ptr<IStreamIn>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getStreamCommon(std::shared_ptr<::aidl::android::hardware::audio::core::IStreamCommon>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getActiveMicrophones(std::vector<::aidl::android::media::audio::common::MicrophoneDynamicInfo>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getMicrophoneDirection(::aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setMicrophoneDirection(::aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection in_direction) = 0;
  virtual ::ndk::ScopedAStatus getMicrophoneFieldDimension(float* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setMicrophoneFieldDimension(float in_zoom) = 0;
  virtual ::ndk::ScopedAStatus updateMetadata(const ::aidl::android::hardware::audio::common::SinkMetadata& in_sinkMetadata) = 0;
  virtual ::ndk::ScopedAStatus getHwGain(std::vector<float>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setHwGain(const std::vector<float>& in_channelGains) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IStreamIn> default_impl;
};
class IStreamInDefault : public IStreamIn {
public:
  ::ndk::ScopedAStatus getStreamCommon(std::shared_ptr<::aidl::android::hardware::audio::core::IStreamCommon>* _aidl_return) override;
  ::ndk::ScopedAStatus getActiveMicrophones(std::vector<::aidl::android::media::audio::common::MicrophoneDynamicInfo>* _aidl_return) override;
  ::ndk::ScopedAStatus getMicrophoneDirection(::aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection* _aidl_return) override;
  ::ndk::ScopedAStatus setMicrophoneDirection(::aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection in_direction) override;
  ::ndk::ScopedAStatus getMicrophoneFieldDimension(float* _aidl_return) override;
  ::ndk::ScopedAStatus setMicrophoneFieldDimension(float in_zoom) override;
  ::ndk::ScopedAStatus updateMetadata(const ::aidl::android::hardware::audio::common::SinkMetadata& in_sinkMetadata) override;
  ::ndk::ScopedAStatus getHwGain(std::vector<float>* _aidl_return) override;
  ::ndk::ScopedAStatus setHwGain(const std::vector<float>& in_channelGains) override;
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
[[nodiscard]] static inline std::string toString(IStreamIn::MicrophoneDirection val) {
  switch(val) {
  case IStreamIn::MicrophoneDirection::UNSPECIFIED:
    return "UNSPECIFIED";
  case IStreamIn::MicrophoneDirection::FRONT:
    return "FRONT";
  case IStreamIn::MicrophoneDirection::BACK:
    return "BACK";
  case IStreamIn::MicrophoneDirection::EXTERNAL:
    return "EXTERNAL";
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
constexpr inline std::array<aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection, 4> enum_values<aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection> = {
  aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection::UNSPECIFIED,
  aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection::FRONT,
  aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection::BACK,
  aidl::android::hardware::audio::core::IStreamIn::MicrophoneDirection::EXTERNAL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
