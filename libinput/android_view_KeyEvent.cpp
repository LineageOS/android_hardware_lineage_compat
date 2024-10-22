/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android_view_KeyEvent.h>
#include <input/Input.h>

namespace android {

jobject android_view_KeyEvent_fromNative(JNIEnv* env, const KeyEvent& event)
{
    return android_view_KeyEvent_obtainAsCopy(env, event).release();
}

KeyEvent android_view_KeyEvent_toNative(JNIEnv* env, jobject eventObj)
{
    return android_view_KeyEvent_obtainAsCopy(env, eventObj);
}

}
