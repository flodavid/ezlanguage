//@author Antoine GARNIER
#include "Program.h"

using namespace std;

Program::Program(Node* right, std::string prg_name) : Node(nullptr, right)
{
    name= prg_name; // TODO
    debug("Program : " + prg_name, AT);
}

string Program::preTranslate() const
{
    return "";
}