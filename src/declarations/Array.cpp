#include "Array.h"

using namespace std;

Array::Array(const std::string & nameC, const string & typeE, unsigned size):
	CommonDeclaration(nullptr, nameC), mTypeElement(typeE), mListInit(""), mSize(size)
{
	debugNode("Array with size "+ size, AT);
}

Array::~Array()
{

}


string Array::preTranslate() const
{
    string res= mTypeElement + " " + getDeclarationName() + "[";
    if (!mListInit.empty()) {
        res+= "] = {" + mListInit + "}";
    }
    else {
        res+= to_string(mSize) + "]";
    }

	res += ";\n";

    return res;
}
