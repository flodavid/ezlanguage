#include "Input.h"

using namespace std;

Input::Input(const string & varName):
    Instruction(nullptr, nullptr), mVarName(varName)
{ }


string Input::preTranslate() const
{
    return indentationText() + INPUT_FUNC_NAME +"(&"+ mVarName + ");\n";
}
