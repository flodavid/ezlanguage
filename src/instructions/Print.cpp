#include "Print.h"

using namespace std;

Print::Print(const string & textStream):
    Instruction(nullptr), mText(textStream)
{ }


string Print::preTranslate() const
{
    return indentationText() +"std::cout"+ mText +"<< std::endl;\n";
}   
