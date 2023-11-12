#pragma once

#include <type_traits>

#include "aoe/macro/arguments.h"


namespace aoe::details::type_traits {
/**
 * @brief 用于检查给定的模板实例化是否合法
 * @tparam TOp 被检查的模板
 * @tparam TArgs 用于实例化该模板的类型参数
 */
template<class TDummy, template<class...> class TOp, class... TArgs>
struct detector {
    inline constexpr static bool enable = false;
};

template<template<class...> class TOp, class... TArgs>
struct detector<std::void_t<TOp<TArgs...>>, TOp, TArgs...> {
    inline constexpr static bool enable = true;
};

/**
 * @brief 通过实例化的方式，检查给定条件是否成立
 */
template<bool CON>
struct checker {
    inline constexpr static bool value = true;
};

template<>
struct checker<false> {
};
} // namespace AOE::details::type_traits


/**
 * @brief 模拟其他语言的行内函数，放在函数后推导的位置。
 * @example
 * auto f(int a, int b) -> AOE_EVAL(a + b)
 */
#define AOE_EVAL(...) \
    decltype(auto) { \
        return (__VA_ARGS__); \
    }


namespace aoe {
/**
 * @brief 用于检查指定模板的实例化是否合法，也即是否符合某种 concept
 * @tparam TOp 被检查的模板
 * @tparam TArgs 实例化该模板的类型参数
 */
template<template<class...> class TOp, class... TArgs>
constexpr static bool is = details::type_traits::detector<void, TOp, TArgs...>::enable;

/**
 * @brief 用于检查给定两个参数的类型是否相同，仅能在 concept 中使用
 */
template<class Lhs, class Rhs>
constexpr auto same_as(Lhs, Rhs) -> AOE_EVAL(details::type_traits::checker<std::is_same_v<Lhs, Rhs>>::value)

/**
 * @brief 用于检查给定的参数是否符合指定的类型，仅能在 concept 中使用
 * @tparam TargetType 指定的类型
 * @tparam CheckedType 被检查的类型
 */
template<class TargetType, class CheckedType>
constexpr auto same_as(CheckedType) -> AOE_EVAL(details::type_traits::checker<std::is_same_v<TargetType, CheckedType>>::value)
} // namespace AOE


/**
 * @brief 模拟实现 c++ 20 requires 语法，静态推断类型，可用于模板参数列表或函数参数列表中。
 * 其中，括号内参数为一个编译时期可进行判断的表达式或 bool 值。
 *
 * @example
 * template<class T, AOE_REQUIRES(std::is_same_v<T, int> or std::is_same_v<T, float>)>
 * T f()
 * {
 *     return T();
 * }
 *
 * f<int>();   // good
 * f<bool>();  // bad
 */
#define AOE_REQUIRES(...) typename std::enable_if<(__VA_ARGS__), int>::type = 0


