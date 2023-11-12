
add_library(aoe_binding SHARED)
target_sources(aoe_binding PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/binding/object.cpp)
target_include_directories(aoe_binding PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(aoe_binding PUBLIC
        aoe_macro
)


add_executable(TEST_aoe_binding)
target_sources(TEST_aoe_binding PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(TEST_aoe_binding PRIVATE aoe_binding)