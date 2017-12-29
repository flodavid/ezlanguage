#include "Container.h"

using namespace std;

Container::Container(const string & nameC, const string & typeE, Expression* size):
	CommonDeclaration(nullptr, nameC), mTypeElement(typeE), mSize(size)
{
	debugNode("Container with expression as size", AT);
}

Container::Container(const string & nameC, Expression* listI, const string & typeE):
	CommonDeclaration(listI, nameC), mTypeElement(typeE), mSize(nullptr)
{
	debugNode("Container with initialisation list", AT);
}

Container::~Container()
{
	if (mSize) delete mSize;
}


string Container::preTranslate() const
{
	string res= "std::"+ getType() + "<" + mTypeElement + "> " + getDeclarationName();
	
	if (mSize != nullptr) {
		res+= "["+ mSize->translate() + "]";
	} else res+= "= { ";

	return res;
}

string Container::postTranslate() const
{
	string res;

	if (!mSize) {
		res+= " }";
	}
	res+= ";\n";

    return res;
}
