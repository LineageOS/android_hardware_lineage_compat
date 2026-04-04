/*
 * SPDX-FileCopyrightText: 2022-2026 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define MGBB_STATUS_FAILURE 0xb

static int stub_fail() {
    return -1;
}

static char* stub_fail_str() {
    return "stub";
}

void* mg_facepp[] = {
        // clang-format off
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail_str,
    &stub_fail_str,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
    &stub_fail,
        // clang-format on
};

int _meg_beauty_body_get_api_impl(void) {
    return MGBB_STATUS_FAILURE;
}
