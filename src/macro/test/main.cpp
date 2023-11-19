#include <iostream>
#include <condition_variable>
#include <thread>
#include <queue>
#include <vector>

using namespace std::chrono_literals;

std::mutex              g_mutex;
std::condition_variable g_cond;
std::queue<int64_t>     g_queue;


struct ElementData {
    std::string                                        name_;
    uint64_t                                           seq_{ 0 };
    std::chrono::time_point<std::chrono::system_clock> ts_;
    std::string                                        describer_;
    std::vector<char>                                  data_;
};

std::queue<ElementData> g_q;

int64_t count = { 0 };


void produce() {
    while (true) {
        std::this_thread::sleep_for(10ms);

        std::unique_lock lk(g_mutex);
        ElementData      data;
        data.seq_       = count++;
        data.ts_        = std::chrono::system_clock::now();
        data.name_      = "knan";
        data.describer_ = "test for cond!";
        data.data_.resize(1024 * 1024 * 10, 'c');
        g_q.push(std::move(data));

        g_cond.notify_one();
    }
}

void process(int a) {
    std::cout << "data = " << a << std::endl;
}

void process(ElementData& data) {
    std::cout << "**************************************************" << std::endl;
    std::cout << "name    = " << data.name_ << std::endl;
    std::cout << "seq     = " << data.seq_ << std::endl;
    auto now = std::chrono::system_clock::now().time_since_epoch().count();
    std::cout << "diff    = " << (now - data.ts_.time_since_epoch().count()) / 1000 << " us" << std::endl;
}


void comsumer() {
    while (true) {

        std::unique_lock lk(g_mutex);
        //
        g_cond.wait(lk, []() { return !g_q.empty(); });
        // ElementData&& data = std::move(g_q.front());
        ElementData data = std::move(g_q.front());
        g_q.pop();
        //
        lk.unlock();

        process(data);
    }
}


int TEST_pr_com() {
    std::thread t1(produce);
    std::thread t2(comsumer);
    std::thread t3(comsumer);
    std::thread t4(comsumer);
    std::thread t5(comsumer);

    while (true) {
        std::this_thread::sleep_for(100ms);
    }

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}

#include "aoe/macro.h"
#include <type_traits>

// define a conecpt
template<typename T>
using MyConcept1 = AOE_CONCEPT((std::is_same_v<T,int>));

// make T concept
template <class T, AOE_REQUIRES(aoe::is<MyConcept1, T>)>
void myFunc(T value)
{
    std::cout << "call myFunc: " << value << std::endl;
}

int main() {

    myFunc(20);
    return 0;
}
