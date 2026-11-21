/*
 * Copyright (C) 2026 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 *
 * Amlogic Widevine OEMCrypto wrapper shim for Android 10 liboemcrypto.so
 * on Android 14 Codec2 (nicepool / fbx8am with 5.15 kernel amlogic_secure_dmabuf).
 *
 * Why a full wrapper library is needed:
 *   libwvhidl.so loads "liboemcrypto.so" via dlopen() and resolves all _oecc*
 *   functions via dlsym(handle, "_oeccXX"). Because _oecc48 / _oecc93 / _oecc1501
 *   are already defined in the stock liboemcrypto.so, a DT_NEEDED library would
 *   not override them. Instead, this library is installed as liboemcrypto.so and
 *   dlopens the stock binary ("liboemcrypto_vendor.so"), forwarding all _oecc*
 *   symbols while translating Codec2 dmabuf file descriptors in secure
 *   OEMCrypto_DestBufferDesc native_handle_t into 0xe2e0XXXX secmem handles.
 */

#define LOG_TAG "oemcrypto_shim"

#include <dlfcn.h>
#include <errno.h>
#include <linux/types.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <log/log.h>

#define VENDOR_OEMCRYPTO_PATH "/vendor/lib/liboemcrypto_vendor.so"

#define SECURE_HEAP_DEFAULT_VERSION             1
#define SECURE_HEAP_USER_TA_VERSION             3

struct secure_block_info {
    __u32 version;
    __u32 size;
    __u32 handle;
    __u32 unused;
    __u32 state;
    __u32 id_high;
    __u32 id_low;
    __u32 paddr;
    __u32 psize;
    __u64 handle_extend;
    __u64 paddr_extend;
};

/* Minimal Android native_handle_t layout */
typedef struct {
    int version; /* sizeof(native_handle_t) = 12 */
    int numFds;
    int numInts;
    int data[1];
} shim_native_handle_t;

/*
 * OEMCrypto_DestBufferDesc layout (16 bytes on 32-bit ARM, verified from
 * _oecc48 @ 0x9ea2, _oecc1501 @ 0xa60a, _oecc93 @ 0xace8 in stock liboemcrypto.so):
 *   +0x00: uint32_t type (0 = clear, 1 = secure, 2 = direct)
 *   +0x04: void *address / native_handle_t *handle (when type == 1)
 *   +0x08: size_t max_length (when type == 1)
 *   +0x0c: size_t offset (when type == 1)
 */
typedef struct {
    uint32_t type;
    void *handle_or_addr;
    uint32_t max_length;
    uint32_t offset;
} shim_dest_buffer_desc_t;

#define OEMCrypto_BufferType_Secure 1

static void *g_vendor_lib = NULL;
static pthread_once_t g_once = PTHREAD_ONCE_INIT;

static void init_vendor_lib(void) {
    g_vendor_lib = dlopen(VENDOR_OEMCRYPTO_PATH, RTLD_NOW | RTLD_LOCAL);
    if (!g_vendor_lib) {
        ALOGE("Failed to dlopen %s: %s", VENDOR_OEMCRYPTO_PATH, dlerror());
    } else {
        ALOGI("Loaded vendor OEMCrypto from %s", VENDOR_OEMCRYPTO_PATH);
    }
}

static void *resolve_sym(const char *name) {
    pthread_once(&g_once, init_vendor_lib);
    if (!g_vendor_lib) return NULL;
    void *fn = dlsym(g_vendor_lib, name);
    if (!fn) {
        ALOGE("Failed to dlsym %s: %s", name, dlerror());
    }
    return fn;
}

/*
 * Inspects out_buffer. If type == OEMCrypto_BufferType_Secure (1) and
 * handle->data[0] is a dmabuf fd (< 0x10000), mmaps the dmabuf fd to read
 * struct secure_block_info and substitutes block->handle (0xe2e0XXXX) or
 * block->paddr into a stack-allocated native_handle_t.
 */
