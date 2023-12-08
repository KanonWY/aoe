#include "aoe/discover/msg/discover_msg.h"


int main() {
    auto msgptr = aoe::discover::message::create("lppp");
    std::cout << static_cast<char*>(msgptr->data()) << std::endl;
    return 0;
}
