#pragma once

#include <mutex>
#include <list>
#include <atomic>
#include <condition_variable>

#include "aoe/discover/msg/discover_msg.h"

namespace aoe::discover {
template<typename T>
class Pool {
public:
    Pool():
        shutdown_(false) {
    }

    ~Pool() {
        shutdown_ = true;
    }

    void pushFront(T obj);

    void pushBack(T obj);

    T popFront(bool peek = false);

    T popBack(bool peek = false);

    T peekFront() {
        return popFront(true);
    }

    T peekBack() {
        return popBack(true);
    }

    [[nodiscard]] bool empty() const { return pool_.empty(); }

    void clear() {
        pool_.clear();
    }

    void shutdown() {
        shutdown_ = true;
        cond_.notify_all();
    }

    bool wait(int64_t timeout = -1) {
        return waiting(timeout);
    }

private:
    // 需要 wait 外层加锁
    bool waiting(int64_t timeout = -1);

private:
    std::atomic<bool>       shutdown_{ false };
    std::condition_variable cond_;
    std::mutex              mutex_;
    std::list<T>            pool_;
};

using MessagePool = Pool<ConstMessagePtr>;

} // namespace aoe::discover

// TEMPLATE IMPL
#include "aoe/discover/msg/discover_msg_pool.inl"
