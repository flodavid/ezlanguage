#include "Function.h"

using namespace std;

Function::Function(const string & name, Node * parameters, Instruction * instructions,
                const string & type):
    Method(name, parameters, instructions), mReturnType(type)
{ }

string Function::preTranslate() const {
    string res= indentationText() + translatePrimitiveType(mReturnType) + " " + getFunctionName() + "(";

    res+= translateParameters();

    res+= ") {\n";

    Instruction::indent();
    return res;
}

string Function::postTranslate() const
{
    Instruction::unindent();
    return "}\n";
}
