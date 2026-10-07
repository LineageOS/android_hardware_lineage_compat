/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "BtAudioDispatcher"

#include <BluetoothAudioProviderFactory.h>
#include <android/binder_manager.h>
#include <log/log.h>

#include <mutex>
#include <string>

namespace aidl::android::hardware::bluetooth::audio {
namespace {

bool IsOffloadSessionType(SessionType session_type) {
    switch (session_type) {
        case SessionType::A2DP_HARDWARE_OFFLOAD_ENCODING_DATAPATH:
        case SessionType::A2DP_HARDWARE_OFFLOAD_DECODING_DATAPATH:
        case SessionType::LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH:
        case SessionType::LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH:
        case SessionType::LE_AUDIO_BROADCAST_HARDWARE_OFFLOAD_ENCODING_DATAPATH:
        case SessionType::LE_AUDIO_BROADCAST_HARDWARE_OFFLOAD_DECODING_DATAPATH:
        case SessionType::LE_AUDIO_PERIPHERAL_OFFLOAD_ENCODING_DATAPATH:
        case SessionType::LE_AUDIO_PERIPHERAL_OFFLOAD_DECODING_DATAPATH:
        case SessionType::HFP_HARDWARE_OFFLOAD_DATAPATH:
            return true;
        case SessionType::UNKNOWN:
        case SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH:
        case SessionType::A2DP_SOFTWARE_DECODING_DATAPATH:
        case SessionType::HEARING_AID_SOFTWARE_ENCODING_DATAPATH:
        case SessionType::LE_AUDIO_SOFTWARE_ENCODING_DATAPATH:
        case SessionType::LE_AUDIO_SOFTWARE_DECODING_DATAPATH:
        case SessionType::LE_AUDIO_BROADCAST_SOFTWARE_ENCODING_DATAPATH:
        case SessionType::LE_AUDIO_BROADCAST_SOFTWARE_DECODING_DATAPATH:
        case SessionType::HFP_SOFTWARE_ENCODING_DATAPATH:
        case SessionType::HFP_SOFTWARE_DECODING_DATAPATH:
            return false;
    }
    return false;
}

class DispatchingProviderFactory : public BnBluetoothAudioProviderFactory {
  public:
    ndk::ScopedAStatus openProvider(
            SessionType session_type,
            std::shared_ptr<IBluetoothAudioProvider>* _aidl_return) override {
        if (!IsOffloadSessionType(session_type)) {
            return software_->openProvider(session_type, _aidl_return);
        }
        auto offload = Offload();
        if (offload == nullptr) {
            *_aidl_return = nullptr;
            return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
        }
        return offload->openProvider(session_type, _aidl_return);
    }

    ndk::ScopedAStatus getProviderCapabilities(
            SessionType session_type, std::vector<AudioCapabilities>* _aidl_return) override {
        if (!IsOffloadSessionType(session_type)) {
            return software_->getProviderCapabilities(session_type, _aidl_return);
        }
        auto offload = Offload();
        if (offload == nullptr) {
            _aidl_return->clear();
            return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
        }
        return offload->getProviderCapabilities(session_type, _aidl_return);
    }

    ndk::ScopedAStatus getProviderInfo(SessionType session_type,
                                       std::optional<ProviderInfo>* _aidl_return) override {
        if (!IsOffloadSessionType(session_type)) {
            return software_->getProviderInfo(session_type, _aidl_return);
        }
        auto offload = Offload();
        if (offload == nullptr) {
            *_aidl_return = std::nullopt;
            return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
        }
        return offload->getProviderInfo(session_type, _aidl_return);
    }

  private:
    std::shared_ptr<IBluetoothAudioProviderFactory> Offload() {
        std::call_once(offload_once_, [this] {
            const std::string instance = std::string() + descriptor + "/offload";
            if (!AServiceManager_isDeclared(instance.c_str())) {
                ALOGI("%s is not declared", instance.c_str());
                return;
            }
            offload_ = IBluetoothAudioProviderFactory::fromBinder(
                    ndk::SpAIBinder(AServiceManager_waitForService(instance.c_str())));
            ALOGW_IF(offload_ == nullptr, "Could not get %s", instance.c_str());
        });
        return offload_;
    }

    const std::shared_ptr<BluetoothAudioProviderFactory> software_ =
            ndk::SharedRefBase::make<BluetoothAudioProviderFactory>();
    std::once_flag offload_once_;
    std::shared_ptr<IBluetoothAudioProviderFactory> offload_;
};

}  // namespace
}  // namespace aidl::android::hardware::bluetooth::audio

using ::aidl::android::hardware::bluetooth::audio::DispatchingProviderFactory;

extern "C" __attribute__((visibility("default"))) binder_status_t
createIBluetoothAudioProviderFactory() {
    auto factory = ndk::SharedRefBase::make<DispatchingProviderFactory>();
    const std::string instance =
            std::string() + DispatchingProviderFactory::descriptor + "/default";
    binder_status_t status =
            AServiceManager_addService(factory->asBinder().get(), instance.c_str());
    ALOGW_IF(status != STATUS_OK, "Could not register %s, status=%d", instance.c_str(), status);
    return status;
}
