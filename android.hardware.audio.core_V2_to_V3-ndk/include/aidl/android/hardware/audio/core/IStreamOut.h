/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IStreamOut.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IStreamOut.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/android/hardware/audio/common/AudioOffloadMetadata.h>
#include <aidl/android/hardware/audio/common/SourceMetadata.h>
#include <aidl/android/hardware/audio/core/IStreamCommon.h>
#include <aidl/android/media/audio/common/AudioDualMonoMode.h>
#include <aidl/android/media/audio/common/AudioLatencyMode.h>
#include <aidl/android/media/audio/common/AudioPlaybackRate.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::audio::common {
class AudioOffloadMetadata;
class SourceMetadata;
}  // namespace aidl::android::hardware::audio::common
namespace aidl::android::hardware::audio::core {
class IStreamCommon;
}  // namespace aidl::android::hardware::audio::core
namespace aidl::android::media::audio::common {
class AudioPlaybackRate;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class IStreamOutDelegator;

class IStreamOut : public ::ndk::ICInterface {
public:
  typedef IStreamOutDelegator DefaultDelegator;
  static const char* descriptor;
  IStreamOut();
  virtual ~IStreamOut();

  enum : int32_t { HW_VOLUME_MIN = 0 };
  enum : int32_t { HW_VOLUME_MAX = 1 };
  enum : int32_t { AUDIO_DESCRIPTION_MIX_LEVEL_MAX = 48 };
  static inline const int32_t version = 3;
  static inline const std::string hash = "eb5f1f5af402830af56b50eb66bdd60fd8cc774e";
  static constexpr uint32_t TRANSACTION_getStreamCommon = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_updateMetadata = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_updateOffloadMetadata = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getHwVolume = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_setHwVolume = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getAudioDescriptionMixLevel = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_setAudioDescriptionMixLevel = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getDualMonoMode = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_setDualMonoMode = FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getRecommendedLatencyModes = FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_setLatencyMode = FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getPlaybackRateParameters = FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_setPlaybackRateParameters = FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_selectPresentation = FIRST_CALL_TRANSACTION + 13;

  static std::shared_ptr<IStreamOut> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IStreamOut>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IStreamOut>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IStreamOut>& impl);
  static const std::shared_ptr<IStreamOut>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getStreamCommon(std::shared_ptr<::aidl::android::hardware::audio::core::IStreamCommon>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus updateMetadata(const ::aidl::android::hardware::audio::common::SourceMetadata& in_sourceMetadata) = 0;
  virtual ::ndk::ScopedAStatus updateOffloadMetadata(const ::aidl::android::hardware::audio::common::AudioOffloadMetadata& in_offloadMetadata) = 0;
  virtual ::ndk::ScopedAStatus getHwVolume(std::vector<float>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setHwVolume(const std::vector<float>& in_channelVolumes) = 0;
  virtual ::ndk::ScopedAStatus getAudioDescriptionMixLevel(float* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setAudioDescriptionMixLevel(float in_leveldB) = 0;
  virtual ::ndk::ScopedAStatus getDualMonoMode(::aidl::android::media::audio::common::AudioDualMonoMode* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setDualMonoMode(::aidl::android::media::audio::common::AudioDualMonoMode in_mode) = 0;
  virtual ::ndk::ScopedAStatus getRecommendedLatencyModes(std::vector<::aidl::android::media::audio::common::AudioLatencyMode>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setLatencyMode(::aidl::android::media::audio::common::AudioLatencyMode in_mode) = 0;
  virtual ::ndk::ScopedAStatus getPlaybackRateParameters(::aidl::android::media::audio::common::AudioPlaybackRate* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setPlaybackRateParameters(const ::aidl::android::media::audio::common::AudioPlaybackRate& in_playbackRate) = 0;
  virtual ::ndk::ScopedAStatus selectPresentation(int32_t in_presentationId, int32_t in_programId) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IStreamOut> default_impl;
};
class IStreamOutDefault : public IStreamOut {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
