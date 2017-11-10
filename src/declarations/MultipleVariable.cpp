#include "MultipleVariable.h"

using namespace std;


MultipleVariable::MultipleVariable(Node * left, Node * right, const vector<string> & n, const string & t): Node(left, right), names(n), type(t)
{}	
		
string MultipleVariable::preTranslate() const
{
	string res = type + " ";
	
	if (!names.empty()) res += names[0];
	for (unsigned int i = 1; i < names.size(); ++i) {
		res += ", " + names[i];
	}
	res += ";";
	return res;
}
