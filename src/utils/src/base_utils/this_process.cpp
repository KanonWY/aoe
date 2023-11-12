#include "aoe/this_process/this_process.h"
#include <unistd.h>


namespace aoe::this_process::details {
    InitHelper::InitHelper() = default;
}  // namespace eon::this_process::details


namespace aoe::this_process {
    struct Program {
        // 启动参数
        int argc = 0;
        char **argv = nullptr;

        // 程序路径
        std::filesystem::path path;

        // 当前工作路径
        const char *pwd = nullptr;
    };

    static Program &getProgram() {
        static Program program;
        return program;
    }

    static void __attribute__((constructor(0))) beforeMain(int argc, char **argv) {
        Program &program = getProgram();

        program.argc = argc;
        program.argv = argv;
        program.path = argv[0];
        program.pwd = getcwd(nullptr, 0);
    }

    int argc() {
        return getProgram().argc;
    }

    char **argv() {
        return getProgram().argv;
    }

    const std::filesystem::path &path() {
        return getProgram().path;
    }

    int pid() {
        return getpid();
    }

    const char *cwd() {
        return getProgram().pwd;
    }
}  // namespace eon::this_process
