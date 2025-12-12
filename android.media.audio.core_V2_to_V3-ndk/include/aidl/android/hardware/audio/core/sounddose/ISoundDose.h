/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash afe48eb8c7a7bb735723924a74ed31e0368f57bd -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose-V3-ndk-source/gen/staging/android/hardware/audio/core/sounddose/ISoundDose.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.core.sounddose-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core.sounddose/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.core.sounddose/3/android/hardware/audio/core/sounddose/ISoundDose.aidl
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
#include <android/binder_ibinder.h>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/audio/core/sounddose/ISoundDose.h>
#include <aidl/android/media/audio/common/AudioDevice.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::common {
class AudioDevice;
}  // namespace aidl::android::media::audio::common
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace core {
namespace sounddose {
class ISoundDoseDelegator;

class ISoundDose : public ::ndk::ICInterface {
public:
  typedef ISoundDoseDelegator DefaultDelegator;
  static const char* descriptor;
  ISoundDose();
  virtual ~ISoundDose();

  class IHalSoundDoseCallbackDelegator;

  class IHalSoundDoseCallback : public ::ndk::ICInterface {
  public:
    typedef IHalSoundDoseCallbackDelegator DefaultDelegator;
    static const char* descriptor;
    IHalSoundDoseCallback();
    virtual ~IHalSoundDoseCallback();

    class MelRecord {
    public:
      typedef std::false_type fixed_size;
      static const char* descriptor;

      std::vector<float> melValues;
      int64_t timestamp = 0L;

      binder_status_t readFromParcel(const AParcel* parcel);
      binder_status_t writeToParcel(AParcel* parcel) const;

      inline bool operator==(const MelRecord& _rhs) const {
        return std::tie(melValues, timestamp) == std::tie(_rhs.melValues, _rhs.timestamp);
      }
      inline bool operator<(const MelRecord& _rhs) const {
        return std::tie(melValues, timestamp) < std::tie(_rhs.melValues, _rhs.timestamp);
      }
      inline bool operator!=(const MelRecord& _rhs) const {
        return !(*this == _rhs);
      }
      inline bool operator>(const MelRecord& _rhs) const {
        return _rhs < *this;
      }
      inline bool operator>=(const MelRecord& _rhs) const {
        return !(*this < _rhs);
      }
      inline bool operator<=(const MelRecord& _rhs) const {
        return !(_rhs < *this);
      }

      static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
      inline std::string toString() const {
        std::ostringstream _aidl_os;
        _aidl_os << "MelRecord{";
        _aidl_os << "melValues: " << ::android::internal::ToString(melValues);
        _aidl_os << ", timestamp: " << ::android::internal::ToString(timestamp);
        _aidl_os << "}";
        return _aidl_os.str();
      }
    };
    static inline const int32_t version = 3;
    static inline const std::string hash = "afe48eb8c7a7bb735723924a74ed31e0368f57bd";
    static constexpr uint32_t TRANSACTION_onMomentaryExposureWarning = FIRST_CALL_TRANSACTION + 0;
    static constexpr uint32_t TRANSACTION_onNewMelValues = FIRST_CALL_TRANSACTION + 1;

    static std::shared_ptr<IHalSoundDoseCallback> fromBinder(const ::ndk::SpAIBinder& binder);
    static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IHalSoundDoseCallback>& instance);
    static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IHalSoundDoseCallback>* instance);
    static bool setDefaultImpl(const std::shared_ptr<IHalSoundDoseCallback>& impl);
    static const std::shared_ptr<IHalSoundDoseCallback>& getDefaultImpl();
    virtual ::ndk::ScopedAStatus onMomentaryExposureWarning(float in_currentDbA, const ::aidl::android::media::audio::common::AudioDevice& in_audioDevice) = 0;
    virtual ::ndk::ScopedAStatus onNewMelValues(const ::aidl::android::hardware::audio::core::sounddose::ISoundDose::IHalSoundDoseCallback::MelRecord& in_melRecord, const ::aidl::android::media::audio::common::AudioDevice& in_audioDevice) = 0;
    virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
    virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
  private:
    static std::shared_ptr<IHalSoundDoseCallback> default_impl;
  };
  class IHalSoundDoseCallbackDefault : public IHalSoundDoseCallback {
  public:
    ::ndk::ScopedAStatus onMomentaryExposureWarning(float in_currentDbA, const ::aidl::android::media::audio::common::AudioDevice& in_audioDevice) override;
    ::ndk::ScopedAStatus onNewMelValues(const ::aidl::android::hardware::audio::core::sounddose::ISoundDose::IHalSoundDoseCallback::MelRecord& in_melRecord, const ::aidl::android::media::audio::common::AudioDevice& in_audioDevice) override;
    ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
    ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
    ::ndk::SpAIBinder asBinder() override;
    bool isRemote() override;
  };
  class BpHalSoundDoseCallback : public ::ndk::BpCInterface<IHalSoundDoseCallback> {
  public:
    explicit BpHalSoundDoseCallback(const ::ndk::SpAIBinder& binder);
    virtual ~BpHalSoundDoseCallback();

    ::ndk::ScopedAStatus onMomentaryExposureWarning(float in_currentDbA, const ::aidl::android::media::audio::common::AudioDevice& in_audioDevice) override;
    ::ndk::ScopedAStatus onNewMelValues(const ::aidl::android::hardware::audio::core::sounddose::ISoundDose::IHalSoundDoseCallback::MelRecord& in_melRecord, const ::aidl::android::media::audio::common::AudioDevice& in_audioDevice) override;
    ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
    ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
    int32_t _aidl_cached_version = -1;
    std::string _aidl_cached_hash = "-1";
    std::mutex _aidl_cached_hash_mutex;
  };
  class BnHalSoundDoseCallback : public ::ndk::BnCInterface<IHalSoundDoseCallback> {
  public:
    BnHalSoundDoseCallback();
    virtual ~BnHalSoundDoseCallback();
    ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
    ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
  protected:
    ::ndk::SpAIBinder createBinder() override;
  private:
  };
  enum : int32_t { DEFAULT_MAX_RS2 = 100 };
  enum : int32_t { MIN_RS2 = 80 };
  static inline const int32_t version = 3;
  static inline const std::string hash = "afe48eb8c7a7bb735723924a74ed31e0368f57bd";
  static constexpr uint32_t TRANSACTION_setOutputRs2UpperBound = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getOutputRs2UpperBound = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_registerSoundDoseCallback = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<ISoundDose> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ISoundDose>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ISoundDose>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ISoundDose>& impl);
  static const std::shared_ptr<ISoundDose>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus setOutputRs2UpperBound(float in_rs2ValueDbA) = 0;
  virtual ::ndk::ScopedAStatus getOutputRs2UpperBound(float* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus registerSoundDoseCallback(const std::shared_ptr<::aidl::android::hardware::audio::core::sounddose::ISoundDose::IHalSoundDoseCallback>& in_callback) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<ISoundDose> default_impl;
};
class ISoundDoseDefault : public ISoundDose {
public:
  ::ndk::ScopedAStatus setOutputRs2UpperBound(float in_rs2ValueDbA) override;
  ::ndk::ScopedAStatus getOutputRs2UpperBound(float* _aidl_return) override;
  ::ndk::ScopedAStatus registerSoundDoseCallback(const std::shared_ptr<::aidl::android::hardware::audio::core::sounddose::ISoundDose::IHalSoundDoseCallback>& in_callback) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace sounddose
}  // namespace core
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
