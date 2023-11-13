# 简答的宏库封装
add_library(aoe_macro INTERFACE)
target_include_directories(aoe_macro INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(Threads REQUIRED)


add_executable(TEST_aoe_macro)
target_sources(TEST_aoe_macro PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
)
target_link_libraries(TEST_aoe_macro PRIVATE 
        aoe_macro Threads::Threads
)