//@author Antoine GARNIER
#include "While.h"

using namespace std;

While::While(ConditionalExpression * cond, Node * instructions):
    Instruction(instructions), mCondition(cond)
{}

While::~While()
{
    delete mCondition;
}


string While::preTranslate() const {
    string res= indentationText() +"while " + mCondition->translate() + " {\n";
    Instruction::indent();
    return res;
}

string While::postTranslate() const
{
    Instruction::unindent();
    //    The instructions have been translated, the loop closes
    return indentationText() +"}\n";
}
