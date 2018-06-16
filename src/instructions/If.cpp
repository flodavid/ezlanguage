#include "If.h"

using namespace std;

If::If(Node * instructions, Node * elseNode, ConditionalExpression * condition):
    Instruction(instructions, elseNode), mCondition(condition), mHasElse(true)
{ }

If::If(Node * instructions, ConditionalExpression * condition):
    Instruction(instructions), mCondition(condition), mHasElse(false)
{ }

If::~If()
{
    delete mCondition;
}


string If::preTranslate() const
{
    string res= indentationText() + "if " + mCondition->translate() + " {\n";
    
    // the instructions are in the left_son (the first one IS the left son)
    
    Instruction::indent();
    return res;
}


string If::postTranslate() const
{
    Instruction::unindent();
    string res= indentationText() + "}";
    if (!mHasElse) res+= "\n";

    return res;
}
