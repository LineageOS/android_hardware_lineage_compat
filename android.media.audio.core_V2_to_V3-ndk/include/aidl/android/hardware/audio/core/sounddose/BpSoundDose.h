/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash afe48eb8c7a7bb735723924a74ed31e0368f57bd -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose-V3-ndk-source/gen/staging/android/hardware/audio/core/sounddose/ISoundDose.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core.sounddose/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core.sounddose/3/android/hardware/audio/core/sounddose/ISoundDose.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/audio/core/sounddose/ISoundDose.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
namespace sounddose {
class BpSoundDose : public ::ndk::BpCInterface<ISoundDose> {
public:
  explicit BpSoundDose(const ::ndk::SpAIBinder& binder);
  virtual ~BpSoundDose();

  ::ndk::ScopedAStatus setOutputRs2UpperBound(float in_rs2ValueDbA) override;
  ::ndk::ScopedAStatus getOutputRs2UpperBound(float* _aidl_return) override;
  ::ndk::ScopedAStatus registerSoundDoseCallback(const std::shared_ptr<::aidl::android::hardware::audio::core::sounddose::ISoundDose::IHalSoundDoseCallback>& in_callback) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace sounddose
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
