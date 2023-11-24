#include <thread>
#include <atomic>
#include <string>
#include <iostream>

// full fence
// 任意两个操作之间使用 full fence, 可以避免操作重排。对于 store | load 操作可能被重排 ？

// acquire fence
// 避免在获取栅栏之前的读操作被获取栅栏之后的读写操作重新排序

// release fence
// 避免在释放栅栏之后的写操作，在释放栅栏之前通过镀锡重新排序

// std::atomic_thread_fence();
//  同步线程之间的内存访问


std::atomic<std::string*> ptr;
int                       data;
std::atomic<int>          atoData;

void producer() {
    auto* p = new std::string("C++11");
    data    = 2011;
    atoData.store(100, std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_release);
    ptr.store(p, std::memory_order_release);
}

void consumer() {
    std::string* p2{ nullptr };
    while (!(p2 = ptr.load(std::memory_order_relaxed))) {};
    std::atomic_thread_fence(std::memory_order_acquire);
    std::cout << "*p2: " << *p2 << std::endl;
    std::cout << "data: " << data << std::endl;
    std::cout << "atoData: " << atoData << std::endl;
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