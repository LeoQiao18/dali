cmake_minimum_required(VERSION 3.16)
project(dali)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/spdlog)

add_library(dali SHARED
        include/dali/app.h
        include/dali/core.h
        include/dali/dali.h
        include/dali/entrypoint.h
        include/dali/event.h
        include/dali/event/app.h
        include/dali/event/common.h
        include/dali/log.h
        src/app.cpp
        src/log.cpp
        include/dali/event/key.h
        include/dali/event/mouse.h)

target_link_libraries(dali PUBLIC spdlog::spdlog)
#include(GenerateExportHeader)
#GENERATE_EXPORT_HEADER(dali
#        BASE_NAME dali
#        EXPORT_MACRO_NAME DALI_EXPORT
#        EXPORT_FILE_NAME dali_export.h
#        STATIC_DEFINE DALI_BUILD_STATIC
#        )
target_include_directories(dali PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_definitions(dali PRIVATE DALI_BUILD_DLL)
if (WIN32)
    target_compile_definitions(dali PRIVATE DALI_PLATFORM_WINDOWS)
endif (WIN32)
