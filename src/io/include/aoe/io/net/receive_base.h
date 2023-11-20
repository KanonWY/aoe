#pragma once

#include <string>
#include <arpa/inet.h>

namespace aoe::io::net {

struct SReceiverAttr {
    std::string ipaddr_;
    int         port_{ 0 };
    bool        broadcast_{ false };
    bool        unicast_{ false };
    bool        loopback_{ true };
    int         rcvbuf_{ 1024 * 1024 };
};

struct CReceiver {
public:
    enum class SocketType {
        SType_Unknown = 0,
        SType_ReceiverUDP,
        SType_ReceiverTCP
    };

    CReceiver() = default;

    explicit CReceiver(SocketType sockType):
        skt_type_(sockType) {}

    virtual bool   Create(const SReceiverAttr& attr_)                                                = 0;
    virtual bool   Destroy()                                                                         = 0;
    virtual size_t Receive(char* buf_, size_t len_, int timeout_, ::sockaddr_in* address_ = nullptr) = 0;

    [[nodiscard]] inline SocketType GetType() const { return skt_type_; };

private:
    SocketType skt_type_{ SocketType::SType_Unknown };
};


} // namespace aoe::io::net