#include "DeclarationMultipleVariable.h"

using namespace std;


DeclarationMultipleVariable::DeclarationMultipleVariable(Node * left, Node * right, const vector<string> & n, const string & t): Node(left, right), names(n), type(t)
{}	
		
string DeclarationMultipleVariable::preTranslate() const
{
	string res = type + " ";
	
	if (!names.empty()) res += names[0];
	for (unsigned int i = 1; i < names.size(); ++i) {
		res += ", " + names[i];
	}
	res += ";";
	return res;
}
