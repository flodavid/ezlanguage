//@author Antoine GARNIER
#include "Program.h"

using namespace std;

Program::Program(Node* right, std::string prg_name) : Node(nullptr, right)
{
    // name(prg_name); // TODO
}

string Program::preTranslate() const
{
    return "";
}