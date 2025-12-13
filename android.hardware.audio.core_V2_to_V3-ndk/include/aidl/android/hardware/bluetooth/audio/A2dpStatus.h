/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/A2dpStatus.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/A2dpStatus.aidl
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
enum class A2dpStatus : int8_t {
  OK = 0,
  BAD_LENGTH = 17,
  BAD_PAYLOAD_FORMAT = 24,
  INVALID_CODEC_TYPE = -63,
  NOT_SUPPORTED_CODEC_TYPE = -62,
  INVALID_SAMPLING_FREQUENCY = -61,
  NOT_SUPPORTED_SAMPLING_FREQUENCY = -60,
  INVALID_CHANNEL_MODE = -59,
  NOT_SUPPORTED_CHANNEL_MODE = -58,
  INVALID_SUBBANDS = -57,
  NOT_SUPPORTED_SUBBANDS = -56,
  INVALID_ALLOCATION_METHOD = -55,
  NOT_SUPPORTED_ALLOCATION_METHOD = -54,
  INVALID_MINIMUM_BITPOOL_VALUE = -53,
  NOT_SUPPORTED_MINIMUM_BITPOOL_VALUE = -52,
  INVALID_MAXIMUM_BITPOOL_VALUE = -51,
  NOT_SUPPORTED_MAXIMUM_BITPOOL_VALUE = -50,
  NOT_SUPPORTED_VBR = -45,
  NOT_SUPPORTED_BIT_RATE = -43,
  INVALID_OBJECT_TYPE = -42,
  NOT_SUPPORTED_OBJECT_TYPE = -41,
  INVALID_CHANNELS = -40,
  NOT_SUPPORTED_CHANNELS = -39,
  INVALID_BLOCK_LENGTH = -35,
  INVALID_CODEC_PARAMETER = -30,
  NOT_SUPPORTED_CODEC_PARAMETER = -29,
  INVALID_DRC = -28,
  NOT_SUPPORTED_DRC = -27,
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
[[nodiscard]] static inline std::string toString(A2dpStatus val) {
  switch(val) {
  case A2dpStatus::OK:
    return "OK";
  case A2dpStatus::BAD_LENGTH:
    return "BAD_LENGTH";
  case A2dpStatus::BAD_PAYLOAD_FORMAT:
    return "BAD_PAYLOAD_FORMAT";
  case A2dpStatus::INVALID_CODEC_TYPE:
    return "INVALID_CODEC_TYPE";
  case A2dpStatus::NOT_SUPPORTED_CODEC_TYPE:
    return "NOT_SUPPORTED_CODEC_TYPE";
  case A2dpStatus::INVALID_SAMPLING_FREQUENCY:
    return "INVALID_SAMPLING_FREQUENCY";
  case A2dpStatus::NOT_SUPPORTED_SAMPLING_FREQUENCY:
    return "NOT_SUPPORTED_SAMPLING_FREQUENCY";
  case A2dpStatus::INVALID_CHANNEL_MODE:
    return "INVALID_CHANNEL_MODE";
  case A2dpStatus::NOT_SUPPORTED_CHANNEL_MODE:
    return "NOT_SUPPORTED_CHANNEL_MODE";
  case A2dpStatus::INVALID_SUBBANDS:
    return "INVALID_SUBBANDS";
  case A2dpStatus::NOT_SUPPORTED_SUBBANDS:
    return "NOT_SUPPORTED_SUBBANDS";
  case A2dpStatus::INVALID_ALLOCATION_METHOD:
    return "INVALID_ALLOCATION_METHOD";
  case A2dpStatus::NOT_SUPPORTED_ALLOCATION_METHOD:
    return "NOT_SUPPORTED_ALLOCATION_METHOD";
  case A2dpStatus::INVALID_MINIMUM_BITPOOL_VALUE:
    return "INVALID_MINIMUM_BITPOOL_VALUE";
  case A2dpStatus::NOT_SUPPORTED_MINIMUM_BITPOOL_VALUE:
    return "NOT_SUPPORTED_MINIMUM_BITPOOL_VALUE";
  case A2dpStatus::INVALID_MAXIMUM_BITPOOL_VALUE:
    return "INVALID_MAXIMUM_BITPOOL_VALUE";
  case A2dpStatus::NOT_SUPPORTED_MAXIMUM_BITPOOL_VALUE:
    return "NOT_SUPPORTED_MAXIMUM_BITPOOL_VALUE";
  case A2dpStatus::NOT_SUPPORTED_VBR:
    return "NOT_SUPPORTED_VBR";
  case A2dpStatus::NOT_SUPPORTED_BIT_RATE:
    return "NOT_SUPPORTED_BIT_RATE";
  case A2dpStatus::INVALID_OBJECT_TYPE:
    return "INVALID_OBJECT_TYPE";
  case A2dpStatus::NOT_SUPPORTED_OBJECT_TYPE:
    return "NOT_SUPPORTED_OBJECT_TYPE";
  case A2dpStatus::INVALID_CHANNELS:
    return "INVALID_CHANNELS";
  case A2dpStatus::NOT_SUPPORTED_CHANNELS:
    return "NOT_SUPPORTED_CHANNELS";
  case A2dpStatus::INVALID_BLOCK_LENGTH:
    return "INVALID_BLOCK_LENGTH";
  case A2dpStatus::INVALID_CODEC_PARAMETER:
    return "INVALID_CODEC_PARAMETER";
  case A2dpStatus::NOT_SUPPORTED_CODEC_PARAMETER:
    return "NOT_SUPPORTED_CODEC_PARAMETER";
  case A2dpStatus::INVALID_DRC:
    return "INVALID_DRC";
  case A2dpStatus::NOT_SUPPORTED_DRC:
    return "NOT_SUPPORTED_DRC";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::A2dpStatus, 28> enum_values<aidl::android::hardware::bluetooth::audio::A2dpStatus> = {
  aidl::android::hardware::bluetooth::audio::A2dpStatus::OK,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::BAD_LENGTH,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::BAD_PAYLOAD_FORMAT,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_CODEC_TYPE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_CODEC_TYPE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_SAMPLING_FREQUENCY,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_SAMPLING_FREQUENCY,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_CHANNEL_MODE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_CHANNEL_MODE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_SUBBANDS,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_SUBBANDS,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_ALLOCATION_METHOD,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_ALLOCATION_METHOD,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_MINIMUM_BITPOOL_VALUE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_MINIMUM_BITPOOL_VALUE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_MAXIMUM_BITPOOL_VALUE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_MAXIMUM_BITPOOL_VALUE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_VBR,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_BIT_RATE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_OBJECT_TYPE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_OBJECT_TYPE,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_CHANNELS,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_CHANNELS,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_BLOCK_LENGTH,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_CODEC_PARAMETER,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_CODEC_PARAMETER,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::INVALID_DRC,
  aidl::android::hardware::bluetooth::audio::A2dpStatus::NOT_SUPPORTED_DRC,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
