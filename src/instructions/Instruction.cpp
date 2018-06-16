#include "Instruction.h"

using namespace std;

Instruction::Instruction(Node * left):
    Node(left, nullptr)
{ }

std::string Instruction::getIndentation() const
{
    string res= "";
    for (unsigned i= 0; i < sIndentation; ++i) {
        res+= indent_sequence;
    }

    return res;
}

// Default indentation sequence
string Instruction::indent_sequence = "    ";
unsigned Instruction::sIndentation= 2;
