/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioFlag.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioFlag.aidl
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
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
enum class AudioFlag : int32_t {
  NONE = 0,
  AUDIBILITY_ENFORCED = 1,
  SCO = 4,
  BEACON = 8,
  HW_AV_SYNC = 16,
  HW_HOTWORD = 32,
  BYPASS_INTERRUPTION_POLICY = 64,
  BYPASS_MUTE = 128,
  LOW_LATENCY = 256,
  DEEP_BUFFER = 512,
  NO_MEDIA_PROJECTION = 1024,
  MUTE_HAPTIC = 2048,
  NO_SYSTEM_CAPTURE = 4096,
  CAPTURE_PRIVATE = 8192,
  CONTENT_SPATIALIZED = 16384,
  NEVER_SPATIALIZE = 32768,
  CALL_REDIRECTION = 65536,
};

}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
[[nodiscard]] static inline std::string toString(AudioFlag val) {
  switch(val) {
  case AudioFlag::NONE:
    return "NONE";
  case AudioFlag::AUDIBILITY_ENFORCED:
    return "AUDIBILITY_ENFORCED";
  case AudioFlag::SCO:
    return "SCO";
  case AudioFlag::BEACON:
    return "BEACON";
  case AudioFlag::HW_AV_SYNC:
    return "HW_AV_SYNC";
  case AudioFlag::HW_HOTWORD:
    return "HW_HOTWORD";
  case AudioFlag::BYPASS_INTERRUPTION_POLICY:
    return "BYPASS_INTERRUPTION_POLICY";
  case AudioFlag::BYPASS_MUTE:
    return "BYPASS_MUTE";
  case AudioFlag::LOW_LATENCY:
    return "LOW_LATENCY";
  case AudioFlag::DEEP_BUFFER:
    return "DEEP_BUFFER";
  case AudioFlag::NO_MEDIA_PROJECTION:
    return "NO_MEDIA_PROJECTION";
  case AudioFlag::MUTE_HAPTIC:
    return "MUTE_HAPTIC";
  case AudioFlag::NO_SYSTEM_CAPTURE:
    return "NO_SYSTEM_CAPTURE";
  case AudioFlag::CAPTURE_PRIVATE:
    return "CAPTURE_PRIVATE";
  case AudioFlag::CONTENT_SPATIALIZED:
    return "CONTENT_SPATIALIZED";
  case AudioFlag::NEVER_SPATIALIZE:
    return "NEVER_SPATIALIZE";
  case AudioFlag::CALL_REDIRECTION:
    return "CALL_REDIRECTION";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::audio::common::AudioFlag, 17> enum_values<aidl::android::media::audio::common::AudioFlag> = {
  aidl::android::media::audio::common::AudioFlag::NONE,
  aidl::android::media::audio::common::AudioFlag::AUDIBILITY_ENFORCED,
  aidl::android::media::audio::common::AudioFlag::SCO,
  aidl::android::media::audio::common::AudioFlag::BEACON,
  aidl::android::media::audio::common::AudioFlag::HW_AV_SYNC,
  aidl::android::media::audio::common::AudioFlag::HW_HOTWORD,
  aidl::android::media::audio::common::AudioFlag::BYPASS_INTERRUPTION_POLICY,
  aidl::android::media::audio::common::AudioFlag::BYPASS_MUTE,
  aidl::android::media::audio::common::AudioFlag::LOW_LATENCY,
  aidl::android::media::audio::common::AudioFlag::DEEP_BUFFER,
  aidl::android::media::audio::common::AudioFlag::NO_MEDIA_PROJECTION,
  aidl::android::media::audio::common::AudioFlag::MUTE_HAPTIC,
  aidl::android::media::audio::common::AudioFlag::NO_SYSTEM_CAPTURE,
  aidl::android::media::audio::common::AudioFlag::CAPTURE_PRIVATE,
  aidl::android::media::audio::common::AudioFlag::CONTENT_SPATIALIZED,
  aidl::android::media::audio::common::AudioFlag::NEVER_SPATIALIZE,
  aidl::android::media::audio::common::AudioFlag::CALL_REDIRECTION,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
