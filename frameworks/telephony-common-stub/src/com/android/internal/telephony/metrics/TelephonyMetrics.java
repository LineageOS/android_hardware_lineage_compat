/*
 * SPDX-FileCopyrightText: 2026 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

package com.android.internal.telephony.metrics;

public class TelephonyMetrics {
    private static TelephonyMetrics sInstance = null;

    public static TelephonyMetrics getInstance() {
        if (sInstance == null) {
            sInstance = new TelephonyMetrics();
        }
        return sInstance;
    }

    public void writeDroppedIncomingMultipartSms(int phoneId, String format, int receivedCount, int totalCount) {}
    public void writeOnRilSolicitedResponse(int phoneId, int rilSerial, int rilError, int rilRequest, Object ret) {}
    public void writeOnRilTimeoutResponse(int phoneId, int rilSerial, int rilRequest) {}
    public void writeRilAnswer(int phoneId, int rilSerial) {}
    public void writeRilSendSms(int phoneId, int rilSerial, int tech, int format, long messageId) {}
}
