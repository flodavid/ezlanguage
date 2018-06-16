#include "Function.h"

using namespace std;

Function::Function(const string & name, Node * parameters, Node * instructions,
                const string & type):
    Method(name, parameters, instructions), return_type(type)
{ }

string Function::preTranslate() const {
    string res= return_type + " " + getFunctionName() + "(";

    res+= translateParameters();

    res+= ") {\n";

    return res;
}

string Function::postTranslate() const
{
    return "}\n";
}
