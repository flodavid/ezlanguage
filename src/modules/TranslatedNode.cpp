#include "TranslatedNode.h"

// @see non optimized data. Replace name by an abstract (virtual static ?) method in Node ?
TranslatedNode::TranslatedNode(const std::string& translated_content, const std::string & _name):
    Node(nullptr, nullptr, "["+ translated_content +"]<-"+ _name), content(translated_content)
{
    debug("["+ content +"] in '"+ _name +"' at construction", AT);
}