static const shim_dest_buffer_desc_t *prepare_dest_buffer(
        const shim_dest_buffer_desc_t *in_desc,
        shim_dest_buffer_desc_t *local_desc,
        shim_native_handle_t *local_nh) {
    if (!in_desc || in_desc->type != OEMCrypto_BufferType_Secure || !in_desc->handle_or_addr) {
        return in_desc;
    }

    const shim_native_handle_t *nh = (const shim_native_handle_t *)in_desc->handle_or_addr;
    uint32_t raw_val = (uint32_t)nh->data[0];

    /* Already a secmem handle (0xe2e0XXXX) or physical address (>= 64KB) */
    if ((raw_val >> 16) != 0 || nh->numFds <= 0) {
        return in_desc;
    }

    int dmabuf_fd = nh->data[0];
    size_t map_len = sizeof(struct secure_block_info);
    struct secure_block_info *block = (struct secure_block_info *)mmap(
            NULL, map_len, PROT_READ, MAP_SHARED, dmabuf_fd, 0);
    if (block == MAP_FAILED) {
        ALOGE("prepare_dest_buffer: mmap(fd=%d) failed: %s", dmabuf_fd, strerror(errno));
        return in_desc;
    }

    uint32_t ver = block->version;
    uint32_t sec_handle = block->handle;
    uint32_t vdec_handle = block->unused;
    uint32_t paddr = block->paddr;
    munmap(block, map_len);

    uint32_t target_handle = 0;
    if (ver == SECURE_HEAP_USER_TA_VERSION) {
        if ((vdec_handle >> 20) == 0xe2e) {
            target_handle = vdec_handle;
        } else if (sec_handle != 0) {
            target_handle = sec_handle;
        }
    } else if (paddr != 0) {
        target_handle = paddr;
    } else if (sec_handle != 0) {
        target_handle = sec_handle;
    }

    if (target_handle == 0) {
        ALOGE("prepare_dest_buffer: fd=%d has empty secure_block_info (ver=%u, handle=0x%x, paddr=0x%x)",
              dmabuf_fd, ver, sec_handle, paddr);
        return in_desc;
    }

    *local_nh = *nh;
    local_nh->data[0] = (int)target_handle;

    *local_desc = *in_desc;
    local_desc->handle_or_addr = local_nh;
    return local_desc;
}

/*
 * _oecc48: OEMCrypto_DecryptCENC (v14/v15 signature in stock liboemcrypto.so @ 0x9e04)
 *   r0: session
 *   r1: data_addr
 *   r2: data_len
 *   r3: is_encrypted
 *   [sp, #0x00]: iv
 *   [sp, #0x04]: block_offset
 *   [sp, #0x08]: out_buffer (OEMCrypto_DestBufferDesc *)
 *   [sp, #0x0c]: pattern (OEMCrypto_CENCEncryptPatternDesc *)
 *   [sp, #0x10]: subsample_flags
 */
typedef uint32_t (*fn_oecc48_t)(uint32_t session, const void *data_addr, uint32_t data_len,
                                uint32_t is_encrypted, const void *iv, uint32_t block_offset,
                                const shim_dest_buffer_desc_t *out_buffer,
                                const void *pattern, uint32_t subsample_flags);

uint32_t _oecc48(uint32_t session, const void *data_addr, uint32_t data_len,
                 uint32_t is_encrypted, const void *iv, uint32_t block_offset,
                 const shim_dest_buffer_desc_t *out_buffer,
                 const void *pattern, uint32_t subsample_flags) {
    static fn_oecc48_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_oecc48_t)resolve_sym("_oecc48");
    if (!real_fn) return 28;

    shim_dest_buffer_desc_t local_desc;
    shim_native_handle_t local_nh;
    const shim_dest_buffer_desc_t *wrapped_out =
            prepare_dest_buffer(out_buffer, &local_desc, &local_nh);

    return real_fn(session, data_addr, data_len, is_encrypted, iv, block_offset,
                   wrapped_out, pattern, subsample_flags);
}

