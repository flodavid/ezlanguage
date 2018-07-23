#include "Module.h"

std::string INPUT_FUNC_NAME = "getUserInput";

using namespace std;

Module::Module(std::string & name, Import* imports, Class* classes, Variable* vars,
    Method* methods):
    Node(imports, classes), mName(name)
{
    addRightChild(vars);
    addRightChild(methods);
    debugNode("Module : " + mName, AT);
}

string Module::preTranslate() const
{
    return 
"#include <string>\n"
"#include <iostream>\n"
"#include <cstdlib>\n"
"#include <map>\n"
"#include <vector>\n"
"#include <list>\n"
"#include <set>\n";
}

string Module::postTranslate() const {
    // Create a file containing all those general purpose functions
    return 
"\#ifndef COMMON_FUNCTIONS\n"
"\#define COMMON_FUNCTIONS\n"
"void "+ INPUT_FUNC_NAME +"(bool* input) {\n"
"    std::string user_input;\n"
"    std::cin >> user_input;\n"
"\n"
"    if(user_input == \"true\" || user_input == \"1\" || user_input == \"yes\"){\n"
"        *input= true;\n"
"    } else if(user_input == \"false\" || user_input == \"0\" || user_input == \"no\"){\n"
"        *input= false;\n"
"    }\n"
"    else {\n"
"        std::cerr<< \"You did not entered text, please enter an boolean text\"<< std::endl;\n"
"        exit(EXIT_FAILURE);\n"
"    }\n"
"}\n"
"\n"
"void "+ INPUT_FUNC_NAME +"(int* input) {\n"
"    std::string user_input;\n"
"    std::cin >> user_input;\n"
"\n"
"    // Check that the user entered some text\n"
"    while (user_input == \"\") {\n"
"        std::cerr<< \"You did not entered text, please enter an integer\"<< std::endl;\n"
"        std::cin >> user_input;\n"
"    }\n"
"\n"
"    char * pEnd;\n"
"    *input= strtol(user_input.c_str(), &pEnd, 10);\n"
"\n"
"    if (*pEnd != '\\0') {\n"
"        std::cerr<< \"The text you entered was not an integer, failure\"<< std::endl;\n"
"        exit(EXIT_FAILURE);\n"
"    }\n"
"}\n"
"\n"
"void "+ INPUT_FUNC_NAME +"(float* input) {\n"
"    std::string user_input;\n"
"    std::cin >> user_input;\n"
"\n"
"    // Check that the user entered some text\n"
"    while (user_input == \"\") {\n"
"        std::cerr<< \"You did not entered text, please enter an floating number\"<< std::endl;\n"
"        std::cin >> user_input;\n"
"    }\n"
"\n"
"    *input= atof(user_input.c_str());\n"
"}\n"
"\n"
"void "+ INPUT_FUNC_NAME +"(std::string* input) {\n"
"    std::cin >> *input;\n"
"}\n"
"\#endif\n"
"\n";
}
