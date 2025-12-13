/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/LatencyMode.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/LatencyMode.aidl
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
namespace hardware {
namespace bluetooth {
namespace audio {
enum class LatencyMode : int32_t {
  UNKNOWN = 0,
  LOW_LATENCY = 1,
  FREE = 2,
  DYNAMIC_SPATIAL_AUDIO_SOFTWARE = 3,
  DYNAMIC_SPATIAL_AUDIO_HARDWARE = 4,
};

}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(LatencyMode val) {
  switch(val) {
  case LatencyMode::UNKNOWN:
    return "UNKNOWN";
  case LatencyMode::LOW_LATENCY:
    return "LOW_LATENCY";
  case LatencyMode::FREE:
    return "FREE";
  case LatencyMode::DYNAMIC_SPATIAL_AUDIO_SOFTWARE:
    return "DYNAMIC_SPATIAL_AUDIO_SOFTWARE";
  case LatencyMode::DYNAMIC_SPATIAL_AUDIO_HARDWARE:
    return "DYNAMIC_SPATIAL_AUDIO_HARDWARE";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::LatencyMode, 5> enum_values<aidl::android::hardware::bluetooth::audio::LatencyMode> = {
  aidl::android::hardware::bluetooth::audio::LatencyMode::UNKNOWN,
  aidl::android::hardware::bluetooth::audio::LatencyMode::LOW_LATENCY,
  aidl::android::hardware::bluetooth::audio::LatencyMode::FREE,
  aidl::android::hardware::bluetooth::audio::LatencyMode::DYNAMIC_SPATIAL_AUDIO_SOFTWARE,
  aidl::android::hardware::bluetooth::audio::LatencyMode::DYNAMIC_SPATIAL_AUDIO_HARDWARE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
