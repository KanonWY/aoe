#include "aoe/discover/msg/discover_msg.h"


namespace aoe::discover {
message::message(const void* data, const size_t size) {
    if (!data || size <= 0) {
        return;
    }
    data_ = new (std::nothrow) char[size + 1];
    if (data_) {
        memcpy(data_, data, size);
        static_cast<char*>(data_)[size] = 0;
        data_size_                      = size;
    }
    else {
        std::cerr << "new operation" << std::endl;
    }
}

message::message(const char* data) {
    if (!data) {
        return;
    }
    if (data_size_ = strlen(data); data_size_ <= 0) {
        return;
    }

    data_ = new (std::nothrow) char[data_size_ + 1];
    if (data_) {
        memcpy(data_, data, data_size_);
        static_cast<char*>(data_)[data_size_] = 0;
    }
    else {
        std::cerr << "new operation error" << std::endl;
    }
}

message::~message() {
    if (data_) {
        delete[] static_cast<char*>(data_);
        data_      = nullptr;
        data_size_ = 0;
    }
}
} // namespace aoe::discover
