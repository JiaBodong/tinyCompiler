/*
    This file contains the implementation of the utility functions.
*/

#ifndef __MMUTIL_H__
#define __MMUTIL_H__

#include "Absyn.H"

#define ENABLE_TYPE_CHECK_DEBUG 0


#if DEBUG
    #define DEBUG_PRINT(ss) \
        std::cerr << "[DEBUG]:" << ss << std::endl;
#else
    #define DEBUG_PRINT(ss) 
#endif

#endif /* __MMUTIL_H__ */ 