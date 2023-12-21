# 编译期 hash_string 库
add_library(aoe_hash_string INTERFACE)
target_include_directories(aoe_hash_string INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


file(GLOB MY_FILES "${CMAKE_CURRENT_SOURCE_DIR}/test/*")

set(EXEC_NAME_LIST "")
foreach(FILE_PATH ${MY_FILES})
    get_filename_component(FILE_NAME ${FILE_PATH} NAME_WE)
    list(APPEND EXEC_NAME_LIST ${FILE_NAME})
endforeach()


foreach(demo_name ${EXEC_NAME_LIST})
    add_executable(${demo_name} test/${demo_name}.cpp)

    # 链接 gtest, 支持单元测试
    target_link_libraries(${demo_name} PRIVATE
            GTest::gtest_main
            aoe_hash_string
    )
    gtest_discover_tests(${demo_name}
            EXTRA_ARGS --gtest_color=yes
    )
endforeach()

