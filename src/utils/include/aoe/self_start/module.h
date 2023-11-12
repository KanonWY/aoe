#pragma once

#include <cstdint>

#include "aoe/self_start/details/module_base.h"
#include "aoe/design_pattern/singleton.h"
#include "aoe/macro.h"

namespace aoe::self_start {

/**
     * @brief 启动模块基础类
     * @tparam TFinalType   最终子类的类型
     * @tparam INSTANCE_ID  全局单例 ID
     * @tparam MODULE_ID    管理单元的 ID
 */
template<typename TFinalType, int64_t INSTANCE_ID = 0, int64_t MODULE_ID = 0>
class IModule: public IModuleBase {
public:
    IModule() = default;

    ~IModule() override = default;

protected:
    [[maybe_unused]] virtual bool onStart(IModule* self) = 0;

    virtual void onClose(IModule* self) = 0;

protected:
    bool onStart(IModuleBase*) final {
        return onStart(this);
    }

    void onClose(IModuleBase*) final {
        onClose(this);
    }

    static std::byte getHelper()
    {
        return init_helper_;
    }

private:
    inline static std::byte init_helper_ = []() -> std::byte {
        aoe::design_pattrn::Singleton<Manager, MODULE_ID>::ref().addModule(
        aoe::design_pattrn::Singleton<TFinalType, INSTANCE_ID>::ref());
        return {};
    }();
};

}

#define AOE_NOT_OPTIMIZE_OUT_GLOBAL_UNIQUE(...)                                                                                            \
    namespace details_no_optimize_out                                                                                                      \
    {                                                                                                                                      \
        static const std::byte AOE_COUNTER_UNIQUE(_no_optimize_helper_) = []() -> std::byte {                                              \
            aoe::design_pattrn::Singleton<__VA_ARGS__>::ref();                                                                           \
            return {};                                                                                                                     \
        }();                                                                                                                               \
    }
