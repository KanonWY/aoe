#pragma once

#include <string>
#include <set>

namespace aoe::self_start {

    /**
     * @brief 模块启动配置策略
     */
    struct Policy {
        // 模块名称
        std::string name;
        // 该模块的对象
        std::set<std::string> dependencies;
        // 优先级
        int32_t priority{100};
    };
}