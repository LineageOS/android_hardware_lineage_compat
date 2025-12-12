/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/IBluetoothAudioProvider.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/IBluetoothAudioProvider.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/bluetooth/audio/IBluetoothAudioProvider.h"

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
namespace bluetooth {
namespace audio {
class BnBluetoothAudioProvider : public ::ndk::BnCInterface<IBluetoothAudioProvider> {
public:
  BnBluetoothAudioProvider();
  virtual ~BnBluetoothAudioProvider();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IBluetoothAudioProviderDelegator : public BnBluetoothAudioProvider {
public:
  explicit IBluetoothAudioProviderDelegator(const std::shared_ptr<IBluetoothAudioProvider> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != IBluetoothAudioProvider::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus endSession() override {
    return _impl->endSession();
  }
  ::ndk::ScopedAStatus startSession(const std::shared_ptr<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioPort>& in_hostIf, const ::aidl::android::hardware::bluetooth::audio::AudioConfiguration& in_audioConfig, const std::vector<::aidl::android::hardware::bluetooth::audio::LatencyMode>& in_supportedLatencyModes, ::aidl::android::hardware::common::fmq::MQDescriptor<int8_t, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>* _aidl_return) override {
    return _impl->startSession(in_hostIf, in_audioConfig, in_supportedLatencyModes, _aidl_return);
  }
  ::ndk::ScopedAStatus streamStarted(::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus in_status) override {
    return _impl->streamStarted(in_status);
  }
  ::ndk::ScopedAStatus streamSuspended(::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus in_status) override {
    return _impl->streamSuspended(in_status);
  }
  ::ndk::ScopedAStatus updateAudioConfiguration(const ::aidl::android::hardware::bluetooth::audio::AudioConfiguration& in_audioConfig) override {
    return _impl->updateAudioConfiguration(in_audioConfig);
  }
  ::ndk::ScopedAStatus setLowLatencyModeAllowed(bool in_allowed) override {
    return _impl->setLowLatencyModeAllowed(in_allowed);
  }
  ::ndk::ScopedAStatus parseA2dpConfiguration(const ::aidl::android::hardware::bluetooth::audio::CodecId& in_codecId, const std::vector<uint8_t>& in_configuration, ::aidl::android::hardware::bluetooth::audio::CodecParameters* out_codecParameters, ::aidl::android::hardware::bluetooth::audio::A2dpStatus* _aidl_return) override {
    return _impl->parseA2dpConfiguration(in_codecId, in_configuration, out_codecParameters, _aidl_return);
  }
  ::ndk::ScopedAStatus getA2dpConfiguration(const std::vector<::aidl::android::hardware::bluetooth::audio::A2dpRemoteCapabilities>& in_remoteA2dpCapabilities, const ::aidl::android::hardware::bluetooth::audio::A2dpConfigurationHint& in_hint, std::optional<::aidl::android::hardware::bluetooth::audio::A2dpConfiguration>* _aidl_return) override {
    return _impl->getA2dpConfiguration(in_remoteA2dpCapabilities, in_hint, _aidl_return);
  }
  ::ndk::ScopedAStatus setCodecPriority(const ::aidl::android::hardware::bluetooth::audio::CodecId& in_codecId, int32_t in_priority) override {
    return _impl->setCodecPriority(in_codecId, in_priority);
  }
  ::ndk::ScopedAStatus getLeAudioAseConfiguration(const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSinkAudioCapabilities, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSourceAudioCapabilities, const std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioConfigurationRequirement>& in_requirements, std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseConfigurationSetting>* _aidl_return) override {
    return _impl->getLeAudioAseConfiguration(in_remoteSinkAudioCapabilities, in_remoteSourceAudioCapabilities, in_requirements, _aidl_return);
  }
  ::ndk::ScopedAStatus getLeAudioAseQosConfiguration(const ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationRequirement& in_qosRequirement, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationPair* _aidl_return) override {
    return _impl->getLeAudioAseQosConfiguration(in_qosRequirement, _aidl_return);
  }
  ::ndk::ScopedAStatus getLeAudioAseDatapathConfiguration(const std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::StreamConfig>& in_sinkConfig, const std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::StreamConfig>& in_sourceConfig, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfigurationPair* _aidl_return) override {
    return _impl->getLeAudioAseDatapathConfiguration(in_sinkConfig, in_sourceConfig, _aidl_return);
  }
  ::ndk::ScopedAStatus onSinkAseMetadataChanged(::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState in_state, int32_t in_cigId, int32_t in_cisId, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>>& in_metadata) override {
    return _impl->onSinkAseMetadataChanged(in_state, in_cigId, in_cisId, in_metadata);
  }
  ::ndk::ScopedAStatus onSourceAseMetadataChanged(::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState in_state, int32_t in_cigId, int32_t in_cisId, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>>& in_metadata) override {
    return _impl->onSourceAseMetadataChanged(in_state, in_cigId, in_cisId, in_metadata);
  }
  ::ndk::ScopedAStatus getLeAudioBroadcastConfiguration(const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSinkAudioCapabilities, const ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastConfigurationRequirement& in_requirement, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastConfigurationSetting* _aidl_return) override {
    return _impl->getLeAudioBroadcastConfiguration(in_remoteSinkAudioCapabilities, in_requirement, _aidl_return);
  }
  ::ndk::ScopedAStatus getLeAudioBroadcastDatapathConfiguration(const ::aidl::android::hardware::bluetooth::audio::AudioContext& in_audioContext, const std::vector<::aidl::android::hardware::bluetooth::audio::LeAudioBroadcastConfiguration::BroadcastStreamMap>& in_streamMap, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration* _aidl_return) override {
    return _impl->getLeAudioBroadcastDatapathConfiguration(in_audioContext, in_streamMap, _aidl_return);
  }
protected:
private:
  std::shared_ptr<IBluetoothAudioProvider> _impl;
};

}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
