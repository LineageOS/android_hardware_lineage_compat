#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.frameworks.stats-V1-ndk
LOCAL_MODULE := android.frameworks.stats-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.frameworks.stats-V1-ndk
LOCAL_MODULE := android.frameworks.stats-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.frameworks.stats-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.common-V1-ndk
LOCAL_MODULE := android.hardware.common-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.common-V1-ndk
LOCAL_MODULE := android.hardware.common-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.common-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.common-V2-ndk
LOCAL_MODULE := android.hardware.common-V2-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.common-V2-ndk
LOCAL_MODULE := android.hardware.common-V2-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.common-V2-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.common.fmq-V1-ndk
LOCAL_MODULE := android.hardware.common.fmq-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.common.fmq-V1-ndk
LOCAL_MODULE := android.hardware.common.fmq-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.common.fmq-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.graphics.common-V1-ndk
LOCAL_MODULE := android.hardware.graphics.common-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.graphics.common-V1-ndk
LOCAL_MODULE := android.hardware.graphics.common-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.graphics.common-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.graphics.common-V2-ndk
LOCAL_MODULE := android.hardware.graphics.common-V2-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.graphics.common-V2-ndk
LOCAL_MODULE := android.hardware.graphics.common-V2-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.graphics.common-V2-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.authsecret-V1-ndk
LOCAL_MODULE := android.hardware.authsecret-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.authsecret-V1-ndk
LOCAL_MODULE := android.hardware.authsecret-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.authsecret-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.automotive.occupant_awareness-V1-ndk
LOCAL_MODULE := android.hardware.automotive.occupant_awareness-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.automotive.occupant_awareness-V1-ndk
LOCAL_MODULE := android.hardware.automotive.occupant_awareness-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.automotive.occupant_awareness-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.gnss-V1-ndk
LOCAL_MODULE := android.hardware.gnss-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.gnss-V1-ndk
LOCAL_MODULE := android.hardware.gnss-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.gnss-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.health.storage-V1-ndk
LOCAL_MODULE := android.hardware.health.storage-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.health.storage-V1-ndk
LOCAL_MODULE := android.hardware.health.storage-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.health.storage-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.identity-V2-ndk
LOCAL_MODULE := android.hardware.identity-V2-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.identity-V2-ndk
LOCAL_MODULE := android.hardware.identity-V2-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.identity-V2-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.identity-V3-ndk
LOCAL_MODULE := android.hardware.identity-V3-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.identity-V3-ndk
LOCAL_MODULE := android.hardware.identity-V3-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.identity-V3-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.keymaster-V2-ndk
LOCAL_MODULE := android.hardware.keymaster-V2-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.keymaster-V2-ndk
LOCAL_MODULE := android.hardware.keymaster-V2-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.keymaster-V2-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.keymaster-V3-ndk
LOCAL_MODULE := android.hardware.keymaster-V3-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.keymaster-V3-ndk
LOCAL_MODULE := android.hardware.keymaster-V3-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.keymaster-V3-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.light-V1-ndk
LOCAL_MODULE := android.hardware.light-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.light-V1-ndk
LOCAL_MODULE := android.hardware.light-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.light-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.memtrack-V1-ndk
LOCAL_MODULE := android.hardware.memtrack-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.memtrack-V1-ndk
LOCAL_MODULE := android.hardware.memtrack-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.memtrack-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.oemlock-V1-ndk
LOCAL_MODULE := android.hardware.oemlock-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.oemlock-V1-ndk
LOCAL_MODULE := android.hardware.oemlock-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.oemlock-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.power-V1-ndk
LOCAL_MODULE := android.hardware.power-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.power-V1-ndk
LOCAL_MODULE := android.hardware.power-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.power-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.power-V2-ndk
LOCAL_MODULE := android.hardware.power-V2-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.power-V2-ndk
LOCAL_MODULE := android.hardware.power-V2-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.power-V2-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.power.stats-V1-ndk
LOCAL_MODULE := android.hardware.power.stats-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.power.stats-V1-ndk
LOCAL_MODULE := android.hardware.power.stats-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.power.stats-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.rebootescrow-V1-ndk
LOCAL_MODULE := android.hardware.rebootescrow-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.rebootescrow-V1-ndk
LOCAL_MODULE := android.hardware.rebootescrow-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.rebootescrow-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.security.keymint-V1-ndk
LOCAL_MODULE := android.hardware.security.keymint-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.security.keymint-V1-ndk
LOCAL_MODULE := android.hardware.security.keymint-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.security.keymint-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.security.secureclock-V1-ndk
LOCAL_MODULE := android.hardware.security.secureclock-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.security.secureclock-V1-ndk
LOCAL_MODULE := android.hardware.security.secureclock-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.security.secureclock-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.security.sharedsecret-V1-ndk
LOCAL_MODULE := android.hardware.security.sharedsecret-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.security.sharedsecret-V1-ndk
LOCAL_MODULE := android.hardware.security.sharedsecret-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.security.sharedsecret-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.vibrator-V1-ndk
LOCAL_MODULE := android.hardware.vibrator-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.vibrator-V1-ndk
LOCAL_MODULE := android.hardware.vibrator-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.vibrator-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.vibrator-V2-ndk
LOCAL_MODULE := android.hardware.vibrator-V2-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.vibrator-V2-ndk
LOCAL_MODULE := android.hardware.vibrator-V2-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.vibrator-V2-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.weaver-V1-ndk
LOCAL_MODULE := android.hardware.weaver-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.hardware.weaver-V1-ndk
LOCAL_MODULE := android.hardware.weaver-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.hardware.weaver-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.system.keystore2-V1-ndk
LOCAL_MODULE := android.system.keystore2-V1-ndk_platform
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SYSTEM_EXT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := android.system.keystore2-V1-ndk
LOCAL_MODULE := android.system.keystore2-V1-ndk_platform.vendor
LOCAL_INSTALLED_MODULE_STEM := android.system.keystore2-V1-ndk_platform.so
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)
