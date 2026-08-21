/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <unistd.h>

extern "C" int ion_close(int fd) {
    return close(fd) < 0 ? -errno : 0;
}
