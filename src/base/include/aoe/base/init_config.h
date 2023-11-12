#pragma once

#include <string>
#include <map>

#include "aoe/base/version.h"

namespace aoe::base {

struct InitConfig {
    bool                               authorized{ false };
    std::string                        node_name;
    Version                            program_version;
    int64_t                            device_id;
    std::map<std::string, std::string> parameters;
};

} // namespace aoe::base