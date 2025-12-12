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

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class BpModule : public ::ndk::BpCInterface<IModule> {
public:
  explicit BpModule(const ::ndk::SpAIBinder& binder);
  virtual ~BpModule();

  ::ndk::ScopedAStatus setModuleDebug(const ::aidl::android::hardware::audio::core::ModuleDebug& in_debug) override;
  ::ndk::ScopedAStatus getTelephony(std::shared_ptr<::aidl::android::hardware::audio::core::ITelephony>* _aidl_return) override;
  ::ndk::ScopedAStatus getBluetooth(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetooth>* _aidl_return) override;
  ::ndk::ScopedAStatus getBluetoothA2dp(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetoothA2dp>* _aidl_return) override;
  ::ndk::ScopedAStatus getBluetoothLe(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetoothLe>* _aidl_return) override;
  ::ndk::ScopedAStatus connectExternalDevice(const ::aidl::android::media::audio::common::AudioPort& in_templateIdAndAdditionalData, ::aidl::android::media::audio::common::AudioPort* _aidl_return) override;
  ::ndk::ScopedAStatus disconnectExternalDevice(int32_t in_portId) override;
  ::ndk::ScopedAStatus getAudioPatches(std::vector<::aidl::android::hardware::audio::core::AudioPatch>* _aidl_return) override;
  ::ndk::ScopedAStatus getAudioPort(int32_t in_portId, ::aidl::android::media::audio::common::AudioPort* _aidl_return) override;
  ::ndk::ScopedAStatus getAudioPortConfigs(std::vector<::aidl::android::media::audio::common::AudioPortConfig>* _aidl_return) override;
  ::ndk::ScopedAStatus getAudioPorts(std::vector<::aidl::android::media::audio::common::AudioPort>* _aidl_return) override;
  ::ndk::ScopedAStatus getAudioRoutes(std::vector<::aidl::android::hardware::audio::core::AudioRoute>* _aidl_return) override;
  ::ndk::ScopedAStatus getAudioRoutesForAudioPort(int32_t in_portId, std::vector<::aidl::android::hardware::audio::core::AudioRoute>* _aidl_return) override;
  ::ndk::ScopedAStatus openInputStream(const ::aidl::android::hardware::audio::core::IModule::OpenInputStreamArguments& in_args, ::aidl::android::hardware::audio::core::IModule::OpenInputStreamReturn* _aidl_return) override;
  ::ndk::ScopedAStatus openOutputStream(const ::aidl::android::hardware::audio::core::IModule::OpenOutputStreamArguments& in_args, ::aidl::android::hardware::audio::core::IModule::OpenOutputStreamReturn* _aidl_return) override;
  ::ndk::ScopedAStatus getSupportedPlaybackRateFactors(::aidl::android::hardware::audio::core::IModule::SupportedPlaybackRateFactors* _aidl_return) override;
  ::ndk::ScopedAStatus setAudioPatch(const ::aidl::android::hardware::audio::core::AudioPatch& in_requested, ::aidl::android::hardware::audio::core::AudioPatch* _aidl_return) override;
  ::ndk::ScopedAStatus setAudioPortConfig(const ::aidl::android::media::audio::common::AudioPortConfig& in_requested, ::aidl::android::media::audio::common::AudioPortConfig* out_suggested, bool* _aidl_return) override;
  ::ndk::ScopedAStatus resetAudioPatch(int32_t in_patchId) override;
  ::ndk::ScopedAStatus resetAudioPortConfig(int32_t in_portConfigId) override;
  ::ndk::ScopedAStatus getMasterMute(bool* _aidl_return) override;
  ::ndk::ScopedAStatus setMasterMute(bool in_mute) override;
  ::ndk::ScopedAStatus getMasterVolume(float* _aidl_return) override;
  ::ndk::ScopedAStatus setMasterVolume(float in_volume) override;
  ::ndk::ScopedAStatus getMicMute(bool* _aidl_return) override;
  ::ndk::ScopedAStatus setMicMute(bool in_mute) override;
  ::ndk::ScopedAStatus getMicrophones(std::vector<::aidl::android::media::audio::common::MicrophoneInfo>* _aidl_return) override;
  ::ndk::ScopedAStatus updateAudioMode(::aidl::android::media::audio::common::AudioMode in_mode) override;
  ::ndk::ScopedAStatus updateScreenRotation(::aidl::android::hardware::audio::core::IModule::ScreenRotation in_rotation) override;
  ::ndk::ScopedAStatus updateScreenState(bool in_isTurnedOn) override;
  ::ndk::ScopedAStatus getSoundDose(std::shared_ptr<::aidl::android::hardware::audio::core::sounddose::ISoundDose>* _aidl_return) override;
  ::ndk::ScopedAStatus generateHwAvSyncId(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getVendorParameters(const std::vector<std::string>& in_ids, std::vector<::aidl::android::hardware::audio::core::VendorParameter>* _aidl_return) override;
  ::ndk::ScopedAStatus setVendorParameters(const std::vector<::aidl::android::hardware::audio::core::VendorParameter>& in_parameters, bool in_async) override;
  ::ndk::ScopedAStatus addDeviceEffect(int32_t in_portConfigId, const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) override;
  ::ndk::ScopedAStatus removeDeviceEffect(int32_t in_portConfigId, const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) override;
  ::ndk::ScopedAStatus getMmapPolicyInfos(::aidl::android::media::audio::common::AudioMMapPolicyType in_mmapPolicyType, std::vector<::aidl::android::media::audio::common::AudioMMapPolicyInfo>* _aidl_return) override;
  ::ndk::ScopedAStatus supportsVariableLatency(bool* _aidl_return) override;
  ::ndk::ScopedAStatus getAAudioMixerBurstCount(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getAAudioHardwareBurstMinUsec(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus prepareToDisconnectExternalDevice(int32_t in_portId) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
