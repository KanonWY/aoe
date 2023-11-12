add_library(aoe_type_traits INTERFACE)
target_include_directories(aoe_type_traits INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


add_executable(TEST_aoe_type_traits)
target_sources(TEST_aoe_type_traits PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/test/aoe_type_traits/main.cpp
)
target_link_libraries(TEST_aoe_type_traits PRIVATE aoe_type_traits)