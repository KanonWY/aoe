//
// Created by yarten on 23-1-2.
//

#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t ap(const char* str, const std::size_t length)
    {
        std::uint32_t hash = 0xAAAAAAAA;

        for (std::size_t i = 0; i < length; i++)
        {
            hash ^= ((i & 1) == 0) ? ((hash << 7) ^ str[i] * (hash >> 3)) : (~((hash << 11) + (str[i] ^ (hash >> 5))));
        }

        return hash;
    }

    static inline std::uint32_t ap(const std::string& str)
    {
        return ap(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _ap_hash(const char* str, std::size_t length)
        {
            return ap(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
