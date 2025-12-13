/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=ndk --structured --version 5 --hash 3ac4a1539dc76abf25f2ade699ee17ba036d7729 -t --stability vintf --min_sdk_version 31 -pout/soong/.intermediates/hardware/interfaces/audio/aidl/android.hardware.audio.common_interface/4/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/aidl/android.hardware.common_interface/2/preprocessed.aidl -pout/soong/.intermediates/hardware/interfaces/common/fmq/aidl/android.hardware.common.fmq_interface/1/preprocessed.aidl --ninja -d out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging/android/hardware/bluetooth/audio/LeAudioConfiguration.cpp.d -h out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/include/staging -o out/soong/.intermediates/hardware/interfaces/bluetooth/audio/aidl/android.hardware.bluetooth.audio-V5-ndk-source/gen/staging -Nhardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5 hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/5/android/hardware/bluetooth/audio/LeAudioConfiguration.aidl
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
#include <aidl/android/hardware/bluetooth/audio/CodecType.h>
#include <aidl/android/hardware/bluetooth/audio/ConfigurationFlags.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioAseConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioCodecConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioConfiguration.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::bluetooth::audio {
class ConfigurationFlags;
class LeAudioAseConfiguration;
}  // namespace aidl::android::hardware::bluetooth::audio
namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
class LeAudioConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  class StreamMap {
  public:
    typedef std::false_type fixed_size;
    static const char* descriptor;

    class BluetoothDeviceAddress {
    public:
      typedef std::false_type fixed_size;
      static const char* descriptor;

      enum class DeviceAddressType : int8_t {
        BLE_ADDRESS_PUBLIC = 0,
        BLE_ADDRESS_RANDOM = 1,
      };

      std::array<uint8_t, 6> deviceAddress = {{}};
      ::aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType deviceAddressType = ::aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType(0);

      binder_status_t readFromParcel(const AParcel* parcel);
      binder_status_t writeToParcel(AParcel* parcel) const;

      inline bool operator==(const BluetoothDeviceAddress& _rhs) const {
        return std::tie(deviceAddress, deviceAddressType) == std::tie(_rhs.deviceAddress, _rhs.deviceAddressType);
      }
      inline bool operator<(const BluetoothDeviceAddress& _rhs) const {
        return std::tie(deviceAddress, deviceAddressType) < std::tie(_rhs.deviceAddress, _rhs.deviceAddressType);
      }
      inline bool operator!=(const BluetoothDeviceAddress& _rhs) const {
        return !(*this == _rhs);
      }
      inline bool operator>(const BluetoothDeviceAddress& _rhs) const {
        return _rhs < *this;
      }
      inline bool operator>=(const BluetoothDeviceAddress& _rhs) const {
        return !(*this < _rhs);
      }
      inline bool operator<=(const BluetoothDeviceAddress& _rhs) const {
        return !(_rhs < *this);
      }

      static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
      inline std::string toString() const {
        std::ostringstream _aidl_os;
        _aidl_os << "BluetoothDeviceAddress{";
        _aidl_os << "deviceAddress: " << ::android::internal::ToString(deviceAddress);
        _aidl_os << ", deviceAddressType: " << ::android::internal::ToString(deviceAddressType);
        _aidl_os << "}";
        return _aidl_os.str();
      }
    };
    char16_t streamHandle = '\0';
    int32_t audioChannelAllocation = 0;
    bool isStreamActive = false;
    std::optional<::aidl::android::hardware::bluetooth::audio::LeAudioAseConfiguration> aseConfiguration;
    std::optional<::aidl::android::hardware::bluetooth::audio::ConfigurationFlags> flags;
    std::optional<::aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap::BluetoothDeviceAddress> bluetoothDeviceAddress;

    binder_status_t readFromParcel(const AParcel* parcel);
    binder_status_t writeToParcel(AParcel* parcel) const;

