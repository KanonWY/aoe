#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int>  mySharedWork;
std::atomic<bool> dataProduced{ false };
std::atomic<bool> dataConsumed{ false };

void dataProducer() {
    mySharedWork = { 1, 0, 3 };
    dataProduced.store(true, std::memory_order_release);
}

void deliver() {
    while (!dataProduced.load(std::memory_order_acquire)) {}
    dataConsumed.store(true, std::memory_order_release);
}

void dataConsumer() {
    while (!dataConsumed.load(std::memory_order_acquire)) {}
    mySharedWork[1] = 2;
}

int main() {
    std::cout << std::endl;

    std::thread t3(dataConsumer);
    std::thread t1(dataProducer);
    std::thread t2(deliver);

    t3.join();
    t2.join();
    t1.join();
    for (auto& v: mySharedWork) {
        std::cout << v << " ";
    }
    std::cout << "\n\n";

    return 0;
}