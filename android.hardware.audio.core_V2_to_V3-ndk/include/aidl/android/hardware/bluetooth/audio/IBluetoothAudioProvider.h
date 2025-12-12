/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/IBluetoothAudioProvider.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/IBluetoothAudioProvider.aidl
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
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/bluetooth/audio/A2dpConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/A2dpConfigurationHint.h>
#include <aidl/android/hardware/bluetooth/audio/A2dpRemoteCapabilities.h>
#include <aidl/android/hardware/bluetooth/audio/A2dpStatus.h>
#include <aidl/android/hardware/bluetooth/audio/AudioConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/AudioContext.h>
#include <aidl/android/hardware/bluetooth/audio/BluetoothAudioStatus.h>
#include <aidl/android/hardware/bluetooth/audio/CodecId.h>
#include <aidl/android/hardware/bluetooth/audio/CodecParameters.h>
#include <aidl/android/hardware/bluetooth/audio/CodecSpecificCapabilitiesLtv.h>
#include <aidl/android/hardware/bluetooth/audio/ConfigurationFlags.h>
#include <aidl/android/hardware/bluetooth/audio/IBluetoothAudioPort.h>
#include <aidl/android/hardware/bluetooth/audio/IBluetoothAudioProvider.h>
#include <aidl/android/hardware/bluetooth/audio/LatencyMode.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioAseConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioBisConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioBroadcastConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/MetadataLtv.h>
#include <aidl/android/hardware/bluetooth/audio/Phy.h>
#include <aidl/android/hardware/common/fmq/MQDescriptor.h>
#include <aidl/android/hardware/common/fmq/SynchronizedReadWrite.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::bluetooth::audio {
class A2dpConfiguration;
class A2dpConfigurationHint;
class A2dpRemoteCapabilities;
class AudioContext;
class CodecParameters;
class ConfigurationFlags;
class IBluetoothAudioPort;
class LeAudioAseConfiguration;
class LeAudioBisConfiguration;
}  // namespace aidl::android::hardware::bluetooth::audio
namespace aidl::android::hardware::common::fmq {
template <typename T, typename Flavor>
class MQDescriptor;
}  // namespace aidl::android::hardware::common::fmq
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class IBluetoothAudioProviderDelegator;

class IBluetoothAudioProvider : public ::ndk::ICInterface {
public:
  typedef IBluetoothAudioProviderDelegator DefaultDelegator;
  static const char* descriptor;
  IBluetoothAudioProvider();
  virtual ~IBluetoothAudioProvider();

