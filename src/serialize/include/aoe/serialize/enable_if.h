#pragma once

namespace aoe::serialize
{
    template <bool B, class T = void>
    struct enable_if_c
    {
        using type = T;
    };

    template <class T>
    struct enable_if_c<false, T>
    {
    };

    template <class Cond, class T = void>
    struct enable_if : public enable_if_c<Cond::value, T>
    {
    };

    template <bool B, class T>
    struct lazy_enable_if_c
    {
        using type = typename T::type;
    };

    template <class T>
    struct lazy_enable_if_c<false, T>
    {
    };

    template <class Cond, class T>
    struct lazy_enable_if : public lazy_enable_if_c<Cond::value, T>
    {
    };

    template <bool B, class T = void>
    struct disable_if_c
    {
        using type = T;
    };

    template <class T>
    struct disable_if_c<true, T>
    {
    };

    template <class Cond, class T = void>
    struct disable_if : public disable_if_c<Cond::value, T>
    {
    };

    template <bool B, class T>
    struct lazy_disable_if_c
    {
        using type = typename T::type;
    };

    template <class T>
    struct lazy_disable_if_c<true, T>
    {
    };

    template <class Cond, class T>
    struct lazy_disable_if : public lazy_disable_if_c<Cond::value, T>
    {
    };

}  // namespace aoe::serialize
