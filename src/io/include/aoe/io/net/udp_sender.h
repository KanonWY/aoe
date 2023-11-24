#pragma once

#include <memory>
#include <string>

/**
 * @brief 关于是否需要加入组播：
 * 如果您的应用程序只需要发送组播消息而不需要接收来自组播组的消息，那么您可以不必显式地加入到组播组中。
 * 这种情况下，只需要创建一个 UDP socket，并使用 send_to 方法向指定的组播地址发送数据即可。
 */

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

class CUDPSenderImpl;

class CUDPSender {
public:
    explicit CUDPSender(const SSenderAttr& attr_);

    CUDPSender() = delete;

    size_t Send(const void* buf_, size_t len_, const char* ipaddr_ = nullptr);
    void   SendAsync(const void* buf_, size_t len_, const char* ipaddr_ = nullptr);

protected:
    std::shared_ptr<CUDPSenderImpl> m_socket_impl;
};
} // namespace aoe::io::net
