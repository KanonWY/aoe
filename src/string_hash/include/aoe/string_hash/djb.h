#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t djb(const char* str, const std::size_t length)
    {
        std::uint32_t hash = 5381;

        for (std::size_t i = 0; i < length; i++)
        {
            hash = ((hash << 5) + hash) + str[i];
        }

        return hash;
    }

    static inline std::uint32_t djb(const std::string& str)
    {
        return djb(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _djb_hash(const char* str, std::size_t length)
        {
            return djb(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
