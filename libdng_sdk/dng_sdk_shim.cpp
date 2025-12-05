/*
 * SPDX-FileCopyrightText: 2025 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

class dng_rect;
class dng_point;
class dng_abort_sniffer;

class dng_area_task {
  public:
    void ProcessOnThread(unsigned int threadIndex, const dng_rect& area, const dng_point& tileSize,
                         dng_abort_sniffer* sniffer);
};

void dng_area_task::ProcessOnThread(unsigned int, const dng_rect&, const dng_point&,
                                    dng_abort_sniffer*) {
    // no-op shim
}
