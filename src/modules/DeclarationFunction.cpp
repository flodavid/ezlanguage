//@author Antoine GARNIER
#include "DeclarationFunction.h"

using namespace std;

DeclarationFunction::DeclarationFunction(Node * left, Node * right, const string & name, const vector< Variable > & args, const string & type): Node(left, right), function_name(name), arguments(args), return_type(type)
{}

string DeclarationFunction::preTranslate() const {
    string res= "";

    res = return_type + " " + getFunctionName() + "(";

    //translation of the arguments
    if(!arguments.empty()) {
        // First parameter
		res += arguments[0].get_type() + " " + arguments[0].get_id();
        // Other parameters
        for (unsigned int i = 1; i < arguments.size(); ++i) {
            res += ", " + arguments[i].get_type() + " " + arguments[i].get_id();
        }
    }

    res+= ") {";

    return res;
}

string DeclarationFunction::postTranslate() const
{
    string res= "}";

    res+= this->getRightSon()->translate();
    return res;
}

