/*
 * Copyright (C) 2026 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 *
 * Amlogic Secmem V2 shim for Android 10 libsecmem.so on Android 14 Codec2
 * (nicepool / fbx8am with 5.15 kernel amlogic_secure_dmabuf).
 *
 * Added via DT_NEEDED to vendor/lib/libsecmem.so so dlsym() from
 * libmediahal_videodec.so (SecureVdecPool) resolves the 6 newer V2 entrypoints:
 *   - Secure_V2_InitSecurePool
 *   - Secure_V2_EnableTVPMemory
 *   - Secure_V2_DestroySecurePool
 *   - Secure_V2_UpdateFrameInfo
 *   - Secure_V2_GetFreeBlockCount
 *   - Secure_V2_PoolFlush
 */

#define LOG_TAG "secmem_shim"

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

/* Kernel struct secure_block_info from amlogic_secure_dmabuf.c */
#define SECURE_HEAP_DEFAULT_VERSION             1
#define SECURE_HEAP_USER_TA_VERSION             3
#define AML_SECURE_DMABUF_HEAP_SETTING_PHYADDR  3

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

/* TEEC & libsecmem internal command IDs in secmem.ta */
#define TA_SECMEM_V2_CMD_MEM_TO_PHY     0xff  /* 255: Secmem_V2_MemToPhy */
#define TA_SECMEM_V2_CMD_PARSE          0x117 /* 279: Secmem_V2_Parse */

/* Secmem_V2_Parse types in Android 10 secmem.ta (tbh @ 0x157a) */
#define SECMEM_PARSE_AVCC               1 /* parser_avcc */
#define SECMEM_PARSE_AVC_START_CODE     2 /* parser_avc_start_code */
#define SECMEM_PARSE_VP9                3 /* parser_vp9 */
#define SECMEM_PARSE_HVCC               4 /* parser_hvcc */
#define SECMEM_PARSE_HVC_START_CODE     5 /* parser_hvc_start_code */
#define SECMEM_PARSE_AV1                6 /* parser_av1 */

typedef uint32_t (*fn_Secure_V2_Init_t)(void *sess, uint32_t src, uint32_t flags,
                                        uint32_t paddr, uint32_t size);
typedef uint32_t (*fn_Secure_V2_Close_t)(void *sess, uint32_t *out);
typedef uint32_t (*fn_Secure_V2_MemCreate_t)(void *sess, uint32_t *pHandle);
typedef uint32_t (*fn_Secure_V2_MemFree_t)(void *sess, uint32_t handle);
typedef uint32_t (*fn_Secure_V2_MemRelease_t)(void *sess, uint32_t handle);
typedef uint32_t (*fn_Secure_V2_MemToPhy_t)(void *sess, uint32_t handle, uint32_t *phyaddr);
typedef uint32_t (*fn_Secure_V2_MemFlush_t)(void *sess);
typedef uint32_t (*fn_Secure_V2_GetVp9HeaderSize_t)(void *sess, uint32_t paddr, uint32_t frame_len,
                                                    uint32_t *out_hdr_size,
                                                    uint32_t *out_frame_sizes);
typedef uint32_t (*fn_Teec_PackUInt_t)(void *shm, uint32_t val, uint32_t *offset);
typedef uint32_t (*fn_Teec_UnPackUInt_t)(void *shm, uint32_t *val, uint32_t *offset);
typedef uint32_t (*fn_Teec_Invoke_t)(void *teec_sess, uint32_t cmd, void *shm);
typedef void (*fn_TEEC_CloseSession_t)(void *teec_sess);
typedef void (*fn_TEEC_FinalizeContext_t)(void *teec_ctx);
typedef void (*fn_releaseshm_t)(void *sess);
typedef int (*fn_secmem_resman_acquire_t)(int handle, int tvp_set, int flags);
typedef int (*fn_tvp_mm_enable_t)(int flags);
typedef int (*fn_tvp_mm_disable_t)(int flags);