    inline bool operator==(const StreamMap& _rhs) const {
      return std::tie(streamHandle, audioChannelAllocation, isStreamActive, aseConfiguration, flags, bluetoothDeviceAddress) == std::tie(_rhs.streamHandle, _rhs.audioChannelAllocation, _rhs.isStreamActive, _rhs.aseConfiguration, _rhs.flags, _rhs.bluetoothDeviceAddress);
    }
    inline bool operator<(const StreamMap& _rhs) const {
      return std::tie(streamHandle, audioChannelAllocation, isStreamActive, aseConfiguration, flags, bluetoothDeviceAddress) < std::tie(_rhs.streamHandle, _rhs.audioChannelAllocation, _rhs.isStreamActive, _rhs.aseConfiguration, _rhs.flags, _rhs.bluetoothDeviceAddress);
    }
    inline bool operator!=(const StreamMap& _rhs) const {
      return !(*this == _rhs);
    }
    inline bool operator>(const StreamMap& _rhs) const {
      return _rhs < *this;
    }
    inline bool operator>=(const StreamMap& _rhs) const {
      return !(*this < _rhs);
    }
    inline bool operator<=(const StreamMap& _rhs) const {
      return !(_rhs < *this);
    }

    static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
    inline std::string toString() const {
      std::ostringstream _aidl_os;
      _aidl_os << "StreamMap{";
      _aidl_os << "streamHandle: " << ::android::internal::ToString(streamHandle);
      _aidl_os << ", audioChannelAllocation: " << ::android::internal::ToString(audioChannelAllocation);
      _aidl_os << ", isStreamActive: " << ::android::internal::ToString(isStreamActive);
      _aidl_os << ", aseConfiguration: " << ::android::internal::ToString(aseConfiguration);
      _aidl_os << ", flags: " << ::android::internal::ToString(flags);
      _aidl_os << ", bluetoothDeviceAddress: " << ::android::internal::ToString(bluetoothDeviceAddress);
      _aidl_os << "}";
      return _aidl_os.str();
    }
  };
  ::aidl::android::hardware::bluetooth::audio::CodecType codecType = ::aidl::android::hardware::bluetooth::audio::CodecType(0);
  std::vector<::aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap> streamMap;
  int32_t peerDelayUs = 0;
  ::aidl::android::hardware::bluetooth::audio::LeAudioCodecConfiguration leAudioCodecConfig;
  std::optional<std::vector<uint8_t>> vendorSpecificMetadata;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const LeAudioConfiguration& _rhs) const {
    return std::tie(codecType, streamMap, peerDelayUs, leAudioCodecConfig, vendorSpecificMetadata) == std::tie(_rhs.codecType, _rhs.streamMap, _rhs.peerDelayUs, _rhs.leAudioCodecConfig, _rhs.vendorSpecificMetadata);
  }
  inline bool operator<(const LeAudioConfiguration& _rhs) const {
    return std::tie(codecType, streamMap, peerDelayUs, leAudioCodecConfig, vendorSpecificMetadata) < std::tie(_rhs.codecType, _rhs.streamMap, _rhs.peerDelayUs, _rhs.leAudioCodecConfig, _rhs.vendorSpecificMetadata);
  }
  inline bool operator!=(const LeAudioConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const LeAudioConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const LeAudioConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const LeAudioConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "LeAudioConfiguration{";
    _aidl_os << "codecType: " << ::android::internal::ToString(codecType);
    _aidl_os << ", streamMap: " << ::android::internal::ToString(streamMap);
    _aidl_os << ", peerDelayUs: " << ::android::internal::ToString(peerDelayUs);
    _aidl_os << ", leAudioCodecConfig: " << ::android::internal::ToString(leAudioCodecConfig);
    _aidl_os << ", vendorSpecificMetadata: " << ::android::internal::ToString(vendorSpecificMetadata);
    _aidl_os << "}";
    return _aidl_os.str();
  }
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
[[nodiscard]] static inline std::string toString(LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType val) {
  switch(val) {
  case LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType::BLE_ADDRESS_PUBLIC:
    return "BLE_ADDRESS_PUBLIC";
  case LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType::BLE_ADDRESS_RANDOM:
    return "BLE_ADDRESS_RANDOM";
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
constexpr inline std::array<aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType, 2> enum_values<aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType> = {
  aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType::BLE_ADDRESS_PUBLIC,
  aidl::android::hardware::bluetooth::audio::LeAudioConfiguration::StreamMap::BluetoothDeviceAddress::DeviceAddressType::BLE_ADDRESS_RANDOM,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
