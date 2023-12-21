#pragma once

#include <any>
#include <functional>
#include <list>


#include "aoe/binding/details/enum_base.h"
#include "aoe/binding/details/type_info.h"
#include "aoe/binding/object_type.h"
#include "aoe/binding/value_type.h"


namespace aoe::binding::details
{
    class ObjectMem;

    /**
     * @brief 获取给定类型的内存布局
     */
    template <typename T>
    const ObjectMem* getObjectMem();

    /**
     * @brief 添加对象的每一个内存字段，该模版函数将使用 AOE_DETAILS_BINDING_IMPL_FILEDS_FILLING 宏进行特化
     * @tparam T
     * @param mem
     */
    template <typename T>
    extern void fillFields(ObjectMem& mem);

    struct ObjectViewMeta
    {
        //! 内存布局
        const ObjectMem* mem = nullptr;
        //! 实际数据地址
        void* data = nullptr;
    };
}  // namespace aoe::binding::details


namespace aoe::binding
{
    namespace details
    {
        // TODO: 这个封装是否必要
        template <class T>
        struct VisitingHelper
        {
            template <class TVisitor>
            static void run(T& obj, TVisitor&& visitor);
        };
    }  // namespace details

    template <typename T, typename TVisitor>
    void visitFields(T& obj, TVisitor&& visitor)
    {
        details::VisitingHelper<T>::run(obj, std::forward<TVisitor>(visitor));
    }
}  // namespace aoe::binding


#define AOE_DETAILS_BINDING_IMPL_FILEDS_FILLING(_type_, ...)                                                                               \
    namespace aoe::binding::details                                                                                                        \
    {                                                                                                                                      \
        template <>                                                                                                                        \
        inline void fillFields<_type_>(ObjectMem & mem)                                                                                    \
        {                                                                                                                                  \
            AOE_MACRO_INVOKE_WITH                                                                                                          \
        }                                                                                                                                  \
    }

#define AOE_DETAILS_BINDING_IMPL_FILLING_ONE_FILED(_type_, _filed_) mem.asStruct().addField(#_filed_, getObject)


namespace aoe::binding::details
{
    class ObjectMem
    {
    public:
        class Value
        {
        public:
            std::function<std::any(void*)>            copy;
            std::function<void(void*, std::any data)> assign;
            std::function<ValueType()>                type;
            // TODO: 内层命名空间的数据结构可以访问外层的？

            template <typename T>
            explicit Value(const T*);
        };

    public:
        class Enum
        {
        public:
            std::function<void(void*, EnumNumber num)> set;
            std::function<EnumNumber(void*)>           get;
            std::function<const EnumItemTable&()>      items;

            template <typename T>
            explicit Enum(const T*);
        };

    public:
        class List
        {
        public:
        };
    };
}  // namespace aoe::binding::details
