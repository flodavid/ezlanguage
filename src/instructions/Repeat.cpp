//@author Antoine GARNIER
#include "Repeat.h"

using namespace std;

Repeat::Repeat(Node * instructions, ConditionalExpression * cond):
    Instruction(instructions), mCondition(cond)
{}

Repeat::~Repeat()
{
    delete mCondition;
}

string Repeat::preTranslate() const
{
    string res= indentationText() +"do {\n";
    Instruction::indent();
    return res;
}

string Repeat::postTranslate() const
{
    Instruction::unindent();
    return indentationText() +"} while " + mCondition->translate() + ";\n";
}
