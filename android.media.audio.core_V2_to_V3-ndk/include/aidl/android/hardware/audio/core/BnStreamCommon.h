/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IStreamCommon.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IStreamCommon.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/audio/core/IStreamCommon.h"

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
class BnStreamCommon : public ::ndk::BnCInterface<IStreamCommon> {
public:
  BnStreamCommon();
  virtual ~BnStreamCommon();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IStreamCommonDelegator : public BnStreamCommon {
public:
  explicit IStreamCommonDelegator(const std::shared_ptr<IStreamCommon> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != IStreamCommon::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus close() override {
    return _impl->close();
  }
  ::ndk::ScopedAStatus prepareToClose() override {
    return _impl->prepareToClose();
  }
  ::ndk::ScopedAStatus updateHwAvSyncId(int32_t in_hwAvSyncId) override {
    return _impl->updateHwAvSyncId(in_hwAvSyncId);
  }
  ::ndk::ScopedAStatus getVendorParameters(const std::vector<std::string>& in_ids, std::vector<::aidl::android::hardware::audio::core::VendorParameter>* _aidl_return) override {
    return _impl->getVendorParameters(in_ids, _aidl_return);
  }
  ::ndk::ScopedAStatus setVendorParameters(const std::vector<::aidl::android::hardware::audio::core::VendorParameter>& in_parameters, bool in_async) override {
    return _impl->setVendorParameters(in_parameters, in_async);
  }
  ::ndk::ScopedAStatus addEffect(const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) override {
    return _impl->addEffect(in_effect);
  }
  ::ndk::ScopedAStatus removeEffect(const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) override {
    return _impl->removeEffect(in_effect);
  }
protected:
private:
  std::shared_ptr<IStreamCommon> _impl;
};

}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