/*
 * _oecc1501: OEMCrypto_DecryptCENCExtend (stock liboemcrypto.so @ 0xa5e8)
 *   Same stack position for out_buffer ([sp, #0x08] = 7th argument).
 */
typedef uint32_t (*fn_oecc1501_t)(uint32_t session, const void *data_addr, uint32_t data_len,
                                  uint32_t is_encrypted, const void *iv, uint32_t block_offset,
                                  const shim_dest_buffer_desc_t *out_buffer,
                                  const void *pattern, uint32_t subsample_flags);

uint32_t _oecc1501(uint32_t session, const void *data_addr, uint32_t data_len,
                   uint32_t is_encrypted, const void *iv, uint32_t block_offset,
                   const shim_dest_buffer_desc_t *out_buffer,
                   const void *pattern, uint32_t subsample_flags) {
    static fn_oecc1501_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_oecc1501_t)resolve_sym("_oecc1501");
    if (!real_fn) return 28;

    shim_dest_buffer_desc_t local_desc;
    shim_native_handle_t local_nh;
    const shim_dest_buffer_desc_t *wrapped_out =
            prepare_dest_buffer(out_buffer, &local_desc, &local_nh);

    return real_fn(session, data_addr, data_len, is_encrypted, iv, block_offset,
                   wrapped_out, pattern, subsample_flags);
}

/*
 * _oecc93: OEMCrypto_CopyBuffer (stock liboemcrypto.so @ 0xabcc)
 *   r0: session
 *   r1: data_addr
 *   r2: data_len
 *   r3: out_buffer (OEMCrypto_DestBufferDesc *)
 *   [sp, #0x00]: subsample_flags
 */
typedef uint32_t (*fn_oecc93_t)(uint32_t session, const void *data_addr, uint32_t data_len,
                                const shim_dest_buffer_desc_t *out_buffer,
                                uint32_t subsample_flags);

uint32_t _oecc93(uint32_t session, const void *data_addr, uint32_t data_len,
                 const shim_dest_buffer_desc_t *out_buffer, uint32_t subsample_flags) {
    static fn_oecc93_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_oecc93_t)resolve_sym("_oecc93");
    if (!real_fn) return 28;

    shim_dest_buffer_desc_t local_desc;
    shim_native_handle_t local_nh;
    const shim_dest_buffer_desc_t *wrapped_out =
            prepare_dest_buffer(out_buffer, &local_desc, &local_nh);

    return real_fn(session, data_addr, data_len, wrapped_out, subsample_flags);
}

/*
 * Generic transparent forwarding thunks for all other exported _oecc* symbols.
 * Using naked assembly tail-calls preserves all registers and stack arguments
 * regardless of arity.
 */
#define DEFINE_OECC_FORWARD(sym)                                  \
    void *__resolve_##sym(void) { return resolve_sym(#sym); }     \
    __attribute__((naked)) void sym(void) {                       \
        __asm__ volatile(                                         \
            "push {r0-r3, lr}\n"                                  \
            "sub sp, sp, #4\n"                                    \
            "bl __resolve_" #sym "\n"                             \
            "mov r12, r0\n"                                       \
            "add sp, sp, #4\n"                                    \
            "pop {r0-r3, lr}\n"                                   \
            "bx r12\n"                                            \
        );                                                        \
    }

