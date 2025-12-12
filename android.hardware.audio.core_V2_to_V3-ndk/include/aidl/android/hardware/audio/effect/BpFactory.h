/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash bfeb16c941085370dc6b68bcd7aec2dbb9435f49 -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types_interface/1/preprocessed.aidl -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging/android/hardware/audio/effect/IFactory.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3/android/hardware/audio/effect/IFactory.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include "aidl/android/hardware/audio/effect/IFactory.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
class BpFactory : public ::ndk::BpCInterface<IFactory> {
public:
  explicit BpFactory(const ::ndk::SpAIBinder& binder);
  virtual ~BpFactory();

  ::ndk::ScopedAStatus queryEffects(const std::optional<::aidl::android::media::audio::common::AudioUuid>& in_type, const std::optional<::aidl::android::media::audio::common::AudioUuid>& in_implementation, const std::optional<::aidl::android::media::audio::common::AudioUuid>& in_proxy, std::vector<::aidl::android::hardware::audio::effect::Descriptor>* _aidl_return) override;
  ::ndk::ScopedAStatus queryProcessing(const std::optional<::aidl::android::hardware::audio::effect::Processing::Type>& in_type, std::vector<::aidl::android::hardware::audio::effect::Processing>* _aidl_return) override;
  ::ndk::ScopedAStatus createEffect(const ::aidl::android::media::audio::common::AudioUuid& in_implUuid, std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>* _aidl_return) override;
  ::ndk::ScopedAStatus destroyEffect(const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_handle) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
