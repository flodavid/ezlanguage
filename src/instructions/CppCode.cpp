#include "CppCode.h"

using namespace std;

CppCode::CppCode(string & textCppCode):
	Instruction(nullptr, nullptr), mTextCppCode(textCppCode)
{ }


string CppCode::preTranslate() const
{
    return mTextCppCode + "\n";
}
