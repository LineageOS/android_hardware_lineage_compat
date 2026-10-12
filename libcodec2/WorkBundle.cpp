// SPDX-FileCopyrightText: The LineageOS Project
// SPDX-License-Identifier: Apache-2.0

extern "C" bool objcpy_current(void* bundle, const void* works, void* sender) __asm__(
        "_ZN7android8hardware5media2c24V1_05utils6objcpyEPNS3_10WorkBundleERKNSt3__14listINS7_"
        "10unique_ptrI6C2WorkNS7_14default_deleteISA_EEEENS7_9allocatorISD_EEEEPNS_"
        "16BufferPoolSenderINS4_15BufferPoolTypesEEE");

extern "C" bool objcpy_legacy(void* bundle, const void* works, void* sender) __asm__(
        "_ZN7android8hardware5media2c24V1_05utils6objcpyEPNS3_10WorkBundleERKNSt3__14listINS7_"
        "10unique_ptrI6C2WorkNS7_14default_deleteISA_EEEENS7_9allocatorISD_EEEEPNS4_"
        "16BufferPoolSenderE");

// BufferPoolSender became a template without changing its HIDL virtual interface.
extern "C" bool objcpy_legacy(void* bundle, const void* works, void* sender) {
    return objcpy_current(bundle, works, sender);
}
