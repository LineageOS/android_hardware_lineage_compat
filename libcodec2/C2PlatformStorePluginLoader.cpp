/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <C2PlatformStorePluginLoader.h>

extern "C" c2_status_t
_ZN27C2PlatformStorePluginLoader15createAllocatorEjPNSt3__110shared_ptrI11C2AllocatorEE(
        C2PlatformStorePluginLoader* loader, C2Allocator::id_t allocatorId,
        std::shared_ptr<C2Allocator>* allocator) {
    return loader->createAllocator(allocatorId, allocator);
}

extern "C" c2_status_t
_ZN27C2PlatformStorePluginLoader15createBlockPoolEjmPNSt3__110shared_ptrI11C2BlockPoolEE(
        C2PlatformStorePluginLoader* loader, C2Allocator::id_t allocatorId,
        C2BlockPool::local_id_t blockPoolId, std::shared_ptr<C2BlockPool>* pool) {
    return loader->createBlockPool(allocatorId, blockPoolId, pool);
}
