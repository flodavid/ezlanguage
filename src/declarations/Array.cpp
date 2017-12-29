#include "Array.h"

using namespace std;

Array::Array(const std::string & nameC, const string & typeE, unsigned size):
	CommonDeclaration(nullptr, nameC), mTypeElement(typeE), mSize(size)
{
	debugNode("Array with size "+ size, AT);
}

Array::Array(const std::string & nameC, const string & typeE, Expression* listInit):
	CommonDeclaration(listInit, nameC), mTypeElement(typeE), mSize(0)
{
	debugNode("Array with init list", AT);
}

Array::~Array()
{

}


string Array::preTranslate() const
{
    string res= mTypeElement + " " + getDeclarationName() + "[";
    if (mSize == 0) {
        res+= "] = {";;
    }
    else {
        res+= to_string(mSize) + "]";
    }

    return res;
}

string Array::postTranslate() const
{
    string res;
    if (mSize == 0) {
        res+= "}";
    }

	res += ";\n";

    return res;
}

