#include "Container.h"

using namespace std;

Container::Container(const string & nameC, const string & typeE, Expression* size,
        bool isParameter):
    CommonVar(nameC, typeE), mSize(size), mIsParameter(isParameter)
{
    debugNode("Container with expression as size", AT);
}

Container::Container(const string & nameC, Expression* listI, const string & typeE):
    CommonVar(nameC, typeE, listI), mSize(nullptr), mIsParameter(false)
{
    debugNode("Container with initialisation list", AT);
}

Container::~Container()
{
    if (mSize) delete mSize;
}

string Container::translateType() const
{
    return "std::"+ getContainerType() + "<" + CommonVar::translateType() + ">";
}

string Container::preTranslate() const
{
    string res= indentationText() + translateType() +" "+ getVariableName();
    
    if (!mIsParameter) {
        if (mSize != nullptr) {
            res+= "["+ mSize->translate() + "]";
        } else res+= "= { ";
    }

    Instruction::indent();
    return res;
}

string Container::postTranslate() const
{
    Instruction::unindent();
    string res;

    if (!mIsParameter) {
        if (!mSize) {
            res+= " }";
        }
        res+= ";\n";
    }

    return res;
}
