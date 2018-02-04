//@author : GINISTY Valentin
#include "Variable.h"

using namespace std;

Variable::Variable(const std::string & name, const std::string & type,
        const std::string & scope, const Node* content, bool co, bool st,
        Expression * construction_parameters):
    CommonDeclaration(nullptr, name), mType(type), mScope(scope), mAffect(content),
    isConst(co), isStatic(st), mConstructionParameters(construction_parameters)
{
    // TODO create a hashed instance of the variable and store it in the hash table
    hashed= new VariableHashed();
}

Variable::~Variable()
{
    delete mAffect;
    delete mConstructionParameters;
}


string Variable::translateType() const
{
    if(mType == "integer"){
        return "int ";
    }else if (mType == "real"){
        return "double ";
    }else if (mType == "string"){
        return "std::string ";
    }else if (mType == "boolean"){
        return "bool ";
    }else{
        // Case of object
        return mType + " ";
    }
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

    res+= translateType();
    res+= getVariableName();
    const string& affectStr= mAffect->translate();
    if ( affectStr != "") {
        // TODO check that we just need the string value of affect, not the Node
        // (or if we just need the HashedVariable)
		res += " = " + affectStr;
    } else if(mConstructionParameters) res += "("+ mConstructionParameters->translate() +")";
    
	res += ";\n";
    return res;
}

const VariableHashed* Variable::getVariableHashed() const {
    return hashed;
}