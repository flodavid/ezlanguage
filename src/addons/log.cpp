#include "log.h"
#include <iostream>

void error(const char *location, const char *msg)
{
    std::cerr << "Error at "<< location<< " : "<< msg<< std::endl;
}


void debug(const std::string &msg, const char *location)
{
#if DEBUG == 1
    std::clog << msg << " at : " << location << std::endl;
#endif
}
