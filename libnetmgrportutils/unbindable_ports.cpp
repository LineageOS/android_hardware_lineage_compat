/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "libnetmgrportutils_shim"

#include <arpa/inet.h>
#include <connectivity_native.h>
#include <dlfcn.h>
#include <errno.h>
#include <log/log.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <chrono>
#include <condition_variable>
#include <mutex>
#include <set>
#include <sstream>
#include <string>
#include <thread>

namespace {

constexpr char kUnbindablePortsPath[] = "/proc/sys/net/ipv4/ip_local_unbindable_ports";
constexpr auto kRetryDelay = std::chrono::seconds(1);

using PortSet = std::set<in_port_t>;

enum class Step { Progress, Idle, Retry };

struct State {
    std::mutex mutex;
    std::condition_variable cond;
    PortSet wanted;
    PortSet applied;
    PortSet rejected;
    bool cleared = false;
    bool dirty = false;
};

State& state() {
    static State& instance = *new State();
    return instance;
}

bool isTransient(int err) {
    return err == EAGAIN || err == EPROTO;
}

PortSet parsePorts(const std::string& list) {
    PortSet ports;
    std::istringstream stream(list);
    std::string token;
    while (std::getline(stream, token, ',')) {
        char* end = nullptr;
        unsigned long first = strtoul(token.c_str(), &end, 10);
        if (end == token.c_str()) continue;
        unsigned long last = *end == '-' ? strtoul(end + 1, nullptr, 10) : first;
        for (unsigned long port = first; port <= last && port <= 65535; port++) {
            ports.insert(static_cast<in_port_t>(port));
        }
    }
    return ports;
}

bool ensureCleared(State& s) {
    if (s.cleared) return true;
    int err = AConnectivityNative_unblockAllPortsForBind();
    if (isTransient(err)) return false;
    if (err) ALOGE("Failed to unblock all ports: %d", err);
    s.cleared = true;
    return true;
}

bool unblockRemoved(State& s) {
    for (auto it = s.applied.begin(); it != s.applied.end();) {
        if (s.wanted.count(*it)) {
            ++it;
            continue;
        }
        int err = AConnectivityNative_unblockPortForBind(htons(*it));
        if (isTransient(err)) return false;
        if (err) ALOGE("Failed to unblock port %u: %d", *it, err);
        it = s.applied.erase(it);
    }
    return true;
}

Step applyNext(State& s) {
    if (!ensureCleared(s) || !unblockRemoved(s)) return Step::Retry;

    for (in_port_t port : s.wanted) {
        if (s.applied.count(port) || s.rejected.count(port)) continue;
        int err = AConnectivityNative_blockPortForBind(htons(port));
        if (isTransient(err)) return Step::Retry;
        if (err) {
            ALOGE("Failed to block port %u: %d", port, err);
            s.rejected.insert(port);
        } else {
            s.applied.insert(port);
        }
        return Step::Progress;
    }

    return Step::Idle;
}

void portWorker() {
    State& s = state();
    std::unique_lock lock(s.mutex);
    bool warned = false;

    while (true) {
        Step step = applyNext(s);
        if (step == Step::Progress) {
            warned = false;
            lock.unlock();
            lock.lock();
            continue;
        }

        if (step == Step::Retry) {
            if (!warned) {
                ALOGW("Connectivity service unavailable, retrying");
                warned = true;
            }
            s.cond.wait_for(lock, kRetryDelay, [&s] { return s.dirty; });
        } else {
            warned = false;
            s.cond.wait(lock, [&s] { return s.dirty; });
        }
        s.dirty = false;
    }
}

void requestPorts(PortSet ports) {
    static std::once_flag workerStarted;
    std::call_once(workerStarted, [] { std::thread(portWorker).detach(); });

    State& s = state();
    std::lock_guard lock(s.mutex);
    s.wanted = std::move(ports);
    s.rejected.clear();
    if (ensureCleared(s)) unblockRemoved(s);
    s.dirty = true;
    s.cond.notify_one();
}

int writeFn(void* cookie, const char* buf, int len) {
    static_cast<std::string*>(cookie)->append(buf, len);
    return len;
}

int closeFn(void* cookie) {
    auto* data = static_cast<std::string*>(cookie);
    requestPorts(parsePorts(*data));
    delete data;
    return 0;
}

}  // namespace

extern "C" FILE* fopen(const char* path, const char* mode) {
    static auto realFopen = reinterpret_cast<decltype(&fopen)>(dlsym(RTLD_NEXT, "fopen"));

    if (path && mode && mode[0] == 'w' && !strcmp(path, kUnbindablePortsPath)) {
        return funopen(new std::string(), nullptr, writeFn, nullptr, closeFn);
    }

    return realFopen(path, mode);
}
