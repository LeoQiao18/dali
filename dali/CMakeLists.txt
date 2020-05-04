cmake_minimum_required(VERSION 3.16)
project(dali)

set(CMAKE_CXX_STANDARD 17)

# ==================== Dali ====================
add_library(dali SHARED
        include/dali/app.h
        include/dali/common.h
        include/dali/core.h
        include/dali/dali.h
        include/dali/entrypoint.h
        include/dali/event.h
        include/dali/event/app.h
        include/dali/event/core.h
        include/dali/event/key.h
        include/dali/event/mouse.h
        include/dali/log.h
        include/dali/window.h
        src/core/app.cpp
        src/core/log.cpp
        src/platform/windows/window.cpp
        src/platform/windows/window.h src/core/window.cpp include/dali/layer.h src/core/layer.cpp)

target_include_directories(dali PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --------------- Dali compilation configurations ---------------
target_compile_definitions(dali PRIVATE DALI_BUILD_DLL)
if (WIN32)
    target_compile_definitions(dali PRIVATE DALI_PLATFORM_WINDOWS)
endif (WIN32)

if (CMAKE_BUILD_TYPE AND
        CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(dali PRIVATE DALI_DEBUG)
endif ()


# ==================== Vendor ====================
# --------------- glad ---------------
add_subdirectory(vendor/glad)
target_link_libraries(dali PUBLIC glad)

# --------------- glfw ---------------
# not building docs, tests and examples
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

target_compile_definitions(dali PRIVATE "GLFW_INCLUDE_NONE")

add_subdirectory(vendor/glfw)
target_link_libraries(dali PUBLIC glfw)

# --------------- spdlog ---------------
add_subdirectory(vendor/spdlog)
target_link_libraries(dali PUBLIC spdlog::spdlog)
