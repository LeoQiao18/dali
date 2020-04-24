cmake_minimum_required(VERSION 3.16)
project(dali-src)

set(CMAKE_CXX_STANDARD 17)

add_library(dali SHARED
        dali.h
        dali/core.h
        dali/application.h dali/application.cpp)
target_link_libraries(dali PUBLIC spdlog::spdlog)
#include(GenerateExportHeader)
#GENERATE_EXPORT_HEADER(dali
#        BASE_NAME dali
#        EXPORT_MACRO_NAME DALI_EXPORT
#        EXPORT_FILE_NAME dali_export.h
#        STATIC_DEFINE DALI_BUILD_STATIC
#        )
target_include_directories(dali PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(dali PRIVATE DALI_BUILD_DLL)
if (WIN32)
    target_compile_definitions(dali PRIVATE DALI_PLATFORM_WINDOWS)
endif (WIN32)