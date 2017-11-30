#include "If.h"

using namespace std;

If::If(Node * left, Node * elseNode, Node * condition):
	Node(left, elseNode), cond(condition)
{ }

string If::preTranslate() const
{
    string res="if(" + cond->translate() + ") ";

    res+= "{\n";
    
    // the instructions are in the left_son (the first one IS the left son)

    return res;
}


string If::postTranslate() const
{
    return "}\n";
}
