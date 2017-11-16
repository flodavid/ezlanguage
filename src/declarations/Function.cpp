//@author Antoine GARNIER
#include "Function.h"

using namespace std;

Function::Function(Node * left, const string & name, const vector< Variable* > & args,
                const string & type):
    Node(left, nullptr, "Function"), function_name(name), arguments(args), return_type(type)
{}

string Function::preTranslate() const {
    string res= "";

    res = return_type + " " + getFunctionName() + "(";

    //translation of the arguments
    if(!arguments.empty()) {
        const Variable* var= arguments[0];
        // First parameter
		res += var->translate();
        // Other parameters
        for (unsigned int i = 1; i < arguments.size(); ++i) {
            res += ", " + var->translate();
        }
    }

    res+= ")\n{";

    return res;
}

string Function::postTranslate() const
{
    return "}";
}

