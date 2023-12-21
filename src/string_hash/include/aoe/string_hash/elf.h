#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t elf(const char* str, const std::size_t length)
    {
        std::uint32_t hash = 0;
        std::uint32_t x    = 0;

        for (std::size_t i = 0; i < length; i++)
        {
            hash = (hash << 4) + str[i];
            if ((x = hash & 0xF0000000L) != 0)
            {
                hash ^= (x >> 24);
            }
            hash &= ~x;
        }

        return hash;
    }

    static inline std::uint32_t elf(const std::string& str)
    {
        return elf(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _elf_hash(const char* str, std::size_t length)
        {
            return elf(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
