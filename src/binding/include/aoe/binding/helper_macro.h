#pragma once

#include "aoe/macro.h"

#define AOE_DETAILS_BINDING_NUMBER_TYPE(_func_)                                                                               \
    _func_(Int8) _func_(UInt8) _func_(Int16) _func_(UInt16) _func_(Int32) _func_(UInt32) _func_(Int64) _func_(UInt64) _func_(Float)        \
        _func_(Double)

#define AOE_DETAILS_BINDING_BASIC_TYPE(_func_) _func_(Bool) _func_(Char) AOE_DETAILS_BINDING_NUMBER_TYPE(_func_)

#define AOE_DETAILS_BINDING_CONTAINER_TYPE(_func_) _func_(List) _func_(Vector) _func_(StrDict) _func_(Optional)

#define AOE_BINDING_BASIC_VALUE_TYPE(_func_)                                                                                  \
    AOE_DETAILS_BINDING_BASIC_TYPE(_func_)                                                                                    \
    _func_(String)

#define AOE_BINDING_VALUE_TYPE(_func_)                                                                                        \
    AOE_BINDING_BASIC_VALUE_TYPE(_func_)

#define AOE_BINDING_SIMPLE_OBJECT_TYPE(_func_) _func_(Value) _func_(Enum)

// 绑定复杂类型
#define AOE_BINDING_COMPLEX_OBJECT_TYPE(_func_)                                                                               \
    AOE_DETAILS_BINDING_CONTAINER_TYPE(_func_)                                                                                \
    _func_(Struct)

#define AOE_BINDING_OBJECT_TYPE(_func_)                                                                                       \
    AOE_BINDING_SIMPLE_OBJECT_TYPE(_func_)                                                                                    \
    AOE_BINDING_COMPLEX_OBJECT_TYPE(_func_)