static fn_Secure_V2_Init_t p_Secure_V2_Init = NULL;
static fn_Secure_V2_Close_t p_Secure_V2_Close = NULL;
static fn_Secure_V2_MemCreate_t p_Secure_V2_MemCreate = NULL;
static fn_Secure_V2_MemFree_t p_Secure_V2_MemFree = NULL;
static fn_Secure_V2_MemRelease_t p_Secure_V2_MemRelease = NULL;
static fn_Secure_V2_MemToPhy_t p_Secure_V2_MemToPhy = NULL;
static fn_Secure_V2_MemFlush_t p_Secure_V2_MemFlush = NULL;
static fn_Secure_V2_GetVp9HeaderSize_t p_Secure_V2_GetVp9HeaderSize = NULL;
static fn_Teec_PackUInt_t p_Teec_PackUInt = NULL;
static fn_Teec_UnPackUInt_t p_Teec_UnPackUInt = NULL;
static fn_Teec_Invoke_t p_Teec_Invoke = NULL;
static fn_TEEC_CloseSession_t p_TEEC_CloseSession = NULL;
static fn_TEEC_FinalizeContext_t p_TEEC_FinalizeContext = NULL;
static fn_releaseshm_t p_releaseshm = NULL;
static fn_secmem_resman_acquire_t p_secmem_resman_acquire = NULL;
static fn_tvp_mm_enable_t p_tvp_mm_enable = NULL;
static fn_tvp_mm_disable_t p_tvp_mm_disable = NULL;

static pthread_once_t g_syms_once = PTHREAD_ONCE_INIT;

static void resolve_secmem_syms(void) {
    void *secmem_dl = dlopen("libsecmem.so", RTLD_NOLOAD | RTLD_NOW);
    if (!secmem_dl) {
        secmem_dl = RTLD_DEFAULT;
    }
    p_Secure_V2_Init = (fn_Secure_V2_Init_t)dlsym(secmem_dl, "Secure_V2_Init");
    p_Secure_V2_Close = (fn_Secure_V2_Close_t)dlsym(secmem_dl, "Secure_V2_Close");
    p_Secure_V2_MemCreate = (fn_Secure_V2_MemCreate_t)dlsym(secmem_dl, "Secure_V2_MemCreate");
    p_Secure_V2_MemFree = (fn_Secure_V2_MemFree_t)dlsym(secmem_dl, "Secure_V2_MemFree");
    p_Secure_V2_MemRelease = (fn_Secure_V2_MemRelease_t)dlsym(secmem_dl, "Secure_V2_MemRelease");
    p_Secure_V2_MemToPhy = (fn_Secure_V2_MemToPhy_t)dlsym(secmem_dl, "Secure_V2_MemToPhy");
    p_Secure_V2_MemFlush = (fn_Secure_V2_MemFlush_t)dlsym(secmem_dl, "Secure_V2_MemFlush");
    p_Secure_V2_GetVp9HeaderSize =
            (fn_Secure_V2_GetVp9HeaderSize_t)dlsym(secmem_dl, "Secure_V2_GetVp9HeaderSize");
    p_Teec_PackUInt = (fn_Teec_PackUInt_t)dlsym(secmem_dl, "Teec_PackUInt");
    p_Teec_UnPackUInt = (fn_Teec_UnPackUInt_t)dlsym(secmem_dl, "Teec_UnPackUInt");
    p_Teec_Invoke = (fn_Teec_Invoke_t)dlsym(secmem_dl, "Teec_Invoke");
    p_TEEC_CloseSession = (fn_TEEC_CloseSession_t)dlsym(secmem_dl, "TEEC_CloseSession");
    p_TEEC_FinalizeContext = (fn_TEEC_FinalizeContext_t)dlsym(secmem_dl, "TEEC_FinalizeContext");
    p_releaseshm = (fn_releaseshm_t)dlsym(secmem_dl, "_Z10releaseshmP12secmem_ctx_t");
    p_secmem_resman_acquire = (fn_secmem_resman_acquire_t)dlsym(secmem_dl, "secmem_resman_acquire");

    void *amav_dl = dlopen("libamavutils.so", RTLD_NOLOAD | RTLD_NOW);
    if (!amav_dl) {
        amav_dl = RTLD_DEFAULT;
    }
    p_tvp_mm_enable = (fn_tvp_mm_enable_t)dlsym(amav_dl, "tvp_mm_enable");
    p_tvp_mm_disable = (fn_tvp_mm_disable_t)dlsym(amav_dl, "tvp_mm_disable");

    ALOGI("Resolved libsecmem syms: Init=%p Close=%p Create=%p Free=%p ToPhy=%p Flush=%p Vp9Hdr=%p CloseSess=%p FinCtx=%p RelShm=%p TvpDis=%p",
          p_Secure_V2_Init, p_Secure_V2_Close, p_Secure_V2_MemCreate,
          p_Secure_V2_MemFree, p_Secure_V2_MemToPhy, p_Secure_V2_MemFlush,
          p_Secure_V2_GetVp9HeaderSize, p_TEEC_CloseSession,
          p_TEEC_FinalizeContext, p_releaseshm, p_tvp_mm_disable);
}

