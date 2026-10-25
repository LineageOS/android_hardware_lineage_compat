/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <hardware_legacy/uevent.h>
#include <poll.h>
#include <sys/socket.h>

int uevent_next_event_timeout(char* buffer, int buffer_length, int timeout_ms) {
    struct pollfd fds = {
            .fd = uevent_get_fd(),
            .events = POLLIN,
    };

    if (poll(&fds, 1, timeout_ms) <= 0 || !(fds.revents & POLLIN)) {
        return 0;
    }

    int count = recv(fds.fd, buffer, buffer_length, 0);
    return count > 0 ? count : 0;
}
