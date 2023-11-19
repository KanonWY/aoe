# aoe 简单序列化库
add_library(aoe_serialize)
target_sources(aoe_serialize PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/serialize.cpp
)
target_include_directories(aoe_serialize PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 序列化库简单测试
add_executable(TEST_aoe_serialize ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(TEST_aoe_serialize PRIVATE
        aoe_serialize
)