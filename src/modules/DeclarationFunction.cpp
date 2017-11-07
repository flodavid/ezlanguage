//@author Antoine GARNIER
#include "DeclarationFunction.h"

using namespace std;

DeclarationFunction::DeclarationFunction(Node * left, Node * right, const string & name, const vector<pair<string, string> > & args, const string & type): Node(left, right), function_name(name), arguments(args), return_type(type)
{}

string DeclarationFunction::preTranslate() const {
    string res= "";

    res = return_type + " " + getFunctionName() + "(";

    //translation of the arguments
    if(!arguments.empty()) {
		
        if (arguments.size() >= 1) {
            res += arguments[0].first + " " + arguments[0].second;
        }
        if (arguments.size() > 1) {
            for (unsigned int i = 1; i < arguments.size(); ++i) {
                res += ", " + arguments[i].first + " " + arguments[i].second;
            }
        }
    }

    res+= ") {";

    return res;
}

string DeclarationFunction::postTranslate() const
{    
    return "}";
}

