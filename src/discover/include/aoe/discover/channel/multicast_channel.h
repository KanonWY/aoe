#pragma once

#include <string>
#include <arpa/inet.h>
#include <functional>

#include "aoe/discover/channel/channel_interface.h"
#include "aoe/discover/msg/discover_msg_pool.h"

namespace aoe::discover {

// ----------------------------------------------------------------------------------------

template<typename T>
std::string getTypeName() {
    std::string type_name;
    std::string name = __PRETTY_FUNCTION__;

    auto begin = name.find("with _TT");
    auto end   = name.find("; std::string =", begin);
    // TODO: support clang and gcc! now only support gcc!
    if ((begin != std::string::npos) && (end != std::string::npos)) {
        type_name = name.substr(begin + 15, end - begin - 15);
    }
    return type_name;
}

// ----------------------------------------------------------------------------------------

template<typename T = std::string>
class MulticastChannel: public IGenericChannel<T> {
public:
    using onMessageCallback = std::function<void(const T&)>;
    using onCloseCallback   = std::function<void()>;
    using onErrorCallback   = std::function<void()>;
    using DataType          = T;

public:
private:
    ChannelInfo channel_info_;
    MessagePool msg_pool_;
    std::size_t msg_pool_size_{ 0 };

};


} // namespace aoe::discover
