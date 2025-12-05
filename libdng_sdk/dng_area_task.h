/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>

class dng_abort_sniffer;
class dng_area_task_progress;
class dng_point;
class dng_rect;

class dng_area_task {
  public:
    void ProcessOnThread(uint32_t threadIndex, const dng_rect& area, const dng_point& tileSize,
                         dng_abort_sniffer* sniffer);
    void ProcessOnThread(uint32_t threadIndex, const dng_rect& area, const dng_point& tileSize,
                         dng_abort_sniffer* sniffer, dng_area_task_progress* progress);
};
