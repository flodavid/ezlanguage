//@author : GINISTY Valentin
#include "Variable.h"

using namespace std;

Variable::Variable(Node * right, const std::string & _name, const std::string & _type,
        const std::string & _scope, const std::string & content, bool co, bool st):
    Node(nullptr, right), name(_name), type(_type), scope(_scope), affect(content), isConst(co), isStatic(st)
{
    // TODO create a hashed instance of the variable and store it in the hash table
    hashed= new VariableHashed();
}

string Variable::preTranslate() const {
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
    if (affect != "") {
        // TODO check that we just need the string value of affect, not the Node
        // (or if we just need the HashedVariable)
		res += " = " + affect + ";";
	}
	else res += ";";
    return res;
}

const VariableHashed* Variable::getVariableHashed() const {
    return hashed;
}