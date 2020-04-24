cmake_minimum_required(VERSION 3.16)
project(dali)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/spdlog)
add_subdirectory(src)
