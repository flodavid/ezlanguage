//@author : GINISTY Valentin
#include "DeclarationVariable.h"

using namespace std;

DeclarationVariable::DeclarationVariable(Node * left, Node * right, const string & n, const string & t, const string & s, Node *content, bool co, bool st): Node(left, right), name(n), type(t), scope(s), affect(content), isConst(co), isStatic(st)
{}

string DeclarationVariable::preTranslate() const {
    string res = "";
    if (isStatic) {
		res += "static ";
	}
    if(isConst){
        res = res + "const ";
    }
    // On ne s'occupe pas du scope

    if(type == "integer"){
        res = res + "int ";
    }else if (type == "real"){
        res = res + "double ";
    }else if (type == "string"){
        res = res + "string ";
    }else if (type == "boolean"){
        res = res + "bool ";
    }else{
        // Case of object
        res += type + " ";
    }
    res += name;
    if (affect != NULL) {
		res += " = " + affect->translate() + ";";
	}
	else res += ";";
    return res;
}
