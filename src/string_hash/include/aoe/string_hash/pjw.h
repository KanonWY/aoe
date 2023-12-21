#pragma once

#include <cstdint>
#include <string>


namespace aoe::string_hash
{
    static constexpr std::uint32_t pjw(const char* str, const std::size_t length)
    {
        constexpr auto BitsInUnsignedInt = (std::uint32_t)(sizeof(std::uint32_t) * 8);
        constexpr auto ThreeQuarters     = (std::uint32_t)((BitsInUnsignedInt * 3) / 4);
        constexpr auto OneEighth         = (std::uint32_t)(BitsInUnsignedInt / 8);
        constexpr auto HighBits          = (std::uint32_t)((0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth));

        std::uint32_t hash = 0;
        std::uint32_t test = 0;

        for (std::size_t i = 0; i < length; i++)
        {
            hash = (hash << OneEighth) + str[i];

            if ((test = hash & HighBits) != 0)
            {
                hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
            }
        }

        return hash;
    }

    static inline std::uint32_t pjw(const std::string& str)
    {
        return pjw(str.data(), str.length());
    }

    namespace literals
    {
        static inline constexpr std::uint32_t operator"" _pjw_hash(const char* str, std::size_t length)
        {
            return pjw(str, length);
        }
    }  // namespace literals
}  // namespace aoe::string_hash
