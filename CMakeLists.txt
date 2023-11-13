cmake_minimum_required(VERSION 3.19)

project(aoe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# compile database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(src)
