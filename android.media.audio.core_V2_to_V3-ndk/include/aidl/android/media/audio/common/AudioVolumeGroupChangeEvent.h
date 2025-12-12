/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioVolumeGroupChangeEvent.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioVolumeGroupChangeEvent.aidl
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
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
class AudioVolumeGroupChangeEvent {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t groupId = 0;
  int32_t volumeIndex = 0;
  bool muted = false;
  int32_t flags = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const AudioVolumeGroupChangeEvent& _rhs) const {
    return std::tie(groupId, volumeIndex, muted, flags) == std::tie(_rhs.groupId, _rhs.volumeIndex, _rhs.muted, _rhs.flags);
  }
  inline bool operator<(const AudioVolumeGroupChangeEvent& _rhs) const {
    return std::tie(groupId, volumeIndex, muted, flags) < std::tie(_rhs.groupId, _rhs.volumeIndex, _rhs.muted, _rhs.flags);
  }
  inline bool operator!=(const AudioVolumeGroupChangeEvent& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const AudioVolumeGroupChangeEvent& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const AudioVolumeGroupChangeEvent& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const AudioVolumeGroupChangeEvent& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  enum : int32_t { VOLUME_FLAG_SHOW_UI = 1 };
  enum : int32_t { VOLUME_FLAG_ALLOW_RINGER_MODES = 2 };
  enum : int32_t { VOLUME_FLAG_PLAY_SOUND = 4 };
  enum : int32_t { VOLUME_FLAG_REMOVE_SOUND_AND_VIBRATE = 8 };
  enum : int32_t { VOLUME_FLAG_VIBRATE = 16 };
  enum : int32_t { VOLUME_FLAG_FIXED_VOLUME = 32 };
  enum : int32_t { VOLUME_FLAG_BLUETOOTH_ABS_VOLUME = 64 };
  enum : int32_t { VOLUME_FLAG_SHOW_SILENT_HINT = 128 };
  enum : int32_t { VOLUME_FLAG_HDMI_SYSTEM_AUDIO_VOLUME = 256 };
  enum : int32_t { VOLUME_FLAG_ACTIVE_MEDIA_ONLY = 512 };
  enum : int32_t { VOLUME_FLAG_SHOW_UI_WARNINGS = 1024 };
  enum : int32_t { VOLUME_FLAG_SHOW_VIBRATE_HINT = 2048 };
  enum : int32_t { VOLUME_FLAG_FROM_KEY = 4096 };
  enum : int32_t { VOLUME_FLAG_ABSOLUTE_VOLUME = 8192 };
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "AudioVolumeGroupChangeEvent{";
    _aidl_os << "groupId: " << ::android::internal::ToString(groupId);
    _aidl_os << ", volumeIndex: " << ::android::internal::ToString(volumeIndex);
    _aidl_os << ", muted: " << ::android::internal::ToString(muted);
    _aidl_os << ", flags: " << ::android::internal::ToString(flags);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
