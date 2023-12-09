#pragma once

#include <mutex>
#include <list>
#include <atomic>
#include <condition_variable>

#include "aoe/discover/msg/discover_msg.h"

namespace aoe::discover {

/**
 * @brief 如何高效的实现一个消息池？
 *        1、压入的消息如果是一个非 const 的左值，最好可以直接移动到池内部
 *        2、压入的消息如果是一个临时的消息，也可以利用移动语句移动到池内部
 *        3、如何设置 push 接口
 *        4、如果我的消息类型必须为智能指针类型该如何设计？
 *        5、如何设计 pop 接口
 * @tparam T 消息类型
 */
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
