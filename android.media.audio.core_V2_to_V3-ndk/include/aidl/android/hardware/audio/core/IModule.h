/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash eb5f1f5af402830af56b50eb66bdd60fd8cc774e -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose_interface/3/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging/android/hardware/audio/core/IModule.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core/3/android/hardware/audio/core/IModule.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_enums.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/audio/common/SinkMetadata.h>
#include <aidl/android/hardware/audio/common/SourceMetadata.h>
#include <aidl/android/hardware/audio/core/AudioPatch.h>
#include <aidl/android/hardware/audio/core/AudioRoute.h>
#include <aidl/android/hardware/audio/core/IBluetooth.h>
#include <aidl/android/hardware/audio/core/IBluetoothA2dp.h>
#include <aidl/android/hardware/audio/core/IBluetoothLe.h>
#include <aidl/android/hardware/audio/core/IModule.h>
#include <aidl/android/hardware/audio/core/IStreamCallback.h>
#include <aidl/android/hardware/audio/core/IStreamIn.h>
#include <aidl/android/hardware/audio/core/IStreamOut.h>
#include <aidl/android/hardware/audio/core/IStreamOutEventCallback.h>
#include <aidl/android/hardware/audio/core/ITelephony.h>
#include <aidl/android/hardware/audio/core/ModuleDebug.h>
#include <aidl/android/hardware/audio/core/StreamDescriptor.h>
#include <aidl/android/hardware/audio/core/VendorParameter.h>
#include <aidl/android/hardware/audio/core/sounddose/ISoundDose.h>
#include <aidl/android/hardware/audio/effect/IEffect.h>
#include <aidl/android/media/audio/common/AudioMMapPolicyInfo.h>
#include <aidl/android/media/audio/common/AudioMMapPolicyType.h>
#include <aidl/android/media/audio/common/AudioMode.h>
#include <aidl/android/media/audio/common/AudioOffloadInfo.h>
#include <aidl/android/media/audio/common/AudioPort.h>
#include <aidl/android/media/audio/common/AudioPortConfig.h>
#include <aidl/android/media/audio/common/MicrophoneInfo.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::audio::common {
class SinkMetadata;
class SourceMetadata;
}  // namespace aidl::android::hardware::audio::common
namespace aidl::android::hardware::audio::core {
class AudioPatch;
class AudioRoute;
class IBluetooth;
class IBluetoothA2dp;
class IBluetoothLe;
class IStreamCallback;
class IStreamIn;
class IStreamOut;
class IStreamOutEventCallback;
class ITelephony;
class ModuleDebug;
class StreamDescriptor;
class VendorParameter;
}  // namespace aidl::android::hardware::audio::core
namespace aidl::android::hardware::audio::core::sounddose {
class ISoundDose;
}  // namespace aidl::android::hardware::audio::core::sounddose
namespace aidl::android::hardware::audio::effect {
class IEffect;
}  // namespace aidl::android::hardware::audio::effect
namespace aidl::android::media::audio::common {
class AudioMMapPolicyInfo;
class AudioOffloadInfo;
class AudioPort;
class AudioPortConfig;
class MicrophoneInfo;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
class IModuleDelegator;

class IModule : public ::ndk::ICInterface {
public:
  typedef IModuleDelegator DefaultDelegator;
  static const char* descriptor;
  IModule();
  virtual ~IModule();

