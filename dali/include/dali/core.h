//
// Created by Leo on 4/23/2020.
//

#ifndef DALI_CORE_H
#define DALI_CORE_H

//#include <dali_export.h>

#ifdef DALI_PLATFORM_WINDOWS

#ifdef DALI_BUILD_DLL
#define DALI_API __declspec(dllexport)
#else //DALI_BUILD_DLL
#define DALI_API __declspec(dllimport)
#endif //DALI_BUILD_DLL

#else //DALI_PLATFORM_WINDOWS
#error Dali only supports Windows.
#endif //DALI_PLATFORM_WINDOWS

/* Debugging */
#ifdef DALI_DEBUG
#if defined(DALI_PLATFORM_WINDOWS)
#define DALI_DEBUGBREAK() __debugbreak()
#elif defined(DALI_PLATFORM_LINUX)
#include <signal.h>
#define DALI_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define DALI_ENABLE_ASSERTS
#else
#define DALI_DEBUGBREAK()
#endif

#ifdef DALI_ENABLE_ASSERTS
#define DALI_ASSERT(x, ...) { if(!(x)) { DALI_ERROR("Assertion Failed: {0}", __VA_ARGS__); DALI_DEBUGBREAK(); } }
#define DALI_CORE_ASSERT(x, ...) { if(!(x)) { DALI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DALI_DEBUGBREAK(); } }
#else
#define DALI_ASSERT(x, ...)
#define DALI_CORE_ASSERT(x, ...)
#endif

/* helpers */
#define BIT(pos) (1 << pos)

#endif //DALI_CORE_H
