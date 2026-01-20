/*
 * Copyright (C) 2022-2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ftl/flags.h>
#include <input/Input.h>
#include <sys/types.h>
#include <ui/LogicalDisplayId.h>
#include <ui/Transform.h>
#include <array>
#include <cstdint>

static const android::ui::Transform kIdentityTransform;

extern "C" void
_ZN7android11MotionEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiNS_3ftl5FlagsINS_10MotionFlagEEEiiiNS_20MotionClassificationERKNS1_9TransformEffffSD_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
        android::MotionEvent* thisptr, int32_t id, int32_t deviceId, uint32_t source,
        android::ui::LogicalDisplayId displayId, std::array<uint8_t, 32> hmac, int32_t action,
        int32_t actionButton, android::ftl::Flags<android::MotionFlag> flags, int32_t edgeFlags,
        int32_t metaState, int32_t buttonState, android::MotionClassification classification,
        const android::ui::Transform& transform, float xPrecision, float yPrecision,
        float rawXCursorPosition, float rawYCursorPosition,
        const android::ui::Transform& rawTransform, int64_t downTime, int64_t eventTime,
        size_t pointerCount, const android::PointerProperties* pointerProperties,
        const android::PointerCoords* pointerCoords);

extern "C" void
_ZN7android8KeyEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiiiiill(
        android::KeyEvent* thisptr, int32_t id, int32_t deviceId, uint32_t source,
        android::ui::LogicalDisplayId displayId, std::array<uint8_t, 32> hmac, int32_t action,
        int32_t flags, int32_t keyCode, int32_t scanCode, int32_t metaState, int32_t repeatCount,
        int64_t downTime, int64_t eventTime);

extern "C" void
_ZN7android11MotionEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiiiiiNS_20MotionClassificationERKNS1_9TransformEffffS9_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
        android::MotionEvent* thisptr, int32_t id, int32_t deviceId, uint32_t source,
        android::ui::LogicalDisplayId displayId, std::array<uint8_t, 32> hmac, int32_t action,
        int32_t actionButton, int32_t flags, int32_t edgeFlags, int32_t metaState,
        int32_t buttonState, android::MotionClassification classification,
        const android::ui::Transform* transform, float xPrecision, float yPrecision,
        float rawXCursorPosition, float rawYCursorPosition,
        const android::ui::Transform* rawTransform, int64_t downTime, int64_t eventTime,
        size_t pointerCount, const android::PointerProperties* pointerProperties,
        const android::PointerCoords* pointerCoords) {
    const android::ui::Transform& safeTransform = transform ? *transform : kIdentityTransform;
    const android::ui::Transform& safeRawTransform =
            rawTransform ? *rawTransform : kIdentityTransform;

    const android::ftl::Flags<android::MotionFlag> safeFlags{static_cast<uint32_t>(flags)};

    _ZN7android11MotionEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiNS_3ftl5FlagsINS_10MotionFlagEEEiiiNS_20MotionClassificationERKNS1_9TransformEffffSD_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
            thisptr, id, deviceId, source, displayId, hmac, action, actionButton, safeFlags,
            edgeFlags, metaState, buttonState, classification, safeTransform, xPrecision,
            yPrecision, rawXCursorPosition, rawYCursorPosition, safeRawTransform, downTime,
            eventTime, pointerCount, pointerProperties, pointerCoords);
}

extern "C" void
_ZN7android11MotionEvent10initializeEiijiNSt3__15arrayIhLm32EEEiiiiiiNS_20MotionClassificationERKNS_2ui9TransformEffffS8_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
        android::MotionEvent* thisptr, int32_t id, int32_t deviceId, uint32_t source,
        int32_t displayId, std::array<uint8_t, 32> hmac, int32_t action, int32_t actionButton,
        int32_t flags, int32_t edgeFlags, int32_t metaState, int32_t buttonState,
        android::MotionClassification classification, const android::ui::Transform* transform,
        float xPrecision, float yPrecision, float rawXCursorPosition, float rawYCursorPosition,
        const android::ui::Transform* rawTransform, int64_t downTime, int64_t eventTime,
        size_t pointerCount, const android::PointerProperties* pointerProperties,
        const android::PointerCoords* pointerCoords) {
    _ZN7android11MotionEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiiiiiNS_20MotionClassificationERKNS1_9TransformEffffS9_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
            thisptr, id, deviceId, source, android::ui::LogicalDisplayId{displayId}, hmac, action,
            actionButton, flags, edgeFlags, metaState, buttonState, classification, transform,
            xPrecision, yPrecision, rawXCursorPosition, rawYCursorPosition, rawTransform, downTime,
            eventTime, pointerCount, pointerProperties, pointerCoords);
}

extern "C" void _ZN7android8KeyEvent10initializeEiijiNSt3__15arrayIhLm32EEEiiiiiill(
        android::KeyEvent* thisptr, int32_t id, int32_t deviceId, uint32_t source,
        int32_t displayId, std::array<uint8_t, 32> hmac, int32_t action, int32_t flags,
        int32_t keyCode, int32_t scanCode, int32_t metaState, int32_t repeatCount, int64_t downTime,
        int64_t eventTime) {
    _ZN7android8KeyEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiiiiill(
            thisptr, id, deviceId, source, android::ui::LogicalDisplayId{displayId}, hmac, action,
            flags, keyCode, scanCode, metaState, repeatCount, downTime, eventTime);
}

extern "C" void _ZN7android17PointerProperties8copyFromERKS0_(
        android::PointerProperties* thisptr, const android::PointerProperties& other) {
    thisptr->id = other.id;
    thisptr->toolType = other.toolType;
}
