#pragma once

#include <memory>

#include "aoe/discover/channel/channel_base.h"

namespace aoe::discover {

// ----------------------------------------------------------------------------------------

template<typename T>
struct IChannelSender {
    virtual size_t send(const T& data) = 0;
};

// ----------------------------------------------------------------------------------------

template<typename DT = std::string>
struct IGenericChannel: public IChannelSender<DT> {
    using DataType                      = DT;
    virtual ~IGenericChannel()          = default;
    virtual size_t send(const DT& data) = 0;
};

// ----------------------------------------------------------------------------------------

template<typename CT = void, typename DT = std::string>
class ChannelTemplate: public IGenericChannel<DT> {
public:
    using DataType = DT;

    ChannelTemplate() = default;
    explicit ChannelTemplate(const ChannelInfo& info):
        channel_info_(info) {
    }

    explicit ChannelTemplate(ChannelInfo&& info):
        channel_info_(std::move(info)) {
    }

    // get struct member
    [[nodiscard]] uint32_t id() const {
        return channel_info_.id_;
    }

    [[nodiscard]] std::string channel_name() const {
        return channel_info_.channel_name_;
    }

    [[nodiscard]] std::string dataType() const {
        return channel_info_.data_type_;
    }

    [[nodiscard]] ChannelType channelType() const {
        return channel_info_.type_;
    }

    [[nodiscard]] std::string domain() const {
        return channel_info_.domain_;
    }

    [[nodiscard]] std::string info() const {
        return channel_info_.info();
    }

    [[nodiscard]] size_t send(const DT& data) override {
        (void)data;
        return 0;
    }

    [[nodiscard]] ChannelInfo channelInfo() const {
        return channel_info_;
    }

    std::ostream* operator<<(std::ostream& os) const {
        return os << info();
    }

    bool operator==(const ChannelInfo& info) const {
        return channel_info_ == info;
    }

    void setChannelInfo(const ChannelInfo& info) {
        channel_info_ = info;
    }


    void setInstance(std::shared_ptr<CT> instance) {
        instance_ = instance;
    }

    std::shared_ptr<CT> instance() {
        return instance_;
    }


private:
    std::shared_ptr<CT> instance_ = nullptr;
    ChannelInfo         channel_info_;
};


} // namespace aoe::discover