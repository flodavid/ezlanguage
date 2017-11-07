#include "DeclarationContainer.h"

using namespace std;


DeclarationContainer::DeclarationContainer(Node * left, Node * right, const string & nameC, const string & typeC, const string & typeE, const string & listI): Node(left, right), nameContainer(nameC), typeContainer(typeC), typeElement(typeE), listInit(listI)
{}


string DeclarationContainer::preTranslate() const
{
	string res;

	if (typeContainer == "array") {
		if (!listInit.empty()) {
			res = typeElement + " " + nameContainer + "[] = {" + listInit + "}";
		}
		else {
			res = typeElement + " " + nameContainer + "[" + to_string(size) + "]";
		}
		res += ";";
	}
	else {
		res = typeContainer + "<" + typeElement + "> " + nameContainer;
		
		if ((size != 0) && ((typeContainer == "list") || (typeContainer == "vector"))) {
			res += "(" + to_string(size) + ")";
		}
		res += ";";
	}
	return res;
}