/*
 * Resolves a secmem handle (0xe2e0XXXX) to its physical address in the TVP pool.
 *
 * Uses Secure_V2_MemToPhy (CMD 0xff in secmem.ta), which calls
 * Secmem_V2_HandleToPhy -> Secmem_V2_FindBlockNode across all active sessions
 * in g_session_list without checking rpc_peer (unlike CMD 0x100 which restricts
 * callers to wv.ta).
 *
 * In Android 10 libsecmem.so, secmem_ctx_t layout (0x60 bytes) is:
 *   +0x00: uint32_t initialized (1 after SessionCreate / Init)
 *   +0x04: TEEC_Context
 *   +0x08: TEEC_Session
 *   +0x10: TEEC_SharedMemory (4KB command buffer)
 *   +0x2c: TEEC_SharedMemory (100KB buffer)
 *   +0x48: uint32_t tvp_mode (2 = resource manager, 1 = tvp_mm_enable)
 *   +0x4c: uint32_t tvp_set (1 = 1080p, 2 = 4K)
 *   +0x58: int32_t  resman_handle
 */
static uint32_t secmem_handle_to_phy(void *sess, uint32_t handle, uint32_t *paddr) {
    pthread_once(&g_syms_once, resolve_secmem_syms);
    if (!sess || !paddr) return 1;
    uint32_t *ctx = (uint32_t *)sess;
    if (ctx[0] == 0) return 1;

    if (p_Secure_V2_MemToPhy) {
        uint32_t res = p_Secure_V2_MemToPhy(sess, handle, paddr);
        if (res == 0 && *paddr != 0) {
            return 0;
        }
    }

    if (p_Teec_PackUInt && p_Teec_UnPackUInt && p_Teec_Invoke) {
        uint8_t *base = (uint8_t *)sess;
        void *teec_sess = base + 0x08;
        void *shm = base + 0x10;
        uint32_t in_off = 0;
        uint32_t out_off = 0;
        uint32_t res = 0;

        res = p_Teec_PackUInt(shm, TA_SECMEM_V2_CMD_MEM_TO_PHY, &in_off);
        if (res == 0) res = p_Teec_PackUInt(shm, handle, &in_off);
        if (res == 0) res = p_Teec_Invoke(teec_sess, TA_SECMEM_V2_CMD_MEM_TO_PHY, shm);
        if (res == 0) res = p_Teec_UnPackUInt(shm, paddr, &out_off);
        if (res == 0 && *paddr != 0) {
            return 0;
        }
    }

    return 1;
}

/*
 * Helper to invoke Secmem_V2_Parse (CMD 0x117) in secmem.ta:
 *   in:  [CMD=0x117, parse_type, handle]
 *   out: [added_bytes]
 */
static uint32_t secmem_invoke_parse(void *sess, uint32_t parse_type,
                                    uint32_t handle, uint32_t *out_added_size) {
    pthread_once(&g_syms_once, resolve_secmem_syms);
    if (!sess || !p_Teec_PackUInt || !p_Teec_UnPackUInt || !p_Teec_Invoke) return 1;
    uint32_t *ctx = (uint32_t *)sess;
    if (ctx[0] == 0) return 1;

    uint8_t *base = (uint8_t *)sess;
    void *teec_sess = base + 0x08;
    void *shm = base + 0x10;
    uint32_t in_off = 0;
    uint32_t out_off = 0;
    uint32_t res = 0;

    res = p_Teec_PackUInt(shm, TA_SECMEM_V2_CMD_PARSE, &in_off);
    if (res == 0) res = p_Teec_PackUInt(shm, parse_type, &in_off);
    if (res == 0) res = p_Teec_PackUInt(shm, handle, &in_off);
    if (res == 0) res = p_Teec_Invoke(teec_sess, TA_SECMEM_V2_CMD_PARSE, shm);
    if (res == 0 && out_added_size) {
        uint32_t parsed_size = 0;
        if (p_Teec_UnPackUInt(shm, &parsed_size, &out_off) == 0) {
            *out_added_size = parsed_size;
        }
    }
    return res;
}

