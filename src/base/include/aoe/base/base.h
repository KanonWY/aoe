#pragma once

#include "aoe/base/init_config.h"

#include <filesystem>
#include <functional>


namespace aoe {

void initialize();

void finalize();

bool ok();

void terminate();

void join();

void joinAndFinalize();

std::size_t signal(int sig, std::function<void(int signal)> handler);

std::size_t signal(int sig, std::function<void(int signal, std::size_t handler_idx)> handler);

void unsignal(int sig, std::size_t handler_idx);
} // namespace aoe


namespace aoe::base {

const std::string& getNodeName();

const InitConfig& getInitConfig();

int64_t getDeviceId();

std::filesystem::path getDataRoot(const std::string& name);

} // namespace aoe::base