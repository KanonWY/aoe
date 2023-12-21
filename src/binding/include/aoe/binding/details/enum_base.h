#pragma once

#include <initializer_list>
#include <map>
#include <string>

namespace aoe::binding
{
    //! 枚举类型
    using EnumNumber = long long;

    /**
     * @brief 通用枚举
     */
    struct EnumItem
    {
        std::string name;
        EnumNumber  number;

        // TODO: 这个的构造函数也许可以优化
        template <typename TEnum>
        EnumItem(std::string name, TEnum n)
            : name(std::move(name)),
              number(EnumNumber(n))
        {
            static_assert(std::is_enum_v<TEnum>);
        }
    };

    class EnumItemTable
    {
    public:
        EnumItemTable(std::initializer_list<EnumItem> list);

        const std::vector<EnumItem>& list() const;

        const std::vector<std::string>& queryNames(EnumNumber number) const;

        std::optional<EnumNumber> queryNumber(const std::string& name) const;

        inline auto begin() const -> AOE_EVAL(items_.begin()) inline auto end() const -> AOE_EVAL(items_.end());

    private:
        std::vector<EnumItem>                          items_;
        std::map<std::string, EnumNumber>              item_numbers_;
        std::map<EnumNumber, std::vector<std::string>> item_names_;
    };

    template <class TEnum>
    extern const EnumItemTable& enumerate();

}  // namespace aoe::binding


// 创建枚举类型的信息表的构建
#define AOE_DETAILS_BINDING_IMPL_ENUMERATING(_type_, ...)                                                                                  \
    namespace aoe::binding                                                                                                                 \
    {                                                                                                                                      \
        template <>                                                                                                                        \
        inline const EnumItemTable& enumerate<_type_>()                                                                                    \
        {                                                                                                                                  \
            using aoe_details_binding_temporary_alias = _type_;                                                                            \
            static const EnumItemTable items          = { AOE_MACRO_INVOKE(AOE_DETATIS_BINDING_ENUM_ITEM, __VA_ARGS__) };                  \
            return items;                                                                                                                  \
        }                                                                                                                                  \
    }


// 辅助创建枚举项的注册过程
#define AOE_DETATIS_BINDING_ENUM_ITEM(_item_) { #_item_, aoe_details_binding_temporary_alias::_item_ },


namespace aoe::binding::details
{


}
