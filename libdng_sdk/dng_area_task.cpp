/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include "dng_area_task.h"

void dng_area_task::ProcessOnThread(uint32_t threadIndex, const dng_rect& area,
                                    const dng_point& tileSize, dng_abort_sniffer* sniffer) {
    return dng_area_task::ProcessOnThread(threadIndex, area, tileSize, sniffer, nullptr);
}
