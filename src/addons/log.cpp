#include "log.h"
#include <iostream>
#include <sstream>

extern "C" void yyprint(const std::string&);

void error(const char *msg, const char *location)
{
    std::cerr << "Error at "<< location<< " : "<< msg<< std::endl;
}

void info(const std::string &msg, const char *location)
{
#if INFO == 1
    std::clog << "<>"  << msg << " at : " << location << std::endl;
#endif
}

void debug(const std::string &msg, const char *location)
{
#if DEBUG == 1
    std::ostringstream oss;
    oss << "  <>"  << msg << " at : " << location;
    yyprint(oss.str());
#endif
}

void debugLex(const std::string &msg, const char *location)
{
#if DEBUGLEX == 1
    std::ostringstream oss;
    oss << msg;
    oss << " at : " << location;
    yyprint(oss.str());
#endif
}

void debugYacc(const std::string &msg, const char *location)
{
#if DEBUGYACC == 1
    std::ostringstream oss;
    oss << msg;
#endif
#if DEBUGYACC == 1 && MINYACC == 0 
    oss << " at : " << location;
#endif
#if DEBUGYACC == 1
    yyprint(oss.str());
#endif
}

void debugNode(const std::string &msg, const char *location)
{
#if DEBUGNODE == 1
    std::clog << ">" << msg << " at : " << location << std::endl;
#endif
}

void debugTranslation(const std::string &msg, const char *location)
{
#if DEBUGTRANSLATION == 1
    std::clog << ">" << msg << " at : " << location << std::endl;
#endif
}
