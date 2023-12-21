#include <aoe/macro.h>
#include <gtest/gtest.h>
#include <iostream>

/**
 * @brief 测试简单拼接，至少拼接 2 个 字符以上,最多 22 个拼接
 */

struct AOE_CONCAT(a, b)
{
};

struct AOE_CONCAT(a, b, c, d, f, g)
{
};

int AOE_CONCAT(o, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21);

#define TEST2(x, y) x##y

#define HELPSTR(x) #x
#define HELPCAT(x) x

#define STR(x) HELPSTR(x)








TEST(macro_concat, two)
{
    int AOE_CONCAT(b, 23){ 222 };
}