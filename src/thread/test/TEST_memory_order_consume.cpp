#include <iostream>
#include <atomic>
#include <thread>
#include <string>

/**
 *  std::memory_order_consume
 *
 * @desc: 1、暂时没有编译器支持
 *        2、难以理解
 *        3、C++17 官方不推荐使用
 *
 *  @desc: 数据依赖关系
 *  carries-a-dependency-to:    携依赖
 *   如果操作 A 的结果在操作 B中作为操作数： 则 A carries-a-dependency-to B.
 *  dependency-order-before:    先依赖
 *
 *
 */

std::atomic<std::string*> ptr;
int                       data;
std::atomic<int>          atoData;

void producer() {
    auto* p = new std::string("C++11");
    data    = 2011;
    atoData.store(2014, std::memory_order_relaxed);
    ptr.store(p, std::memory_order_release);
}

void consumer() {
    std::string* p2;
    while (!(p2 = ptr.load(std::memory_order_consume))) {}
    std::cout << "*p2 = " << *p2 << std::endl;
    std::cout << "data: " << data << std::endl;
    std::cout << "atoData: " << atoData.load(std::memory_order_relaxed) << std::endl;
}

int main() {
    std::cout << std::endl;
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    std::cout << std::endl;
    return 0;
}
