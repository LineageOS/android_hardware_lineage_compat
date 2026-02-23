/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include "BluetoothAudioSession.h"

namespace aidl::android::hardware::bluetooth::audio {

bool BluetoothAudioSession::IsSessionReady() {
    return IsSessionReady(false);
}

}  // namespace aidl::android::hardware::bluetooth::audio
