//@author Antoine GARNIER
#include "Function.h"

using namespace std;

Function::Function(Node * left, Node * right, const string & name, const vector< VariableHashed > & args, const string & type): Node(left, right), function_name(name), arguments(args), return_type(type)
{}

string Function::preTranslate() const {
    string res= "";

    res = return_type + " " + getFunctionName() + "(";

    //translation of the arguments
    if(!arguments.empty()) {
        // const VariableHashed* var= arguments[0].getVariableHashed();
        const VariableHashed* var= &(arguments[0]);
        // First parameter
		res += var->get_type() + " " + var->get_id();
        // Other parameters
        for (unsigned int i = 1; i < arguments.size(); ++i) {
            res += ", " + var->get_type() + " " + var->get_id();
        }
    }

    res+= ") {";

    return res;
}

string Function::postTranslate() const
{
    string res= "}";

    res+= this->getRightSon()->translate();
    return res;
}

