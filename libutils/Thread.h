/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <utils/Thread.h>

namespace utils32 {

class Thread : public android::Thread {
public:
    android::status_t run(const char* name, int32_t priority, size_t stack);
};

} // namespace utils32
