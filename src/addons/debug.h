
#pragma once

//#define NDEBUG 1 // pour enlever les assert()

// All or no debugs, default value : 0
#define DEBUG_ALL           0 // For all debugs ; be careful, many text
#define NO_DEBUG            0 // Not any debug

// Generic debug
#define DEBUG               1


#if DEBUG_ALL
    #define DEBUG           1
#endif

#if NO_DEBUG
    #define DEBUG           0
#endif
