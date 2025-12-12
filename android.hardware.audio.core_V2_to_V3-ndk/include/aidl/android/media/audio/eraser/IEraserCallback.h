/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 1 --hash d0f24b98624bc07be92c5dc38302f967c522ff14 -t --stability vintf --min_sdk_version current -pout/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.common.types_interface/4/preprocessed.aidl --ninja -d out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/staging/android/media/audio/eraser/IEraserCallback.cpp.d -h out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/include/staging -o out/soong/.intermediates/system/hardware/interfaces/media/android.media.audio.eraser.types-V1-ndk-source/gen/staging -Nsystem/hardware/interfaces/media/aidl_api/android.media.audio.eraser.types/1 system/hardware/interfaces/media/aidl_api/android.media.audio.eraser.types/1/android/media/audio/eraser/IEraserCallback.aidl
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
#include <aidl/android/media/audio/eraser/ClassificationMetadataList.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::media::audio::eraser {
class ClassificationMetadataList;
}  // namespace aidl::android::media::audio::eraser
namespace aidl {
namespace android {
namespace media {
namespace audio {
namespace eraser {
class IEraserCallbackDelegator;

class IEraserCallback : public ::ndk::ICInterface {
public:
  typedef IEraserCallbackDelegator DefaultDelegator;
  static const char* descriptor;
  IEraserCallback();
  virtual ~IEraserCallback();

  static inline const int32_t version = 1;
  static inline const std::string hash = "d0f24b98624bc07be92c5dc38302f967c522ff14";
  static constexpr uint32_t TRANSACTION_onClassifierUpdate = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IEraserCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IEraserCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IEraserCallback>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IEraserCallback>& impl);
  static const std::shared_ptr<IEraserCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onClassifierUpdate(int32_t in_soundSourceId, const ::aidl::android::media::audio::eraser::ClassificationMetadataList& in_metadata) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IEraserCallback> default_impl;
};
class IEraserCallbackDefault : public IEraserCallback {
public:
  ::ndk::ScopedAStatus onClassifierUpdate(int32_t in_soundSourceId, const ::aidl::android::media::audio::eraser::ClassificationMetadataList& in_metadata) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace eraser
}  // namespace audio
}  // namespace media
}  // namespace android
}  // namespace aidl
