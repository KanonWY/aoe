#pragma once

#include <memory>

#include "aoe/io/net/receive_base.h"

namespace aoe::io::net {

class CUDPReceiverBase {
public:
    explicit CUDPReceiverBase(const SReceiverAttr& /*attr_*/){};

    virtual ~CUDPReceiverBase() = default;

    CUDPReceiverBase(CUDPReceiverBase&&)                 = delete;
    CUDPReceiverBase& operator=(CUDPReceiverBase&&)      = delete;
    CUDPReceiverBase(const CUDPReceiverBase&)            = delete;
    CUDPReceiverBase& operator=(const CUDPReceiverBase&) = delete;

    virtual bool AddMultiCastGroup(const char* ipaddr_) = 0;
    virtual bool RemMultiCastGroup(const char* ipaddr_) = 0;

    virtual size_t Receive(char* buf_, size_t len_, int timeout_, ::sockaddr_in* address_ = nullptr) = 0;

};
} // namespace aoe::io::net
