#pragma once

#include "aoe/binding/object_type.h"
#include "aoe/binding/value_type.h"
#include "aoe/string_hash.h"


namespace aoe::binding::details
{
    /**
     * @brief 类型信息
     */
    struct TypeInfo
    {
        const char* name      = nullptr;
        std::size_t hash_code = 0;
    };
}  // namespace aoe::binding::details


namespace aoe::binding::details
{
    template <typename T>
    static constexpr TypeInfo getSimpleTypeInfo();

    template <typename T>
    static constexpr TypeInfo getContainerTypeInfo();

    template <typename T>
    struct TypeHelper
    {
        // TODO: 这里可以加 inline ?
        inline constexpr static TypeInfo info = getSimpleTypeInfo<T>();
    };


    //! 辅助获取容器化的类型，容器化类型也会被注册为 value 类型
    template <typename T, bool IS_VALUE = isValue<T>()>
    struct ContainerTypeHelper;

    template <typename T>
    struct ContainerTypeHelper<T, true>
    {
        inline constexpr static TypeInfo info = getSimpleTypeInfo<T>();
    };

    template <typename T>
    struct ContainerTypeHelper<T, false>
    {
        inline constexpr static TypeInfo info = getContainerTypeInfo<T>();
    };

    //! 特化显示注册值类型为容器化类型
#define AOE_DETAILS_IMPL_TMP(_container_type_)                                                                                             \
    template <class T>                                                                                                                     \
    struct TypeHelper<def::_container_type_<T>>                                                                                            \
    {                                                                                                                                      \
        inline constexpr static TypeInfo info = ContainerTypeHelper<def::_container_type_<T>>::info;                                       \
    };

    AOE_DETAILS_BINDING_CONTAINER_TYPE(AOE_DETAILS_IMPL_TMP)

#undef AOE_DETAILS_IMPL_TMP

}  // namespace aoe::binding::details

namespace aoe::binding::details
{
    /**
     * @brief 获取指定类型的信息，根据用户注册的类型来获取最终的信息
     * @tparam T
     * @return
     */
    template <typename T>
    static constexpr TypeInfo getTypeInfo()
    {
        return TypeHelper<T>::info;
    }

}  // namespace aoe::binding::details


/**
 * @brief 根据类型信息注册对象的信息
 */
#define AOE_DETAILS_BINDING_REGISTER_TYPE_INFO(_type_)                                                                                     \
    namespace aoe::binding::details                                                                                                        \
    {                                                                                                                                      \
        template <>                                                                                                                        \
        constexpr inline TypeInfo getSimpleTypeInfo<_type_>()                                                                              \
        {                                                                                                                                  \
            using namespace string_hash::literals;                                                                                         \
                                                                                                                                           \
            TypeInfo info;                                                                                                                 \
            info.name      = #_type_;                                                                                                      \
            info.hash_code = #_type_##_fnv_hash;                                                                                           \
            return info;                                                                                                                   \
        }                                                                                                                                  \
    }                                                                                                                                      \
    AOE_MACRO_INVOKE_WITH(AOE_DETAILS_BINDING_REGISTER_CONATINER_TYPE_INFO_DO, 1,                                                          \
        _type_ AOE_DETAILS_BINDING_CONTAINER_TYPE(AOE_DETAILS_BINDING_EXPAND_TYPE))


/**
 * @brief 展开宏
 */
#define AOE_DETAILS_BINDING_EXPAND_TYPE(_type_) , _type_

/**
 * @brief 指定类型在一种容器内的信息注册实例化宏，辅助全容器类型信息注册宏
 */

#define AOE_DETAILS_BINDING_REGISTER_CONATINER_TYPE_INFO_DO(_type_, _container_)                                                           \
    namespace aoe::binding::details                                                                                                        \
    {                                                                                                                                      \
        template <>                                                                                                                        \
        constexpr inline TypeInfo getContainerTypeInfo<aoe::binding::def::_container_<_type_>>()                                           \
        {                                                                                                                                  \
            using namespace string_hash::literals;                                                                                         \
            TypeInfo info;                                                                                                                 \
            info.name      = #_container_ "<" #_type_ ">";                                                                                 \
            info.hash_code = #_container_ "<" #_type_ ">"##_js_hash;                                                                       \
            return info;                                                                                                                   \
        }                                                                                                                                  \
    }
