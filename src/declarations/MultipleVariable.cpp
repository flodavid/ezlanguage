#include "MultipleVariable.h"

using namespace std;


MultipleVariable::MultipleVariable(const vector<string> & n, const string & t):
	names(n), type(t)
{}

void MultipleVariable::addVar(const std::string& var)
{
    names.push_back(var);
}
		
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
