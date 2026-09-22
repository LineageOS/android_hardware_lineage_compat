/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <dlfcn.h>

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

namespace lineage::bluetooth::audio {

namespace symbols {
constexpr char kGetSessionInstance[] =
        "_ZN4aidl7android8hardware9bluetooth5audio29BluetoothAudioSessionInstance18"
        "GetSessionInstanceERKNS3_11SessionTypeE";
constexpr char kIsSessionReadyCurrent[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14IsSessionReadyEb";
constexpr char kRegisterStatusCback[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession19RegisterStatusCbackERKNS"
        "3_"
        "19PortStatusCallbacksE";
constexpr char kUnregisterStatusCback[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession21UnregisterStatusCbackEt";
constexpr char kGetAudioConfig[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14GetAudioConfigEv";
constexpr char kStartStream[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession11StartStreamEb";
constexpr char kSuspendStream[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession13SuspendStreamEv";
constexpr char kStopStream[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession10StopStreamEv";
constexpr char kGetPresentationPosition[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession23GetPresentationPositionE"
        "R"
        "NS3_20PresentationPositionE";
constexpr char kUpdateSourceMetadata[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession20UpdateSourceMetadataERK1"
        "5"
        "source_metadata";
constexpr char kUpdateSinkMetadata[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession18UpdateSinkMetadataERK13"
        "sink_metadata";
constexpr char kGetSupportedLatencyModes[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession24GetSupportedLatencyModes"
        "Ev";
constexpr char kSetLatencyMode[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession14SetLatencyModeERKNS3_11"
        "LatencyModeE";
constexpr char kOutWritePcmData[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession15OutWritePcmDataEPKvm";
constexpr char kInReadPcmData[] =
        "_ZN4aidl7android8hardware9bluetooth5audio21BluetoothAudioSession13InReadPcmDataEPvm";
}  // namespace symbols

// A member function is reached as a free function taking the object first.
// Return types are spelled out rather than turned into an output parameter:
// a returned class is passed back through a register the caller sets up, and
// which register that is belongs to the compiler, not to us.
struct SessionObject;

using GetSessionInstanceFn = std::shared_ptr<SessionObject> (*)(const int32_t*);
using ReadyCurrentFn = bool (*)(SessionObject*, bool);
using RegisterCbackFn = uint16_t (*)(SessionObject*, const void*);
using UnregisterCbackFn = void (*)(SessionObject*, uint16_t);
using StartStreamFn = bool (*)(SessionObject*, bool);
using SuspendStreamFn = bool (*)(SessionObject*);
using StopStreamFn = void (*)(SessionObject*);
using GetPositionFn = bool (*)(SessionObject*, void*);
using UpdateMetadataFn = void (*)(SessionObject*, const void*);
using GetLatencyModesFn = std::vector<int32_t> (*)(SessionObject*);
using SetLatencyModeFn = void (*)(SessionObject*, const int32_t*);
using WritePcmFn = size_t (*)(SessionObject*, const void*, size_t);
using ReadPcmFn = size_t (*)(SessionObject*, void*, size_t);

template <typename T>
inline T Lookup(void* library, const char* name) {
    return reinterpret_cast<T>(dlsym(library, name));
}

}  // namespace lineage::bluetooth::audio
