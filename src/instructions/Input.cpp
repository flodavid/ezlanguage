#include "Input.h"

using namespace std;

Input::Input(Node * instructions, Node * elseNode, ConditionalExpression * condition):
    Instruction(instructions, elseNode), mCondition(condition), mHasElse(true)
{ }

Input::Input(Node * instructions, ConditionalExpression * condition):
    Instruction(instructions), mCondition(condition), mHasElse(false)
{ }

Input::~Input()
{
    delete mCondition;
}


string Input::preTranslate() const
{
    string res= indentationText() ;
    
    return res;
}
