#pragma once

#include "aoe/self_start/details/module_base.h"
#include "aoe/self_start/policy.h"

#include <list>
#include <map>
#include <string>
#include <mutex>
#include <vector>

namespace aoe::self_start {
    /**
     * @brief 模块管理器，用于管理模块调用
     */
    class Manager {
    public:
        /**
         * @brief 将某一个模块纳入到模块管理之中
         * @param moduel
         */
        void addModule(IModuleBase &moduel);

        void setup();

        void shutdown();

        ~Manager();

    private:
        void findDependencies(const std::string &name,
                              std::list<std::string> &depending_chain,
                              std::map<std::string, std::set<std::string>> &modules_dependencies);

    private:
        struct Module {
            Policy policy_{};
            IModuleBase *module_{nullptr};
        };
    private:
        std::mutex mutex_;
        bool started_ = {false};
        std::map<std::string, Module> named_modules_;
        std::map<unsigned, std::vector<Module>> ordered_modules_;
        std::vector<Module> ordered_started_modules_;
    };
}