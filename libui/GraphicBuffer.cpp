/*
 * Copyright (C) 2022-2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <ui/GraphicBufferMapper.h>
#include <ui/Rect.h>
#include <utils/Errors.h>

namespace android {

extern "C" {
status_t _ZN7android13GraphicBuffer4lockEjPPvPiS3_(void* thisptr, uint32_t inUsage, void** vaddr,
                                                   int32_t* outBytesPerPixel,
                                                   int32_t* outBytesPerStride);

status_t _ZN7android13GraphicBuffer4lockEjPPv(void* thisptr, uint32_t inUsage, void** vaddr) {
    return _ZN7android13GraphicBuffer4lockEjPPvPiS3_(thisptr, inUsage, vaddr, nullptr, nullptr);
}

status_t _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(
        void* thisptr, buffer_handle_t handle, uint32_t usage, const Rect& bounds, void** vaddr,
        int32_t* outBytesPerPixel, int32_t* outBytesPerStride);

status_t _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv(
        void* thisptr, buffer_handle_t handle, uint32_t usage, const Rect& bounds, void** vaddr) {
    return _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(
            thisptr, handle, usage, bounds, vaddr, nullptr, nullptr);
}
}

}  // namespace android
