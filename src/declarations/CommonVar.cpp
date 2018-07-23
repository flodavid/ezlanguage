#include "CommonVar.h"

using namespace std;

CommonVar::CommonVar(const string & name, const string & type,
        Expression* content, bool isInitList, const string & scope, bool isConst):
    CommonDeclaration(nullptr, name), mType(type), mScope(scope), mAffect(content),
    mIsInitList(isInitList), mIsConst(isConst)
{
    // TODO create a hashed instance of the variable and store it in the hash table
    hashed= new VariableHashed();
}

CommonVar::~CommonVar()
{
    if(mAffect) delete mAffect;
    delete hashed;
}


string CommonVar::translateType() const
{
    string trans_type= translatePrimitiveType(mType);

    if(trans_type != ""){
        return trans_type;
    }else{
        // Case of object
        return mType;
    }
}

string CommonVar::preTranslate() const
{
    string res = "";
    if(mIsConst){
        res+= "const ";
    }
    // TODO Scope is not used ("local " or "global ")

    res+= translateType() + " ";
    res+= getVariableName();

    if(mAffect) {
        const string& affectStr= mAffect->translate();
        if (affectStr != "") {
            // TODO check that we just need the string value of affect, not the Node
            // (or if we just need the HashedVariable)
            if (mIsInitList) res+= " = " + affectStr;
            else res+= "( " + affectStr +" )";
        }
    }
    
    return res;
}

const VariableHashed* CommonVar::getVariableHashed() const {
    return hashed;
}
