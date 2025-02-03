/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <memory>
#include "include/serializable.h" // copy_size_and_data_from_buf function header definition
#include "include/UniquePtr.h" // Android 11 QPR3 UniquePtr header

namespace keymaster {

// keymaster::copy_size_and_data_from_buf
extern "C" bool
_ZN9keymaster27copy_size_and_data_from_bufEPPKhS1_PmPNS_9UniquePtrIA_hNS_13DefaultDeleteIS5_EEEE(
        const uint8_t** buf_ptr, const uint8_t* end, size_t* size, UniquePtr<uint8_t[]>* dest) {

    // Directly reinterpret `UniquePtr<uint8_t[]>*` as `std::unique_ptr<uint8_t[], std::default_delete<uint8_t[]>>*`
    std::unique_ptr<uint8_t[], std::default_delete<uint8_t[]>>* converted_dest = reinterpret_cast<std::unique_ptr<uint8_t[], std::default_delete<uint8_t[]>>*>(dest);

    return copy_size_and_data_from_buf(buf_ptr, end, size, converted_dest);
}

} // namespace keymaster
