#pragma once

#include <list>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include "aoe/binding/details/helper_macro.h"

namespace aoe::binding::def
{
    template <typename T>
    using List = std::list<T>;

    template <typename T>
    using Vector = std::vector<T>;

    template <typename T>
    using StrDict = std::map<std::string, T>;

    template <typename T>
    using Optional = std::optional<T>;

    template <typename T>
    using Struct = T;
}  // namespace aoe::binding::def


namespace aoe::binding
{
    /**
     * @brief 支持的可以绑定的类型
     */
    enum class ObjectType
    {
#define AOE_DETAILS_IMPL_TMP(_type_) _type_,

        // 宏展开枚举
        AOE_BINDING_OBJECT_TYPE(AOE_DETAILS_IMPL_TMP)

#undef AOE_DETAILS_IMPL_TMP
    };
}  // namespace aoe::binding
