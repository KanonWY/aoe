#pragma once

/**
 * @note 本文件由程序生成，请勿修改。
 */

#pragma once

#include "aoe/macro/arguments.h"

/**
 * @brief 单参宏函数展开
 * @example
 *
 * // 单参宏函数
 * #define MY_MACRO(n) std::cout << n << std::endl;
 *
 * // 进行宏函数展开
 * AOE_MACRO_INVOKE(MY_MACRO, 1, 2, 3)
 *
 * // 这等价于
 * MY_MACRO(1) \
 * MY_MACRO(2) \
 * MY_MACRO(3)
 */
#define AOE_MACRO_INVOKE(_func_, ...) AOE_CONCAT(AOE_DETAILS_MACRO_INVOKE_WITH_0_, AOE_COUNT_ARGS(__VA_ARGS__))(_func_, __VA_ARGS__)

/**
 * @brief 固定了部分参数后的多参宏函数展开
 * @example
 *
 * // 多参宏函数，除了最后一个参数，其余都是固定参数
 * #define MY_MACRO(a, n) std::cout << a << " " << n << std::endl;
 *
 * // 进行宏函数展开
 * AOE_MACRO_INVOKE_WITH(MY_MACRO, 1, 666, 1, 2, 3)
 *
 * // 这等价于
 * MY_MACRO(666, 1) \
 * MY_MACRO(666, 2) \
 * MY_MACRO(666, 3)
 */
#define AOE_MACRO_INVOKE_WITH(_func_, _n_, ...)                                                                                            \
    AOE_CONCAT(AOE_DETAILS_MACRO_INVOKE_WITH_, _n_, _, AOE_COUNT_ARGS(AOE_ARGS_EXCEPT_FIRST(_n_, __VA_ARGS__)))                            \
    (_func_, __VA_ARGS__)

// 保留前 n 个参数，待扩展参数往后移动一位
#define AOE_DETAILS_INVOKE_SHIFT_ONE(_n_, ...) AOE_CONCAT(AOE_DETAILS_INVOKE_SHIFT_ONE_, AOE_DETAILS_INVOKE_IS_ZERO(_n_))(_n_, __VA_ARGS__)

#define AOE_DETAILS_INVOKE_SHIFT_ONE_0(_n_, ...) AOE_ARGS_EXCEPT_FIRST(1, __VA_ARGS__)

#define AOE_DETAILS_INVOKE_SHIFT_ONE_N(_n_, ...)                                                                                           \
    AOE_ARGS_FIRST(_n_, __VA_ARGS__), AOE_ARGS_EXCEPT_FIRST(1, AOE_ARGS_EXCEPT_FIRST(_n_, __VA_ARGS__))

// 调用函数的辅助宏，确保宏函数参数被正确展开
#define AOE_DETAILS_INVOKE_DO(_func_, ...) _func_(__VA_ARGS__)

// 判断一个数是否为零，不为零时返回 N
#define AOE_DETAILS_INVOKE_IS_ZERO(_n_) AOE_CONCAT(AOE_DETAILS_INVOKE_IS_ZERO_, _n_)

