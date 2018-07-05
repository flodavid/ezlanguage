//@author : GINISTY Valentin
#include "Variable.h"

using namespace std;

Variable::Variable(const std::string & name, const std::string & type,
        Expression* content, const std::string & scope, bool co, bool st):
    CommonVar(name, type, content, false, scope, co), mIsInstruction(true), mIsStatic(st)
{ }

Variable::Variable(bool co, const std::string & name, const std::string & type,
        Expression* content):
    CommonVar(name, type, content, false, "", co), mIsInstruction(false), mIsStatic(false)
{ }

Variable::~Variable()
{ }


string Variable::preTranslate() const {
    string res = "";
    if (mIsInstruction) res+= indentationText();
    if (mIsStatic) {
        res += "static ";
    }

    res += CommonVar::preTranslate() +";";
    if (mIsInstruction) res+= '\n';
    return res;
}