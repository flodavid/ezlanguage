#include "Else.h"

using namespace std;

Else::Else(Node * left):
    Instruction(left)
{ }

string Else::preTranslate() const
{
    // We put indentation text, because it has been chosen to put all else on another line
    //  as the closing bracket of its corresponding if instruction
    string res= indentationText() +"else {\n";

    Instruction::indent();
    return res;
}

string Else::postTranslate() const
{
    Instruction::unindent();
    return indentationText() +"}\n";
}
