#include "Procedure.h"

using namespace std;

Procedure::Procedure(const string & name, Node * parameters, Node * instructions):
    Method(name, parameters, instructions)
{}

std::string Procedure::preTranslate() const {
    std::string res = "void " + getProcedureName() + "(";

	res+= translateParameters();

    res += ") {\n";
    return res;
}

string Procedure::postTranslate() const
{
    return "}\n";
}
