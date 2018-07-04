#include "Instruction.h"

using namespace std;

// Default indentation sequence
string Instruction::indent_sequence = "    ";
int Instruction::sIndentation= 0;

Instruction::Instruction(Node * left, Node * right):
    Node(left, right)
{ }

std::string Instruction::indentationText() const
{
    string res= "";
    debug("Indentation of "+ getName() + ": "+ to_string(sIndentation), AT);
    for (int i= 0; i < sIndentation; ++i) {
        res+= indent_sequence;
    }

    return res;
}
