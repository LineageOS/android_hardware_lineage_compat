/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 3 --hash bfeb16c941085370dc6b68bcd7aec2dbb9435f49 -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types_interface/1/preprocessed.aidl -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging/android/hardware/audio/effect/LoudnessEnhancer.cpp.d -h out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.effect-V3-ndk-source/gen/staging -Nhardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3 hardware/interfaces/audio/aidl/aidl_api/android.hardware.audio.effect/3/android/hardware/audio/effect/LoudnessEnhancer.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#include "aidl/android/hardware/audio/effect/LoudnessEnhancer.h"

#include <android/binder_parcel_utils.h>
#include <aidl/android/media/audio/eraser/BnEraserCallback.h>
#include <aidl/android/media/audio/eraser/BpEraserCallback.h>
#include <aidl/android/media/audio/eraser/IEraserCallback.h>

namespace aidl {
namespace android {
namespace hardware {
namespace audio {
namespace effect {
const char* LoudnessEnhancer::descriptor = "android.hardware.audio.effect.LoudnessEnhancer";

binder_status_t LoudnessEnhancer::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendor: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendor>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendor>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case gainMb: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<gainMb>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<gainMb>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t LoudnessEnhancer::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendor: return ::ndk::AParcel_writeData(_parcel, get<vendor>());
  case gainMb: return ::ndk::AParcel_writeData(_parcel, get<gainMb>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

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
const char* LoudnessEnhancer::Id::descriptor = "android.hardware.audio.effect.LoudnessEnhancer.Id";

binder_status_t LoudnessEnhancer::Id::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case vendorExtensionTag: {
    ::aidl::android::hardware::audio::effect::VendorExtension _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::VendorExtension>) {
      set<vendorExtensionTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<vendorExtensionTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case commonTag: {
    ::aidl::android::hardware::audio::effect::LoudnessEnhancer::Tag _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::aidl::android::hardware::audio::effect::LoudnessEnhancer::Tag>) {
      set<commonTag>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<commonTag>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t LoudnessEnhancer::Id::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case vendorExtensionTag: return ::ndk::AParcel_writeData(_parcel, get<vendorExtensionTag>());
  case commonTag: return ::ndk::AParcel_writeData(_parcel, get<commonTag>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
}  // namespace aidl
