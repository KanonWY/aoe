#pragma once

#include <cstring>
#include <ifaddrs.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>

namespace aoe::io::net {

inline static std::vector<int> get_interface_index_list() {
    std::vector<int> interface_index_list;
    ifaddrs*         ifa  = nullptr;
    ifaddrs*         ifap = nullptr;

    // get a list of network interfaces
    getifaddrs(&ifap);

    // create a list of network interfaces indexes
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
#if defined (__APPLE__)
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
#else
    if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_PACKET) {
#endif
            auto index = if_nametoindex(ifa->ifa_name);
            if (index) {
                interface_index_list.push_back(index);
            }
        }
    }

    freeifaddrs(ifap);

    return interface_index_list;
}

inline static bool set_socket_mcast_group_option(int socket, const char* ipaddr_, int option) {
    // set the multicast socket option on all interfaces
    for (int iface: get_interface_index_list()) {
        group_req    group_req = {};
        sockaddr_in* group     = nullptr;

        memset(&group_req, 0, sizeof(group_req));
        group_req.gr_interface = iface;
        group                  = reinterpret_cast<sockaddr_in*>(&group_req.gr_group);
        group->sin_family      = AF_INET;
        group->sin_addr.s_addr = inet_addr(ipaddr_);
        group->sin_port        = 0;

        int rc = setsockopt(socket, IPPROTO_IP, option, &group_req, sizeof(group_source_req));
        if (rc != 0) {
            std::cerr << "setsockopt failed. Unable to set multicast group option: " << strerror(errno) << std::endl;
            return (false);
        }
    }

    return (true);
}
} // namespace aoe::io::net