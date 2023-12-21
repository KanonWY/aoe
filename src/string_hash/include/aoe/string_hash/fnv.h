#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t fnv(const char* str, const std::size_t length)
    {
        constexpr std::uint32_t big_prime = 0x811C9DC5;

        std::uint32_t hash = 0;

        for (std::size_t i = 0; i < length; ++i)
        {
            hash *= big_prime;
            hash ^= str[i];
        }

        return hash;
    }

    static inline std::uint32_t fnv(const std::string& str)
    {
        return fnv(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _fnv_hash(const char* str, std::size_t length)
        {
            return fnv(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
