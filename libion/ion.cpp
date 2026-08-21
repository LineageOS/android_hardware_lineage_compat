/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <unistd.h>

#include <ion/ion.h>

int ion_close(int fd)
{
    int ret = close(fd);
    if (ret < 0) return -errno;
    return ret;
}
