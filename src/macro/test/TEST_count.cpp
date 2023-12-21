#include <aoe/macro.h>
#include <gtest/gtest.h>
#include <iostream>

/**
 * @brief 如果获取宏参数的数量，变参宏
 */
#define TEST_AOE_COUNT_ARGS(...) TEST_AOE_DETAILS_COUNT_ARGS(__VA_ARGS__, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, )

#define TEST_AOE_DETAILS_COUNT_ARGS(X12, X11, X10, X9, X8, X7, X6, X5, X4, X3, X2, X1, N, ...) N

TEST(macro, count)
{
    AOE_COUNT_ARGS();
    AOE_COUNT_ARGS(1, 23);
}