  class LeAudioDeviceCapabilities {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::bluetooth::audio::CodecId codecId;
    std::vector<::aidl::android::hardware::bluetooth::audio::CodecSpecificCapabilitiesLtv> codecSpecificCapabilities;
    std::optional<std::vector<uint8_t>> vendorCodecSpecificCapabilities;
    std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>> metadata;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioDeviceCapabilities& _rhs) const {
      return std::tie(codecId, codecSpecificCapabilities, vendorCodecSpecificCapabilities, metadata) == std::tie(_rhs.codecId, _rhs.codecSpecificCapabilities, _rhs.vendorCodecSpecificCapabilities, _rhs.metadata);
    }
    inline bool operator<(const LeAudioDeviceCapabilities& _rhs) const {
      return std::tie(codecId, codecSpecificCapabilities, vendorCodecSpecificCapabilities, metadata) < std::tie(_rhs.codecId, _rhs.codecSpecificCapabilities, _rhs.vendorCodecSpecificCapabilities, _rhs.metadata);
    }
    inline bool operator!=(const LeAudioDeviceCapabilities& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioDeviceCapabilities& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioDeviceCapabilities& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioDeviceCapabilities& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioDeviceCapabilities{";
      _aidl_os << "codecId: " << ::android::internal::ToString(codecId);
      _aidl_os << ", codecSpecificCapabilities: " << ::android::internal::ToString(codecSpecificCapabilities);
      _aidl_os << ", vendorCodecSpecificCapabilities: " << ::android::internal::ToString(vendorCodecSpecificCapabilities);
      _aidl_os << ", metadata: " << ::android::internal::ToString(metadata);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioDataPathConfiguration {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    class IsoDataPathConfiguration {
    public:
      typedef std::false_type fixed_size;
      static const char* descriptor;

      ::aidl::android::hardware::bluetooth::audio::CodecId codecId;
      bool isTransparent = false;
      int32_t controllerDelayUs = 0;
      std::optional<std::vector<uint8_t>> configuration;

      binder_status_t readFromParcel(const AParcel* parcel);
      binder_status_t writeToParcel(AParcel* parcel) const;

      inline bool operator==(const IsoDataPathConfiguration& _rhs) const {
        return std::tie(codecId, isTransparent, controllerDelayUs, configuration) == std::tie(_rhs.codecId, _rhs.isTransparent, _rhs.controllerDelayUs, _rhs.configuration);
      }
      inline bool operator<(const IsoDataPathConfiguration& _rhs) const {
        return std::tie(codecId, isTransparent, controllerDelayUs, configuration) < std::tie(_rhs.codecId, _rhs.isTransparent, _rhs.controllerDelayUs, _rhs.configuration);
      }
      inline bool operator!=(const IsoDataPathConfiguration& _rhs) const {
        return !(*this == _rhs);
      }
      inline bool operator>(const IsoDataPathConfiguration& _rhs) const {
        return _rhs < *this;
      }
      inline bool operator>=(const IsoDataPathConfiguration& _rhs) const {
        return !(*this < _rhs);
      }
      inline bool operator<=(const IsoDataPathConfiguration& _rhs) const {
        return !(_rhs < *this);
      }

      static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
      inline std::string toString() const {
        std::ostringstream _aidl_os;
        _aidl_os << "IsoDataPathConfiguration{";
        _aidl_os << "codecId: " << ::android::internal::ToString(codecId);
        _aidl_os << ", isTransparent: " << ::android::internal::ToString(isTransparent);
        _aidl_os << ", controllerDelayUs: " << ::android::internal::ToString(controllerDelayUs);
        _aidl_os << ", configuration: " << ::android::internal::ToString(configuration);
        _aidl_os << "}";
        return _aidl_os.str();
      }
    };
    class DataPathConfiguration {
    public:
      typedef std::false_type fixed_size;
      static const char* descriptor;

      std::optional<std::vector<uint8_t>> configuration;

      binder_status_t readFromParcel(const AParcel* parcel);
      binder_status_t writeToParcel(AParcel* parcel) const;

      inline bool operator==(const DataPathConfiguration& _rhs) const {
        return std::tie(configuration) == std::tie(_rhs.configuration);
      }
      inline bool operator<(const DataPathConfiguration& _rhs) const {
        return std::tie(configuration) < std::tie(_rhs.configuration);
      }
      inline bool operator!=(const DataPathConfiguration& _rhs) const {
        return !(*this == _rhs);
      }
      inline bool operator>(const DataPathConfiguration& _rhs) const {
        return _rhs < *this;
      }
      inline bool operator>=(const DataPathConfiguration& _rhs) const {
        return !(*this < _rhs);
      }
      inline bool operator<=(const DataPathConfiguration& _rhs) const {
        return !(_rhs < *this);
      }

      static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
      inline std::string toString() const {
        std::ostringstream _aidl_os;
        _aidl_os << "DataPathConfiguration{";
        _aidl_os << "configuration: " << ::android::internal::ToString(configuration);
        _aidl_os << "}";
        return _aidl_os.str();
      }
    };
    int32_t dataPathId = 0;
    ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration::DataPathConfiguration dataPathConfiguration;
    ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration::IsoDataPathConfiguration isoDataPathConfiguration;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioDataPathConfiguration& _rhs) const {
      return std::tie(dataPathId, dataPathConfiguration, isoDataPathConfiguration) == std::tie(_rhs.dataPathId, _rhs.dataPathConfiguration, _rhs.isoDataPathConfiguration);
    }
    inline bool operator<(const LeAudioDataPathConfiguration& _rhs) const {
      return std::tie(dataPathId, dataPathConfiguration, isoDataPathConfiguration) < std::tie(_rhs.dataPathId, _rhs.dataPathConfiguration, _rhs.isoDataPathConfiguration);
    }
    inline bool operator!=(const LeAudioDataPathConfiguration& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioDataPathConfiguration& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioDataPathConfiguration& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioDataPathConfiguration& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioDataPathConfiguration{";
      _aidl_os << "dataPathId: " << ::android::internal::ToString(dataPathId);
      _aidl_os << ", dataPathConfiguration: " << ::android::internal::ToString(dataPathConfiguration);
      _aidl_os << ", isoDataPathConfiguration: " << ::android::internal::ToString(isoDataPathConfiguration);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Framing : int8_t {
    UNFRAMED = 0,
    FRAMED = 1,
  };

  class LeAudioAseQosConfiguration {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t sduIntervalUs = 0;
    ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing framing = ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing(0);
    std::vector<::aidl::android::hardware::bluetooth::audio::Phy> phy;
    int32_t maxTransportLatencyMs = 0;
    int32_t maxSdu = 0;
    int32_t retransmissionNum = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioAseQosConfiguration& _rhs) const {
      return std::tie(sduIntervalUs, framing, phy, maxTransportLatencyMs, maxSdu, retransmissionNum) == std::tie(_rhs.sduIntervalUs, _rhs.framing, _rhs.phy, _rhs.maxTransportLatencyMs, _rhs.maxSdu, _rhs.retransmissionNum);
    }
    inline bool operator<(const LeAudioAseQosConfiguration& _rhs) const {
      return std::tie(sduIntervalUs, framing, phy, maxTransportLatencyMs, maxSdu, retransmissionNum) < std::tie(_rhs.sduIntervalUs, _rhs.framing, _rhs.phy, _rhs.maxTransportLatencyMs, _rhs.maxSdu, _rhs.retransmissionNum);
    }
    inline bool operator!=(const LeAudioAseQosConfiguration& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioAseQosConfiguration& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioAseQosConfiguration& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioAseQosConfiguration& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioAseQosConfiguration{";
      _aidl_os << "sduIntervalUs: " << ::android::internal::ToString(sduIntervalUs);
      _aidl_os << ", framing: " << ::android::internal::ToString(framing);
      _aidl_os << ", phy: " << ::android::internal::ToString(phy);
      _aidl_os << ", maxTransportLatencyMs: " << ::android::internal::ToString(maxTransportLatencyMs);
      _aidl_os << ", maxSdu: " << ::android::internal::ToString(maxSdu);
      _aidl_os << ", retransmissionNum: " << ::android::internal::ToString(retransmissionNum);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class Packing : int8_t {
    SEQUENTIAL = 0,
    INTERLEAVED = 1,
  };

  class LeAudioAseConfigurationSetting {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    class AseDirectionConfiguration {
    public:
      typedef std::false_type fixed_size;
      static const char* descriptor;

      ::aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration aseConfiguration;
      std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfiguration> qosConfiguration;
      std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration> dataPathConfiguration;

      binder_status_t readFromParcel(const AParcel* parcel);
      binder_status_t writeToParcel(AParcel* parcel) const;

      inline bool operator==(const AseDirectionConfiguration& _rhs) const {
        return std::tie(aseConfiguration, qosConfiguration, dataPathConfiguration) == std::tie(_rhs.aseConfiguration, _rhs.qosConfiguration, _rhs.dataPathConfiguration);
      }
      inline bool operator<(const AseDirectionConfiguration& _rhs) const {
        return std::tie(aseConfiguration, qosConfiguration, dataPathConfiguration) < std::tie(_rhs.aseConfiguration, _rhs.qosConfiguration, _rhs.dataPathConfiguration);
      }
      inline bool operator!=(const AseDirectionConfiguration& _rhs) const {
        return !(*this == _rhs);
      }
      inline bool operator>(const AseDirectionConfiguration& _rhs) const {
        return _rhs < *this;
      }
      inline bool operator>=(const AseDirectionConfiguration& _rhs) const {
        return !(*this < _rhs);
      }
      inline bool operator<=(const AseDirectionConfiguration& _rhs) const {
        return !(_rhs < *this);
      }

      static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
      inline std::string toString() const {
        std::ostringstream _aidl_os;
        _aidl_os << "AseDirectionConfiguration{";
        _aidl_os << "aseConfiguration: " << ::android::internal::ToString(aseConfiguration);
        _aidl_os << ", qosConfiguration: " << ::android::internal::ToString(qosConfiguration);
        _aidl_os << ", dataPathConfiguration: " << ::android::internal::ToString(dataPathConfiguration);
        _aidl_os << "}";
        return _aidl_os.str();
      }
    };
    ::aidl::android::hardware::bluetooth::audio::AudioContext audioContext;
    ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing packing = ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing(0);
    std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseConfigurationSetting::AseDirectionConfiguration>>> sinkAseConfiguration;
    std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseConfigurationSetting::AseDirectionConfiguration>>> sourceAseConfiguration;
    std::optional<::aidl::android::hardware::bluetooth::audio::ConfigurationFlags> flags;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioAseConfigurationSetting& _rhs) const {
      return std::tie(audioContext, packing, sinkAseConfiguration, sourceAseConfiguration, flags) == std::tie(_rhs.audioContext, _rhs.packing, _rhs.sinkAseConfiguration, _rhs.sourceAseConfiguration, _rhs.flags);
    }
    inline bool operator<(const LeAudioAseConfigurationSetting& _rhs) const {
      return std::tie(audioContext, packing, sinkAseConfiguration, sourceAseConfiguration, flags) < std::tie(_rhs.audioContext, _rhs.packing, _rhs.sinkAseConfiguration, _rhs.sourceAseConfiguration, _rhs.flags);
    }
    inline bool operator!=(const LeAudioAseConfigurationSetting& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioAseConfigurationSetting& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioAseConfigurationSetting& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioAseConfigurationSetting& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioAseConfigurationSetting{";
      _aidl_os << "audioContext: " << ::android::internal::ToString(audioContext);
      _aidl_os << ", packing: " << ::android::internal::ToString(packing);
      _aidl_os << ", sinkAseConfiguration: " << ::android::internal::ToString(sinkAseConfiguration);
      _aidl_os << ", sourceAseConfiguration: " << ::android::internal::ToString(sourceAseConfiguration);
      _aidl_os << ", flags: " << ::android::internal::ToString(flags);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioConfigurationRequirement {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    class AseDirectionRequirement {
    public:
      typedef std::false_type fixed_size;
      static const char* descriptor;

      ::aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration aseConfiguration;

      binder_status_t readFromParcel(const AParcel* parcel);
      binder_status_t writeToParcel(AParcel* parcel) const;

      inline bool operator==(const AseDirectionRequirement& _rhs) const {
        return std::tie(aseConfiguration) == std::tie(_rhs.aseConfiguration);
      }
      inline bool operator<(const AseDirectionRequirement& _rhs) const {
        return std::tie(aseConfiguration) < std::tie(_rhs.aseConfiguration);
      }
      inline bool operator!=(const AseDirectionRequirement& _rhs) const {
        return !(*this == _rhs);
      }
      inline bool operator>(const AseDirectionRequirement& _rhs) const {
        return _rhs < *this;
      }
      inline bool operator>=(const AseDirectionRequirement& _rhs) const {
        return !(*this < _rhs);
      }
      inline bool operator<=(const AseDirectionRequirement& _rhs) const {
        return !(_rhs < *this);
      }

      static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
      inline std::string toString() const {
        std::ostringstream _aidl_os;
        _aidl_os << "AseDirectionRequirement{";
        _aidl_os << "aseConfiguration: " << ::android::internal::ToString(aseConfiguration);
        _aidl_os << "}";
        return _aidl_os.str();
      }
    };
    ::aidl::android::hardware::bluetooth::audio::AudioContext audioContext;
    std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioConfigurationRequirement::AseDirectionRequirement>>> sinkAseRequirement;
    std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioConfigurationRequirement::AseDirectionRequirement>>> sourceAseRequirement;
    std::optional<::aidl::android::hardware::bluetooth::audio::ConfigurationFlags> flags;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioConfigurationRequirement& _rhs) const {
      return std::tie(audioContext, sinkAseRequirement, sourceAseRequirement, flags) == std::tie(_rhs.audioContext, _rhs.sinkAseRequirement, _rhs.sourceAseRequirement, _rhs.flags);
    }
    inline bool operator<(const LeAudioConfigurationRequirement& _rhs) const {
      return std::tie(audioContext, sinkAseRequirement, sourceAseRequirement, flags) < std::tie(_rhs.audioContext, _rhs.sinkAseRequirement, _rhs.sourceAseRequirement, _rhs.flags);
    }
    inline bool operator!=(const LeAudioConfigurationRequirement& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioConfigurationRequirement& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioConfigurationRequirement& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioConfigurationRequirement& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioConfigurationRequirement{";
      _aidl_os << "audioContext: " << ::android::internal::ToString(audioContext);
      _aidl_os << ", sinkAseRequirement: " << ::android::internal::ToString(sinkAseRequirement);
      _aidl_os << ", sourceAseRequirement: " << ::android::internal::ToString(sourceAseRequirement);
      _aidl_os << ", flags: " << ::android::internal::ToString(flags);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioAseQosConfigurationRequirement {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    class AseQosDirectionRequirement {
    public:
      typedef std::false_type fixed_size;
      static const char* descriptor;

      ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing framing = ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing(0);
      std::vector<::aidl::android::hardware::bluetooth::audio::Phy> preferredPhy;
      int32_t preferredRetransmissionNum = 0;
      int32_t maxTransportLatencyMs = 0;
      int32_t presentationDelayMinUs = 0;
      int32_t presentationDelayMaxUs = 0;
      int32_t preferredPresentationDelayMinUs = 0;
      int32_t preferredPresentationDelayMaxUs = 0;
      ::aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration aseConfiguration;

      binder_status_t readFromParcel(const AParcel* parcel);
      binder_status_t writeToParcel(AParcel* parcel) const;

      inline bool operator==(const AseQosDirectionRequirement& _rhs) const {
        return std::tie(framing, preferredPhy, preferredRetransmissionNum, maxTransportLatencyMs, presentationDelayMinUs, presentationDelayMaxUs, preferredPresentationDelayMinUs, preferredPresentationDelayMaxUs, aseConfiguration) == std::tie(_rhs.framing, _rhs.preferredPhy, _rhs.preferredRetransmissionNum, _rhs.maxTransportLatencyMs, _rhs.presentationDelayMinUs, _rhs.presentationDelayMaxUs, _rhs.preferredPresentationDelayMinUs, _rhs.preferredPresentationDelayMaxUs, _rhs.aseConfiguration);
      }
      inline bool operator<(const AseQosDirectionRequirement& _rhs) const {
        return std::tie(framing, preferredPhy, preferredRetransmissionNum, maxTransportLatencyMs, presentationDelayMinUs, presentationDelayMaxUs, preferredPresentationDelayMinUs, preferredPresentationDelayMaxUs, aseConfiguration) < std::tie(_rhs.framing, _rhs.preferredPhy, _rhs.preferredRetransmissionNum, _rhs.maxTransportLatencyMs, _rhs.presentationDelayMinUs, _rhs.presentationDelayMaxUs, _rhs.preferredPresentationDelayMinUs, _rhs.preferredPresentationDelayMaxUs, _rhs.aseConfiguration);
      }
      inline bool operator!=(const AseQosDirectionRequirement& _rhs) const {
        return !(*this == _rhs);
      }
      inline bool operator>(const AseQosDirectionRequirement& _rhs) const {
        return _rhs < *this;
      }
      inline bool operator>=(const AseQosDirectionRequirement& _rhs) const {
        return !(*this < _rhs);
      }
      inline bool operator<=(const AseQosDirectionRequirement& _rhs) const {
        return !(_rhs < *this);
      }

      static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
      inline std::string toString() const {
        std::ostringstream _aidl_os;
        _aidl_os << "AseQosDirectionRequirement{";
        _aidl_os << "framing: " << ::android::internal::ToString(framing);
        _aidl_os << ", preferredPhy: " << ::android::internal::ToString(preferredPhy);
        _aidl_os << ", preferredRetransmissionNum: " << ::android::internal::ToString(preferredRetransmissionNum);
        _aidl_os << ", maxTransportLatencyMs: " << ::android::internal::ToString(maxTransportLatencyMs);
        _aidl_os << ", presentationDelayMinUs: " << ::android::internal::ToString(presentationDelayMinUs);
        _aidl_os << ", presentationDelayMaxUs: " << ::android::internal::ToString(presentationDelayMaxUs);
        _aidl_os << ", preferredPresentationDelayMinUs: " << ::android::internal::ToString(preferredPresentationDelayMinUs);
        _aidl_os << ", preferredPresentationDelayMaxUs: " << ::android::internal::ToString(preferredPresentationDelayMaxUs);
        _aidl_os << ", aseConfiguration: " << ::android::internal::ToString(aseConfiguration);
        _aidl_os << "}";
        return _aidl_os.str();
      }
    };
    ::aidl::android::hardware::bluetooth::audio::AudioContext audioContext;
    std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationRequirement::AseQosDirectionRequirement> sinkAseQosRequirement;
    std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationRequirement::AseQosDirectionRequirement> sourceAseQosRequirement;
    std::optional<::aidl::android::hardware::bluetooth::audio::ConfigurationFlags> flags;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioAseQosConfigurationRequirement& _rhs) const {
      return std::tie(audioContext, sinkAseQosRequirement, sourceAseQosRequirement, flags) == std::tie(_rhs.audioContext, _rhs.sinkAseQosRequirement, _rhs.sourceAseQosRequirement, _rhs.flags);
    }
    inline bool operator<(const LeAudioAseQosConfigurationRequirement& _rhs) const {
      return std::tie(audioContext, sinkAseQosRequirement, sourceAseQosRequirement, flags) < std::tie(_rhs.audioContext, _rhs.sinkAseQosRequirement, _rhs.sourceAseQosRequirement, _rhs.flags);
    }
    inline bool operator!=(const LeAudioAseQosConfigurationRequirement& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioAseQosConfigurationRequirement& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioAseQosConfigurationRequirement& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioAseQosConfigurationRequirement& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioAseQosConfigurationRequirement{";
      _aidl_os << "audioContext: " << ::android::internal::ToString(audioContext);
      _aidl_os << ", sinkAseQosRequirement: " << ::android::internal::ToString(sinkAseQosRequirement);
      _aidl_os << ", sourceAseQosRequirement: " << ::android::internal::ToString(sourceAseQosRequirement);
      _aidl_os << ", flags: " << ::android::internal::ToString(flags);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioAseQosConfigurationPair {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfiguration> sinkQosConfiguration;
    std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfiguration> sourceQosConfiguration;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioAseQosConfigurationPair& _rhs) const {
      return std::tie(sinkQosConfiguration, sourceQosConfiguration) == std::tie(_rhs.sinkQosConfiguration, _rhs.sourceQosConfiguration);
    }
    inline bool operator<(const LeAudioAseQosConfigurationPair& _rhs) const {
      return std::tie(sinkQosConfiguration, sourceQosConfiguration) < std::tie(_rhs.sinkQosConfiguration, _rhs.sourceQosConfiguration);
    }
    inline bool operator!=(const LeAudioAseQosConfigurationPair& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioAseQosConfigurationPair& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioAseQosConfigurationPair& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioAseQosConfigurationPair& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioAseQosConfigurationPair{";
      _aidl_os << "sinkQosConfiguration: " << ::android::internal::ToString(sinkQosConfiguration);
      _aidl_os << ", sourceQosConfiguration: " << ::android::internal::ToString(sourceQosConfiguration);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioDataPathConfigurationPair {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration> inputConfig;
    std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration> outputConfig;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioDataPathConfigurationPair& _rhs) const {
      return std::tie(inputConfig, outputConfig) == std::tie(_rhs.inputConfig, _rhs.outputConfig);
    }
    inline bool operator<(const LeAudioDataPathConfigurationPair& _rhs) const {
      return std::tie(inputConfig, outputConfig) < std::tie(_rhs.inputConfig, _rhs.outputConfig);
    }
    inline bool operator!=(const LeAudioDataPathConfigurationPair& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioDataPathConfigurationPair& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioDataPathConfigurationPair& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioDataPathConfigurationPair& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioDataPathConfigurationPair{";
      _aidl_os << "inputConfig: " << ::android::internal::ToString(inputConfig);
      _aidl_os << ", outputConfig: " << ::android::internal::ToString(outputConfig);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class StreamConfig {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::bluetooth::audio::AudioContext audioContext;
    std::vector<::aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap> streamMap;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const StreamConfig& _rhs) const {
      return std::tie(audioContext, streamMap) == std::tie(_rhs.audioContext, _rhs.streamMap);
    }
    inline bool operator<(const StreamConfig& _rhs) const {
      return std::tie(audioContext, streamMap) < std::tie(_rhs.audioContext, _rhs.streamMap);
    }
    inline bool operator!=(const StreamConfig& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const StreamConfig& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const StreamConfig& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const StreamConfig& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "StreamConfig{";
      _aidl_os << "audioContext: " << ::android::internal::ToString(audioContext);
      _aidl_os << ", streamMap: " << ::android::internal::ToString(streamMap);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum class AseState : int8_t {
    ENABLING = 0,
    STREAMING = 1,
    DISABLING = 2,
  };

  enum class BroadcastQuality : int8_t {
    STANDARD = 0,
    HIGH = 1,
  };

  class LeAudioBroadcastSubgroupConfigurationRequirement {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    ::aidl::android::hardware::bluetooth::audio::AudioContext audioContext;
    ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::BroadcastQuality quality = ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::BroadcastQuality(0);
    int32_t bisNumPerSubgroup = 0;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioBroadcastSubgroupConfigurationRequirement& _rhs) const {
      return std::tie(audioContext, quality, bisNumPerSubgroup) == std::tie(_rhs.audioContext, _rhs.quality, _rhs.bisNumPerSubgroup);
    }
    inline bool operator<(const LeAudioBroadcastSubgroupConfigurationRequirement& _rhs) const {
      return std::tie(audioContext, quality, bisNumPerSubgroup) < std::tie(_rhs.audioContext, _rhs.quality, _rhs.bisNumPerSubgroup);
    }
    inline bool operator!=(const LeAudioBroadcastSubgroupConfigurationRequirement& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioBroadcastSubgroupConfigurationRequirement& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioBroadcastSubgroupConfigurationRequirement& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioBroadcastSubgroupConfigurationRequirement& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioBroadcastSubgroupConfigurationRequirement{";
      _aidl_os << "audioContext: " << ::android::internal::ToString(audioContext);
      _aidl_os << ", quality: " << ::android::internal::ToString(quality);
      _aidl_os << ", bisNumPerSubgroup: " << ::android::internal::ToString(bisNumPerSubgroup);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioBroadcastConfigurationRequirement {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastSubgroupConfigurationRequirement> subgroupConfigurationRequirements;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioBroadcastConfigurationRequirement& _rhs) const {
      return std::tie(subgroupConfigurationRequirements) == std::tie(_rhs.subgroupConfigurationRequirements);
    }
    inline bool operator<(const LeAudioBroadcastConfigurationRequirement& _rhs) const {
      return std::tie(subgroupConfigurationRequirements) < std::tie(_rhs.subgroupConfigurationRequirements);
    }
    inline bool operator!=(const LeAudioBroadcastConfigurationRequirement& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioBroadcastConfigurationRequirement& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioBroadcastConfigurationRequirement& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioBroadcastConfigurationRequirement& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioBroadcastConfigurationRequirement{";
      _aidl_os << "subgroupConfigurationRequirements: " << ::android::internal::ToString(subgroupConfigurationRequirements);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioSubgroupBisConfiguration {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t numBis = 0;
    ::aidl::android::hardware::bluetooth::audio::LeAudioBisConfiguration bisConfiguration;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioSubgroupBisConfiguration& _rhs) const {
      return std::tie(numBis, bisConfiguration) == std::tie(_rhs.numBis, _rhs.bisConfiguration);
    }
    inline bool operator<(const LeAudioSubgroupBisConfiguration& _rhs) const {
      return std::tie(numBis, bisConfiguration) < std::tie(_rhs.numBis, _rhs.bisConfiguration);
    }
    inline bool operator!=(const LeAudioSubgroupBisConfiguration& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioSubgroupBisConfiguration& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioSubgroupBisConfiguration& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioSubgroupBisConfiguration& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioSubgroupBisConfiguration{";
      _aidl_os << "numBis: " << ::android::internal::ToString(numBis);
      _aidl_os << ", bisConfiguration: " << ::android::internal::ToString(bisConfiguration);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioBroadcastSubgroupConfiguration {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioSubgroupBisConfiguration> bisConfigurations;
    std::optional<std::vector<uint8_t>> vendorCodecConfiguration;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioBroadcastSubgroupConfiguration& _rhs) const {
      return std::tie(bisConfigurations, vendorCodecConfiguration) == std::tie(_rhs.bisConfigurations, _rhs.vendorCodecConfiguration);
    }
    inline bool operator<(const LeAudioBroadcastSubgroupConfiguration& _rhs) const {
      return std::tie(bisConfigurations, vendorCodecConfiguration) < std::tie(_rhs.bisConfigurations, _rhs.vendorCodecConfiguration);
    }
    inline bool operator!=(const LeAudioBroadcastSubgroupConfiguration& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioBroadcastSubgroupConfiguration& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioBroadcastSubgroupConfiguration& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioBroadcastSubgroupConfiguration& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioBroadcastSubgroupConfiguration{";
      _aidl_os << "bisConfigurations: " << ::android::internal::ToString(bisConfigurations);
      _aidl_os << ", vendorCodecConfiguration: " << ::android::internal::ToString(vendorCodecConfiguration);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  class LeAudioBroadcastConfigurationSetting {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    int32_t sduIntervalUs = 0;
    int32_t numBis = 0;
    int32_t maxSduOctets = 0;
    int32_t maxTransportLatencyMs = 0;
    int32_t retransmitionNum = 0;
    std::vector<::aidl::android::hardware::bluetooth::audio::Phy> phy;
    ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing packing = ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing(0);
    ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing framing = ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing(0);
    std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration> dataPathConfiguration;
    std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastSubgroupConfiguration> subgroupsConfigurations;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const LeAudioBroadcastConfigurationSetting& _rhs) const {
      return std::tie(sduIntervalUs, numBis, maxSduOctets, maxTransportLatencyMs, retransmitionNum, phy, packing, framing, dataPathConfiguration, subgroupsConfigurations) == std::tie(_rhs.sduIntervalUs, _rhs.numBis, _rhs.maxSduOctets, _rhs.maxTransportLatencyMs, _rhs.retransmitionNum, _rhs.phy, _rhs.packing, _rhs.framing, _rhs.dataPathConfiguration, _rhs.subgroupsConfigurations);
    }
    inline bool operator<(const LeAudioBroadcastConfigurationSetting& _rhs) const {
      return std::tie(sduIntervalUs, numBis, maxSduOctets, maxTransportLatencyMs, retransmitionNum, phy, packing, framing, dataPathConfiguration, subgroupsConfigurations) < std::tie(_rhs.sduIntervalUs, _rhs.numBis, _rhs.maxSduOctets, _rhs.maxTransportLatencyMs, _rhs.retransmitionNum, _rhs.phy, _rhs.packing, _rhs.framing, _rhs.dataPathConfiguration, _rhs.subgroupsConfigurations);
    }
    inline bool operator!=(const LeAudioBroadcastConfigurationSetting& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const LeAudioBroadcastConfigurationSetting& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const LeAudioBroadcastConfigurationSetting& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const LeAudioBroadcastConfigurationSetting& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "LeAudioBroadcastConfigurationSetting{";
      _aidl_os << "sduIntervalUs: " << ::android::internal::ToString(sduIntervalUs);
      _aidl_os << ", numBis: " << ::android::internal::ToString(numBis);
      _aidl_os << ", maxSduOctets: " << ::android::internal::ToString(maxSduOctets);
      _aidl_os << ", maxTransportLatencyMs: " << ::android::internal::ToString(maxTransportLatencyMs);
      _aidl_os << ", retransmitionNum: " << ::android::internal::ToString(retransmitionNum);
      _aidl_os << ", phy: " << ::android::internal::ToString(phy);
      _aidl_os << ", packing: " << ::android::internal::ToString(packing);
      _aidl_os << ", framing: " << ::android::internal::ToString(framing);
      _aidl_os << ", dataPathConfiguration: " << ::android::internal::ToString(dataPathConfiguration);
      _aidl_os << ", subgroupsConfigurations: " << ::android::internal::ToString(subgroupsConfigurations);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  enum : int32_t { CODEC_PRIORITY_DISABLED = -1 };
  enum : int32_t { CODEC_PRIORITY_NONE = 0 };
  static inline const int32_t version = 5;
  static inline const std::string hash = "3ac4a1539dc76abf25f2ade699ee17ba036d7729";
  static constexpr uint32_t TRANSACTION_endSession = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_startSession = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_streamStarted = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_streamSuspended = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_updateAudioConfiguration = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setLowLatencyModeAllowed = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_parseA2dpConfiguration = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getA2dpConfiguration = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_setCodecPriority = FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getLeAudioAseConfiguration = FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getLeAudioAseQosConfiguration = FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getLeAudioAseDatapathConfiguration = FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_onSinkAseMetadataChanged = FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_onSourceAseMetadataChanged = FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_getLeAudioBroadcastConfiguration = FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_getLeAudioBroadcastDatapathConfiguration = FIRST_CALL_TRANSACTION + 15;

  static std::shared_ptr<IBluetoothAudioProvider> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothAudioProvider>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothAudioProvider>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IBluetoothAudioProvider>& impl);
  static const std::shared_ptr<IBluetoothAudioProvider>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus endSession() = 0;
  virtual ::ndk::ScopedAStatus startSession(const std::shared_ptr<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioPort>& in_hostIf, const ::aidl::android::hardware::bluetooth::audio::AudioConfiguration& in_audioConfig, const std::vector<::aidl::android::hardware::bluetooth::audio::LatencyMode>& in_supportedLatencyModes, ::aidl::android::hardware::common::fmq::MQDescriptor<int8_t, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus streamStarted(::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus in_status) = 0;
  virtual ::ndk::ScopedAStatus streamSuspended(::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus in_status) = 0;
  virtual ::ndk::ScopedAStatus updateAudioConfiguration(const ::aidl::android::hardware::bluetooth::audio::AudioConfiguration& in_audioConfig) = 0;
  virtual ::ndk::ScopedAStatus setLowLatencyModeAllowed(bool in_allowed) = 0;
  virtual ::ndk::ScopedAStatus parseA2dpConfiguration(const ::aidl::android::hardware::bluetooth::audio::CodecId& in_codecId, const std::vector<uint8_t>& in_configuration, ::aidl::android::hardware::bluetooth::audio::CodecParameters* out_codecParameters, ::aidl::android::hardware::bluetooth::audio::A2dpStatus* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getA2dpConfiguration(const std::vector<::aidl::android::hardware::bluetooth::audio::A2dpRemoteCapabilities>& in_remoteA2dpCapabilities, const ::aidl::android::hardware::bluetooth::audio::A2dpConfigurationHint& in_hint, std::optional<::aidl::android::hardware::bluetooth::audio::A2dpConfiguration>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setCodecPriority(const ::aidl::android::hardware::bluetooth::audio::CodecId& in_codecId, int32_t in_priority) = 0;
  virtual ::ndk::ScopedAStatus getLeAudioAseConfiguration(const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSinkAudioCapabilities, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSourceAudioCapabilities, const std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioConfigurationRequirement>& in_requirements, std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseConfigurationSetting>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getLeAudioAseQosConfiguration(const ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationRequirement& in_qosRequirement, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationPair* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getLeAudioAseDatapathConfiguration(const std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::StreamConfig>& in_sinkConfig, const std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::StreamConfig>& in_sourceConfig, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfigurationPair* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus onSinkAseMetadataChanged(::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState in_state, int32_t in_cigId, int32_t in_cisId, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>>& in_metadata) = 0;
  virtual ::ndk::ScopedAStatus onSourceAseMetadataChanged(::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState in_state, int32_t in_cigId, int32_t in_cisId, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>>& in_metadata) = 0;
  virtual ::ndk::ScopedAStatus getLeAudioBroadcastConfiguration(const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSinkAudioCapabilities, const ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastConfigurationRequirement& in_requirement, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastConfigurationSetting* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getLeAudioBroadcastDatapathConfiguration(const ::aidl::android::hardware::bluetooth::audio::AudioContext& in_audioContext, const std::vector<::aidl::android::hardware::bluetooth::audio::LeAudioBroadcastConfiguration::BroadcastStreamMap>& in_streamMap, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IBluetoothAudioProvider> default_impl;
};
class IBluetoothAudioProviderDefault : public IBluetoothAudioProvider {
public:
  ::ndk::ScopedAStatus endSession() override;
  ::ndk::ScopedAStatus startSession(const std::shared_ptr<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioPort>& in_hostIf, const ::aidl::android::hardware::bluetooth::audio::AudioConfiguration& in_audioConfig, const std::vector<::aidl::android::hardware::bluetooth::audio::LatencyMode>& in_supportedLatencyModes, ::aidl::android::hardware::common::fmq::MQDescriptor<int8_t, ::aidl::android::hardware::common::fmq::SynchronizedReadWrite>* _aidl_return) override;
  ::ndk::ScopedAStatus streamStarted(::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus in_status) override;
  ::ndk::ScopedAStatus streamSuspended(::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus in_status) override;
  ::ndk::ScopedAStatus updateAudioConfiguration(const ::aidl::android::hardware::bluetooth::audio::AudioConfiguration& in_audioConfig) override;
  ::ndk::ScopedAStatus setLowLatencyModeAllowed(bool in_allowed) override;
  ::ndk::ScopedAStatus parseA2dpConfiguration(const ::aidl::android::hardware::bluetooth::audio::CodecId& in_codecId, const std::vector<uint8_t>& in_configuration, ::aidl::android::hardware::bluetooth::audio::CodecParameters* out_codecParameters, ::aidl::android::hardware::bluetooth::audio::A2dpStatus* _aidl_return) override;
  ::ndk::ScopedAStatus getA2dpConfiguration(const std::vector<::aidl::android::hardware::bluetooth::audio::A2dpRemoteCapabilities>& in_remoteA2dpCapabilities, const ::aidl::android::hardware::bluetooth::audio::A2dpConfigurationHint& in_hint, std::optional<::aidl::android::hardware::bluetooth::audio::A2dpConfiguration>* _aidl_return) override;
  ::ndk::ScopedAStatus setCodecPriority(const ::aidl::android::hardware::bluetooth::audio::CodecId& in_codecId, int32_t in_priority) override;
  ::ndk::ScopedAStatus getLeAudioAseConfiguration(const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSinkAudioCapabilities, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSourceAudioCapabilities, const std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioConfigurationRequirement>& in_requirements, std::vector<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseConfigurationSetting>* _aidl_return) override;
  ::ndk::ScopedAStatus getLeAudioAseQosConfiguration(const ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationRequirement& in_qosRequirement, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioAseQosConfigurationPair* _aidl_return) override;
  ::ndk::ScopedAStatus getLeAudioAseDatapathConfiguration(const std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::StreamConfig>& in_sinkConfig, const std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::StreamConfig>& in_sourceConfig, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfigurationPair* _aidl_return) override;
  ::ndk::ScopedAStatus onSinkAseMetadataChanged(::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState in_state, int32_t in_cigId, int32_t in_cisId, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>>& in_metadata) override;
  ::ndk::ScopedAStatus onSourceAseMetadataChanged(::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState in_state, int32_t in_cigId, int32_t in_cisId, const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::MetadataLtv>>>& in_metadata) override;
  ::ndk::ScopedAStatus getLeAudioBroadcastConfiguration(const std::optional<std::vector<std::optional<::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDeviceCapabilities>>>& in_remoteSinkAudioCapabilities, const ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastConfigurationRequirement& in_requirement, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioBroadcastConfigurationSetting* _aidl_return) override;
  ::ndk::ScopedAStatus getLeAudioBroadcastDatapathConfiguration(const ::aidl::android::hardware::bluetooth::audio::AudioContext& in_audioContext, const std::vector<::aidl::android::hardware::bluetooth::audio::LeAudioBroadcastConfiguration::BroadcastStreamMap>& in_streamMap, ::aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::LeAudioDataPathConfiguration* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
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
[[nodiscard]] static inline std::string toString(IBluetoothAudioProvider::Packing val) {
  switch(val) {
  case IBluetoothAudioProvider::Packing::SEQUENTIAL:
    return "SEQUENTIAL";
  case IBluetoothAudioProvider::Packing::INTERLEAVED:
    return "INTERLEAVED";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing, 2> enum_values<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing> = {
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing::SEQUENTIAL,
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Packing::INTERLEAVED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(IBluetoothAudioProvider::Framing val) {
  switch(val) {
  case IBluetoothAudioProvider::Framing::UNFRAMED:
    return "UNFRAMED";
  case IBluetoothAudioProvider::Framing::FRAMED:
    return "FRAMED";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing, 2> enum_values<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing> = {
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing::UNFRAMED,
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::Framing::FRAMED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(IBluetoothAudioProvider::AseState val) {
  switch(val) {
  case IBluetoothAudioProvider::AseState::ENABLING:
    return "ENABLING";
  case IBluetoothAudioProvider::AseState::STREAMING:
    return "STREAMING";
  case IBluetoothAudioProvider::AseState::DISABLING:
    return "DISABLING";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState, 3> enum_values<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState> = {
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState::ENABLING,
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState::STREAMING,
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::AseState::DISABLING,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
[[nodiscard]] static inline std::string toString(IBluetoothAudioProvider::BroadcastQuality val) {
  switch(val) {
  case IBluetoothAudioProvider::BroadcastQuality::STANDARD:
    return "STANDARD";
  case IBluetoothAudioProvider::BroadcastQuality::HIGH:
    return "HIGH";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::BroadcastQuality, 2> enum_values<aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::BroadcastQuality> = {
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::BroadcastQuality::STANDARD,
  aidl::android::hardware::bluetooth::audio::IBluetoothAudioProvider::BroadcastQuality::HIGH,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
