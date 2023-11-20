#include "aoe/discover/channel/channel_net_tools.h"

namespace aoe::discover {

std::string getAddress(const struct sockaddr_in& addr) {
    std::string ip_port_str(inet_ntoa(addr.sin_addr));
    ip_port_str.append(":").append(std::to_string(htons(addr.sin_port)));
    return ip_port_str;
}

[[nodiscard]] std::string makeMulticastAddress(std::size_t hash, const std::string& start) {
    const auto& addr0 = start;
    std::string addr1 = std::to_string((hash >> 8) & 0xFF);
    std::string addr2 = std::to_string((hash >> 16) & 0xFF);
    std::string addr3 = std::to_string((hash >> 24) & 0xFF);
    return addr0 + "." + addr1 + "." + addr2 + "." + addr3;
}

} // namespace aoe::discover