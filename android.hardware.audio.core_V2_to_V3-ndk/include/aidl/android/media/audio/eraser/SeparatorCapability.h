/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash d0f24b98624bc07be92c5dc38302f967c522ff14 -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/staging/android/media/audio/eraser/SeparatorCapability.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.eraser.types/1 system/hardware/interfaces/media/aidl_api/android.media.audio.eraser.types/1/android/media/audio/eraser/SeparatorCapability.aidl
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
namespace eraser {
class SeparatorCapability {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  bool supported = false;
  int32_t maxSoundSources = 4;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const SeparatorCapability& _rhs) const {
    return std::tie(supported, maxSoundSources) == std::tie(_rhs.supported, _rhs.maxSoundSources);
  }
  inline bool operator<(const SeparatorCapability& _rhs) const {
    return std::tie(supported, maxSoundSources) < std::tie(_rhs.supported, _rhs.maxSoundSources);
  }
  inline bool operator!=(const SeparatorCapability& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const SeparatorCapability& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const SeparatorCapability& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const SeparatorCapability& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  enum : int32_t { MIN_SOUND_SOURCE_SUPPORTED = 2 };
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "SeparatorCapability{";
    _aidl_os << "supported: " << ::android::internal::ToString(supported);
    _aidl_os << ", maxSoundSources: " << ::android::internal::ToString(maxSoundSources);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
