#include "Function.h"

using namespace std;

Function::Function(Node * parameters, const string & name, Node * left,
                const string & type):
    Procedure(name, parameters, left), return_type(type)
{ }

string Function::preTranslate() const {
    string res= "";

    res = return_type + " " + getFunctionName() + "(";

    //translation of the parameters
    res += mParameters->translate();

    res+= ") {\n";

    return res;
}

string Function::postTranslate() const
{
    return "}\n";
}
