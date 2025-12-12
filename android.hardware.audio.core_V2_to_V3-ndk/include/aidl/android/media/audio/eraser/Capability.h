/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash d0f24b98624bc07be92c5dc38302f967c522ff14 -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/staging/android/media/audio/eraser/Capability.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.eraser.types/1 system/hardware/interfaces/media/aidl_api/android.media.audio.eraser.types/1/android/media/audio/eraser/Capability.aidl
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
#include <aidl/android/media/audio/common/AudioChannelLayout.h>
#include <aidl/android/media/audio/eraser/ClassifierCapability.h>
#include <aidl/android/media/audio/eraser/Mode.h>
#include <aidl/android/media/audio/eraser/RemixerCapability.h>
#include <aidl/android/media/audio/eraser/SeparatorCapability.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::eraser {
class ClassifierCapability;
class RemixerCapability;
class SeparatorCapability;
}  // namespace aidl::android::media::audio::eraser
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace eraser {
class Capability {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::vector<int32_t> sampleRates;
  std::vector<::aidl::android::media::audio::common::AudioChannelLayout> channelLayouts;
  std::vector<::aidl::android::media::audio::eraser::Mode> modes;
  ::aidl::android::media::audio::eraser::SeparatorCapability separator;
  ::aidl::android::media::audio::eraser::ClassifierCapability classifier;
  ::aidl::android::media::audio::eraser::RemixerCapability remixer;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const Capability& _rhs) const {
    return std::tie(sampleRates, channelLayouts, modes, separator, classifier, remixer) == std::tie(_rhs.sampleRates, _rhs.channelLayouts, _rhs.modes, _rhs.separator, _rhs.classifier, _rhs.remixer);
  }
  inline bool operator<(const Capability& _rhs) const {
    return std::tie(sampleRates, channelLayouts, modes, separator, classifier, remixer) < std::tie(_rhs.sampleRates, _rhs.channelLayouts, _rhs.modes, _rhs.separator, _rhs.classifier, _rhs.remixer);
  }
  inline bool operator!=(const Capability& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const Capability& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const Capability& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const Capability& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "Capability{";
    _aidl_os << "sampleRates: " << ::android::internal::ToString(sampleRates);
    _aidl_os << ", channelLayouts: " << ::android::internal::ToString(channelLayouts);
    _aidl_os << ", modes: " << ::android::internal::ToString(modes);
    _aidl_os << ", separator: " << ::android::internal::ToString(separator);
    _aidl_os << ", classifier: " << ::android::internal::ToString(classifier);
    _aidl_os << ", remixer: " << ::android::internal::ToString(remixer);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
