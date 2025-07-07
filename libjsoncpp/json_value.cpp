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

extern "C" Json::Value* _ZN4Json5ValueC1Ex(Json::Value* thisptr, Json::Int64 value) {
    new (thisptr) Json::Value(value);
    return thisptr;
}

extern "C" Json::Value* _ZN4Json5ValueC1Ey(Json::Value* thisptr, Json::UInt64 value) {
    new (thisptr) Json::Value(value);
    return thisptr;
}
