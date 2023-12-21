#pragma once

#include <cstdint>
#include <string>

namespace aoe::string_hash
{
    static constexpr std::uint32_t bkdr(const char* str, const std::size_t length)
    {
        constexpr std::uint32_t seed = 131;  // 31 131 1313 13131 131313 etc..

        std::uint32_t hash = 0;

        for (std::size_t i = 0; i < length; i++)
        {
            hash = (hash * seed) + str[i];
        }

        return hash;
    }

    static inline std::uint32_t bkdr(const std::string& str)
    {
        return bkdr(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _bkdr_hash(const char* str, std::size_t length)
        {
            return bkdr(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
