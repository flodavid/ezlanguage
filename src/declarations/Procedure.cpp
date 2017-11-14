//@author GARNIER Antoine
#include "Procedure.h"

using namespace std;

Procedure::Procedure(Node * left, Node * right, const string & name, const vector<Variable> & args): Node(left, right), procedure_name(name), arguments(args)
{}

std::string Procedure::preTranslate() const {
    string res = "";
	
	if (procedure_name == "main") res = "int main(int argc, char ** argv) {";
	else {
		res= "void " + getProcedureName() + "(";

		//translation of the arguments
		if(!arguments.empty()) {
			
			if (arguments.size() >= 1) {
				// TODO use translate (preTranslate for knowing we must put a ",")
				res+= arguments[0].preTranslate();
			}
			if (arguments.size() > 1) {
				for (unsigned int i = 1; i < arguments.size(); ++i) {
					// TODO use translate (preTranslate for knowing we must put a ",")
					res+= ", " + arguments[0].preTranslate();
				}
			}
		}

		res += ") {";
	}

    //translation of the instructions
    res+= " "+ this->getLeftSon()->translate();
    res+= "}";

    res= this->getRightSon()->translate();
    return res;
}

string Procedure::postTranslate() const
{
    return "}";
}
