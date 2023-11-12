#pragma once

#include "aoe/macro/expand.h"

/**
 * @brief 统计宏参数数量，并展开为该数字（最多支持 64 个参数）
 */
#define AOE_COUNT_ARGS(...)                                                                                                                \
    AOE_MACRO_EXPAND(AOE_DETAILS_COUNT_ARGS(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45,   \
        44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13,    \
        12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, ))


/**
 * @brief 统计宏参数的数量，若参数数量为 0 ，则结果为 0 ；若参数数量非零，则结果为 N
 */
#define AOE_COUNT_ARGS_0_N(...)                                                                                                            \
    AOE_MACRO_EXPAND(EON_DETAILS_COUNT_ARGS(__VA_ARGS__, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,  \
        N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 0))


/**
 * @brief 统计宏参数的数量，若参数数量为 0 ，则结果为 0 ；若参数数量为 1 ，则结果为 1 ；若参数数量多于 1 ，则结果为 N
 */
#define AOE_COUNT_ARGS_0_1_N(...)                                                                                                          \
    AOE_MACRO_EXPAND(EON_DETAILS_COUNT_ARGS(__VA_ARGS__, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,  \
        N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 1, 0))


// 参数计数辅助函数
#define AOE_DETAILS_COUNT_ARGS(X64, X63, X62, X61, X60, X59, X58, X57, X56, X55, X54, X53, X52, X51, X50, X49, X48, X47, X46, X45, X44,    \
    X43, X42, X41, X40, X39, X38, X37, X36, X35, X34, X33, X32, X31, X30, X29, X28, X27, X26, X25, X24, X23, X22, X21, X20, X19, X18, X17, \
    X16, X15, X14, X13, X12, X11, X10, X9, X8, X7, X6, X5, X4, X3, X2, X1, N, ...)                                                         \
    N
