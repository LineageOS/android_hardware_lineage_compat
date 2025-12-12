/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioPolicyForceUse.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioPolicyForceUse.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#include "aidl/android/media/audio/common/AudioPolicyForceUse.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
const char* AudioPolicyForceUse::descriptor = "android.media.audio.common.AudioPolicyForceUse";

binder_status_t AudioPolicyForceUse::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case forMedia: {
    ::aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioPolicyForceUse::MediaDeviceCategory>) {
      set<forMedia>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<forMedia>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case forCommunication: {
    ::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory>) {
      set<forCommunication>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<forCommunication>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case forRecord: {
    ::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory>) {
      set<forRecord>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<forRecord>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case forVibrateRinging: {
    ::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioPolicyForceUse::CommunicationDeviceCategory>) {
      set<forVibrateRinging>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<forVibrateRinging>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case dock: {
    ::aidl::android::media::audio::common::AudioPolicyForceUse::DockType _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioPolicyForceUse::DockType>) {
      set<dock>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<dock>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case systemSounds: {
    bool _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<bool>) {
      set<systemSounds>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<systemSounds>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case hdmiSystemAudio: {
    bool _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<bool>) {
      set<hdmiSystemAudio>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<hdmiSystemAudio>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case encodedSurround: {
    ::aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::media::audio::common::AudioPolicyForceUse::EncodedSurroundConfig>) {
      set<encodedSurround>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<encodedSurround>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t AudioPolicyForceUse::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case forMedia: return ::ndk::AParcel_writeData(_parcel, get<forMedia>());
  case forCommunication: return ::ndk::AParcel_writeData(_parcel, get<forCommunication>());
  case forRecord: return ::ndk::AParcel_writeData(_parcel, get<forRecord>());
  case forVibrateRinging: return ::ndk::AParcel_writeData(_parcel, get<forVibrateRinging>());
  case dock: return ::ndk::AParcel_writeData(_parcel, get<dock>());
  case systemSounds: return ::ndk::AParcel_writeData(_parcel, get<systemSounds>());
  case hdmiSystemAudio: return ::ndk::AParcel_writeData(_parcel, get<hdmiSystemAudio>());
  case encodedSurround: return ::ndk::AParcel_writeData(_parcel, get<encodedSurround>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
