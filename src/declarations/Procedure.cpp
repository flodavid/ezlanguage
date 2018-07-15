#include "Procedure.h"

using namespace std;

Procedure::Procedure(const string & name, Node * parameters, Instruction * instructions):
    Method(name, parameters, instructions)
{}

std::string Procedure::preTranslate() const {
    std::string res = "void " + getProcedureName() + "(";

    res+= translateParameters();

    res += ") {\n";

    Instruction::indent();
    return res;
}

string Procedure::postTranslate() const
{
    Instruction::unindent();
    return "}\n";
}
