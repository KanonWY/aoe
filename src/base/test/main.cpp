#include <iostream>
#include "aoe/base/base.h"

int main() {
    aoe::initialize();
    std::cout << aoe::base::getNodeName() << std::endl;
    std::cout << "TEST_aoe_base" << std::endl;
    aoe::joinAndFinalize();
    return 0;
}