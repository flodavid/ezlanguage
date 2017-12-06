#include "TranslatedNode.h"

using namespace std;

// @see non optimized data. Replace name by an abstract (virtual static ?) method in Node ?
TranslatedNode::TranslatedNode(const std::string& translated_content, const std::string & _name):
    Expression(), content(translated_content)
{
    debugNode("["+ content +"] in '"+ _name +"' at construction", AT);
}

TranslatedNode::TranslatedNode(const std::string& translated_content, Node* right_son, const std::string & _name):
    Expression(nullptr, right_son), content(translated_content)
{
    debugNode("["+ content +"] in '"+ _name +"' at construction", AT);
}


string TranslatedNode::preTranslate() const {
    return content;
}
