#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t bp(const char* str, const std::size_t length)
    {
        std::uint32_t hash = 0;

        for (std::size_t i = 0; i < length; i++)
        {
            hash = hash << 7 ^ str[i];
        }

        return hash;
    }

    static inline std::uint32_t bp(const std::string& str)
    {
        return bp(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _bp_hash(const char* str, std::size_t length)
        {
            return bp(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
