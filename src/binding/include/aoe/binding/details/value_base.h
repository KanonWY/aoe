#pragma once

#include "aoe/binding/details/type_base.h"
#include "aoe/binding/value_type.h"


namespace aoe::binding::details
{
    class ValueBase : public TypeBase
    {
    protected:
        ValueBase() = default;
        ValueBase(const TypeInfo& info, ValueType type)
            : TypeBase(info),
              type_(type)
        {
        }

    public:
        inline ValueType type() const
        {
            return type_;
        }

    protected:
        void setValueType(ValueType type)
        {
            type_ = type;
        }

    private:
        // 值类型枚举标签
        ValueType type_{ ValueType::Undefined };
    };
}  // namespace aoe::binding::details


//! 注册内置值类型
#define AOE_DETAILS_BINDING_INTERNAL_VALUE(_type_)                                                                                         \
    AOE_DETAILS_BINDING_REGISTER_TYPE_INFO(_type_)                                                                                         \
    AOE_DETAILS_BIDNING_IMPL_IS_VALUE(_type_)

//! 实际注册展开
AOE_BINDING_VALUE_TYPE(AOE_DETAILS_BINDING_INTERNAL_VALUE)