/*
 * Called by SecureVdecPool::enable_tvp_sync / enable_secure_stream_out:
 *   Secure_V2_EnableTVPMemory(mSecmemSession, tvp_set)
 *   tvp_set: 1 (1080p) or 2 (4K)
 *
 * Replicates Secure_ProtectMem() from Android 10 libsecmem.so (0x3440)
 * using secmem_resman_acquire() or tvp_mm_enable().
 */
uint32_t Secure_V2_EnableTVPMemory(void *sess, uint32_t tvp_set) {
    pthread_once(&g_syms_once, resolve_secmem_syms);
    if (!sess) return 1;

    uint32_t *ctx = (uint32_t *)sess;
    uint32_t actual_set = tvp_set ? (tvp_set & 0xf) : 1;
    uint32_t tvp_mode = ctx[0x48 / 4];
    int32_t resman_id = (int32_t)ctx[0x58 / 4];
    int rc = 0;

    if (p_tvp_mm_enable) {
        rc = p_tvp_mm_enable((int)actual_set);
    } else if (tvp_mode >= 2 && resman_id >= 0 && p_secmem_resman_acquire) {
        rc = p_secmem_resman_acquire(resman_id, (int)actual_set, 3);
    }

    ctx[0x4c / 4] = actual_set;
    ALOGI("Secure_V2_EnableTVPMemory(sess=%p, tvp_set=%u, mode=%u, resman=%d) -> rc=%d",
          sess, actual_set, tvp_mode, resman_id, rc);
    return 0;
}

/*
 * Tears down the underlying TEEC session & shared memory in secmem_ctx_t so a
 * subsequent Secure_V2_Init() opens a fresh TA session (with sess->config == 0).
 * Mirrors libsecmem.so internal teardown at 0x3f0c.
 */
static void secmem_reset_teec_session(void *sess) {
    uint32_t *ctx = (uint32_t *)sess;
    if (!ctx || ctx[0] == 0) return;

    uint8_t *base = (uint8_t *)sess;
    if (p_TEEC_CloseSession) {
        p_TEEC_CloseSession(base + 0x08);
    }
    if (p_TEEC_FinalizeContext) {
        p_TEEC_FinalizeContext(base + 0x04);
    }
    if (p_releaseshm) {
        p_releaseshm(sess);
    }
    ctx[0] = 0;
}

/*
 * Called by SecureVdecPool::create_secure_channel / update_frame_info:
 *   Secure_V2_InitSecurePool(mSecmemSession, 1, 0, 2, dmabuf_fd)
 */
