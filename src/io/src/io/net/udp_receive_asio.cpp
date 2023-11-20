#include <iostream>

#include "aoe/io/net/udp_receive_asio.h"
#include "aoe/io/net/net_base.h"

namespace aoe::io::net {

CUDPReceiverAsio::CUDPReceiverAsio(const SReceiverAttr& attr_):
    CUDPReceiverBase(attr_),
    m_created(false),
    m_broadcast(attr_.broadcast_),
    m_unicast(attr_.unicast_),
    m_socket(m_iocontext) {
    if (m_broadcast && m_unicast) {
        std::cerr << "CUDPReceiverAsio: Setting broadcast and unicast option true is not allowed." << std::endl;
        return;
    }

    // create socket
    const asio::ip::udp::endpoint listen_endpoint(asio::ip::udp::v4(), static_cast<unsigned short>(attr_.port_));
    {
        asio::error_code ec;
        m_socket.open(listen_endpoint.protocol(), ec);
        if (ec) {
            std::cerr << "CUDPReceiverAsio: Unable to open socket: " << ec.message() << std::endl;
            return;
        }
    }

    // set socket reuse
    {
        asio::error_code ec;
        m_socket.set_option(asio::ip::udp::socket::reuse_address(true), ec);
        if (ec) {
            std::cerr << "CUDPReceiverAsio: Unable to set reuse-address option: " << ec.message() << std::endl;
        }
    }

    // bind socket
    {
        asio::error_code ec;
        m_socket.bind(listen_endpoint, ec);
        if (ec) {
            std::cerr << "CUDPReceiverAsio: Unable to bind socket to " << listen_endpoint.address().to_string() << ":" << listen_endpoint.port() << ": " << ec.message() << std::endl;
            return;
        }
    }

    if (!m_unicast) {
        // set loopback option
        const asio::ip::multicast::enable_loopback loopback(attr_.loopback_);

        asio::error_code ec;
        m_socket.set_option(loopback, ec);
        if (ec) {
            std::cerr << "CUDPReceiverAsio: Unable to enable loopback: " << ec.message() << std::endl;
        }
    }

    // set receive buffer size (default = 1 MB)
    {
        int rcvbuf = 1024 * 1024;
        if (attr_.rcvbuf_ > 0) rcvbuf = attr_.rcvbuf_;
        const asio::socket_base::receive_buffer_size recbufsize(rcvbuf);
        asio::error_code                             ec;
        m_socket.set_option(recbufsize, ec);
        if (ec) {
            std::cerr << "CUDPReceiverAsio: Unable to set receive buffer size: " << ec.message() << std::endl;
        }
    }

    // join multicast group
    AddMultiCastGroup(attr_.ipaddr_.c_str());

    // state successful creation
    m_created = true;
}

bool CUDPReceiverAsio::AddMultiCastGroup(const char* ipaddr_) {
    if (!m_broadcast && !m_unicast) {
        if (IsUdpMulticastJoinAllIfEnabled) {
            if (!set_socket_mcast_group_option(m_socket.native_handle(), ipaddr_, MCAST_JOIN_GROUP)) {
                return (false);
            }
        }
        else {
            asio::error_code ec;
            m_socket.set_option(asio::ip::multicast::join_group(asio::ip::make_address(ipaddr_)), ec);
            if (ec) {
                std::cerr << "CUDPReceiverAsio: Unable to join multicast group: " << ec.message() << std::endl;
                return (false);
            }
        }
    }
    return true;
}

bool CUDPReceiverAsio::RemMultiCastGroup(const char* ipaddr_) {
    if (!m_broadcast && !m_unicast) {
        // Leave multicast group
        if (IsUdpMulticastJoinAllIfEnabled) {
            if (!set_socket_mcast_group_option(m_socket.native_handle(), ipaddr_, MCAST_LEAVE_GROUP)) {
                return (false);
            }
        }
        else {
            asio::error_code ec;
            m_socket.set_option(asio::ip::multicast::leave_group(asio::ip::make_address(ipaddr_)), ec);
            if (ec) {
                std::cerr << "CUDPReceiverAsio: Unable to leave multicast group: " << ec.message() << std::endl;
                return (false);
            }
        }
    }
    return true;
}

void CUDPReceiverAsio::RunIOContext(const asio::chrono::steady_clock::duration& timeout) {
    m_iocontext.restart();
    m_iocontext.run_for(timeout);

    if (!m_iocontext.stopped()) {
        m_socket.cancel();

        m_iocontext.run();
    }
}


size_t CUDPReceiverAsio::Receive(char* buf_, size_t len_, int timeout_, ::sockaddr_in* address_) {
    if (!m_created) return 0;

    size_t reclen{ 0 };

    m_socket.async_receive_from(asio::buffer(buf_, len_), m_sender_endpoint, [&reclen](std::error_code ec, std::size_t length) {
        if (!ec) {
            reclen = length;
        }
    });
    // run for timeout ms
    RunIOContext(asio::chrono::milliseconds(timeout_));
    // retrieve underlaying raw socket informations
    if (address_) {
        if (m_sender_endpoint.address().is_v4()) {
            asio::detail::sockaddr_in4_type* in4 = reinterpret_cast<asio::detail::sockaddr_in4_type*>(m_sender_endpoint.data());
            address_->sin_addr                   = in4->sin_addr;
            address_->sin_family                 = in4->sin_family;
            address_->sin_port                   = in4->sin_port;
            memset(&(address_->sin_zero), 0, 8);
        }
        else {
            std::cout << "CUDPReceiverAsio: ipv4 address conversion failed." << std::endl;
        }
    }
    return reclen;
}

} // namespace aoe::io::net