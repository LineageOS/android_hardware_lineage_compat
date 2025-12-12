/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/IBluetoothAudioPort.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/IBluetoothAudioPort.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/bluetooth/audio/IBluetoothAudioPort.h"

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
class BnBluetoothAudioPort : public ::ndk::BnCInterface<IBluetoothAudioPort> {
public:
  BnBluetoothAudioPort();
  virtual ~BnBluetoothAudioPort();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IBluetoothAudioPortDelegator : public BnBluetoothAudioPort {
public:
  explicit IBluetoothAudioPortDelegator(const std::shared_ptr<IBluetoothAudioPort> &impl) : _impl(impl) {
     int32_t _impl_ver = 0;
     if (!impl->getInterfaceVersion(&_impl_ver).isOk()) {;
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Delegator failed to get version of the implementation.");
     }
     if (_impl_ver != IBluetoothAudioPort::version) {
        __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "Mismatched versions of delegator and implementation is not allowed.");
     }
  }

  ::ndk::ScopedAStatus getPresentationPosition(::aidl::android::hardware::bluetooth::audio::PresentationPosition* _aidl_return) override {
    return _impl->getPresentationPosition(_aidl_return);
  }
  ::ndk::ScopedAStatus startStream(bool in_isLowLatency) override {
    return _impl->startStream(in_isLowLatency);
  }
  ::ndk::ScopedAStatus stopStream() override {
    return _impl->stopStream();
  }
  ::ndk::ScopedAStatus suspendStream() override {
    return _impl->suspendStream();
  }
  ::ndk::ScopedAStatus updateSourceMetadata(const ::aidl::android::hardware::audio::common::SourceMetadata& in_sourceMetadata) override {
    return _impl->updateSourceMetadata(in_sourceMetadata);
  }
  ::ndk::ScopedAStatus updateSinkMetadata(const ::aidl::android::hardware::audio::common::SinkMetadata& in_sinkMetadata) override {
    return _impl->updateSinkMetadata(in_sinkMetadata);
  }
  ::ndk::ScopedAStatus setLatencyMode(::aidl::android::hardware::bluetooth::audio::LatencyMode in_latencyMode) override {
    return _impl->setLatencyMode(in_latencyMode);
  }
protected:
private:
  std::shared_ptr<IBluetoothAudioPort> _impl;
};

}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
