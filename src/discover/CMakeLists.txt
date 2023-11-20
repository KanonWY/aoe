# aoe 节点发现机制

find_package(asio REQUIRED)
find_package(Threads REQUIRED)


add_library(aoe_discover)
target_sources(aoe_discover PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/node.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/discover/msg/discover_msg.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/discover/channel/channel_base.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/discover/channel/multicast_channel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/discover/channel/channel_net_tools.cpp
)
target_include_directories(aoe_discover PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(aoe_discover PUBLIC aoe_serialize)

# 序列化库简单测试
add_executable(TEST_aoe_discover_client ${CMAKE_CURRENT_SOURCE_DIR}/test/aoe_discover_client.cpp)
target_link_libraries(TEST_aoe_discover_client PRIVATE
        aoe_discover
)

add_executable(TEST_aoe_discover_server ${CMAKE_CURRENT_SOURCE_DIR}/test/aoe_discover_server.cpp)
target_link_libraries(TEST_aoe_discover_server PRIVATE
        aoe_discover
        asio::asio
        Threads::Threads
)