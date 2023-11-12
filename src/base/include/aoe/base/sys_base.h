#pragma once

#include "aoe/base/init_config.h"
#include "aoe/self_start/self_start.h"
#include "aoe/self_start/module.h"
#include "aoe/base/base.h"

namespace aoe::base {

static constexpr int64_t AOE_SELF_START_MANAGER_ID = 2147483647;


template<typename TFinalType, int64_t INSTANCE_ID = 0>
class ISys: public self_start::IModule<TFinalType, INSTANCE_ID, AOE_SELF_START_MANAGER_ID> {
    using Base = self_start::IModule<TFinalType, INSTANCE_ID, AOE_SELF_START_MANAGER_ID>;

protected:
    // pure virtual interface, any moduel must implement two interface!
    virtual bool onStart(ISys* isys, const InitConfig& init_config) = 0;
    virtual void onClose(ISys* self)                                = 0;

protected:
    bool onStart(Base*) final {
        return onStart(this, getInitConfig());
    }

    void onClose(Base*) final {
        onClose(this);
    }
};

} // namespace aoe::base
