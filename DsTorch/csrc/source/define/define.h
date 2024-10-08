//
// Created by luwei on 24/10/8.
//

#ifndef DSTORCH_DEFINE_H
#define DSTORCH_DEFINE_H

#ifdef _WIN32
    #ifdef DLL_EXPORTS
        #define DLL_API extern "C" __declspec(dllexport)
    #else
        #define DLL_API __declspec(dllimport)
    #endif
#else
    #ifdef DLL_EXPORTS
        #define DLL_API extern "C" __attribute__((visibility("default")))
    #else
        #define DLL_API
    #endif
#endif

#endif //DSTORCH_DEFINE_H
