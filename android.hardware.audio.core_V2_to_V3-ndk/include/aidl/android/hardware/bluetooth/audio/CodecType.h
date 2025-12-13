/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/CodecType.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/CodecType.aidl
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
enum class CodecType : int32_t {
  UNKNOWN = 0,
  SBC = 1,
  AAC = 2,
  APTX = 3,
  APTX_HD = 4,
  LDAC = 5,
  LC3 = 6,
  VENDOR = 7,
  APTX_ADAPTIVE = 8,
  OPUS = 9,
  APTX_ADAPTIVE_LE = 10,
  APTX_ADAPTIVE_LEX = 11,
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
[[nodiscard]] static inline std::string toString(CodecType val) {
  switch(val) {
  case CodecType::UNKNOWN:
    return "UNKNOWN";
  case CodecType::SBC:
    return "SBC";
  case CodecType::AAC:
    return "AAC";
  case CodecType::APTX:
    return "APTX";
  case CodecType::APTX_HD:
    return "APTX_HD";
  case CodecType::LDAC:
    return "LDAC";
  case CodecType::LC3:
    return "LC3";
  case CodecType::VENDOR:
    return "VENDOR";
  case CodecType::APTX_ADAPTIVE:
    return "APTX_ADAPTIVE";
  case CodecType::OPUS:
    return "OPUS";
  case CodecType::APTX_ADAPTIVE_LE:
    return "APTX_ADAPTIVE_LE";
  case CodecType::APTX_ADAPTIVE_LEX:
    return "APTX_ADAPTIVE_LEX";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::CodecType, 12> enum_values<aidl::android::hardware::bluetooth::audio::CodecType> = {
  aidl::android::hardware::bluetooth::audio::CodecType::UNKNOWN,
  aidl::android::hardware::bluetooth::audio::CodecType::SBC,
  aidl::android::hardware::bluetooth::audio::CodecType::AAC,
  aidl::android::hardware::bluetooth::audio::CodecType::APTX,
  aidl::android::hardware::bluetooth::audio::CodecType::APTX_HD,
  aidl::android::hardware::bluetooth::audio::CodecType::LDAC,
  aidl::android::hardware::bluetooth::audio::CodecType::LC3,
  aidl::android::hardware::bluetooth::audio::CodecType::VENDOR,
  aidl::android::hardware::bluetooth::audio::CodecType::APTX_ADAPTIVE,
  aidl::android::hardware::bluetooth::audio::CodecType::OPUS,
  aidl::android::hardware::bluetooth::audio::CodecType::APTX_ADAPTIVE_LE,
  aidl::android::hardware::bluetooth::audio::CodecType::APTX_ADAPTIVE_LEX,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
