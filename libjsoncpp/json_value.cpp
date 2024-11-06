/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <json/value.h>

extern "C" Json::Value* _ZN4Json5ValueaSES0_(Json::Value* thisptr, Json::Value other) {
    *thisptr = other;
    return thisptr;
}