uint32_t Secure_V2_InitSecurePool(void *sess, uint32_t src, uint32_t flags,
                                  uint32_t mode, uint32_t dmabuf_fd) {
    pthread_once(&g_syms_once, resolve_secmem_syms);
    if (!sess) return 1;

    uint32_t *ctx = (uint32_t *)sess;
    uint32_t saved_tvp_set = ctx[0x4c / 4];
    uint32_t actual_set = saved_tvp_set ? (saved_tvp_set & 0xf) : 1;

    /*
     * In Android 10 Secure_V2_Init(sess, src, packed_flags, paddr, size):
     *   mode       = (packed_flags >> 13) & 0xf
     *   vdec_type  = (packed_flags >> 9) & 0xf
     *   codec_flag = (packed_flags >> 4) & 0xf  (1 = VP9 bit0, 2 = AV1 bit10, 3 = small)
     *   tvp_set    = packed_flags & 0xf
     *
     * Default codec_flag to 1 (VP9 bit0) when flags == 0: for H.264/HEVC this only
     * adds 0x80 bytes of allocation headroom in Secmem_V2_MemAlloc_, while enabling
     * CMD 0xd0 (Secure_V2_GetVp9HeaderSize) with full TEE_CacheClean(len + 0x84)
     * when Secure_V2_UpdateFrameInfo receives VP9 frames.
     */
    uint32_t codec_flag = (flags & 0xf) ? (flags & 0xf) : 1U;
    uint32_t packed_flags = (1U << 9) | (codec_flag << 4) | actual_set;

    uint32_t ret = 0;
    if (p_Secure_V2_Init) {
        ret = p_Secure_V2_Init(sess, src, packed_flags, 0, 0);
        if (ret != 0 && actual_set > 1) {
            /*
             * On Android 10 secmem.ta, tvp_set == 2 (config & 0x100) requests a
             * 12 MB ES pool; if the kernel dmabuf_manage session also holds part
             * of OP-TEE's secure ES pool, Secmem_V2_PoolAlloc fails with 0x1006.
             * Reopen a fresh TA session and fall back to tvp_set == 1 (4 MB ES
             * pool; the 240 MB 4K TVP frame-buffer pool in CMA is unaffected).
             */
            uint32_t fallback_flags = (1U << 9) | (codec_flag << 4) | 1U;
            ALOGW("Secure_V2_InitSecurePool: packed=0x%x failed (ret=0x%x), retrying with 4MB ES pool (packed=0x%x)",
                  packed_flags, ret, fallback_flags);
            secmem_reset_teec_session(sess);
            packed_flags = fallback_flags;
            ret = p_Secure_V2_Init(sess, src, packed_flags, 0, 0);
        }
    }
    ctx[0x4c / 4] = actual_set;

    ALOGI("Secure_V2_InitSecurePool(sess=%p, src=%u, flags=0x%x, req_mode=%u, fd=%u) -> packed=0x%x ret=0x%x",
          sess, src, flags, mode, dmabuf_fd, packed_flags, ret);
    return ret;
}

/*
 * Called by SecureVdecPool::~SecureVdecPool:
 *   Secure_V2_DestroySecurePool(mSecmemSession)
 */
uint32_t Secure_V2_DestroySecurePool(void *sess) {
    pthread_once(&g_syms_once, resolve_secmem_syms);
    ALOGI("Secure_V2_DestroySecurePool(sess=%p)", sess);
    if (!sess) return 0;
    uint32_t out = 0;
    uint32_t ret = 0;
    if (p_Secure_V2_Close) {
        ret = p_Secure_V2_Close(sess, &out);
    }
    uint32_t *ctx = (uint32_t *)sess;
    if (p_tvp_mm_enable && p_tvp_mm_disable && ctx[0x4c / 4] != 0) {
        p_tvp_mm_disable(0);
        ctx[0x4c / 4] = 0;
    }
    return ret;
}

/*
 * Called by SecureVdecPool::flush_vdec_pool:
 *   Secure_V2_PoolFlush(mSecmemSession)
 */
uint32_t Secure_V2_PoolFlush(void *sess) {
    pthread_once(&g_syms_once, resolve_secmem_syms);
    ALOGI("Secure_V2_PoolFlush(sess=%p)", sess);
    if (!sess) return 0;
    if (p_Secure_V2_MemFlush) {
        p_Secure_V2_MemFlush(sess);
    }
    return 0;
}

/*
 * Called by SecureVdecPool::update_frame_info (0xda4c8 in libmediahal_videodec.so):
 *   Secure_V2_UpdateFrameInfo(mSecmemSession, codec_type, dmabuf_fd, flags, pFrameSize)
 *
 * NOTE:
 *   - r0 (arg0): mSecmemSession
 *   - r1 (arg1): codec_type (0 = H264/HEVC, 1 = VP9, 2 = AV1)
 *   - r2 (arg2): dmabuf_fd
 *   - r3 (arg3): flags
 *   - [sp] (arg4): pFrameSize (IN/OUT parameter holding the input frame's byte size!)
 *
 * V4L2VideoDecodeAccelerator::AppendToSecureInputFrame sets input_record.bytes_used
 * to offset + *pFrameSize after update_frame_info returns. Never zero *pFrameSize!
 *
 * Responsibilities on kernel 5.15 amlogic_secure_dmabuf:
 *   1. mmap(dmabuf_fd) to access struct secure_block_info.
 *   2. If block->version == SECURE_HEAP_USER_TA_VERSION (3), query the physical
 *      address for the active handle (block->unused if already switched to an
 *      mSecmemSession handle, or block->handle on first use) via Secure_V2_MemToPhy.
 *   3. If VP9/AV1 header rebuild is requested (flags & 0x10), invoke Secmem_V2_Parse
 *      (CMD 0x117) and add any inserted AMLV header bytes to *pFrameSize.
 *   4. Set block->paddr = paddr, block->psize = block->size,
 *      block->state = AML_SECURE_DMABUF_HEAP_SETTING_PHYADDR (3),
 *      and trigger secure_heap_mmap() a second time so the kernel binds
 *      buffer->sg_table.sgl->dma_address = block->paddr for V4L2 decoder input!
 *   5. Free the handle's ring-buffer allocation in mSecmemSession via
 *      Secure_V2_MemFree (CMD 0x102) (or allocate an mSecmemSession handle via
 *      Secure_V2_MemCreate on first use and store it in block->unused) so that
 *      when Codec2 reuses this dmabuf_fd for a subsequent frame, node->data_paddr
 *      in secmem.ta is 0 and wv.ta allocates a fresh ring-buffer slot.
 */
