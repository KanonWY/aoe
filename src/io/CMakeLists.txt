find_package(asio REQUIRED)
find_package(Threads REQUIRED)

add_library(aoe_io)
target_sources(aoe_io PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/io/net/udp_receive.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/io/net/udp_receive_asio.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/io/net/udp_sender.cpp
)
target_link_libraries(aoe_io PUBLIC
        asio::asio
        Threads::Threads
)
target_include_directories(aoe_io PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(TEST_udp_client)
target_sources(TEST_udp_client PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/test/udp_client.cpp
)
target_link_libraries(TEST_udp_client PRIVATE aoe_io)