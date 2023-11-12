#include <iostream>
#include <aoe/this_process/this_process.h>

int main(int argc, char **argv) {
    std::cout << aoe::this_process::path().string() << std::endl;
    std::cout << "test base_utils" << std::endl;
    return 0;
}