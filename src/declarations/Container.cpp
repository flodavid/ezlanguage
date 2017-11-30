#include "Container.h"

using namespace std;

Container::Container(Node * left, const string & nameC, const string & typeC,
                    const string & typeE, const string & listI, unsigned size):
	CommonDeclaration(left, nameC), nameContainer(nameC), typeContainer(typeC), typeElement(typeE), listInit(listI), mSize(size)
{}


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
		res+= ";";
	}
	else {
		res= "std::"+ typeContainer + "<" + typeElement + "> " + nameContainer;
		
		if ((mSize != 0) && (typeContainer == "list" || typeContainer == "vector")) {
			res += "(" + to_string(mSize) + ")";
		}
		res += ";";
	}
	return res;
}