DEFINE_OECC_FORWARD(_oecc01)
DEFINE_OECC_FORWARD(_oecc02)
DEFINE_OECC_FORWARD(_oecc03)
DEFINE_OECC_FORWARD(_oecc04)
DEFINE_OECC_FORWARD(_oecc05)
DEFINE_OECC_FORWARD(_oecc06)
DEFINE_OECC_FORWARD(_oecc07)
DEFINE_OECC_FORWARD(_oecc08)
DEFINE_OECC_FORWARD(_oecc09)
DEFINE_OECC_FORWARD(_oecc10)
DEFINE_OECC_FORWARD(_oecc12)
DEFINE_OECC_FORWARD(_oecc13)
DEFINE_OECC_FORWARD(_oecc14)
DEFINE_OECC_FORWARD(_oecc17)
DEFINE_OECC_FORWARD(_oecc18)
DEFINE_OECC_FORWARD(_oecc19)
DEFINE_OECC_FORWARD(_oecc21)
DEFINE_OECC_FORWARD(_oecc22)
DEFINE_OECC_FORWARD(_oecc23)
DEFINE_OECC_FORWARD(_oecc24)
DEFINE_OECC_FORWARD(_oecc25)
DEFINE_OECC_FORWARD(_oecc26)
DEFINE_OECC_FORWARD(_oecc27)
DEFINE_OECC_FORWARD(_oecc29)
DEFINE_OECC_FORWARD(_oecc30)
DEFINE_OECC_FORWARD(_oecc31)
DEFINE_OECC_FORWARD(_oecc32)
DEFINE_OECC_FORWARD(_oecc33)
DEFINE_OECC_FORWARD(_oecc34)
DEFINE_OECC_FORWARD(_oecc36)
DEFINE_OECC_FORWARD(_oecc37)
DEFINE_OECC_FORWARD(_oecc38)
DEFINE_OECC_FORWARD(_oecc39)
DEFINE_OECC_FORWARD(_oecc41)
DEFINE_OECC_FORWARD(_oecc42)
DEFINE_OECC_FORWARD(_oecc43)
DEFINE_OECC_FORWARD(_oecc44)
DEFINE_OECC_FORWARD(_oecc45)
DEFINE_OECC_FORWARD(_oecc46)
DEFINE_OECC_FORWARD(_oecc49)
DEFINE_OECC_FORWARD(_oecc50)
DEFINE_OECC_FORWARD(_oecc51)
DEFINE_OECC_FORWARD(_oecc52)
DEFINE_OECC_FORWARD(_oecc53)
DEFINE_OECC_FORWARD(_oecc54)
DEFINE_OECC_FORWARD(_oecc55)
DEFINE_OECC_FORWARD(_oecc57)
DEFINE_OECC_FORWARD(_oecc61)
DEFINE_OECC_FORWARD(_oecc62)
DEFINE_OECC_FORWARD(_oecc63)
DEFINE_OECC_FORWARD(_oecc64)
DEFINE_OECC_FORWARD(_oecc65)
DEFINE_OECC_FORWARD(_oecc66)
DEFINE_OECC_FORWARD(_oecc67)
DEFINE_OECC_FORWARD(_oecc68)
DEFINE_OECC_FORWARD(_oecc69)
DEFINE_OECC_FORWARD(_oecc70)
DEFINE_OECC_FORWARD(_oecc71)
DEFINE_OECC_FORWARD(_oecc78)
DEFINE_OECC_FORWARD(_oecc81)
DEFINE_OECC_FORWARD(_oecc83)
DEFINE_OECC_FORWARD(_oecc84)
DEFINE_OECC_FORWARD(_oecc85)
DEFINE_OECC_FORWARD(_oecc86)
DEFINE_OECC_FORWARD(_oecc88)
DEFINE_OECC_FORWARD(_oecc89)
DEFINE_OECC_FORWARD(_oecc90)
DEFINE_OECC_FORWARD(_oecc91)
DEFINE_OECC_FORWARD(_oecc92)
DEFINE_OECC_FORWARD(OEMCrypto_DecryptCENCExtendSupport)
DEFINE_OECC_FORWARD(OEMCrypto_DecryptShareMemorySize)
DEFINE_OECC_FORWARD(OEMCrypto_DeleteUsageTable)
