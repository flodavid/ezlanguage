// log.h : include file for logs functions
//
#pragma once
#include <stdio.h>
#include <string>
// #include <tchar.h>

#include "debug.h"

// To represent infinity
#define UNSIGNED_INFINITY std::numeric_limits<unsigned>::max()

// For error and debug output

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT TOSTRING(__FILE__) ":l" TOSTRING(__LINE__)

void error(const char *location, const char *msg);
void info(const std::string& msg, const char *location);
void debug(const std::string& msg, const char *location);
void debugLex(const std::string& msg, const char *location);
void debugYacc(const std::string& msg, const char *location);
void debugNode(const std::string& msg, const char *location);