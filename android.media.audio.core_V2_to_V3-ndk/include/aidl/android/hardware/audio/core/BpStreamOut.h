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

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class BpStreamOut : public ::ndk::BpCInterface<IStreamOut> {
public:
  explicit BpStreamOut(const ::ndk::SpAIBinder& binder);
  virtual ~BpStreamOut();

  ::ndk::ScopedAStatus getStreamCommon(std::shared_ptr<::aidl::android::hardware::audio::core::IStreamCommon>* _aidl_return) override;
  ::ndk::ScopedAStatus updateMetadata(const ::aidl::android::hardware::audio::common::SourceMetadata& in_sourceMetadata) override;
  ::ndk::ScopedAStatus updateOffloadMetadata(const ::aidl::android::hardware::audio::common::AudioOffloadMetadata& in_offloadMetadata) override;
  ::ndk::ScopedAStatus getHwVolume(std::vector<float>* _aidl_return) override;
  ::ndk::ScopedAStatus setHwVolume(const std::vector<float>& in_channelVolumes) override;
  ::ndk::ScopedAStatus getAudioDescriptionMixLevel(float* _aidl_return) override;
  ::ndk::ScopedAStatus setAudioDescriptionMixLevel(float in_leveldB) override;
  ::ndk::ScopedAStatus getDualMonoMode(::aidl::android::media::audio::common::AudioDualMonoMode* _aidl_return) override;
  ::ndk::ScopedAStatus setDualMonoMode(::aidl::android::media::audio::common::AudioDualMonoMode in_mode) override;
  ::ndk::ScopedAStatus getRecommendedLatencyModes(std::vector<::aidl::android::media::audio::common::AudioLatencyMode>* _aidl_return) override;
  ::ndk::ScopedAStatus setLatencyMode(::aidl::android::media::audio::common::AudioLatencyMode in_mode) override;
  ::ndk::ScopedAStatus getPlaybackRateParameters(::aidl::android::media::audio::common::AudioPlaybackRate* _aidl_return) override;
  ::ndk::ScopedAStatus setPlaybackRateParameters(const ::aidl::android::media::audio::common::AudioPlaybackRate& in_playbackRate) override;
  ::ndk::ScopedAStatus selectPresentation(int32_t in_presentationId, int32_t in_programId) override;
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
