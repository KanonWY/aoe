#include "aoe/io/net/udp_receive.h"
#include "aoe/io/net/udp_receive_asio.h"

namespace aoe::io::net {
CUDPReceiver::CUDPReceiver():
    CReceiver(CReceiver::SocketType::SType_Unknown) {
}

bool CUDPReceiver::Create(const SReceiverAttr& attr_) {
    if (socket_impl_)
        return false;

    socket_impl_ = std::make_shared<CUDPReceiverAsio>(attr_);
    return true;
}

bool CUDPReceiver::Destroy() {
    if (!socket_impl_) return (false);
    socket_impl_.reset();
    return true;
}

bool CUDPReceiver::AddMultiCastGroup(const char* ipaddr_) {
    if (!socket_impl_) return (false);
    return (socket_impl_->AddMultiCastGroup(ipaddr_));
}

bool CUDPReceiver::RemMultiCastGroup(const char* ipaddr_) {
    if (!socket_impl_) return (false);
    return (socket_impl_->RemMultiCastGroup(ipaddr_));
}


size_t CUDPReceiver::Receive(char* buf_, size_t len_, int timeout_, ::sockaddr_in* address_) {
    if (!socket_impl_) return (0);
    return (socket_impl_->Receive(buf_, len_, timeout_, address_));
}
} // namespace aoe::io::net