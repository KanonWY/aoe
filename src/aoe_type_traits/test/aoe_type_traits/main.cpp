#include <iostream>
#include <future>

int main(int argc, char *argv[]) {

    for (int i = 0; i < 10; ++i) {
        std::future<std::string> res = std::async(std::launch::async, []() {
            std::cout << "this thread id = " << std::this_thread::get_id() << std::endl;
            std::string res{"lll"};
            return res;
        });
    }
    std::future<std::string> res = std::async(std::launch::async, []() {
        std::cout << "this thread id = " << std::this_thread::get_id() << std::endl;
        std::string res{"lllMMMM"};
        return res;
    });

    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "===> finished" << std::endl;
    std::cout << "main thread is " << std::this_thread::get_id() << std::endl;

    return 0;
}