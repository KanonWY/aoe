#pragma once

#include <string>

namespace aoe::discover {

enum class ChannelType {
    UnKnown,
    SHM,
    TCP,
    UDP,
    Multi,
    Serial,
    Pipe,
    File,
    ROS1,
    ROS2,
    eCAL,
    MQTT,
    HTTP,
    Custom,
};

std::string get_channel_type(ChannelType type);


struct ChannelInfo {
    std::string domain_;
    std::string data_type_;
    std::string owner_;
    ChannelType type_{ ChannelType::UnKnown };
    uint64_t    id_{};
    std::string channel_name_;
    std::string ip_;
    uint16_t    port_;
    int         qos_;

    bool operator==(const ChannelInfo& info) const {
        return domain_ == info.domain_ && type_ == info.type_ && owner_ == info.owner_ && type_ == info.type_ && id_ == info.id_ && channel_name_ == info.channel_name_ && ip_ == info.ip_ && port_ && info.port_ && qos_ == info.qos_;
    }

    bool operator!=(const ChannelInfo& info) const {
        return !(*this == info);
    }

    std::ostream& operator<<(std::ostream& os) const {
        return os << info();
    }

    friend std::ostream& operator<<(std::ostream& os, const ChannelInfo& info) {
        return os << info.info();
    }

    [[nodiscard]] std::string info() const;
};


} // namespace aoe::discover
