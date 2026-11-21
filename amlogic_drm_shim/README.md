# Amlogic Widevine L1 DRM & Secmem V2 Shims for `nicepool` (`fbx8am`)

## Problem Summary
`nicepool` runs 32-bit Android 10 proprietary TEE/DRM blobs (`liboemcrypto.so`, `libsecmem.so`, `e043cde0-61d0-11e5-9c260002a5d5c51b.ta` Widevine TA, `2c1a33c0-44cc-11e5-bc3b0002a5d5c51b.ta` Secmem TA) on top of Android 14+ Codec2 (`libcodec2_aml_video_decoder.so`, `libmediahal_videodec.so`, `libmediahal_dmabufmanage.so`) and the 5.15 kernel (`amlogic_secure_dmabuf.c`, `dmabuf_manage.c`).

Two ABI mismatches break Widevine L1 secure playback:

1. **Dmabuf FD vs. Secmem Handle in `liboemcrypto.so` (`_oecc48`, `_oecc93`, `_oecc1501`)**:
   - Codec2 allocates secure input buffers from `/dev/dma_heap/system-secure-uncached` (`amlogic_secure_dmabuf.c`), which wraps a 1-page `struct secure_block_info` containing `version = 3` (`SECURE_HEAP_USER_TA_VERSION`) and `handle = 0xe2e0XXXX` (from `TA_SECMEM_V2_CMD_MEM_CREATE = 251`), and passes the dmabuf file descriptor in `native_handle->data[0]`.
   - Stock Android 10 `liboemcrypto.so` expects `native_handle->data[0]` to be the `0xe2e0XXXX` secmem handle directly, so it passes the raw dmabuf FD to `wv.ta`, which fails in `TEE_Vdec_Mmap_Cached` (`0xffff0006` -> `OEMCrypto_DecryptCENC` status `28`).
   - **Solution (`liboemcrypto_shim`)**: Installed as `/vendor/lib/liboemcrypto.so` (with stock binary moved to `/vendor/lib/liboemcrypto_vendor.so`), `mmap`s the dmabuf FD in `_oecc48`, `_oecc93`, and `_oecc1501` to extract the active secmem handle (`block->unused` once recycled into `mSecmemSession`, or `block->handle` on initial use), and passes a stack-copied `native_handle_t` with `data[0] = active_handle` to the vendor library.

2. **Missing Secmem V2 Codec2 Wrapper Symbols, Physical Address Binding, VP9 Header Parsing, and 4K Pool Sizing in `libsecmem.so`**:
   - `libmediahal_videodec.so` (`SecureVdecPool`) `dlsym`s 6 V2 functions from `libsecmem.so` that do not exist in Android 10 `libsecmem.so`:
     - `Secure_V2_InitSecurePool`
     - `Secure_V2_EnableTVPMemory`
     - `Secure_V2_DestroySecurePool`
     - `Secure_V2_UpdateFrameInfo`
     - `Secure_V2_GetFreeBlockCount`
     - `Secure_V2_PoolFlush`
   - For `version == 3` secure dmabufs, physical memory in `secmem.ta` is allocated lazily by `wv.ta` via `Secmem_V2_MemAllocRPC` (`CMD 0xfe`) during `OEMCrypto_DecryptCENC`. Before V4L2 queues the input dmabuf, `Secure_V2_UpdateFrameInfo`:
     - Resolves the active `0xe2e0XXXX` handle to its physical address via `Secure_V2_MemToPhy` (`CMD 0xff`).
     - For VP9 (`flags & 0x10`), invokes `Secure_V2_GetVp9HeaderSize` (`CMD 0xd0`, which cleans `frame_len + 0x84` bytes of CPU D-cache after prepending AMLV headers) for `mSecmemSession`-owned frames, falling back to `Secmem_V2_Parse` (`CMD 0x117`) for initial kernel handles or AV1.
     - Writes `block->paddr`, `block->psize`, and `block->state = AML_SECURE_DMABUF_HEAP_SETTING_PHYADDR` (`3`) and triggers a second `mmap()` so `secure_heap_mmap()` updates `buffer->sg_table.sgl->dma_address`.
     - Recycles per-dmabuf handles in `mSecmemSession` via `Secure_V2_MemCreate`/`Secure_V2_MemFree` (`block->unused`) so reused Codec2 input buffers allocate fresh ring-buffer slots.
   - `Secure_V2_InitSecurePool` falls back from `tvp_set == 2` (12 MB ES pool) to `tvp_set == 1` (4 MB ES pool) after reopening the TEEC session if OP-TEE's 16 MB ES pool cannot fit a second 12 MB allocation, and `Secure_V2_DestroySecurePool` balances `tvp_mm_enable()` with `tvp_mm_disable(0)`.
   - **Solution (`libsecmem_shim`)**: Added via `patchelf --add-needed libsecmem_shim.so` to `/vendor/lib/libsecmem.so`.
