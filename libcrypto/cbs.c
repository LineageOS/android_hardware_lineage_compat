/*
 * Copyright (c) 2014, Google Inc.
 *
 * SPDX-License-Identifier: ISC
 */

#include <openssl/base.h>

// From <openssl/bytestring.h>
struct cbs_st {
    const uint8_t* data;
    size_t len;

#if !defined(BORINGSSL_NO_CXX)
    // Allow implicit conversions to and from bssl::Span<const uint8_t>.
    cbs_st(bssl::Span<const uint8_t> span) : data(span.data()), len(span.size()) {}
    operator bssl::Span<const uint8_t>() const {
        return bssl::MakeConstSpan(data, len);
    }

    // Defining any constructors requires we explicitly default the others.
    cbs_st() = default;
    cbs_st(const cbs_st&) = default;
    cbs_st& operator=(const cbs_st&) = default;
#endif
};

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
