#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<int> count{ 0 };

void add() {
    for (int n = 0; n < 1000; ++n) {
        count.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {

    std::vector<std::thread> v;
    for (int i = 0; i < 10; ++i) {
        v.emplace_back(add);
    }

    for (auto& th: v) {
        th.join();
    }

    std::cout << "count all = " << count << std::endl;
    std::cout << std::endl;
    return 0;
}