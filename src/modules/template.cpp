#include "Template.h"

using namespace std;

Template::Template(Node * left, Node * elseNode, ConditionalExpression * condition):
	Node(left, elseNode), mCondition(condition)
{ }

Template::~Template()
{

}


string Template::preTranslate() const
{
    string res="";
    
    // the instructions are in the left_son (the first one IS the left son)

    return res;
}


string Template::postTranslate() const
{
    return "}\n";
}
