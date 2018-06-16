//@author : GINISTY Valentin
#include "Variable.h"

using namespace std;

Variable::Variable(const std::string & name, const std::string & type,
        Expression* content, const std::string & scope, bool co, bool st):
    CommonVar(name, type, content, false, scope, co), mIsInstruction(true), mIsStatic(st),
    mConstructionParameters(nullptr)
{ }

Variable::Variable(bool co, const std::string & name, const std::string & type,
        Expression* content):
    CommonVar(name, type, content, false, "", co), mIsInstruction(false), mIsStatic(false),
    mConstructionParameters(nullptr)
{ }

Variable::~Variable()
{
    if(mConstructionParameters) delete mConstructionParameters;
}


string Variable::preTranslate() const {
    string res = indentationText();
    if (mIsStatic) {
        res += "static ";
    }

    res += CommonVar::preTranslate();

    // // If mAffect has an empty translation, we can try to translate construction parameters
    // if(!mAffect || mAffect->translate() == "") // Removed, useless if class correctly constructed
    res+= constructionParameters();
    
	res += ";";
    if (mIsInstruction) res+= '\n';
    return res;
}

string Variable::constructionParameters() const
{
    return (
        mConstructionParameters
        ? "("+ mConstructionParameters->translate() +")"
        : ""
    );
}