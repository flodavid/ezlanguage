//@author GARNIER Antoine
#include "Procedure.h"

using namespace std;

Procedure::Procedure(Node * left, const string & name, const vector<Variable*> & args):
	Node(left, nullptr, "Procedure '"+ name +"'"), procedure_name(name), arguments(args)
{}

std::string Procedure::preTranslate() const {
    std::string res = "";
	
	// TODO correct main function check (main name is the program name, not mandatory "main")
	if (procedure_name == "main") res =
		"int main(int argc, char ** argv";

	else {
		res= "void " + getProcedureName() + "(";

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

	}
	res += ") {\n";

    return res;
}

string Procedure::postTranslate() const
{
    return "}\n";
}
