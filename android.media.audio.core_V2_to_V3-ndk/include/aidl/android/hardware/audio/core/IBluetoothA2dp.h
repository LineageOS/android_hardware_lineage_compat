/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IBluetoothA2dp.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IBluetoothA2dp.aidl
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
#include <aidl/android/hardware/audio/core/VendorParameter.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::audio::core {
class VendorParameter;
}  // namespace aidl::android::hardware::audio::core
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class IBluetoothA2dpDelegator;

class IBluetoothA2dp : public ::ndk::ICInterface {
public:
  typedef IBluetoothA2dpDelegator DefaultDelegator;
  static const char* descriptor;
  IBluetoothA2dp();
  virtual ~IBluetoothA2dp();

  static inline const int32_t version = 3;
  static inline const std::string hash = "eb5f1f5af402830af56b50eb66bdd60fd8cc774e";
  static constexpr uint32_t TRANSACTION_isEnabled = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_setEnabled = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_supportsOffloadReconfiguration = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_reconfigureOffload = FIRST_CALL_TRANSACTION + 3;

  static std::shared_ptr<IBluetoothA2dp> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothA2dp>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothA2dp>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IBluetoothA2dp>& impl);
  static const std::shared_ptr<IBluetoothA2dp>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus isEnabled(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setEnabled(bool in_enabled) = 0;
  virtual ::ndk::ScopedAStatus supportsOffloadReconfiguration(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus reconfigureOffload(const std::vector<::aidl::android::hardware::audio::core::VendorParameter>& in_parameters) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IBluetoothA2dp> default_impl;
};
class IBluetoothA2dpDefault : public IBluetoothA2dp {
public:
  ::ndk::ScopedAStatus isEnabled(bool* _aidl_return) override;
  ::ndk::ScopedAStatus setEnabled(bool in_enabled) override;
  ::ndk::ScopedAStatus supportsOffloadReconfiguration(bool* _aidl_return) override;
  ::ndk::ScopedAStatus reconfigureOffload(const std::vector<::aidl::android::hardware::audio::core::VendorParameter>& in_parameters) override;
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