/**
 * @brief 模拟实现 c++ 20 concept 语法，创建一个可用复用的类型推断过程。
 *
 * @example 简单的类型推断，并用于特化函数。
 *
 * // 定义一个可复用的概念
 * template<class T>
 * using IntOrFloat = AOE_CONCEPT(
 *     ( std::is_same_v<T, int> or  std::is_same_v<T, float> )
 * );
 *
 * // 利用概念进行函数模板实例化匹配
 * template<class T, AOE_REQUIRES(AOE::is<IntOrFloat, T>)>
 * void f()
 * {
 *     std::cout << "T is int or float" << std::endl;
 * }
 *
 * // 概念的检查结果是一个布尔值，因此支持布尔操作，
 * // 定义对概念的否定，可实现函数特化
 * template<class T, AOE_REQUIRES(not AOE::is<IntOrFloat, T>)>
 * void f()
 * {
 *     std::cout << "T is NOT int and NOT float" << std::endl;
 * }
 *
 * // 概念的结果也可以用于 static_assert 中，实现静态类型检查
 * template<class T>
 * class MyClass
 * {
 *     static_assert( AOE::is<IntOrFloat, T> );
 * };
 *
 * @example 定义符合多个类型推断的概念
 *
 * // 使用 () 分隔判断条件
 * template<class T>
 * using MyConcept = AOE_CONCEPT(
 *     ( std::is_base_of_v<MyBase1, T> ),
 *     ( std::is_base_of_v<MyBase2, T> )
 * );
 *
 * // 上述语句也等价于
 * template<class T>
 * using MyConcept = AOE_CONCEPT(
 *     ( std::is_base_of_v<MyBase1, T> and std::is_base_of_v<MyBase2, T> )
 * );
 *
 * @example 定义符合某种操作的概念
 *
 * // 使用 AOE_DETECTS 宏或 AOE_DETECTS_AS 宏，检查指定类型是否
 * // 包含某种操作（成员、成员函数、静态成员、静态函数、子类型等）
 * template<class T>
 * using Iterable = AOE_CONCEPT(
 *     ( AOE_DETECTS(T, .begin())       ),
 *     ( AOE_DETECTS(T, .end())         ),
 *     ( AOE_DETECTS(const T, .begin()) ),
 *     ( AOE_DETECTS(const T, .end())   )
 * );
 *
 * @example 级联多个概念，组成新的概念
 *
 * template<class T>
 * using NonCostIterable = AOE_CONCEPT(
 *     ( AOE_DETECTS(T, .begin())       ),
 *     ( AOE_DETECTS(T, .end())         )
 * );
 *
 * template<class T>
 * using CostIterable = AOE_CONCEPT(
 *     ( AOE_DETECTS(const T, .begin()) ),
 *     ( AOE_DETECTS(const T, .end())   )
 * );
 *
 * template<class T>
 * using Iterable = AOE_CONCEPT(
 *     ( AOE::is<NonCostIterable, T> ),
 *     ( AOE::is<CostIterable,    T> ),
 * );
 *
 * @example 混用布尔条件判断与操作兼容性判断，构造复杂的概念
 *
 * template<class T, class E>
 * using MyConcept = AOE_CONCEPT(
 *     ( std::is_same_v<E, int>            ),
 *     ( AOE_DETECTS(T, .push_back(E())    ),
 *     ( AOE_DETECTS_AS(bool, T, .empty()) )
 * );
 */
#define AOE_CONCEPT(...) decltype(AOE_CONCAT(AOE_DETAILS_CONCEPT_, AOE_COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__))


/**
 * @brief 用于修饰函数或类，静态推断它是否应该被使用。
 * @example
 * template<class T>
 * class A
 * {
 * public:
 *     AOE_ENABLE_IF(std::is_same_v<T, int>)
 *     void f() {}
 * };
 *
 * A<int> a1;
 * a1.f();   // good
 *
 * A<float> a2;
 * a2.f();   // bad
 */
#define AOE_ENABLE_IF(...) template<typename Dummy = std::true_type, AOE_REQUIRES(Dummy::value and (__VA_ARGS__))>


/**
 * @brief 检查给定类型是否能够进行某种操作
 */
#define AOE_DETECTS(_type_, ...) (std::is_same_v<AOE_DETAILS_DETECTS(_type_, __VA_ARGS__), AOE_DETAILS_DETECTS(_type_, __VA_ARGS__)>)


/**
 * @brief 检查给定类型是否能够进行某种操作，并获得指定类型的结果
 */
#define AOE_DETECTS_AS(_result_type_, _type_, ...) (std::is_same_v<_result_type_, AOE_DETAILS_DETECTS(_type_, __VA_ARGS__)>)


// 对指定类型进行实例化操作，并获取操作的结果类型
#define AOE_DETAILS_DETECTS(_type_, ...) decltype(AOE_DECLVALUE(_type_) __VA_ARGS__)


/**
 * @brief 检查给定的表达式是否合法
 */
#define AOE_TESTS(...) (std::is_same_v<AOE_DETAILS_TESTS(__VA_ARGS__), AOE_DETAILS_TESTS(__VA_ARGS__)>)


/**
 * @brief 检查给定的表达式是否合法，且其返回值与给定的类型相符
 */
#define AOE_TESTS_AS(_result_type_, ...) (std::is_same_v<_result_type_, AOE_DETAILS_TESTS(__VA_ARGS__)>)


