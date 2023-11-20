#pragma once

#include <string>
#include <arpa/inet.h>

namespace aoe::discover {

#ifndef MULTICAST_IP_ADAPTER_START
constexpr const char* MULTICAST_IP_ADAPTER_START = "239";
#endif

#ifndef MULTICAST_PORT_ADAPTER
constexpr int MULTICAST_PORT_ADAPTER = 50000;
#endif

#ifndef MULTICAST_PORT_ADAPTER_HASH
constexpr int MULTICAST_PORT_ADAPTER_HASH = 11111;
#endif

#ifndef MULTICAST_RECV_BUFFER_SIZE
constexpr int MULTICAST_RECV_BUFFER_SIZE = 65535;
#endif

#ifndef MULTICAST_PACKAGE_SIZE
constexpr int MULTICAST_PACKAGE_SIZE = 64000;
#endif

#ifndef MULTICAST_PACKAGE_TIMEOUT
constexpr int MULTICAST_PACKAGE_TIMEOUT = 3000;
#endif

[[nodiscard]] std::string
getAddress(const struct sockaddr_in& addr);

[[nodiscard]] std::string makeMulticastAddress(std::size_t hash, const std::string& start = MULTICAST_IP_ADAPTER_START);



} // namespace aoe::discover