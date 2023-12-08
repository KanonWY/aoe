#include "aoe/base/base.h"
#include "aoe/this_process/this_process.h"
#include "aoe/self_start/self_start.h"

#include <set>
#include <csignal>
#include <iostream>
#include <functional>
#include <atomic>
#include <condition_variable>

namespace aoe::base {

// 用户信号处理函数
using UserSignalHandler = std::function<void(int sig, std::size_t hander_idx)>;

// 框架基础配置
static InitConfig                                              s_init_config_;

// 整个框架是否停止
static std::atomic_bool                                        s_is_eon_stopped{ true };

// 阻塞等待程序退出的条件变量及其守护锁
static std::condition_variable                                 s_join_cd_;
static std::mutex                                              s_join_mutex_;

// 信号锁
static std::mutex                                              s_signal_mutex_;
// eon 框架内部处理的信号的集合
static std::set<int>                                           s_internal_used_siganls_;

static std::map<int, std::map<std::size_t, UserSignalHandler>> s_user_signal_handlers_;

/**
 * @brief 信号处理函数
 * @param signal
 */
static void signalHandler(int signal) {
    std::map<std::size_t, UserSignalHandler> signal_handlers;
    {
        std::unique_lock<std::mutex> lock(s_signal_mutex_);
        if (auto it = s_user_signal_handlers_.find(signal); it != s_user_signal_handlers_.end()) {
            signal_handlers = it->second;
        }

        // call all signal hander function
        for (const auto& [idx, handler]: signal_handlers) {
            handler(signal, idx);
        }
        switch (signal) {
            case SIGINT:
            case SIGTERM: {
                ::aoe::terminate();
            } break;
            default:
                break;
        }
    }
}

const InitConfig& getInitConfig() {
    return s_init_config_;
}

const std::string& getNodeName() {
    return s_init_config_.node_name;
}

int64_t getDeviceId() {
    return s_init_config_.device_id;
}

std::filesystem::path getDataRoot(const std::string& name) {
    if (name.empty()) {
        return {};
    }

    const char* user_name = std::getenv("USER");
    if (user_name == nullptr) {
        return {};
    }

    // 设备 ID
    std::string device_id = std::to_string(s_init_config_.device_id);

    std::filesystem::path root = "/home/" + std::string(user_name) + "/.aoe/" + name + "/" + device_id;

    if (not std::filesystem::exists(root)) {
        if (not std::filesystem::create_directories(root)) {
            return {};
        }
    }
    return std::filesystem::is_directory(root) ? root : std::filesystem::path();
}


} // namespace aoe::base

namespace aoe {
void initialize() {
    // 内部注册的信号
    base::s_internal_used_siganls_ = { SIGTERM, SIGINT };
    for (auto signal: base::s_internal_used_siganls_) {
        std::signal(signal, base::signalHandler);
    }

    // 环境变量处理函数
    static auto env = [](const char* key) -> std::string {
        if (auto* str = std::getenv(key); str == nullptr) {
            return "";
        }
        else {
            return str;
        }
    };

    if (std::string str = env("AOE_AUTHORIZED"); str == "True") {
        base::s_init_config_.authorized = true;
    }

    if (base::s_init_config_.node_name = env("AOE_NODE_NAME"); base::s_init_config_.node_name.empty()) {
        base::s_init_config_.node_name = aoe::this_process::path().filename();
    }
    // TODO: store all env variable
    // we need to store all env variable which start with aoe!

    base::s_is_eon_stopped = false;

    // TODO: use some ways to deal with self_start module?
    // forch link is not a good way, we need a more pretty ways to do this!
    self_start::setup();

    if (aoe::base::s_is_eon_stopped) {
        finalize();
        std::exit(0);
    }
    std::cout << "aoe start" << std::endl;
}

void finalize() {
    // 关闭 eon 框架，也将退出所有相关阻塞等待的流程
    ::aoe::terminate();
    std::cout << "aoe finalize..." << std::endl;
    // 关闭全部 eon 系统模块
}

bool ok() {
    return not base::s_is_eon_stopped;
}

void terminate() {
    base::s_is_eon_stopped = true;
    base::s_join_cd_.notify_all();
}


void join() {
    std::unique_lock<std::mutex> lock(base::s_join_mutex_);

    while (not base::s_is_eon_stopped)
        base::s_join_cd_.wait(lock);
}


void joinAndFinalize() {
    join();
    finalize();
}

std::size_t signal(int sig, std::function<void(int)> handler) {
    if (handler == nullptr) {
        std::cerr << "signal(int sig, std::function<void(int)> handler) handler is nullptr" << std::endl;
    }

    return signal(sig,
    [handler = std::move(handler)](int sig, auto) {
        handler(sig);
    });
}


std::size_t signal(int sig, std::function<void(int, std::size_t)> handler) {
    // 不允许传入空函数指针
    if (handler == nullptr) {
        std::cerr << "signal(int sig, std::function<void(int)> handler) handler is nullptr" << std::endl;
    }

    std::unique_lock lock(base::s_signal_mutex_);

    // 若本信号不属于系统内默认接管的信号，则需要进行初始化
    if (base::s_internal_used_siganls_.find(sig) == base::s_internal_used_siganls_.end())
        std::signal(sig, base::signalHandler);

    // 新增指定信号的处理函数
    static std::size_t handler_idx = 0;

    base::s_user_signal_handlers_[sig].insert_or_assign(++handler_idx, std::move(handler));

    // 返回该处理器编号，可用于反注册
    return handler_idx;
}

void unsignal(int sig, std::size_t handler_idx) {
    std::unique_lock<std::mutex> lock(base::s_signal_mutex_);
    base::s_user_signal_handlers_[sig].erase(handler_idx);
}

} // namespace aoe