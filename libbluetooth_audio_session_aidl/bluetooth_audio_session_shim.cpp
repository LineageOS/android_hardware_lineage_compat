/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <stdint.h>

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {

class BluetoothAudioSession {
public:
    // This is the NEW Android 16 signature we are forwarding the call to.
    // 'b' in the mangled name means it takes a boolean.
    bool IsSessionReady(bool arg);

    // This is the OLD Android 15 signature that Amlogic is looking for.
    // 'v' in the mangled name means void (no arguments).
    bool IsSessionReady();
};

// Provide the old symbol to the Amlogic blob
bool BluetoothAudioSession::IsSessionReady() {
    // true means primary hal
    return IsSessionReady(true);
}

} // namespace audio
} // namespace bluetooth
} // namespace hardware
} // namespace android
} // namespace aidl