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
#include <cassert>

#ifndef __BIONIC__
#ifndef __assert2
#define __assert2(a,b,c,d) ((void)0)
#endif
#endif

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
namespace sounddose {
class BnSoundDose : public ::ndk::BnCInterface<ISoundDose> {
public:
  BnSoundDose();
  virtual ~BnSoundDose();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class ISoundDoseDelegator : public BnSoundDose {
public:
  explicit ISoundDoseDelegator(const std::shared_ptr<ISoundDose> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != ISoundDose::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus setOutputRs2UpperBound(float in_rs2ValueDbA) override {
    return _impl->setOutputRs2UpperBound(in_rs2ValueDbA);
  }
  ::ndk::ScopedAStatus getOutputRs2UpperBound(float* _aidl_return) override {
    return _impl->getOutputRs2UpperBound(_aidl_return);
  }
  ::ndk::ScopedAStatus registerSoundDoseCallback(const std::shared_ptr<::aidl::android::hardware::audio::core::sounddose::ISoundDose::IHalSoundDoseCallback>& in_callback) override {
    return _impl->registerSoundDoseCallback(in_callback);
  }
protected:
private:
  std::shared_ptr<ISoundDose> _impl;
};

}  // namespace sounddose
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
