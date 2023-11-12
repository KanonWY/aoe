#pragma once

#include "aoe/macro/concat.h"
#include "aoe/macro/count.h"
#include "aoe/macro//expand.h"

namespace AOE::discard {

/**
 * @brief 标识一些参数不会被使用，使编译器不要产生警告。
 */
#define AOE_UNUSED(...) AOE_CONCAT(AOE_DETAILS_UNUSED_, AOE_COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)


/**
 * @note 末尾追加 void(0) 是为了能够使 clion 对齐时，不会缩进一个层级。并不清楚为什么不加会被认为需要缩进。
 */
#define AOE_DETAILS_UNUSED_1(x) \
    (void)x; \
    void(0)
#define AOE_DETAILS_UNUSED_2(x, y) \
    (void)x; \
    (void)y; \
    void(0)
#define AOE_DETAILS_UNUSED_3(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_2(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_4(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_3(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_5(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_4(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_6(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_5(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_7(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_6(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_8(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_7(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_9(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_8(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_10(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_9(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_11(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_10(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_12(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_11(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_13(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_12(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_14(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_13(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_15(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_14(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_16(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_15(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_17(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_16(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_18(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_17(__VA_ARGS__)
#define AOE_DETAILS_UNUSED_19(x, ...) \
    (void)x; \
    AOE_DETAILS_UNUSED_18(__VA_ARGS__)

} // namespace AOE::discard
// #define AOE_UNUSED(...) AOE_CONCAT(AOE_DETAILS_UNUSED_, AOE_COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)
#define AOE_UNUSED_NEW(...) \
    [](...) {}(__VA_ARGS__);
