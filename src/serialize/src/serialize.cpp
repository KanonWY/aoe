#include "aoe/serialize/serialize.h"

namespace aoe::serialize
{
    std::string getNodeVersion()
    {
        return { "VERSION 1" };
    }
}  // namespace aoe::serialize