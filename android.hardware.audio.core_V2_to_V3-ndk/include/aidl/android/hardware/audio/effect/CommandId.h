/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash bfeb16c941085370dc6b68bcd7aec2dbb9435f49 -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types_interface/1/preprocessed.aidl -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging/android/hardware/audio/effect/CommandId.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3/android/hardware/audio/effect/CommandId.aidl
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
namespace audio {
namespace effect {
enum class CommandId : int32_t {
  START = 0,
  STOP = 1,
  RESET = 2,
  VENDOR_COMMAND_0 = 256,
  VENDOR_COMMAND_1 = 257,
  VENDOR_COMMAND_2 = 258,
  VENDOR_COMMAND_3 = 259,
  VENDOR_COMMAND_4 = 260,
  VENDOR_COMMAND_5 = 261,
  VENDOR_COMMAND_6 = 262,
  VENDOR_COMMAND_7 = 263,
  VENDOR_COMMAND_8 = 264,
  VENDOR_COMMAND_9 = 265,
};

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
[[nodiscard]] static inline std::string toString(CommandId val) {
  switch(val) {
  case CommandId::START:
    return "START";
  case CommandId::STOP:
    return "STOP";
  case CommandId::RESET:
    return "RESET";
  case CommandId::VENDOR_COMMAND_0:
    return "VENDOR_COMMAND_0";
  case CommandId::VENDOR_COMMAND_1:
    return "VENDOR_COMMAND_1";
  case CommandId::VENDOR_COMMAND_2:
    return "VENDOR_COMMAND_2";
  case CommandId::VENDOR_COMMAND_3:
    return "VENDOR_COMMAND_3";
  case CommandId::VENDOR_COMMAND_4:
    return "VENDOR_COMMAND_4";
  case CommandId::VENDOR_COMMAND_5:
    return "VENDOR_COMMAND_5";
  case CommandId::VENDOR_COMMAND_6:
    return "VENDOR_COMMAND_6";
  case CommandId::VENDOR_COMMAND_7:
    return "VENDOR_COMMAND_7";
  case CommandId::VENDOR_COMMAND_8:
    return "VENDOR_COMMAND_8";
  case CommandId::VENDOR_COMMAND_9:
    return "VENDOR_COMMAND_9";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::audio::effect::CommandId, 13> enum_values<aidl::android::hardware::audio::effect::CommandId> = {
  aidl::android::hardware::audio::effect::CommandId::START,
  aidl::android::hardware::audio::effect::CommandId::STOP,
  aidl::android::hardware::audio::effect::CommandId::RESET,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_0,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_1,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_2,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_3,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_4,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_5,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_6,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_7,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_8,
  aidl::android::hardware::audio::effect::CommandId::VENDOR_COMMAND_9,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
