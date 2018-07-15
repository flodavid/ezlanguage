#include "FunctionCallInstruction.h"

using namespace std;

FunctionCallInstruction::FunctionCallInstruction(FunctionCall* callToTransform):
	FunctionCall(callToTransform), Instruction(nullptr)
{ }

FunctionCallInstruction::FunctionCallInstruction(const std::string & functionName, Expression * arguments,
            Expression* objectExpression):
	FunctionCall(functionName, arguments, objectExpression), Instruction(nullptr)
{ }


string FunctionCallInstruction::preTranslate() const
{
	return Instruction::indentationText() + FunctionCall::preTranslate() + ";\n";
}
