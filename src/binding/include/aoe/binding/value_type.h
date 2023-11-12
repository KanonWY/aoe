#pragma once

#include <type_traits>
#include <string>

#include "aoe/binding/helper_macro.h"

namespace aoe::binding::def {
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
} // namespace aoe::binding::def

namespace aoe::binding {
using namespace ::aoe::binding::def;

template<typename T>
static constexpr bool isValue() {
    return false;
}

enum class ValueType : size_t {

};


} // namespace aoe::binding