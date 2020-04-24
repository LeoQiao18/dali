cmake_minimum_required(VERSION 3.16)
project(sandbox-src)

set(CMAKE_CXX_STANDARD 17)

add_executable(sandbox sandbox.cpp)
target_link_libraries(sandbox PRIVATE dali)

if (WIN32)
    target_compile_definitions(sandbox PRIVATE DALI_PLATFORM_WINDOWS)
endif (WIN32)
