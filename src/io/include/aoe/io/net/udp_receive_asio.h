#pragma once

#include <asio.hpp>

#include "aoe/io/net/udp_receive_base.h"

#define IsUdpMulticastJoinAllIfEnabled true

namespace aoe::io::net {

class CUDPReceiverAsio: public CUDPReceiverBase {
public:
    explicit CUDPReceiverAsio(const SReceiverAttr& attr_);

    bool AddMultiCastGroup(const char* ipaddr_) final;
    bool RemMultiCastGroup(const char* ipaddr_) override;

    size_t Receive(char* buf_, size_t len_, int timeout_, ::sockaddr_in* address_ = nullptr) override;

protected:
    void RunIOContext(const asio::chrono::steady_clock::duration& timeout);

    bool                    m_created{ false };
    bool                    m_broadcast{ false };
    bool                    m_unicast{ false };
    asio::io_context        m_iocontext;
    asio::ip::udp::socket   m_socket;
    asio::ip::udp::endpoint m_sender_endpoint;
};

} // namespace aoe::io::net