// 判断一个数是否为零的辅助宏
#define AOE_DETAILS_INVOKE_IS_ZERO_0  0
#define AOE_DETAILS_INVOKE_IS_ZERO_1  N
#define AOE_DETAILS_INVOKE_IS_ZERO_2  N
#define AOE_DETAILS_INVOKE_IS_ZERO_3  N
#define AOE_DETAILS_INVOKE_IS_ZERO_4  N
#define AOE_DETAILS_INVOKE_IS_ZERO_5  N
#define AOE_DETAILS_INVOKE_IS_ZERO_6  N
#define AOE_DETAILS_INVOKE_IS_ZERO_7  N
#define AOE_DETAILS_INVOKE_IS_ZERO_8  N
#define AOE_DETAILS_INVOKE_IS_ZERO_9  N
#define AOE_DETAILS_INVOKE_IS_ZERO_10 N
#define AOE_DETAILS_INVOKE_IS_ZERO_11 N
#define AOE_DETAILS_INVOKE_IS_ZERO_12 N
#define AOE_DETAILS_INVOKE_IS_ZERO_13 N
#define AOE_DETAILS_INVOKE_IS_ZERO_14 N
#define AOE_DETAILS_INVOKE_IS_ZERO_15 N
#define AOE_DETAILS_INVOKE_IS_ZERO_16 N
#define AOE_DETAILS_INVOKE_IS_ZERO_17 N
#define AOE_DETAILS_INVOKE_IS_ZERO_18 N
#define AOE_DETAILS_INVOKE_IS_ZERO_19 N
#define AOE_DETAILS_INVOKE_IS_ZERO_20 N
#define AOE_DETAILS_INVOKE_IS_ZERO_21 N
#define AOE_DETAILS_INVOKE_IS_ZERO_22 N
#define AOE_DETAILS_INVOKE_IS_ZERO_23 N
#define AOE_DETAILS_INVOKE_IS_ZERO_24 N
#define AOE_DETAILS_INVOKE_IS_ZERO_25 N
#define AOE_DETAILS_INVOKE_IS_ZERO_26 N
#define AOE_DETAILS_INVOKE_IS_ZERO_27 N
#define AOE_DETAILS_INVOKE_IS_ZERO_28 N
#define AOE_DETAILS_INVOKE_IS_ZERO_29 N
#define AOE_DETAILS_INVOKE_IS_ZERO_30 N
#define AOE_DETAILS_INVOKE_IS_ZERO_31 N
#define AOE_DETAILS_INVOKE_IS_ZERO_32 N
#define AOE_DETAILS_INVOKE_IS_ZERO_33 N
#define AOE_DETAILS_INVOKE_IS_ZERO_34 N
#define AOE_DETAILS_INVOKE_IS_ZERO_35 N
#define AOE_DETAILS_INVOKE_IS_ZERO_36 N
#define AOE_DETAILS_INVOKE_IS_ZERO_37 N
#define AOE_DETAILS_INVOKE_IS_ZERO_38 N
#define AOE_DETAILS_INVOKE_IS_ZERO_39 N
#define AOE_DETAILS_INVOKE_IS_ZERO_40 N
#define AOE_DETAILS_INVOKE_IS_ZERO_41 N
#define AOE_DETAILS_INVOKE_IS_ZERO_42 N
#define AOE_DETAILS_INVOKE_IS_ZERO_43 N
#define AOE_DETAILS_INVOKE_IS_ZERO_44 N
#define AOE_DETAILS_INVOKE_IS_ZERO_45 N
#define AOE_DETAILS_INVOKE_IS_ZERO_46 N
#define AOE_DETAILS_INVOKE_IS_ZERO_47 N
#define AOE_DETAILS_INVOKE_IS_ZERO_48 N
#define AOE_DETAILS_INVOKE_IS_ZERO_49 N
#define AOE_DETAILS_INVOKE_IS_ZERO_50 N

// 固定 0 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, ...) AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_0_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_0_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(0, __VA_ARGS__))

// 固定 1 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(1, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(1, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_1_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_1_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(1, __VA_ARGS__))

// 固定 2 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(2, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(2, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_2_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_2_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(2, __VA_ARGS__))

// 固定 3 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(3, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(3, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_3_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_3_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(3, __VA_ARGS__))

// 固定 4 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(4, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(4, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_4_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_4_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(4, __VA_ARGS__))

// 固定 5 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(5, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(5, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_5_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_5_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(5, __VA_ARGS__))

// 固定 6 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(6, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(6, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_6_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_6_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(6, __VA_ARGS__))

// 固定 7 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(7, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(7, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_7_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_7_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(7, __VA_ARGS__))

// 固定 8 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(8, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(8, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_8_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_8_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(8, __VA_ARGS__))

// 固定 9 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, ...)                                                                                     \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(9, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(9, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_2(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_3(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_4(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_5(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_6(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_7(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_8(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_9(_func_, ...)                                                                                     \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_10(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_11(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_12(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_13(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_14(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_15(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_16(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_17(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_18(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_19(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_20(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_21(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_22(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_23(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_24(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_25(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_26(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_27(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_28(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_29(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_30(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_31(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_32(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_33(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_34(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_35(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_36(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_37(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_38(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_39(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_40(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_41(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_42(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_43(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_44(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_45(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_46(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_47(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_48(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_49(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_9_50(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_1(_func_, __VA_ARGS__)                                                                                 \
    AOE_DETAILS_MACRO_INVOKE_WITH_9_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(9, __VA_ARGS__))

// 固定 10 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(10, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(10, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_10_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_10_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(10, __VA_ARGS__))

// 固定 11 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(11, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(11, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_11_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_11_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(11, __VA_ARGS__))

// 固定 12 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(12, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(12, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_12_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_12_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(12, __VA_ARGS__))

// 固定 13 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(13, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(13, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_13_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_13_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(13, __VA_ARGS__))

// 固定 14 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(14, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(14, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_14_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_14_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(14, __VA_ARGS__))

// 固定 15 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(15, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(15, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_15_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_15_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(15, __VA_ARGS__))

// 固定 16 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(16, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(16, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_16_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_16_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(16, __VA_ARGS__))

// 固定 17 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(17, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(17, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_17_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_17_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(17, __VA_ARGS__))

