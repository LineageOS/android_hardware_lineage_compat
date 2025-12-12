/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/AudioProductStrategyType.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/AudioProductStrategyType.aidl
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
enum class AudioProductStrategyType : int8_t {
  SYS_RESERVED_NONE = -1,
  MEDIA = 0,
  PHONE = 1,
  SONIFICATION = 2,
  SONIFICATION_RESPECTFUL = 3,
  DTMF = 4,
  ENFORCED_AUDIBLE = 5,
  TRANSMITTED_THROUGH_SPEAKER = 6,
  ACCESSIBILITY = 7,
  SYS_RESERVED_REROUTING = 8,
  SYS_RESERVED_CALL_ASSISTANT = 9,
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
[[nodiscard]] static inline std::string toString(AudioProductStrategyType val) {
  switch(val) {
  case AudioProductStrategyType::SYS_RESERVED_NONE:
    return "SYS_RESERVED_NONE";
  case AudioProductStrategyType::MEDIA:
    return "MEDIA";
  case AudioProductStrategyType::PHONE:
    return "PHONE";
  case AudioProductStrategyType::SONIFICATION:
    return "SONIFICATION";
  case AudioProductStrategyType::SONIFICATION_RESPECTFUL:
    return "SONIFICATION_RESPECTFUL";
  case AudioProductStrategyType::DTMF:
    return "DTMF";
  case AudioProductStrategyType::ENFORCED_AUDIBLE:
    return "ENFORCED_AUDIBLE";
  case AudioProductStrategyType::TRANSMITTED_THROUGH_SPEAKER:
    return "TRANSMITTED_THROUGH_SPEAKER";
  case AudioProductStrategyType::ACCESSIBILITY:
    return "ACCESSIBILITY";
  case AudioProductStrategyType::SYS_RESERVED_REROUTING:
    return "SYS_RESERVED_REROUTING";
  case AudioProductStrategyType::SYS_RESERVED_CALL_ASSISTANT:
    return "SYS_RESERVED_CALL_ASSISTANT";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::media::audio::common::AudioProductStrategyType, 11> enum_values<aidl::android::media::audio::common::AudioProductStrategyType> = {
  aidl::android::media::audio::common::AudioProductStrategyType::SYS_RESERVED_NONE,
  aidl::android::media::audio::common::AudioProductStrategyType::MEDIA,
  aidl::android::media::audio::common::AudioProductStrategyType::PHONE,
  aidl::android::media::audio::common::AudioProductStrategyType::SONIFICATION,
  aidl::android::media::audio::common::AudioProductStrategyType::SONIFICATION_RESPECTFUL,
  aidl::android::media::audio::common::AudioProductStrategyType::DTMF,
  aidl::android::media::audio::common::AudioProductStrategyType::ENFORCED_AUDIBLE,
  aidl::android::media::audio::common::AudioProductStrategyType::TRANSMITTED_THROUGH_SPEAKER,
  aidl::android::media::audio::common::AudioProductStrategyType::ACCESSIBILITY,
  aidl::android::media::audio::common::AudioProductStrategyType::SYS_RESERVED_REROUTING,
  aidl::android::media::audio::common::AudioProductStrategyType::SYS_RESERVED_CALL_ASSISTANT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
