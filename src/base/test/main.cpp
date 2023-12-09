#include <iostream>
#include "aoe/base/base.h"
#include <thread>
#include <atomic>

std::atomic<int64_t> m_count{ 0 };


int main() {
    aoe::initialize();
    while (aoe::ok()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "hello world " << m_count++ << std::endl;
        std::cout << std::this_thread::get_id() << std::endl;
    }
    aoe::finalize();
    return 0;
}