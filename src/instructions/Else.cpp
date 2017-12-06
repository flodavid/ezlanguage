#include "Else.h"

using namespace std;

Else::Else(Node * left):
	Node(left, nullptr)
{ }

string Else::preTranslate() const
{
    string res="else {\n";

    return res;
}

string Else::postTranslate() const
{
    return "}\n";
}
