add_library(aoe_base_utils SHARED)
target_sources(aoe_base_utils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/base_utils/this_process.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/base_utils/manager.cpp
)
target_include_directories(aoe_base_utils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(aoe_base_utils PUBLIC aoe_macro)


# for TEST
add_executable(TEST_aoe_base_utils)
target_sources(TEST_aoe_base_utils PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/test/base_utils/main.cpp)
target_link_libraries(TEST_aoe_base_utils PRIVATE
        aoe_base_utils)


add_executable(TEST_module_manager)
target_sources(TEST_module_manager PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/test/module_manager/main.cpp)
target_link_libraries(TEST_module_manager
        PUBLIC aoe_base_utils)