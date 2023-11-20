cmake_minimum_required(VERSION 3.19)


set(USE_CLANG OFF CACHE BOOL "Use clang as compiler")
set(USE_CLANG_ADDRESS_SANITIZER OFF CACHE BOOL "Use clang address sanitizer")
set(DEBUG_PROF ON CACHE BOOL "use gperftools" FORCE)

project(aoe LANGUAGES CXX C ASM)

# cmake module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# 设置 C++ 标准，一些通用的 flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# 64位
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
# 全局位置无关
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# 使用-pipe可以大大加快编译速度
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe")

if (USE_CLANG_ADDRESS_SANITIZER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls")
endif ()

# C++文件扩展名集合
set(CPP_HEADER_EXT "*.h" "*.hpp" "*.hrp" "*.hxx")
set(CPP_SOURCE_EXT "*.cpp" "*.cxx" "*.cc")
set(C_SOURCE_EXT "*.c")

# 可执行文件和库文件集中存放
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/release/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/release/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/release/arc")

# compile database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)