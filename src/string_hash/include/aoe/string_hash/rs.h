#pragma once

#include <cstdint>
#include <string>

namespace aoe::string_hash
{
    static constexpr std::uint32_t rs(const char* str, const std::size_t length)
    {
        std::uint32_t b    = 378551;
        std::uint32_t a    = 63689;
        std::uint32_t hash = 0;

        for (std::size_t i = 0; i < length; i++)
        {
            hash = hash * a + str[i];
            a    = a * b;
        }

        return hash;
    }

    static inline std::uint32_t rs(const std::string& str)
    {
        return rs(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _rs_hash(const char* str, std::size_t length)
        {
            return rs(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
