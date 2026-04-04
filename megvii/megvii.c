/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

static int stub_fail() {
    return -1;
}

static char* stub_fail_str() {
    return "stub";
}

void* mg_facepp[] = {
        &stub_fail, &stub_fail, &stub_fail, &stub_fail_str, &stub_fail_str, &stub_fail, &stub_fail,
        &stub_fail, &stub_fail, &stub_fail, &stub_fail,     &stub_fail,     &stub_fail, &stub_fail,
        &stub_fail, &stub_fail, &stub_fail, &stub_fail,     &stub_fail,     &stub_fail, &stub_fail,
        &stub_fail, &stub_fail, &stub_fail, &stub_fail,     &stub_fail,     &stub_fail,
};

void _meg_beauty_body_get_api_impl(void) {}
