#pragma once

#include "aoe/self_start/policy.h"

namespace aoe::self_start {
    class Manager;

    /**
     * @brief 抽象基类
     */
    class IModuleBase {
    public:
        virtual ~IModuleBase() = default;

        friend class Manager;
    protected:
        virtual Policy getSelfStartPolicy() = 0;

        virtual bool onStart(IModuleBase *self) = 0;

        virtual void onClose(IModuleBase *self) = 0;
    };
}