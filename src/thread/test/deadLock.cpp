#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

struct CriticalData {
    std::mutex mut;
};


void deadLock(CriticalData& a, CriticalData& b) {
    a.mut.lock();
    std::cout << "get first mutex" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    b.mut.lock();
    std::cout << "get the second mutex" << std::endl;

    a.mut.unlock();
    b.mut.unlock();
}


int main() {
    CriticalData c1;
    CriticalData c2;

    std::thread t1([&]() { deadLock(c1, c2); });
    std::thread t2([&]() { deadLock(c2, c1); });

    t1.join();
    t2.join();
    return 0;
}