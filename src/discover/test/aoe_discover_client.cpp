#include "aoe/discover/msg/discover_msg.h"
#include <cassert>


int main() {
    auto msgptr = aoe::discover::message::create("lppp");
    assert(msgptr->data() == nullptr);
    return 0;
}
