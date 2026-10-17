/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <C2BufferPriv.h>

extern "C" void
pooledBlockPoolCurrent(C2PooledBlockPool* self, const std::shared_ptr<C2Allocator>& allocator, C2BlockPool::local_id_t localId, C2PooledBlockPool::BufferPoolVer ver) __asm__(
        "_ZN17C2PooledBlockPoolC1ERKNSt3__110shared_ptrI11C2AllocatorEEmNS_13BufferPoolVerE");

extern "C" void pooledBlockPoolLegacy(
        C2PooledBlockPool* self, const std::shared_ptr<C2Allocator>& allocator,
        C2BlockPool::local_id_t
                localId) __asm__("_ZN17C2PooledBlockPoolC1ERKNSt3__110shared_ptrI11C2AllocatorEEm");

// Constructor symbols receive the implicit this pointer before their declared arguments.
extern "C" void pooledBlockPoolLegacy(C2PooledBlockPool* self,
                                      const std::shared_ptr<C2Allocator>& allocator,
                                      C2BlockPool::local_id_t localId) {
    pooledBlockPoolCurrent(self, allocator, localId, C2PooledBlockPool::VER_HIDL);
}
