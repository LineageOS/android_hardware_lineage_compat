/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/IBluetoothAudioProviderFactory.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/IBluetoothAudioProviderFactory.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/bluetooth/audio/IBluetoothAudioProviderFactory.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class BpBluetoothAudioProviderFactory : public ::ndk::BpCInterface<IBluetoothAudioProviderFactory> {
public:
  explicit BpBluetoothAudioProviderFactory(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothAudioProviderFactory();

  ::ndk::ScopedAStatus getProviderCapabilities(::aidl::android::hardware::bluetooth::audio::SessionType in_sessionType, std::vector<::aidl::android::hardware::bluetooth::audio::AudioCapabilities>* _aidl_return) override;
  ::ndk::ScopedAStatus openProvider(::aidl::android::hardware::bluetooth::audio::SessionType in_sessionType, std::shared_ptr<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider>* _aidl_return) override;
  ::ndk::ScopedAStatus getProviderInfo(::aidl::android::hardware::bluetooth::audio::SessionType in_sessionType, std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProviderFactory::ProviderInfo>* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
