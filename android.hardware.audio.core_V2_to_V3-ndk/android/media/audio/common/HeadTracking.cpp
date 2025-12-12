/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 4 --hash af71e6ae2c6861fc2b09bb477e7285e6777cd41c -t --stability vintf --min_sdk_version 29 --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging/android/media/audio/common/HeadTracking.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types-V4-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4 system/hardware/interfaces/media/aidl_api/android.media.audio.common.types/4/android/media/audio/common/HeadTracking.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#include "aidl/android/media/audio/common/HeadTracking.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace common {
const char* HeadTracking::descriptor = "android.media.audio.common.HeadTracking";

binder_status_t HeadTracking::readFromParcel(const AParcel* _aidl_parcel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  int32_t _aidl_start_pos = AParcel_getDataPosition(_aidl_parcel);
  int32_t _aidl_parcelable_size = 0;
  _aidl_ret_status = AParcel_readInt32(_aidl_parcel, &_aidl_parcelable_size);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (_aidl_parcelable_size < 4) return STATUS_BAD_VALUE;
  if (_aidl_start_pos > INT32_MAX - _aidl_parcelable_size) return STATUS_BAD_VALUE;
  AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos + _aidl_parcelable_size);
  return _aidl_ret_status;
}
binder_status_t HeadTracking::writeToParcel(AParcel* _aidl_parcel) const {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_start_pos = AParcel_getDataPosition(_aidl_parcel);
  _aidl_ret_status = AParcel_writeInt32(_aidl_parcel, 0);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  int32_t _aidl_end_pos = AParcel_getDataPosition(_aidl_parcel);
  AParcel_setDataPosition(_aidl_parcel, _aidl_start_pos);
  AParcel_writeInt32(_aidl_parcel, _aidl_end_pos - _aidl_start_pos);
  AParcel_setDataPosition(_aidl_parcel, _aidl_end_pos);
  return _aidl_ret_status;
}

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
const char* HeadTracking::SensorData::descriptor = "android.media.audio.common.HeadTracking.SensorData";

binder_status_t HeadTracking::SensorData::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (static_cast<Tag>(_aidl_tag)) {
  case headToStage: {
    std::array<float, 6> _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readData(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::array<float, 6>>) {
      set<headToStage>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<headToStage>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t HeadTracking::SensorData::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = ::ndk::AParcel_writeData(_parcel, static_cast<int32_t>(getTag()));
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case headToStage: return ::ndk::AParcel_writeData(_parcel, get<headToStage>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace common
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
