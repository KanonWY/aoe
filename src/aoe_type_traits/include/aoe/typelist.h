#pragma once

#include <type_traits>
#include <string>

/**
 *
 *  @desc 类型列表是用于存储类型的容器，在模版元编程中十分常见，可以用于保存 cpp 中的类型信息，在编译时处理
 *
 */



namespace aoe::typelist {

// 使用 namespace inline 来控制版本
//  inline namespace V1 中的内容将会自动被 上层的目标所见
//
inline namespace V1 {
/**
 * @desc 类型列表
 * @tparam ...
 */
template<typename...>
struct typeList {
};

/**
 * @desc 空类型
 */
struct empty_type {
};

namespace detail {

template<typename TL>
struct length;

template<template<class...> typename TL, typename... Ts>
struct length<TL<Ts...>> {
    using type = std::integral_constant<std::size_t, sizeof...(Ts)>;
};
} // namespace detail

template<typename TL>
using length_t = typename detail::length<TL>::type;

/**
 * @desc 获取类型列表的长度
 * @tparam TL
 */
template<typename TL>
constexpr static std::size_t length_v = length_t<TL>::value;

namespace detail {
template<typename TL>
struct front_type;

template<template<typename...> typename TL, typename T, typename... Ts>
struct front_type<TL<T, Ts...>> {
    using type = T;
};

template<template<typename...> typename TL>
struct front_type<TL<>> {
    using type = empty_type;
};
} // namespace detail

/**
 * @desc 获取类型列表的头元素类型
 */
template<typename TL>
using front_t = typename detail::front_type<TL>::type;

namespace detail {
template<typename TL>
struct back_type;

template<template<typename...> typename TL, typename T, typename... Ts>
struct back_type<TL<T, Ts...>> {
    using type = typename back_type<TL<Ts...>>::type;
};

template<template<typename...> typename TL, typename T>
struct back_type<TL<T>> {
    using type = T;
};

template<template<typename...> typename TL>
struct back_type<TL<>> {
    using type = empty_type;
};
} // namespace detail

/**
 * @desc 获取类型列表尾类型
 */
template<typename TL>
using back_t = typename detail::back_type<TL>::type;

namespace detail {

template<std::size_t Index, std::size_t N, typename TL>
struct at_type;

template<std::size_t Index, std::size_t N, template<typename...> typename TL, typename T, typename... Ts>
struct at_type<Index, N, TL<T, Ts...>> {
    using type = std::conditional_t<Index == N, T, typename at_type<Index, N + 1, TL<Ts...>>::type>;
};

template<std::size_t Index, std::size_t N>
struct at_type<Index, N, typeList<>> {
    using type = empty_type;
};
} // namespace detail

/**
 * @desc 获取类型列表的 index 对应的类型
 */
template<std::size_t Index, typename TL>
using at_t = typename detail::at_type<Index, 0, TL>::type;

namespace detail {

template<typename TL, typename T>
struct push_back_type;

template<template<typename...> typename TL, typename T, typename... Ts>
struct push_back_type<TL<Ts...>, T> {
    using type = TL<Ts..., T>;
};

template<typename TL, typename T>
struct push_front_type;

template<template<typename...> typename TL, typename T, typename... Ts>
struct push_front_type<TL<Ts...>, T> {
    using type = TL<T, Ts...>;
};
} // namespace detail

/**
 * @desc 从类型列表尾部插入一个类型元素获取新的类型列表
 */
template<typename TL, typename T>
using push_back_t = typename detail::push_back_type<TL, T>::type;

/**
 * @desc 从类型列表头部插入一个类型元素获取新的类型列表
 */
template<typename TL, typename T>
using push_front_t = typename detail::push_front_type<TL, T>::type;

namespace detail {

template<typename TL>
struct pop_front_type;

template<template<typename...> typename TL, typename T, typename... Ts>
struct pop_front_type<TL<T, Ts...>> {
    using type = typeList<Ts...>;
};

template<template<typename...> typename TL>
struct pop_front_type<TL<>> {
    using type = typeList<>;
};
} // namespace detail

/**
 * @desc 删除列表中的第一个类型元素获取新的类型列表
 */
template<typename TL>
using pop_front_t = typename detail::pop_front_type<TL>::type;

namespace detail {
template<std::ptrdiff_t N, typename R, typename TL>
struct pop_back_type;

template<std::ptrdiff_t N, typename... Ts, typename U, typename... Us>
struct pop_back_type<N, typeList<Ts...>, typeList<U, Us...>> {
    using type = typename pop_back_type<N - 1, typeList<Ts..., U>, typeList<Us...>>::type;
};

template<typename... Ts, typename... Us>
struct pop_back_type<0, typeList<Ts...>, typeList<Us...>> {
    using type = typeList<Ts...>;
};

template<typename... Ts, typename U, typename... Us>
struct pop_back_type<0, typeList<Ts...>, typeList<U, Us...>> {
    using type = typeList<Ts...>;
};

template<>
struct pop_back_type<-1, typeList<>, typeList<>> {
    using type = typeList<>;
};
} // namespace detail

/**
 * @desc 删除类型列表尾部的类型元素得到新的类型列表
 */
template<typename TL>
using pop_back_t = typename detail::pop_back_type<static_cast<std::ptrdiff_t>(length_v<TL>) - 1,
typeList<>,
TL>::type;

static void TEST_pop_back_t() {
    static_assert(std::is_same_v<pop_back_t<typeList<>>, typeList<>>);
    static_assert(std::is_same_v<pop_back_t<typeList<int, double>>, typeList<int>>);
    static_assert(std::is_same_v<pop_back_t<typeList<long, int, double>>, typeList<long, int>>);
}

namespace detail {
template<typename T, typename TL>
struct index_of_type;

template<typename T>
struct index_of_type<T, typeList<>> {
    static constexpr std::size_t value = -1;
};

// recursive:
template<typename T, typename... Ts>
struct index_of_type<T, typeList<T, Ts...>> {
    static constexpr std::size_t value = 0;
};

// recursive:
template<typename T, typename TF, typename... ResTs>
struct index_of_type<T, typeList<TF, ResTs...>> {
    static constexpr std::size_t value = 1 + index_of_type<T, typeList<ResTs...>>::value;
};

template<typename T, typename>
struct IndexOfType;

template<typename T>
struct IndexOfType<T, typeList<>> {
    static constexpr std::size_t value = -1;
};

template<typename T, typename... Ts>
struct IndexOfType<T, typeList<T, Ts...>> {
    static constexpr std::size_t value = 0;
};


} // namespace detail

template<typename T, typename TL>
static inline constexpr size_t index_of_type_v = detail::index_of_type<T, TL>::value;

static void TEST_index_of_type_v() {
    static_assert(index_of_type_v<int, typeList<>> == -1);
    static_assert(index_of_type_v<int, typeList<int, double, long, short>> == 0);
    static_assert(index_of_type_v<double, typeList<int, double, long, short>> == 1);
    static_assert(index_of_type_v<long, typeList<int, double, long, short>> == 2);
    static_assert(index_of_type_v<short, typeList<int, double, long, short>> == 3);
    static_assert(index_of_type_v<char, typeList<int, double, long, short, char>> == 4);
    static_assert(index_of_type_v<std::string, typeList<int, double, long, short, char>> == 4);
}
} // namespace V1
} // namespace aoe::typelist
