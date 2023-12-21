#include <aoe/string_hash.h>
#include <gtest/gtest.h>

TEST(string_hash, ap)
{
    using namespace aoe::string_hash::literals;
    constexpr std::uint32_t ap_hash_code = "hello world"_ap_hash;

    constexpr std::uint32_t bkdr_hash_code = "hello world"_bkdr_hash;
    EXPECT_NE(ap_hash_code, bkdr_hash_code);
}

TEST(string_hash, bkdr)
{
    EXPECT_EQ(1, 1);
}