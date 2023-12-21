
# 使用 googletest 进行单元测试
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shard_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)


# 添加所有组件

add_subdirectory(utils)
add_subdirectory(aoe_type_traits)
add_subdirectory(macro)
add_subdirectory(base)
add_subdirectory(binding)
add_subdirectory(serialize)
add_subdirectory(discover)
add_subdirectory(io)
add_subdirectory(thread)
add_subdirectory(string_hash)