  class OpenInputStreamArguments {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t portConfigId = 0;
    ::aidl::android::hardware::audio::common::SinkMetadata sinkMetadata;
    int64_t bufferSizeFrames = 0L;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const OpenInputStreamArguments& _rhs) const {
      return std::tie(portConfigId, sinkMetadata, bufferSizeFrames) == std::tie(_rhs.portConfigId, _rhs.sinkMetadata, _rhs.bufferSizeFrames);
    }
    inline bool operator<(const OpenInputStreamArguments& _rhs) const {
      return std::tie(portConfigId, sinkMetadata, bufferSizeFrames) < std::tie(_rhs.portConfigId, _rhs.sinkMetadata, _rhs.bufferSizeFrames);
    }
    inline bool operator!=(const OpenInputStreamArguments& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const OpenInputStreamArguments& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const OpenInputStreamArguments& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const OpenInputStreamArguments& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "OpenInputStreamArguments{";
      _aidl_os << "portConfigId: " << ::android::internal::ToString(portConfigId);
      _aidl_os << ", sinkMetadata: " << ::android::internal::ToString(sinkMetadata);
      _aidl_os << ", bufferSizeFrames: " << ::android::internal::ToString(bufferSizeFrames);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class OpenInputStreamReturn {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::shared_ptr<::aidl::android::hardware::audio::core::IStreamIn> stream;
    ::aidl::android::hardware::audio::core::StreamDescriptor desc;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const OpenInputStreamReturn& _rhs) const {
      return std::tie(stream, desc) == std::tie(_rhs.stream, _rhs.desc);
    }
    inline bool operator<(const OpenInputStreamReturn& _rhs) const {
      return std::tie(stream, desc) < std::tie(_rhs.stream, _rhs.desc);
    }
    inline bool operator!=(const OpenInputStreamReturn& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const OpenInputStreamReturn& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const OpenInputStreamReturn& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const OpenInputStreamReturn& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "OpenInputStreamReturn{";
      _aidl_os << "stream: " << ::android::internal::ToString(stream);
      _aidl_os << ", desc: " << ::android::internal::ToString(desc);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class OpenOutputStreamArguments {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t portConfigId = 0;
    ::aidl::android::hardware::audio::common::SourceMetadata sourceMetadata;
    std::optional<::aidl::android::media::audio::common::AudioOffloadInfo> offloadInfo;
    int64_t bufferSizeFrames = 0L;
    std::shared_ptr<::aidl::android::hardware::audio::core::IStreamCallback> callback;
    std::shared_ptr<::aidl::android::hardware::audio::core::IStreamOutEventCallback> eventCallback;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const OpenOutputStreamArguments& _rhs) const {
      return std::tie(portConfigId, sourceMetadata, offloadInfo, bufferSizeFrames, callback, eventCallback) == std::tie(_rhs.portConfigId, _rhs.sourceMetadata, _rhs.offloadInfo, _rhs.bufferSizeFrames, _rhs.callback, _rhs.eventCallback);
    }
    inline bool operator<(const OpenOutputStreamArguments& _rhs) const {
      return std::tie(portConfigId, sourceMetadata, offloadInfo, bufferSizeFrames, callback, eventCallback) < std::tie(_rhs.portConfigId, _rhs.sourceMetadata, _rhs.offloadInfo, _rhs.bufferSizeFrames, _rhs.callback, _rhs.eventCallback);
    }
    inline bool operator!=(const OpenOutputStreamArguments& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const OpenOutputStreamArguments& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const OpenOutputStreamArguments& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const OpenOutputStreamArguments& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "OpenOutputStreamArguments{";
      _aidl_os << "portConfigId: " << ::android::internal::ToString(portConfigId);
      _aidl_os << ", sourceMetadata: " << ::android::internal::ToString(sourceMetadata);
      _aidl_os << ", offloadInfo: " << ::android::internal::ToString(offloadInfo);
      _aidl_os << ", bufferSizeFrames: " << ::android::internal::ToString(bufferSizeFrames);
      _aidl_os << ", callback: " << ::android::internal::ToString(callback);
      _aidl_os << ", eventCallback: " << ::android::internal::ToString(eventCallback);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class OpenOutputStreamReturn {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::shared_ptr<::aidl::android::hardware::audio::core::IStreamOut> stream;
    ::aidl::android::hardware::audio::core::StreamDescriptor desc;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const OpenOutputStreamReturn& _rhs) const {
      return std::tie(stream, desc) == std::tie(_rhs.stream, _rhs.desc);
    }
    inline bool operator<(const OpenOutputStreamReturn& _rhs) const {
      return std::tie(stream, desc) < std::tie(_rhs.stream, _rhs.desc);
    }
    inline bool operator!=(const OpenOutputStreamReturn& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const OpenOutputStreamReturn& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const OpenOutputStreamReturn& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const OpenOutputStreamReturn& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "OpenOutputStreamReturn{";
      _aidl_os << "stream: " << ::android::internal::ToString(stream);
      _aidl_os << ", desc: " << ::android::internal::ToString(desc);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class SupportedPlaybackRateFactors {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    float minSpeed = 0.000000f;
    float maxSpeed = 0.000000f;
    float minPitch = 0.000000f;
    float maxPitch = 0.000000f;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const SupportedPlaybackRateFactors& _rhs) const {
      return std::tie(minSpeed, maxSpeed, minPitch, maxPitch) == std::tie(_rhs.minSpeed, _rhs.maxSpeed, _rhs.minPitch, _rhs.maxPitch);
    }
    inline bool operator<(const SupportedPlaybackRateFactors& _rhs) const {
      return std::tie(minSpeed, maxSpeed, minPitch, maxPitch) < std::tie(_rhs.minSpeed, _rhs.maxSpeed, _rhs.minPitch, _rhs.maxPitch);
    }
    inline bool operator!=(const SupportedPlaybackRateFactors& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const SupportedPlaybackRateFactors& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const SupportedPlaybackRateFactors& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const SupportedPlaybackRateFactors& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "SupportedPlaybackRateFactors{";
      _aidl_os << "minSpeed: " << ::android::internal::ToString(minSpeed);
      _aidl_os << ", maxSpeed: " << ::android::internal::ToString(maxSpeed);
      _aidl_os << ", minPitch: " << ::android::internal::ToString(minPitch);
      _aidl_os << ", maxPitch: " << ::android::internal::ToString(maxPitch);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class ScreenRotation : int32_t {
    DEG_0 = 0,
    DEG_90 = 1,
    DEG_180 = 2,
    DEG_270 = 3,
  };

  enum : int32_t { DEFAULT_AAUDIO_MIXER_BURST_COUNT = 2 };
  enum : int32_t { DEFAULT_AAUDIO_HARDWARE_BURST_MIN_DURATION_US = 1000 };
  static inline const int32_t version = 3;
  static inline const std::string hash = "eb5f1f5af402830af56b50eb66bdd60fd8cc774e";
  static constexpr uint32_t TRANSACTION_setModuleDebug = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getTelephony = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getBluetooth = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getBluetoothA2dp = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getBluetoothLe = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_connectExternalDevice = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_disconnectExternalDevice = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getAudioPatches = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_getAudioPort = FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getAudioPortConfigs = FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getAudioPorts = FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getAudioRoutes = FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_getAudioRoutesForAudioPort = FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_openInputStream = FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_openOutputStream = FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_getSupportedPlaybackRateFactors = FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_setAudioPatch = FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_setAudioPortConfig = FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_resetAudioPatch = FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_resetAudioPortConfig = FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_getMasterMute = FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_setMasterMute = FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_getMasterVolume = FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_setMasterVolume = FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_getMicMute = FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_setMicMute = FIRST_CALL_TRANSACTION + 25;
  static constexpr uint32_t TRANSACTION_getMicrophones = FIRST_CALL_TRANSACTION + 26;
  static constexpr uint32_t TRANSACTION_updateAudioMode = FIRST_CALL_TRANSACTION + 27;
  static constexpr uint32_t TRANSACTION_updateScreenRotation = FIRST_CALL_TRANSACTION + 28;
  static constexpr uint32_t TRANSACTION_updateScreenState = FIRST_CALL_TRANSACTION + 29;
  static constexpr uint32_t TRANSACTION_getSoundDose = FIRST_CALL_TRANSACTION + 30;
  static constexpr uint32_t TRANSACTION_generateHwAvSyncId = FIRST_CALL_TRANSACTION + 31;
  static constexpr uint32_t TRANSACTION_getVendorParameters = FIRST_CALL_TRANSACTION + 32;
  static constexpr uint32_t TRANSACTION_setVendorParameters = FIRST_CALL_TRANSACTION + 33;
  static constexpr uint32_t TRANSACTION_addDeviceEffect = FIRST_CALL_TRANSACTION + 34;
  static constexpr uint32_t TRANSACTION_removeDeviceEffect = FIRST_CALL_TRANSACTION + 35;
  static constexpr uint32_t TRANSACTION_getMmapPolicyInfos = FIRST_CALL_TRANSACTION + 36;
  static constexpr uint32_t TRANSACTION_supportsVariableLatency = FIRST_CALL_TRANSACTION + 37;
  static constexpr uint32_t TRANSACTION_getAAudioMixerBurstCount = FIRST_CALL_TRANSACTION + 38;
  static constexpr uint32_t TRANSACTION_getAAudioHardwareBurstMinUsec = FIRST_CALL_TRANSACTION + 39;
  static constexpr uint32_t TRANSACTION_prepareToDisconnectExternalDevice = FIRST_CALL_TRANSACTION + 40;

  static std::shared_ptr<IModule> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IModule>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IModule>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IModule>& impl);
  static const std::shared_ptr<IModule>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus setModuleDebug(const ::aidl::android::hardware::audio::core::ModuleDebug& in_debug) = 0;
  virtual ::ndk::ScopedAStatus getTelephony(std::shared_ptr<::aidl::android::hardware::audio::core::ITelephony>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getBluetooth(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetooth>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getBluetoothA2dp(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetoothA2dp>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getBluetoothLe(std::shared_ptr<::aidl::android::hardware::audio::core::IBluetoothLe>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus connectExternalDevice(const ::aidl::android::media::audio::common::AudioPort& in_templateIdAndAdditionalData, ::aidl::android::media::audio::common::AudioPort* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus disconnectExternalDevice(int32_t in_portId) = 0;
  virtual ::ndk::ScopedAStatus getAudioPatches(std::vector<::aidl::android::hardware::audio::core::AudioPatch>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAudioPort(int32_t in_portId, ::aidl::android::media::audio::common::AudioPort* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAudioPortConfigs(std::vector<::aidl::android::media::audio::common::AudioPortConfig>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAudioPorts(std::vector<::aidl::android::media::audio::common::AudioPort>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAudioRoutes(std::vector<::aidl::android::hardware::audio::core::AudioRoute>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAudioRoutesForAudioPort(int32_t in_portId, std::vector<::aidl::android::hardware::audio::core::AudioRoute>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus openInputStream(const ::aidl::android::hardware::audio::core::IModule::OpenInputStreamArguments& in_args, ::aidl::android::hardware::audio::core::IModule::OpenInputStreamReturn* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus openOutputStream(const ::aidl::android::hardware::audio::core::IModule::OpenOutputStreamArguments& in_args, ::aidl::android::hardware::audio::core::IModule::OpenOutputStreamReturn* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getSupportedPlaybackRateFactors(::aidl::android::hardware::audio::core::IModule::SupportedPlaybackRateFactors* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setAudioPatch(const ::aidl::android::hardware::audio::core::AudioPatch& in_requested, ::aidl::android::hardware::audio::core::AudioPatch* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setAudioPortConfig(const ::aidl::android::media::audio::common::AudioPortConfig& in_requested, ::aidl::android::media::audio::common::AudioPortConfig* out_suggested, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus resetAudioPatch(int32_t in_patchId) = 0;
  virtual ::ndk::ScopedAStatus resetAudioPortConfig(int32_t in_portConfigId) = 0;
  virtual ::ndk::ScopedAStatus getMasterMute(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setMasterMute(bool in_mute) = 0;
  virtual ::ndk::ScopedAStatus getMasterVolume(float* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setMasterVolume(float in_volume) = 0;
  virtual ::ndk::ScopedAStatus getMicMute(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setMicMute(bool in_mute) = 0;
  virtual ::ndk::ScopedAStatus getMicrophones(std::vector<::aidl::android::media::audio::common::MicrophoneInfo>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus updateAudioMode(::aidl::android::media::audio::common::AudioMode in_mode) = 0;
  virtual ::ndk::ScopedAStatus updateScreenRotation(::aidl::android::hardware::audio::core::IModule::ScreenRotation in_rotation) = 0;
  virtual ::ndk::ScopedAStatus updateScreenState(bool in_isTurnedOn) = 0;
  virtual ::ndk::ScopedAStatus getSoundDose(std::shared_ptr<::aidl::android::hardware::audio::core::sounddose::ISoundDose>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus generateHwAvSyncId(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getVendorParameters(const std::vector<std::string>& in_ids, std::vector<::aidl::android::hardware::audio::core::VendorParameter>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setVendorParameters(const std::vector<::aidl::android::hardware::audio::core::VendorParameter>& in_parameters, bool in_async) = 0;
  virtual ::ndk::ScopedAStatus addDeviceEffect(int32_t in_portConfigId, const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) = 0;
  virtual ::ndk::ScopedAStatus removeDeviceEffect(int32_t in_portConfigId, const std::shared_ptr<::aidl::android::hardware::audio::effect::IEffect>& in_effect) = 0;
  virtual ::ndk::ScopedAStatus getMmapPolicyInfos(::aidl::android::media::audio::common::AudioMMapPolicyType in_mmapPolicyType, std::vector<::aidl::android::media::audio::common::AudioMMapPolicyInfo>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus supportsVariableLatency(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAAudioMixerBurstCount(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAAudioHardwareBurstMinUsec(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus prepareToDisconnectExternalDevice(int32_t in_portId) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IModule> default_impl;
};
class IModuleDefault : public IModule {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
[[nodiscard]] static inline std::string toString(IModule::ScreenRotation val) {
  switch(val) {
  case IModule::ScreenRotation::DEG_0:
    return "DEG_0";
  case IModule::ScreenRotation::DEG_90:
    return "DEG_90";
  case IModule::ScreenRotation::DEG_180:
    return "DEG_180";
  case IModule::ScreenRotation::DEG_270:
    return "DEG_270";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::core::IModule::ScreenRotation, 4> enum_values<aidl::android::hardware::audio::core::IModule::ScreenRotation> = {
  aidl::android::hardware::audio::core::IModule::ScreenRotation::DEG_0,
  aidl::android::hardware::audio::core::IModule::ScreenRotation::DEG_90,
  aidl::android::hardware::audio::core::IModule::ScreenRotation::DEG_180,
  aidl::android::hardware::audio::core::IModule::ScreenRotation::DEG_270,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
