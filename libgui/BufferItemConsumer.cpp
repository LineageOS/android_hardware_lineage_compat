/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <functional>
#include <optional>

#include <gui/BufferItem.h>
#include <ui/Fence.h>
#include <ui/GraphicBuffer.h>
#include <utils/Errors.h>
#include <utils/Timers.h>

using android::BufferItem;
using android::Fence;
using android::GraphicBuffer;
using android::sp;
using android::status_t;

using BufferFreedCallback = std::function<void(const sp<GraphicBuffer>&)>;

// android::BufferItemConsumer::acquireBuffer(
//         BufferItem*, nsecs_t, bool, std::optional<BufferFreedCallback>)
extern "C" status_t
_ZN7android18BufferItemConsumer13acquireBufferEPNS_10BufferItemElbNSt3__18optionalINS3_8functionIFvRKNS_2spINS_13GraphicBufferEEEEEEEE(
        void* thisptr, BufferItem* item, nsecs_t presentWhen, bool waitForFence,
        std::optional<BufferFreedCallback> onBufferFreed);

// android::BufferItemConsumer::acquireBuffer(BufferItem*, nsecs_t, bool)
extern "C" status_t _ZN7android18BufferItemConsumer13acquireBufferEPNS_10BufferItemElb(
        void* thisptr, BufferItem* item, nsecs_t presentWhen, bool waitForFence) {
    return _ZN7android18BufferItemConsumer13acquireBufferEPNS_10BufferItemElbNSt3__18optionalINS3_8functionIFvRKNS_2spINS_13GraphicBufferEEEEEEEE(
            thisptr, item, presentWhen, waitForFence, std::nullopt);
}

// android::BufferItemConsumer::releaseBuffer(
//         const BufferItem&, const sp<Fence>&, std::optional<BufferFreedCallback>)
extern "C" status_t
_ZN7android18BufferItemConsumer13releaseBufferERKNS_10BufferItemERKNS_2spINS_5FenceEEENSt3__18optionalINS9_8functionIFvRKNS4_INS_13GraphicBufferEEEEEEEE(
        void* thisptr, const BufferItem& item, const sp<Fence>& releaseFence,
        std::optional<BufferFreedCallback> onBufferFreed);

// android::BufferItemConsumer::releaseBuffer(const BufferItem&, const sp<Fence>&)
extern "C" status_t
_ZN7android18BufferItemConsumer13releaseBufferERKNS_10BufferItemERKNS_2spINS_5FenceEEE(
        void* thisptr, const BufferItem& item, const sp<Fence>& releaseFence) {
    return _ZN7android18BufferItemConsumer13releaseBufferERKNS_10BufferItemERKNS_2spINS_5FenceEEENSt3__18optionalINS9_8functionIFvRKNS4_INS_13GraphicBufferEEEEEEEE(
            thisptr, item, releaseFence, std::nullopt);
}
