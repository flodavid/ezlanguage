#include "If.h"

using namespace std;

If::If(Instruction * instructions, Else * elseNode, ConditionalExpression * condition):
    Instruction(instructions, elseNode), mCondition(condition), mHasElse(elseNode != nullptr)
{ }

If::If(Instruction * instructions, ConditionalExpression * condition):
    Instruction(instructions), mCondition(condition), mHasElse(false)
{ }

If::~If()
{
    delete mCondition;
}


string If::preTranslate() const
{
    string res= Instruction::indentationText() + "if " + mCondition->translate() + " {\n";
    
    // the instructions are in the left_son (the first one IS the left son)
    
    Instruction::indent();
    return res;
}


string If::postTranslate() const
{
    Instruction::unindent();
    string res= Instruction::indentationText() + "}";
    if (!mHasElse) res+= "\n";

    return res;
}
