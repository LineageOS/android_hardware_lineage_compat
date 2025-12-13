/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/AptxAdaptiveChannelMode.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/AptxAdaptiveChannelMode.aidl
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
enum class AptxAdaptiveChannelMode : int32_t {
  JOINT_STEREO = 0,
  MONO = 1,
  DUAL_MONO = 2,
  TWS_STEREO = 4,
  UNKNOWN = 255,
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
[[nodiscard]] static inline std::string toString(AptxAdaptiveChannelMode val) {
  switch(val) {
  case AptxAdaptiveChannelMode::JOINT_STEREO:
    return "JOINT_STEREO";
  case AptxAdaptiveChannelMode::MONO:
    return "MONO";
  case AptxAdaptiveChannelMode::DUAL_MONO:
    return "DUAL_MONO";
  case AptxAdaptiveChannelMode::TWS_STEREO:
    return "TWS_STEREO";
  case AptxAdaptiveChannelMode::UNKNOWN:
    return "UNKNOWN";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode, 5> enum_values<aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode> = {
  aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode::JOINT_STEREO,
  aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode::MONO,
  aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode::DUAL_MONO,
  aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode::TWS_STEREO,
  aidl::android::hardware::bluetooth::audio::AptxAdaptiveChannelMode::UNKNOWN,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
