namespace aoe::discover {
template<typename T>
void Pool<T>::pushFront(T obj) {
    std::unique_lock<std::mutex> lock(mutex_);
    pool_.push_front(obj);
}

template<typename T>
void Pool<T>::pushBack(T obj) {
    std::unique_lock<std::mutex> lock(mutex_);
    pool_.push_back(obj);
}

template<typename T>
T Pool<T>::popFront(bool peek) {
    std::unique_lock<std::mutex> lock(mutex_);
    if (pool_.empty()) {
        return nullptr;
    }
    T front = pool_.front();
    if (!peek) {
        pool_.pop_front();
    }
    return front;
}
template<typename T>
T Pool<T>::popBack(bool peek) {
    std::unique_lock<std::mutex> lock(mutex_);
    if (pool_.empty()) {
        return nullptr;
    }
    T back = pool_.back();
    if (!peek) {
        pool_.pop_back();
    }
    return back;
}

template<typename T>
bool Pool<T>::waiting(int64_t timeout) {

    std::unique_lock<std::mutex> lock(mutex_);
    if (shutdown_) {
        return false;
    }
    if (!pool_.empty()) {
        return true;
    }
    if (timeout < 0) {
        cond_.wait(lock, [this]() { return !pool_.empty(); });
    }
    else {
        cond_.wait_for(lock, std::chrono::milliseconds(timeout), [this]() {
            return !pool_.empty();
        });
    }
    if (pool_.empty() && !shutdown_) {
        return true;
    }
    return false;
}

} // namespace aoe::discover
