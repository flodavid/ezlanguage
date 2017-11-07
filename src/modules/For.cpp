//@author : GINISTY Valentin
#include "For.h"


using namespace std;

For::For(Node * left, Node * right, const string & name, const string & begin, const string & end, const string & s, const string & t): Node(left, right), ind_name(name),  ind_begin(begin), ind_end(end), step(s), type(t), container_name("")
{}


For::For (Node * left, Node * right, const string & name, const string & container) : Node(left, right), ind_name(name), ind_begin(""), ind_end(""), step(""), type(""), container_name(container)
{}


//forall i in 1..10 (step X)
string For::preTranslate() const
{
	string res = "for (";
	if (container_name.empty()) {
		if (!type.empty()) res += type + " ";
		res += ind_name + " = " + ind_begin + "; " + ind_name + " <= " + ind_end + "; " + ind_name + " += " + step + ") {";
	}
	else {
		res += "auto " + ind_name + " : " + container_name + ") {";
	}
	return res;
}

string For::postTranslate() const
{
    return "}";
}

