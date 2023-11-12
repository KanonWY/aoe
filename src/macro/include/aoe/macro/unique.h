/**
 * @brief 使用 __COUNTER__ 或 __LINE__ ，创建唯一的命名
 */

#pragma once

#include "aoe/macro/concat.h"

/**
 * @brief 创建出现次数唯一命名（同一份文件内）
 * @example
 * int AOE_COUNTER_UNIQUE(a) = 1;
 * int AOE_COUNTER_UNIQUE(a) = 2;
 * int AOE_COUNTER_UNIQUE(a) = 3;
 */
#define AOE_COUNTER_UNIQUE(_x_) AOE_CONCAT(_x_, _COUNTER_UNIQUE_, __COUNTER__)


/**
 * @brief 创建代码行内唯一命名
 * @example
 * int AOE_LINE_UNIQUE(a) = 1; AOE_LINE_UNIQUE(a) = -1;
 * int AOE_LINE_UNIQUE(a) = 2; AOE_LINE_UNIQUE(a) = -2;
 */
#define AOE_LINE_UNIQUE(_x_) AOE_CONCAT(_x_, _LINE_UNIQUE_, __LINE__)
