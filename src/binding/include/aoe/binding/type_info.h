#pragma once

#include <cstddef>

namespace aoe::binding {

struct TypeInfo {
    const char* name{ nullptr };
    std::size_t hash_code_{ 0 };
};


template<typename T>
static constexpr TypeInfo getSimpleTypeInfo();

template<class T>
static constexpr TypeInfo getContainerTypeInfo();



} // namespace aoe::binding