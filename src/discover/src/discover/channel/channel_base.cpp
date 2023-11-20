
#include <sstream>

#include "aoe/discover/channel/channel_base.h"


namespace aoe::discover {

std::string get_channel_type(ChannelType type) {
    std::stringstream ss;
    switch (type) {
        case ChannelType::UnKnown:
            ss << "unknown";
            break;
        case ChannelType::TCP:
            ss << "TCP";
            break;
        case ChannelType::UDP:
            ss << "UDP";
            break;
        case ChannelType::Multi:
            ss << "Multi";
            break;
        case ChannelType::Serial:
            ss << "Serial";
            break;
        case ChannelType::Pipe:
            ss << "Pipe";
            break;
        case ChannelType::File:
            ss << "File";
            break;
        case ChannelType::ROS1:
            ss << "ROS1";
            break;
        case ChannelType::ROS2:
            ss << "ROS2";
            break;
        case ChannelType::eCAL:
            ss << "eCAL";
            break;
        case ChannelType::MQTT:
            ss << "MQTT";
            break;
        case ChannelType::HTTP:
            ss << "HTTP";
            break;
        case ChannelType::Custom:
            ss << "Custom";
            break;
        case ChannelType::SHM:
            ss << "SHM";
            break;
        default:
            ss << "other unknown channel type";
            break;
    }
    return ss.str();
}

std::string ChannelInfo::info() const {
}

} // namespace aoe::discover