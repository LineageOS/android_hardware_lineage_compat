/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IStreamOut.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IStreamOut.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/audio/core/IStreamOut.h"

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
class BnStreamOut : public ::ndk::BnCInterface<IStreamOut> {
public:
  BnStreamOut();
  virtual ~BnStreamOut();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IStreamOutDelegator : public BnStreamOut {
public:
  explicit IStreamOutDelegator(const std::shared_ptr<IStreamOut> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != IStreamOut::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus getStreamCommon(std::shared_ptr<::aidl::android::hardware::audio::core::IStreamCommon>* _aidl_return) override {
    return _impl->getStreamCommon(_aidl_return);
  }
  ::ndk::ScopedAStatus updateMetadata(const ::aidl::android::hardware::audio::common::SourceMetadata& in_sourceMetadata) override {
    return _impl->updateMetadata(in_sourceMetadata);
  }
  ::ndk::ScopedAStatus updateOffloadMetadata(const ::aidl::android::hardware::audio::common::AudioOffloadMetadata& in_offloadMetadata) override {
    return _impl->updateOffloadMetadata(in_offloadMetadata);
  }
  ::ndk::ScopedAStatus getHwVolume(std::vector<float>* _aidl_return) override {
    return _impl->getHwVolume(_aidl_return);
  }
  ::ndk::ScopedAStatus setHwVolume(const std::vector<float>& in_channelVolumes) override {
    return _impl->setHwVolume(in_channelVolumes);
  }
  ::ndk::ScopedAStatus getAudioDescriptionMixLevel(float* _aidl_return) override {
    return _impl->getAudioDescriptionMixLevel(_aidl_return);
  }
  ::ndk::ScopedAStatus setAudioDescriptionMixLevel(float in_leveldB) override {
    return _impl->setAudioDescriptionMixLevel(in_leveldB);
  }
  ::ndk::ScopedAStatus getDualMonoMode(::aidl::android::media::audio::common::AudioDualMonoMode* _aidl_return) override {
    return _impl->getDualMonoMode(_aidl_return);
  }
  ::ndk::ScopedAStatus setDualMonoMode(::aidl::android::media::audio::common::AudioDualMonoMode in_mode) override {
    return _impl->setDualMonoMode(in_mode);
  }
  ::ndk::ScopedAStatus getRecommendedLatencyModes(std::vector<::aidl::android::media::audio::common::AudioLatencyMode>* _aidl_return) override {
    return _impl->getRecommendedLatencyModes(_aidl_return);
  }
  ::ndk::ScopedAStatus setLatencyMode(::aidl::android::media::audio::common::AudioLatencyMode in_mode) override {
    return _impl->setLatencyMode(in_mode);
  }
  ::ndk::ScopedAStatus getPlaybackRateParameters(::aidl::android::media::audio::common::AudioPlaybackRate* _aidl_return) override {
    return _impl->getPlaybackRateParameters(_aidl_return);
  }
  ::ndk::ScopedAStatus setPlaybackRateParameters(const ::aidl::android::media::audio::common::AudioPlaybackRate& in_playbackRate) override {
    return _impl->setPlaybackRateParameters(in_playbackRate);
  }
  ::ndk::ScopedAStatus selectPresentation(int32_t in_presentationId, int32_t in_programId) override {
    return _impl->selectPresentation(in_presentationId, in_programId);
  }
protected:
private:
  std::shared_ptr<IStreamOut> _impl;
};

}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
