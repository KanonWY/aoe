#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t dek(const char* str, const std::size_t length)
    {
        unsigned int hash = static_cast<unsigned int>(length);

        for (std::size_t i = 0; i < length; i++)
        {
            hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
        }

        return hash;
    }

    static inline std::uint32_t dek(const std::string& str)
    {
        return dek(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _dek_hash(const char* str, std::size_t length)
        {
            return dek(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
