#pragma once

#include <cstdint>
#include <string>

namespace aoe::string_hash
{
    static constexpr std::uint32_t sdbm(const char* str, const std::size_t length)
    {
        std::uint32_t hash = 0;

        for (std::size_t i = 0; i < length; i++)
        {
            hash = str[i] + (hash << 6) + (hash << 16) - hash;
        }

        return hash;
    }

    static inline std::uint32_t sdbm(const std::string& str)
    {
        return sdbm(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _sdbm_hash(const char* str, std::size_t length)
        {
            return sdbm(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
