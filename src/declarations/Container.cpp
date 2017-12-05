#include "Container.h"

using namespace std;

Container::Container(const string & nameC, const string & typeC, const string & typeE,
                    const string & listI):
	CommonDeclaration(nullptr, nameC), nameContainer(nameC), typeContainer(typeC), typeElement(typeE), listInit(listI), mSize(0)
{
	debugNode("Container with initialisation list", AT);
}

Container::Container(const string & nameC, const string & typeC, const string & typeE,
					unsigned size):
	CommonDeclaration(nullptr, nameC), nameContainer(nameC), typeContainer(typeC), typeElement(typeE), listInit(""), mSize(size)
{
	debugNode("Container with size "+ size, AT);
}


string Container::preTranslate() const
{
	string res;

	if (typeContainer == "array") {
        res= typeElement + " " + nameContainer + "[";
		if (!listInit.empty()) {
			res+= "] = {" + listInit + "}";
		}
		else {
			res+= to_string(mSize) + "]";
		}
	}
	else {
		res= "std::"+ typeContainer + "<" + typeElement + "> " + nameContainer;
		
		if ((mSize != 0) && (typeContainer == "list" || typeContainer == "vector")) {
			res += "(" + to_string(mSize) + ")";
		}
	}
	res += ";\n";

	return res;
}
