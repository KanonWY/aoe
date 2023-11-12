#pragma once

#include <filesystem>

namespace aoe::this_process {
    namespace details {
        struct InitHelper {
            InitHelper();
        };

        static InitHelper init_helper;
    } // namespace details

/**
 * @return main() 函数的参数个数
 */
    int argc();

/**
 * @return main() 函数的参数数组
 */
    char **argv();

/**
 * @return 程序的路径
 */
    const std::filesystem::path &path();

/**
 * @return 进程 id
 */
    int pid();

/**
 * @return 当前的工作路径
 */
    const char *cwd();
} // namespace eon::this_process
