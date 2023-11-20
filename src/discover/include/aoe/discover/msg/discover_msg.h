#pragma once

#include <memory>
#include <cstring>
#include <iostream>

namespace aoe::discover {
    class message {
    public:
        using Ptr = std::shared_ptr<message>;
        using ConstPtr = std::shared_ptr<const message>;

        message() = default;

        message& operator=(const message&rhs) = default;

        message& operator=(message&&) = default;

        message(const void* data, size_t size);

        explicit message(const char* data);

        ~message();

        explicit message(const std::string* data): message(data->c_str(), data->size()) {
        }

        explicit message(const std::string&data) : message(data.c_str(), data.size()) {
        }

        explicit message(std::string&&data) : message(data.c_str(), data.size()) {
        }


        [[nodiscard]] void* data() const {
            return data_;
        }

        [[nodiscard]] size_t size() const {
            return data_size_;
        }

        [[nodiscard]] bool copyTo(void* dst, const size_t size) const {
            if (!dst || (size > data_size_)) {
                return false;
            }
            memcpy(dst, data_, size);
            return true;
        }

        void copyTo(std::string&dst) const {
            // fix: no use assign
            dst.assign(static_cast<char *>(data_), data_size_);
        }

        // STATIC FACTORY!
        static Ptr create(const void* data, size_t size) {
            return std::make_shared<message>(data, size);
        }

        static Ptr create(const std::string* data) {
            return std::make_shared<message>(data->c_str(), data->size());
        }

        static Ptr create(const std::string&data) {
            return std::make_shared<message>(data.c_str(), data.size());
        }

        static Ptr create(const std::string&&data) {
            return std::make_shared<message>(data.c_str(), data.size());
        }

        static Ptr create(const char* data) {
            return std::make_shared<message>(data);
        }

    private:
        size_t data_size_{0};
        void* data_{nullptr};
    };

    using MessagePtr = message::Ptr;
    using ConstMessagePtr = message::ConstPtr;

    inline MessagePtr makeMessage(const void* data, size_t size) {
        return aoe::discover::message::create(data, size);
    }

    inline MessagePtr makeMessage(const char* data) {
        return aoe::discover::message::create(data);
    }

    inline MessagePtr makeMessage(const std::string* data) {
        return aoe::discover::message::create(data);
    }

    inline MessagePtr makeMessage(const std::string&data) {
        return aoe::discover::message::create(data);
    }

    inline MessagePtr makeMessage(const std::string&&data) {
        return aoe::discover::message::create(data);
    }
}
