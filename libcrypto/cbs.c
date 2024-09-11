/*
 * Copyright (c) 2014, Google Inc.
 *
 * SPDX-License-Identifier: ISC
 */

#include <stdint.h>

// From <openssl/bytestring.h>
struct cbs_st {
    const uint8_t* data;
    size_t len;
};

typedef struct cbs_st CBS;

void CBS_init(CBS* cbs, const uint8_t* data, size_t len) {
    cbs->data = data;
    cbs->len = len;
}

const uint8_t* CBS_data(const CBS* cbs) {
    return cbs->data;
}

size_t CBS_len(const CBS* cbs) {
    return cbs->len;
}
