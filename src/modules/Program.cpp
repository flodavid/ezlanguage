#include "Program.h"

using namespace std;

Program::Program(std::string & name, Import* imports, Class* classes, Variable* vars,
    Method* methods, Main* main):
    Module(name, imports, classes, vars, methods)
{
    addRightChild(main);
    debugNode("Program : " + name, AT);
}
