/*
 * Copyright (C) 2022-2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <input/Input.h>
#include <sys/types.h>
#include <ui/LogicalDisplayId.h>

extern "C" void
_ZN7android11MotionEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiiiiiNS_20MotionClassificationERKNS1_9TransformEffffS9_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
        int32_t id, int32_t deviceId, uint32_t source, android::ui::LogicalDisplayId displayId,
        std::array<uint8_t, 32> hmac, int32_t action, int32_t actionButton, int32_t flags,
        int32_t edgeFlags, int32_t metaState, int32_t buttonState, void* classification,
        void* transform, float xPrecision, float yPrecision, float rawXCursorPosition,
        float rawYCursorPosition, void* rawTransform, void* downTime, void* eventTime,
        size_t pointerCount, void* pointerProperties, void* pointerCoords);

extern "C" void
_ZN7android11MotionEvent10initializeEiijiNSt3__15arrayIhLm32EEEiiiiiiNS_20MotionClassificationERKNS_2ui9TransformEffffS8_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
        int32_t id, int32_t deviceId, uint32_t source, int32_t displayId,
        std::array<uint8_t, 32> hmac, int32_t action, int32_t actionButton, int32_t flags,
        int32_t edgeFlags, int32_t metaState, int32_t buttonState, void* classification,
        void* transform, float xPrecision, float yPrecision, float rawXCursorPosition,
        float rawYCursorPosition, void* rawTransform, void* downTime, void* eventTime,
        size_t pointerCount, void* pointerProperties, void* pointerCoords) {
    _ZN7android11MotionEvent10initializeEiijNS_2ui16LogicalDisplayIdENSt3__15arrayIhLm32EEEiiiiiiNS_20MotionClassificationERKNS1_9TransformEffffS9_llmPKNS_17PointerPropertiesEPKNS_13PointerCoordsE(
            id, deviceId, source, android::ui::LogicalDisplayId{displayId}, hmac, action,
            actionButton, flags, edgeFlags, metaState, buttonState, classification, transform,
            xPrecision, yPrecision, rawXCursorPosition, rawYCursorPosition, rawTransform, downTime,
            eventTime, pointerCount, pointerProperties, pointerCoords);
}

extern "C" void _ZN7android17PointerProperties8copyFromERKS0_(
        android::PointerProperties* thisptr, const android::PointerProperties& other) {
    thisptr->id = other.id;
    thisptr->toolType = other.toolType;
}
