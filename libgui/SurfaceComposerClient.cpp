/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

extern "C" void _ZN7android21SurfaceComposerClient11Transaction5applyEbb(bool synchronous,
                                                                         bool oneWay);

extern "C" void _ZN7android21SurfaceComposerClient11Transaction5applyEb(bool synchronous) {
    _ZN7android21SurfaceComposerClient11Transaction5applyEbb(synchronous, false);
}
