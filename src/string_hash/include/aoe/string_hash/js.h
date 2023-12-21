#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t js(const char* str, const std::size_t length)
    {
        std::uint32_t hash = 1315423911;

        for (std::size_t i = 0; i < length; i++)
        {
            hash ^= ((hash << 5) + str[i] + (hash >> 2));
        }

        return hash;
    }

    static inline std::uint32_t js(const std::string& str)
    {
        return js(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _js_hash(const char* str, std::size_t length)
        {
            return js(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
