#pragma once

#include <memory>

#include "aoe/io/net/receive_base.h"

namespace aoe::io::net {

class CUDPReceiverBase;

class CUDPReceiver: public CReceiver {
public:
    CUDPReceiver();

    bool Create(const SReceiverAttr& attr_) override;
    bool Destroy() override;

    bool AddMultiCastGroup(const char* ipaddr_);
    bool RemMultiCastGroup(const char* ipaddr_);

    size_t Receive(char* buf_, size_t len_, int timeout_, ::sockaddr_in* address_ = nullptr) override;

protected:
    std::shared_ptr<CUDPReceiverBase> socket_impl_;
};
} // namespace aoe::io::net