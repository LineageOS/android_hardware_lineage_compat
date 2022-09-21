/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <gui/IGraphicBufferProducer.h>
#include <stdint.h>

using android::IBinder;
using android::IGraphicBufferProducer;
using android::sp;

extern "C" void _ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEbRKNS1_INS_7IBinderEEE(
        const sp<IGraphicBufferProducer>& bufferProducer, bool controlledByApp,
        const sp<IBinder>& surfaceControlHandle);

extern "C" void _ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEb(
        const sp<IGraphicBufferProducer>& bufferProducer, bool controlledByApp) {
    _ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEbRKNS1_INS_7IBinderEEE(
            bufferProducer, controlledByApp, NULL);
}