// 运行表达式，并获取表达式的结果
#define AOE_DETAILS_TESTS(...) decltype(__VA_ARGS__)

// 检查指定表达式是否成立
#define AOE_DETAILS_CONCEPT_CHECKS(...) ::aoe::details::type_traits::checker<__VA_ARGS__>::value

// 用于 AOE_CONCEPT 中条件检查的宏，需要分成使用两层宏实现，确保宏参数正确展开
#define AOE_DETAILS_CONCEPT_1(...) AOE_DETAILS_CONCEPT_1_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_2(...) AOE_DETAILS_CONCEPT_2_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_3(...) AOE_DETAILS_CONCEPT_3_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_4(...) AOE_DETAILS_CONCEPT_4_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_5(...) AOE_DETAILS_CONCEPT_5_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_6(...) AOE_DETAILS_CONCEPT_6_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_7(...) AOE_DETAILS_CONCEPT_7_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_8(...) AOE_DETAILS_CONCEPT_8_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_9(...) AOE_DETAILS_CONCEPT_9_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_10(...) AOE_DETAILS_CONCEPT_10_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_11(...) AOE_DETAILS_CONCEPT_11_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_12(...) AOE_DETAILS_CONCEPT_12_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_13(...) AOE_DETAILS_CONCEPT_13_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_14(...) AOE_DETAILS_CONCEPT_14_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_15(...) AOE_DETAILS_CONCEPT_15_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_16(...) AOE_DETAILS_CONCEPT_16_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_17(...) AOE_DETAILS_CONCEPT_17_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_18(...) AOE_DETAILS_CONCEPT_18_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_19(...) AOE_DETAILS_CONCEPT_19_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_20(...) AOE_DETAILS_CONCEPT_20_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_21(...) AOE_DETAILS_CONCEPT_21_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_22(...) AOE_DETAILS_CONCEPT_22_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_23(...) AOE_DETAILS_CONCEPT_23_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_24(...) AOE_DETAILS_CONCEPT_24_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_25(...) AOE_DETAILS_CONCEPT_25_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_26(...) AOE_DETAILS_CONCEPT_26_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_27(...) AOE_DETAILS_CONCEPT_27_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_28(...) AOE_DETAILS_CONCEPT_28_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_29(...) AOE_DETAILS_CONCEPT_29_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_30(...) AOE_DETAILS_CONCEPT_30_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_31(...) AOE_DETAILS_CONCEPT_31_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_32(...) AOE_DETAILS_CONCEPT_32_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_33(...) AOE_DETAILS_CONCEPT_33_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_34(...) AOE_DETAILS_CONCEPT_34_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_35(...) AOE_DETAILS_CONCEPT_35_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_36(...) AOE_DETAILS_CONCEPT_36_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_37(...) AOE_DETAILS_CONCEPT_37_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_38(...) AOE_DETAILS_CONCEPT_38_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_39(...) AOE_DETAILS_CONCEPT_39_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_40(...) AOE_DETAILS_CONCEPT_40_DO(__VA_ARGS__)

#define AOE_DETAILS_CONCEPT_1_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_
#define AOE_DETAILS_CONCEPT_2_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_1_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_3_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_2_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_4_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_3_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_5_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_4_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_6_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_5_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_7_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_6_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_8_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_7_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_9_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_8_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_10_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_9_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_11_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_10_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_12_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_11_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_13_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_12_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_14_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_13_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_15_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_14_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_16_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_15_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_17_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_16_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_18_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_17_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_19_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_18_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_20_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_19_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_21_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_20_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_22_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_21_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_23_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_22_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_24_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_23_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_25_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_24_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_26_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_25_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_27_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_26_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_28_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_27_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_29_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_28_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_30_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_29_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_31_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_30_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_32_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_31_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_33_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_32_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_34_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_33_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_35_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_34_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_36_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_35_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_37_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_36_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_38_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_37_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_39_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_38_DO(__VA_ARGS__)
#define AOE_DETAILS_CONCEPT_40_DO(_con_, ...) AOE_DETAILS_CONCEPT_CHECKS _con_, AOE_DETAILS_CONCEPT_39_DO(__VA_ARGS__)