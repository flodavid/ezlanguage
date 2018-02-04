
#pragma once

//#define NDEBUG 1 // pour enlever les assert()

// All or no debugs, default value : 0
#define DEBUG_ALL           0 // For all debugs ; be careful, many text
#define NO_DEBUG            0 // Not any debug

// Generic debug
#define DEBUG               0
#define DEBUGLEX            0
#define DEBUGYACC           1
#define MINYACC             0
#define DEBUGNODE           0


#if DEBUG_ALL
    #define DEBUG               1
    #define DEBUGLEX            1
    #define DEBUGYACC           1
#endif

#if NO_DEBUG
    #define DEBUG               0
    #define DEBUGLEX            0
    #define DEBUGYACC           0
#endif
