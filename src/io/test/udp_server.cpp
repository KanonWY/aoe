#include <iostream>
#include "aoe/base/base.h"
#include <aoe/io/net/udp_sender.h>
#include <thread>

int EWE() {
    aoe::io::net::SSenderAttr attr;
    attr.ipaddr = "230.0.0.1";
    attr.port   = 2222;
    aoe::io::net::CUDPSender sender(attr);
    int64_t                  seq = 0;

    std::string msg = "hello";

    while (aoe::ok()) {
        std::string sendMsg = msg + (std::to_string(seq++));
        sender.Send(sendMsg.data(), sendMsg.size());
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "UDP_client run" << std::endl;
    return 0;
}

int main() {
    aoe::io::net::SSenderAttr attr;
    attr.ipaddr = "230.0.0.1";
    attr.port   = 2222;
    aoe::io::net::CUDPSender sender(attr);
    sender.Send("ddd", 3);
    return 0;
}