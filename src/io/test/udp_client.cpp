#include <iostream>
#include <aoe/io/net/udp_receive.h>
#include "aoe/io/net/net_base.h"

using namespace aoe::io::net;

int main() {
    aoe::io::net::CUDPReceiver  receiver;
    aoe::io::net::SReceiverAttr attr;
    attr.port_   = 2222;
    attr.ipaddr_ = "239.0.0.1";
    receiver.Create(attr);

    return 0;
}