#include "If.h"

using namespace std;

If::If(Node * left, Node * elseNode, ConditionalExpression * condition):
	Node(left, elseNode), mCondition(condition)
{ }

If::If(Node * left, ConditionalExpression * condition):
	Node(left, nullptr), mCondition(condition)
{ }

If::~If()
{	
    delete mCondition;
}


string If::preTranslate() const
{
    string res="if(" + mCondition->translate() + ") ";

    res+= "{\n";
    
    // the instructions are in the left_son (the first one IS the left son)

    return res;
}


string If::postTranslate() const
{
    return "}\n";
}
