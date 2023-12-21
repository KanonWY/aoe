#include <aoe/macro.h>
#include <gtest/gtest.h>
#include <iostream>

#define HELLOWORLD(A) std::cout << A << std::endl;

TEST(macro_invoke, AOE_MACRO_INVOKE)
{
    AOE_MACRO_INVOKE(HELLOWORLD, 1, 2, 3)
    AOE_ARGS_FIRST(1,2,3,4);
}