uint32_t Secure_V2_UpdateFrameInfo(void *sess, uint32_t codec_type, uint32_t dmabuf_fd,
                                   uint32_t flags, uint32_t *pFrameSize) {
    pthread_once(&g_syms_once, resolve_secmem_syms);

    if ((dmabuf_fd >> 16) != 0) {
        return 0;
    }

    size_t map_len = sizeof(struct secure_block_info);
    struct secure_block_info *block = (struct secure_block_info *)mmap(
            NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, (int)dmabuf_fd, 0);
    if (block == MAP_FAILED) {
        ALOGE("Secure_V2_UpdateFrameInfo: mmap(fd=%u) failed: %s", dmabuf_fd, strerror(errno));
        return 0;
    }

    uint32_t ver = block->version;
    uint32_t kernel_handle = block->handle;
    uint32_t vdec_handle = block->unused;
    uint32_t active_handle = ((vdec_handle >> 20) == 0xe2e) ? vdec_handle : kernel_handle;
    uint32_t paddr = block->paddr;
    uint32_t size = block->size;

    if (ver == SECURE_HEAP_USER_TA_VERSION && (active_handle >> 20) == 0xe2e) {
        uint32_t resolved_paddr = 0;
        uint32_t ret = secmem_handle_to_phy(sess, active_handle, &resolved_paddr);
        if (ret == 0 && resolved_paddr != 0) {
            paddr = resolved_paddr;
        } else if (paddr == 0) {
            ALOGW("Secure_V2_UpdateFrameInfo: fd=%u handle=0x%x phy lookup failed (ret=0x%x)",
                  dmabuf_fd, active_handle, ret);
        }

        /*
         * In V4L2VideoDecodeAccelerator:
         *   codec_type == 0: H264 / HEVC / Legacy
         *   codec_type == 1: VP9 (flags & 0x10)
         *   codec_type == 2: AV1 (flags & 0x10)
         *
         * In Android 10 secmem.ta:
         *   - Secmem_V2_Parse (CMD 0x117) shifts the VP9 frame by +16*N bytes
         *     but calls TEE_CacheClean(vaddr, orig_data_size) (0x190e..0x1916),
         *     leaving the last 16*N bytes unflushed in CPU D-cache!
         *   - Secmem_V2_GetFrameHeaderSize (CMD 0xd0, Secure_V2_GetVp9HeaderSize)
         *     calls the same parser_vp9_add_header() and then calls
         *     TEE_CacheClean(vaddr, frame_len + 0x84) (0x4160..0x4166), cleanly
         *     flushing the entire shifted frame + 4-byte trailer to DRAM.
         *     CMD 0xd0 requires paddr to lie inside mSecmemSession's pool, so use
         *     it for all mSecmemSession-owned frames (vdec_handle) and fall back
         *     to CMD 0x117 for initial kernel_handle frames or AV1.
         */
        if (flags & 0x10) {
            uint32_t orig_size = pFrameSize ? *pFrameSize : 0;
            int parsed = 0;

            if (codec_type == 1 && (vdec_handle >> 20) == 0xe2e &&
                paddr != 0 && orig_size > 0 && p_Secure_V2_GetVp9HeaderSize) {
                uint32_t hdr_size = 0;
                uint32_t frame_sizes[8];
                memset(frame_sizes, 0, sizeof(frame_sizes));
                uint32_t vp9_ret = p_Secure_V2_GetVp9HeaderSize(
                        sess, paddr, orig_size, &hdr_size, frame_sizes);
                if (vp9_ret == 0) {
                    uint32_t total_len = 0;
                    for (int i = 0; i < 8; i++) {
                        total_len += frame_sizes[i];
                    }
                    if (total_len > orig_size && total_len <= orig_size + 0x200) {
                        *pFrameSize = total_len;
                        parsed = 1;
                    } else if (hdr_size > 0 && hdr_size <= 0x200) {
                        *pFrameSize = orig_size + hdr_size;
                        parsed = 1;
                    }
                } else {
                    ALOGW("Secure_V2_UpdateFrameInfo: GetVp9HeaderSize(paddr=0x%x, len=%u) failed (ret=0x%x), falling back to Parse",
                          paddr, orig_size, vp9_ret);
                }
            }

            if (!parsed) {
                uint32_t parse_type = 0;
                if (codec_type == 1) {
                    parse_type = SECMEM_PARSE_VP9;
                } else if (codec_type == 2) {
                    parse_type = SECMEM_PARSE_AV1;
                }
                if (parse_type != 0) {
                    uint32_t added_bytes = 0;
                    uint32_t parse_ret = secmem_invoke_parse(sess, parse_type, active_handle, &added_bytes);
                    if (parse_ret == 0 && pFrameSize && added_bytes > 0 && added_bytes <= 0x200) {
                        *pFrameSize += added_bytes;
                    } else if (parse_ret != 0) {
                        ALOGW("Secure_V2_UpdateFrameInfo: Secmem_V2_Parse(type=%u, handle=0x%x) failed (ret=0x%x)",
                              parse_type, active_handle, parse_ret);
                    }
                }
            }
        }

        if (paddr != 0) {
            block->paddr = paddr;
            block->psize = size;
            block->state = AML_SECURE_DMABUF_HEAP_SETTING_PHYADDR;

            /* Second mmap triggers secure_heap_mmap() in kernel to bind sgl->dma_address */
            void *bind_map = mmap(NULL, map_len, PROT_READ | PROT_WRITE,
                                  MAP_SHARED, (int)dmabuf_fd, 0);
            if (bind_map != MAP_FAILED) {
                munmap(bind_map, map_len);
            } else {
                ALOGE("Secure_V2_UpdateFrameInfo: bind mmap(fd=%u, paddr=0x%x) failed: %s",
                      dmabuf_fd, paddr, strerror(errno));
            }
        }

        /*
         * When (flags & 0x4) == 0, the complete input frame has now been bound to
         * sgl->dma_address for V4L2. Reset the handle's ring-buffer data pointer in
         * secmem.ta (or attach an mSecmemSession-owned handle in block->unused on
         * first use) so the next frame reusing this dmabuf_fd gets a fresh allocation.
         */
        if ((flags & 0x4) == 0) {
            if ((vdec_handle >> 20) == 0xe2e) {
                if (p_Secure_V2_MemFree) {
                    p_Secure_V2_MemFree(sess, vdec_handle);
                }
            } else if (p_Secure_V2_MemCreate) {
                uint32_t new_handle = 0;
                uint32_t cr = p_Secure_V2_MemCreate(sess, &new_handle);
                if (cr == 0 && (new_handle >> 20) == 0xe2e) {
                    block->unused = new_handle;
                } else {
                    ALOGW("Secure_V2_UpdateFrameInfo: Secure_V2_MemCreate failed (ret=0x%x, handle=0x%x)",
                          cr, new_handle);
                }
            }
        }
    }

    munmap(block, map_len);
    return 0;
}

/*
 * Called by SecureVdecPool::acquire_free_slot_number (0xda5be in libmediahal_videodec.so):
 *   Secure_V2_GetFreeBlockCount(mSecmemSession, dmabuf_fd, min_size, &allocated_count, &max_count)
 *
 * SecureVdecPool computes:
 *   free_slots = 8 - (allocated_count + vdec_queued_count)
 */
uint32_t Secure_V2_GetFreeBlockCount(void *sess, int dmabuf_fd, int min_size,
                                     int *pAllocatedCount, int *pMaxCount) {
    (void)sess;
    (void)dmabuf_fd;
    (void)min_size;
    if (pAllocatedCount) *pAllocatedCount = 0;
    if (pMaxCount) *pMaxCount = 8;
    return 0;
}
