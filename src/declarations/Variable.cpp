//@author : GINISTY Valentin
#include "Variable.h"

using namespace std;

Variable::Variable(const std::string & name, const std::string & type,
        const std::string & scope, const Node* content, bool co, bool st):
    CommonVar(name, type, scope, content, co), isStatic(st), mConstructionParameters(nullptr)
{ }

Variable::Variable(const std::string & name, const std::string & type,
        Expression * construction_parameters, const std::string & scope, bool co, bool st):
    CommonVar(name, type, scope, nullptr, co), isStatic(st), mConstructionParameters(construction_parameters)
{ }

Variable::~Variable()
{
    if(mConstructionParameters) delete mConstructionParameters;
}


string Variable::preTranslate() const {
    string res = "";
    if (isStatic) {
        res += "static ";
    }

    res += CommonVar::preTranslate();

    if(mAffect && mAffect->translate() != "") res+= constructionParameters();
    
	res += ";\n";
    return res;
}
