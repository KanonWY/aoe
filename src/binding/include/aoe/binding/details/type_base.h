#pragma once

#include "aoe/binding/details/type_info.h"

namespace aoe::binding::details
{
    class TypeBase
    {
    protected:
        TypeBase() = default;

        explicit TypeBase(const TypeInfo& info)
            : info_(info)
        {
        }

    public:
        [[nodiscard]] inline const char* name() const
        {
            return info_.name;
        }

        [[nodiscard]] inline std::size_t hashCode() const
        {
            return info_.hash_code;
        }


        /**
         * @brief 检测当前类型是否是 T
         * @tparam T
         * @return
         */
        template <typename T>
        [[nodiscard]] bool is() const
        {
            return getTypeInfo<T>().hash_code == info_.hash_code;
        }

    protected:
        void setTypeInfo(const TypeInfo& info)
        {
            info_ = info;
        }

    private:
        friend TypeInfo getTypeInfo(const TypeBase& type_base)
        {
            return type_base.info_;
        }

    private:
        // 类型信息
        TypeInfo info_;
    };
}  // namespace aoe::binding::details