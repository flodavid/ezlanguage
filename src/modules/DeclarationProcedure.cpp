//@author GARNIER Antoine
#include "DeclarationProcedure.h"

using namespace std;

DeclarationProcedure::DeclarationProcedure(Node * left, Node * right, const string & name, const vector<pair<string, string> > & args): Node(left, right), procedure_name(name), arguments(args)
{}

std::string DeclarationProcedure::preTranslate() const {
    string res = "";
	
	if (procedure_name == "main") res = "int main(int argc, char ** argv) {";
	else {
		res= "void " + getProcedureName() + "(";

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

		res += ") {";
	}

    return res;
}

string DeclarationProcedure::postTranslate() const
{
    return "}";
}
