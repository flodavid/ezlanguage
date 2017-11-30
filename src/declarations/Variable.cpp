//@author : GINISTY Valentin
#include "Variable.h"

using namespace std;

Variable::Variable(const std::string & name, const std::string & type,
        const std::string & scope, const Node* content, bool co, bool st):
    CommonDeclaration(nullptr, name), mType(type), mScope(scope), affect(content), isConst(co), isStatic(st)
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
    // TODO Scope is not used ("local " or "global ")

    if(mType == "integer"){
        res = res + "int ";
    }else if (mType == "real"){
        res = res + "double ";
    }else if (mType == "string"){
        res = res + "std::string ";
    }else if (mType == "boolean"){
        res = res + "bool ";
    }else{
        // Case of object
        res += mType + " ";
    }
    res += getVariableName();
    const string& affectStr= affect->translate();
    if ( affectStr != "") {
        // TODO check that we just need the string value of affect, not the Node
        // (or if we just need the HashedVariable)
		res += " = " + affectStr;
    }
    
	res += ";\n";
    return res;
}

const VariableHashed* Variable::getVariableHashed() const {
    return hashed;
}