#pragma once

#include "aoe/this_process/this_process.h"
#include "aoe/design_pattern/singleton.h"


namespace aoe::self_start{


template<int64_t MANAGER_ID = 0>
void setup()
{
    aoe::design_pattrn::Singleton<Manager, MANAGER_ID>::ref().setup();
}

template <int64_t MANAGER_ID = 0>
void shutdown()
{
    aoe::design_pattrn::Singleton<Manager,MANAGER_ID>::ref().shutdown();
}
}