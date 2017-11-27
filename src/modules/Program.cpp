//@author Antoine GARNIER
#include "Program.h"

std::string INPUT_FUNC_NAME = "getUserInput";

using namespace std;

Program::Program(std::string prg_name, Node* right) : Node(nullptr, right)
{
    name= prg_name; // TODO
    debug("Program : " + prg_name, AT);
}

string Program::preTranslate() const
{
    return 
"#include <string>\n"
"#include <iostream>\n"
"#include <cstdlib>\n"
"\n"
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
"        std::cerr<< \"You did not entered text, please enter an floating number\"<< std::endl\n";
"       exit(EXIT_FAILURE);\n"
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
"\n";
}
