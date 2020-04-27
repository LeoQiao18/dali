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

/* helpers */
#define BIT(pos) (1 << pos)

#endif //DALI_CORE_H
