/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IModule.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IModule.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/audio/core/IModule.h"

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
class BnModule : public ::ndk::BnCInterface<IModule> {
public:
  BnModule();
  virtual ~BnModule();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IModuleDelegator : public BnModule {
public:
  explicit IModuleDelegator(const std::shared_ptr<IModule> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != IModule::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus setModuleDebug(const ::aidl::android::hardware::audio::core::ModuleDebug& in_debug) override {
    return _impl->setModuleDebug(in_debug);
  }
  ::ndk::ScopedAStatus getTelephony(std::shared_ptr<::aidl::android::hardware::audio::core::ITelephony>* _aidl_return) override {
    return _impl->getTelephony(_aidl_return);
  }
  ::ndk::ScopedAStatus getBluetooth(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetooth>* _aidl_return) override {
    return _impl->getBluetooth(_aidl_return);
  }
  ::ndk::ScopedAStatus getBluetoothA2dp(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetoothA2dp>* _aidl_return) override {
    return _impl->getBluetoothA2dp(_aidl_return);
  }
  ::ndk::ScopedAStatus getBluetoothLe(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetoothLe>* _aidl_return) override {
    return _impl->getBluetoothLe(_aidl_return);
  }
  ::ndk::ScopedAStatus connectExternalDevice(const ::aidl::android::media::audio::common::AudioPort& in_templateIdAndAdditionalData, ::aidl::android::media::audio::common::AudioPort* _aidl_return) override {
    return _impl->connectExternalDevice(in_templateIdAndAdditionalData, _aidl_return);
  }
  ::ndk::ScopedAStatus disconnectExternalDevice(int32_t in_portId) override {
    return _impl->disconnectExternalDevice(in_portId);
  }
  ::ndk::ScopedAStatus getAudioPatches(std::vector<::aidl::android::hardware::audio::core::AudioPatch>* _aidl_return) override {
    return _impl->getAudioPatches(_aidl_return);
  }
  ::ndk::ScopedAStatus getAudioPort(int32_t in_portId, ::aidl::android::media::audio::common::AudioPort* _aidl_return) override {
    return _impl->getAudioPort(in_portId, _aidl_return);
  }
  ::ndk::ScopedAStatus getAudioPortConfigs(std::vector<::aidl::android::media::audio::common::AudioPortConfig>* _aidl_return) override {
    return _impl->getAudioPortConfigs(_aidl_return);
  }
  ::ndk::ScopedAStatus getAudioPorts(std::vector<::aidl::android::media::audio::common::AudioPort>* _aidl_return) override {
    return _impl->getAudioPorts(_aidl_return);
  }
  ::ndk::ScopedAStatus getAudioRoutes(std::vector<::aidl::android::hardware::audio::core::AudioRoute>* _aidl_return) override {
    return _impl->getAudioRoutes(_aidl_return);
  }
  ::ndk::ScopedAStatus getAudioRoutesForAudioPort(int32_t in_portId, std::vector<::aidl::android::hardware::audio::core::AudioRoute>* _aidl_return) override {
    return _impl->getAudioRoutesForAudioPort(in_portId, _aidl_return);
  }
  ::ndk::ScopedAStatus openInputStream(const ::aidl::android::hardware::audio::core::IModule::OpenInputStreamArguments& in_args, ::aidl::android::hardware::audio::core::IModule::OpenInputStreamReturn* _aidl_return) override {
    return _impl->openInputStream(in_args, _aidl_return);
  }
  ::ndk::ScopedAStatus openOutputStream(const ::aidl::android::hardware::audio::core::IModule::OpenOutputStreamArguments& in_args, ::aidl::android::hardware::audio::core::IModule::OpenOutputStreamReturn* _aidl_return) override {
    return _impl->openOutputStream(in_args, _aidl_return);
  }
  ::ndk::ScopedAStatus getSupportedPlaybackRateFactors(::aidl::android::hardware::audio::core::IModule::SupportedPlaybackRateFactors* _aidl_return) override {
    return _impl->getSupportedPlaybackRateFactors(_aidl_return);
  }
  ::ndk::ScopedAStatus setAudioPatch(const ::aidl::android::hardware::audio::core::AudioPatch& in_requested, ::aidl::android::hardware::audio::core::AudioPatch* _aidl_return) override {
    return _impl->setAudioPatch(in_requested, _aidl_return);
  }
  ::ndk::ScopedAStatus setAudioPortConfig(const ::aidl::android::media::audio::common::AudioPortConfig& in_requested, ::aidl::android::media::audio::common::AudioPortConfig* out_suggested, bool* _aidl_return) override {
    return _impl->setAudioPortConfig(in_requested, out_suggested, _aidl_return);
  }
  ::ndk::ScopedAStatus resetAudioPatch(int32_t in_patchId) override {
    return _impl->resetAudioPatch(in_patchId);
  }
  ::ndk::ScopedAStatus resetAudioPortConfig(int32_t in_portConfigId) override {
    return _impl->resetAudioPortConfig(in_portConfigId);
  }
  ::ndk::ScopedAStatus getMasterMute(bool* _aidl_return) override {
    return _impl->getMasterMute(_aidl_return);
  }
  ::ndk::ScopedAStatus setMasterMute(bool in_mute) override {
    return _impl->setMasterMute(in_mute);
  }
  ::ndk::ScopedAStatus getMasterVolume(float* _aidl_return) override {
    return _impl->getMasterVolume(_aidl_return);
  }
  ::ndk::ScopedAStatus setMasterVolume(float in_volume) override {
    return _impl->setMasterVolume(in_volume);
  }
  ::ndk::ScopedAStatus getMicMute(bool* _aidl_return) override {
    return _impl->getMicMute(_aidl_return);
  }
  ::ndk::ScopedAStatus setMicMute(bool in_mute) override {
    return _impl->setMicMute(in_mute);
  }
  ::ndk::ScopedAStatus getMicrophones(std::vector<::aidl::android::media::audio::common::MicrophoneInfo>* _aidl_return) override {
    return _impl->getMicrophones(_aidl_return);
  }
  ::ndk::ScopedAStatus updateAudioMode(::aidl::android::media::audio::common::AudioMode in_mode) override {
    return _impl->updateAudioMode(in_mode);
  }
  ::ndk::ScopedAStatus updateScreenRotation(::aidl::android::hardware::audio::core::IModule::ScreenRotation in_rotation) override {
    return _impl->updateScreenRotation(in_rotation);
  }
  ::ndk::ScopedAStatus updateScreenState(bool in_isTurnedOn) override {
    return _impl->updateScreenState(in_isTurnedOn);
  }
  ::ndk::ScopedAStatus getSoundDose(std::shared_ptr<::aidl::android::hardware::audio::core::sounddose::ISoundDose>* _aidl_return) override {
    return _impl->getSoundDose(_aidl_return);
  }
  ::ndk::ScopedAStatus generateHwAvSyncId(int32_t* _aidl_return) override {
    return _impl->generateHwAvSyncId(_aidl_return);
  }
  ::ndk::ScopedAStatus getVendorParameters(const std::vector<std::string>& in_ids, std::vector<::aidl::android::hardware::audio::core::VendorParameter>* _aidl_return) override {
    return _impl->getVendorParameters(in_ids, _aidl_return);
  }
  ::ndk::ScopedAStatus setVendorParameters(const std::vector<::aidl::android::hardware::audio::core::VendorParameter>& in_parameters, bool in_async) override {
    return _impl->setVendorParameters(in_parameters, in_async);
  }
  ::ndk::ScopedAStatus addDeviceEffect(int32_t in_portConfigId, const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) override {
    return _impl->addDeviceEffect(in_portConfigId, in_effect);
  }
  ::ndk::ScopedAStatus removeDeviceEffect(int32_t in_portConfigId, const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) override {
    return _impl->removeDeviceEffect(in_portConfigId, in_effect);
  }
  ::ndk::ScopedAStatus getMmapPolicyInfos(::aidl::android::media::audio::common::AudioMMapPolicyType in_mmapPolicyType, std::vector<::aidl::android::media::audio::common::AudioMMapPolicyInfo>* _aidl_return) override {
    return _impl->getMmapPolicyInfos(in_mmapPolicyType, _aidl_return);
  }
  ::ndk::ScopedAStatus supportsVariableLatency(bool* _aidl_return) override {
    return _impl->supportsVariableLatency(_aidl_return);
  }
  ::ndk::ScopedAStatus getAAudioMixerBurstCount(int32_t* _aidl_return) override {
    return _impl->getAAudioMixerBurstCount(_aidl_return);
  }
  ::ndk::ScopedAStatus getAAudioHardwareBurstMinUsec(int32_t* _aidl_return) override {
    return _impl->getAAudioHardwareBurstMinUsec(_aidl_return);
  }
  ::ndk::ScopedAStatus prepareToDisconnectExternalDevice(int32_t in_portId) override {
    return _impl->prepareToDisconnectExternalDevice(in_portId);
  }
protected:
private:
  std::shared_ptr<IModule> _impl;
};

}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
