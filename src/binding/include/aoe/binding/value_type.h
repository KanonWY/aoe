#pragma once

#include <string>
#include <type_traits>

#include "aoe/binding/details/helper_macro.h"

namespace aoe::binding::def
{
    //! 当前系内定义的基本值类型

    using Bool   = bool;
    using Char   = char;
    using Int8   = int8_t;
    using UInt8  = uint8_t;
    using Int16  = int16_t;
    using UInt16 = uint16_t;
    using Int32  = int32_t;
    using UInt32 = uint32_t;
    using Int64  = int64_t;
    using UInt64 = uint64_t;
    using Float  = float;
    using Double = double;
    using String = std::string;
}  // namespace aoe::binding::def

namespace aoe::binding
{
    /**
     * @brief: 值类型枚举类
     */
    enum class ValueType : size_t
    {
        Undefined,

#define AOE_DETAILS_IMPL_TMP(_type_) _type_,

        //! aoe::binding 内置值类型
        AOE_BINDING_VALUE_TYPE(AOE_DETAILS_IMPL_TMP)

#undef AOE_DETAILS_IMPL_TMP

            CustomDerfined
    };
}  // namespace aoe::binding

namespace aoe::binding::details
{
    using namespace ::aoe::binding::def;
    /**
     * @brief 判断 T 类型是否为 value 类型，该函数模版会被 AOE_DETAILS_BIDNING_IMPL_IS_VALUE 宏偏特化
     * @tparam T
     * @return
     */
    template <typename T>
    static constexpr bool isValue()
    {
        return false;
    }
}  // namespace aoe::binding::details

/**
 * @brief 用于偏特化 isValue 模版函数的宏
 */
#define AOE_DETAILS_BIDNING_IMPL_IS_VALUE(_type_)                                                                                          \
    namespace aoe::binding::details                                                                                                        \
    {                                                                                                                                      \
        template <>                                                                                                                        \
        constexpr inline bool isValue<_type_>()                                                                                            \
        {                                                                                                                                  \
            return true;                                                                                                                   \
        }                                                                                                                                  \
    }

namespace aoe::binding
{
    /**
     * @brief 获取 T 类型的值类型
     * @tparam T
     * @return 值类型（枚举类）
     */
    template <typename T>
    constexpr ValueType getValueType()
    {
        if constexpr (not aoe::binding::details::isValue<T>())
        {
            return ValueType::Undefined;
        }

#define AOE_DETAILS_IMPL_TMP(_type_)                                                                                                       \
    if constexpr (std::is_same_v<::aoe::binding::def::_type_, T>)                                                                          \
        return ValueType::_type_;

        // 展开宏，用于展开多个 if constexpr 表达式， 在编译器确定出 T 的值类型
        AOE_BINDING_VALUE_TYPE(AOE_DETAILS_IMPL_TMP)

#undef AOE_DETAILS_IMPL_TMP

        return ValueType::CustomDerfined;
    }
}  // namespace aoe::binding