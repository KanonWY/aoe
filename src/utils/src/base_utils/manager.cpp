#include "aoe/self_start/manager.h"
#include <iostream>

namespace aoe::self_start {

    void Manager::addModule(aoe::self_start::IModuleBase &moduel_base) {

        std::unique_lock<std::mutex> lk(mutex_);
        auto policy = moduel_base.getSelfStartPolicy();

        if (named_modules_.find(policy.name) == named_modules_.end()) {
            Module module;
            module.policy_ = policy;
            module.module_ = &moduel_base;

            std::map<std::string, Module> temp;
            temp[policy.name] = module;
            named_modules_[policy.name] = module;
            ordered_modules_[policy.priority].push_back(module);
        } else {
            std::cerr << "[LaunchCenter] multiple modules with the same name [" << policy.name << "] existed."
                      << std::endl;
            abort();
        }
    }

    void Manager::setup() {
        std::unique_lock<std::mutex> lk(mutex_);

        if (started_) {
            return;
        }
        started_ = true;
        // 所有模块的依赖（递归全部）
        std::map<std::string, std::set<std::string>> modules_dependencies;
        std::list<std::string> depending_chain;

        for (auto &module_it: named_modules_) {
            findDependencies(module_it.second.policy_.name, depending_chain, modules_dependencies);
        }

        // 根据不同优先等级先后，启动模块
        std::map<std::string, bool> inited_modules;

        for (auto &ordered_it: ordered_modules_) {
            size_t inited_count = 0;
            size_t last_count = 0;

            while (inited_count != ordered_it.second.size()) {
                for (auto &module: ordered_it.second) {
                    // 若模块所有依赖已经启动（或没有依赖），则可以被启动
                    if (modules_dependencies[module.policy_.name].empty()) {
                        if (inited_modules[module.policy_.name])
                            continue;
                        else
                            inited_modules[module.policy_.name] = true;

                        bool status = module.module_->onStart(module.module_);
                        ++inited_count;

                        if (not status) {
                            std::cerr << "[LaunchCenter] module launch failed: [" << module.policy_.name << "]"
                                      << std::endl;
                            abort();
                        } else {
                            // 该模块正常启动，将其从剩余所有模块的依赖列表中删除
                            ordered_started_modules_.push_back(module);

                            for (auto &dependency_it: modules_dependencies)
                                dependency_it.second.erase(module.policy_.name);
                        }
                    }
                }
                // 若前后两轮扫描，没有任何模块被启动，则说明这一个层级的模块初始化完毕（可能有些没法被启动）
                if (inited_count == last_count)
                    break;
                else
                    last_count = inited_count;
            }
        }
    }


    void Manager::shutdown() {
        std::unique_lock lock(mutex_);

        // 按照模块的启动顺序，以倒序关闭它们
        for (auto i = ordered_started_modules_.rbegin(), end = ordered_started_modules_.rend(); i != end; ++i)
            i->module_->onClose(i->module_);

        started_ = false;
        ordered_started_modules_.clear();
    }

    Manager::~Manager() {
        shutdown();
    }

    void Manager::findDependencies(const std::string &name, std::list<std::string> &depending_chain,
                                   std::map<std::string, std::set<std::string>> &modules_dependencies) {
        if (modules_dependencies.find(name) != modules_dependencies.end())
            return;

        depending_chain.push_back(name);

        auto &policy = named_modules_.at(name).policy_;

        for (auto &dependency: policy.dependencies) {
            // 检查依赖是否存在
            if (named_modules_.find(dependency) == named_modules_.end()) {
                std::cerr << "[LaunchCenter] module dependency not found: "
                          << "[" << name << "] -> [" << dependency << "]" << std::endl;
                abort();
            }

            // 检查循环依赖
            for (auto &i: depending_chain) {
                if (i == dependency) {
                    std::cerr << "[LaunchCenter] module loop dependency found: ";

                    for (auto &j: depending_chain)
                        std::cerr << "[" << j << "]"
                                  << " -> ";
                    std::cerr << "[" << dependency << "]" << std::endl;

                    abort();
                }
            }

            // 检查优先级颠倒依赖（值越大，优先级越低，不应该依赖优先级低的模块）
            if (auto depend_priority = named_modules_[dependency].policy_.priority; depend_priority > policy.priority) {
                std::cerr << "[LaunchCenter] module priority error: "
                          << "[" << name << "](" << policy.priority << ") ->"
                          << "[" << dependency << "](" << depend_priority << ")" << std::endl;
                abort();
            }

            // 查找每个依赖及其子依赖，全部添加到依赖列表中
            findDependencies(dependency, depending_chain, modules_dependencies);
            modules_dependencies[name].insert(dependency);
            modules_dependencies[name].insert(modules_dependencies[dependency].begin(),
                                              modules_dependencies[dependency].end());
        }

        depending_chain.pop_back();
    }
}