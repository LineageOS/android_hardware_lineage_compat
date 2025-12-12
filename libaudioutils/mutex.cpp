/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <audio_utils/mutex.h>

namespace android::audio_utils {

bool mutex_get_enable_flag() {
    return mutex::kDefaultPriorityInheritance;
}

}  // namespace android::audio_utils
