
# aoe_base 库包括了框架启动流程，捕获信号等等
add_library(aoe_base)
target_sources(aoe_base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/base/base.cpp)
target_include_directories(aoe_base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(aoe_base aoe_base_utils)