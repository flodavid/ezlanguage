#include "CommonVar.h"

using namespace std;

CommonVar::CommonVar(const std::string & name, const std::string & type,
        const std::string & scope, const Node* content, bool co):
    CommonDeclaration(nullptr, name), mType(type), mScope(scope), mAffect(content),
    isConst(co)
{
    // TODO create a hashed instance of the variable and store it in the hash table
    hashed= new VariableHashed();
}

CommonVar::CommonVar(Node * left, const string & name, const std::string & type,
        const std::string & scope, bool co):
    CommonDeclaration(left, name), mType(type), mScope(scope), mAffect(nullptr),
    isConst(co)
{ }

CommonVar::~CommonVar()
{
    if(mAffect) delete mAffect;
}


string CommonVar::translateType() const
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

string CommonVar::preTranslate() const {
    string res = "";
    if(isConst){
        res = res + "const ";
    }
    // TODO Scope is not used ("local " or "global ")

    res+= translateType();
    res+= getVariableName();

    if(mAffect) {
        const string& affectStr= mAffect->translate();
        if (affectStr != "") {
            // TODO check that we just need the string value of affect, not the Node
            // (or if we just need the HashedVariable)
            res+= " = " + affectStr;
        }
    }
    
    return res;
}

const VariableHashed* CommonVar::getVariableHashed() const {
    return hashed;
}
