/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

namespace aidl::android::hardware::bluetooth::audio {

class BluetoothAudioSession {
public:
    bool IsSessionReady();
    bool IsSessionReady(bool is_primary_hal);
};

}  // namespace aidl::android::hardware::bluetooth::audio
