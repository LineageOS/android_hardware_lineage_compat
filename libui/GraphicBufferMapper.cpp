/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <ui/GraphicBufferMapper.h>
#include <ui/Rect.h>
#include <utils/Errors.h>

using android::Rect;
using android::status_t;

extern "C" {
status_t _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv(
        void* thisptr, buffer_handle_t handle, uint32_t usage, const Rect& bounds, void** vaddr);

status_t _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(
        void* thisptr, buffer_handle_t handle, uint32_t usage, const Rect& bounds, void** vaddr,
        int32_t* /*outBytesPerPixel*/, int32_t* /*outBytesPerStride*/) {
    return _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv(
            thisptr, handle, usage, bounds, vaddr);
}

status_t _ZNK7android14Gralloc4Mapper6unlockEPK13native_handle(buffer_handle_t handle);

status_t _ZN7android19GraphicBufferMapper6unlockEPK13native_handle(
        buffer_handle_t handle, android::base::unique_fd* /*outFence*/) {
    return _ZNK7android14Gralloc4Mapper6unlockEPK13native_handle(handle);
}
}
