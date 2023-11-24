#include <atomic>
#include <iostream>
#include <string>
#include <thread>

/**
 * @brief 顺序一致性，所有线程上的操作都遵循一个通用时钟。
 *        一个线程可以看到另一个线程的操作，因此可以到所有其他线程的操作
 */

std::string       work;
std::atomic<bool> ready{ false };

void consumer() {
    while (!ready.load()) {}
    std::cout << work << std::endl;
}

void producer() {
    work  = "done work";
    ready = true;
}

void TestSEQ_CST() {
    std::thread prod(producer);
    std::thread con(consumer);
    prod.join();
    con.join();
}

int main() {
    TestSEQ_CST();
    return 0;
}