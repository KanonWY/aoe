#pragma once

#include <memory>
#include <string>

namespace aoe::io::net {
struct SSenderAttr {
    std::string ipaddr;
    int         port{ 0 };
    int         ttl{ 0 };
    bool        broadcast{ false };
    bool        unicast{ false };
    bool        loopback{ true };
    int         sndbuf{ 1024 * 1024 };
};

// UDP Sender Impl
class CUDPSenderImpl;

class CUDPSender {
public:
    CUDPSender(const SSenderAttr& attr_);

    size_t Send(const void* buf_, size_t len_, const char* ipaddr_ = nullptr);
    void   SendAsync(const void* buf_, size_t len_, const char* ipaddr_ = nullptr);

protected:
    std::shared_ptr<CUDPSenderImpl> m_socket_impl;
};
} // namespace aoe::io::net