// 固定 18 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(18, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(18, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_18_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_18_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(18, __VA_ARGS__))

// 固定 19 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(19, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(19, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_19_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_19_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(19, __VA_ARGS__))

// 固定 20 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(20, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(20, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_20_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_20_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(20, __VA_ARGS__))

// 固定 21 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(21, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(21, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_21_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_21_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(21, __VA_ARGS__))

// 固定 22 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(22, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(22, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_22_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_22_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(22, __VA_ARGS__))

// 固定 23 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(23, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(23, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_23_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_23_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(23, __VA_ARGS__))

// 固定 24 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(24, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(24, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_24_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_24_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(24, __VA_ARGS__))

// 固定 25 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(25, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(25, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_25_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_25_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(25, __VA_ARGS__))

// 固定 26 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(26, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(26, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_26_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_26_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(26, __VA_ARGS__))

// 固定 27 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(27, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(27, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_27_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_27_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(27, __VA_ARGS__))

// 固定 28 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(28, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(28, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_28_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_28_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(28, __VA_ARGS__))

// 固定 29 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(29, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(29, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_29_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_29_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(29, __VA_ARGS__))

// 固定 30 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(30, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(30, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_30_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_30_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(30, __VA_ARGS__))

// 固定 31 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(31, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(31, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_31_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_31_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(31, __VA_ARGS__))

// 固定 32 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(32, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(32, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_32_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_32_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(32, __VA_ARGS__))

// 固定 33 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(33, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(33, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_33_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_33_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(33, __VA_ARGS__))

// 固定 34 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(34, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(34, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_34_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_34_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(34, __VA_ARGS__))

// 固定 35 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(35, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(35, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_35_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_35_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(35, __VA_ARGS__))

// 固定 36 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(36, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(36, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_36_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_36_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(36, __VA_ARGS__))

// 固定 37 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(37, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(37, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_37_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_37_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(37, __VA_ARGS__))

// 固定 38 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(38, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(38, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_38_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_38_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(38, __VA_ARGS__))

// 固定 39 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(39, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(39, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_39_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_39_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(39, __VA_ARGS__))

// 固定 40 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(40, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(40, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_40_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_40_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(40, __VA_ARGS__))

// 固定 41 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(41, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(41, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_41_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_41_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(41, __VA_ARGS__))

// 固定 42 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(42, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(42, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_42_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_42_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(42, __VA_ARGS__))

// 固定 43 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(43, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(43, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_43_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_43_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(43, __VA_ARGS__))

// 固定 44 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(44, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(44, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_44_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_44_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(44, __VA_ARGS__))

// 固定 45 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(45, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(45, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_45_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_45_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(45, __VA_ARGS__))

// 固定 46 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(46, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(46, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_46_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_46_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(46, __VA_ARGS__))

// 固定 47 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(47, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(47, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_47_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_47_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(47, __VA_ARGS__))

// 固定 48 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(48, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(48, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_48_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_48_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(48, __VA_ARGS__))

// 固定 49 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(49, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(49, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_49_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_49_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(49, __VA_ARGS__))

// 固定 50 个参数，进行宏函数展开
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, ...)                                                                                    \
    AOE_DETAILS_INVOKE_DO(_func_, AOE_ARGS_FIRST(50, __VA_ARGS__), AOE_ARGS_FIRST(1, AOE_ARGS_EXCEPT_FIRST(50, __VA_ARGS__)))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_2(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_3(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_2(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_4(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_3(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_5(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_4(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_6(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_5(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_7(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_6(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_8(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_7(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_9(_func_, ...)                                                                                    \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_8(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_10(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_9(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_11(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_10(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_12(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_11(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_13(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_12(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_14(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_13(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_15(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_14(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_16(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_15(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_17(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_16(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_18(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_17(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_19(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_18(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_20(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_19(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_21(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_20(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_22(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_21(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_23(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_22(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_24(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_23(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_25(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_24(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_26(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_25(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_27(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_26(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_28(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_27(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_29(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_28(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_30(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_29(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_31(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_30(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_32(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_31(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_33(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_32(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_34(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_33(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_35(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_34(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_36(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_35(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_37(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_36(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_38(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_37(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_39(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_38(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_40(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_39(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_41(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_40(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_42(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_41(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_43(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_42(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_44(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_43(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_45(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_44(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_46(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_45(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_47(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_46(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_48(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_47(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_49(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_48(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
#define AOE_DETAILS_MACRO_INVOKE_WITH_50_50(_func_, ...)                                                                                   \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_1(_func_, __VA_ARGS__)                                                                                \
    AOE_DETAILS_MACRO_INVOKE_WITH_50_49(_func_, AOE_DETAILS_INVOKE_SHIFT_ONE(50, __VA_ARGS__))
