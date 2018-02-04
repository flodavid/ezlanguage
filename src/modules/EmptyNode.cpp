#include "EmptyNode.h"

using namespace std;

EmptyNode::EmptyNode():
	TranslatedNode("")
{ }

EmptyNode::~EmptyNode()
{ }


string EmptyNode::preTranslate() const
{
    return "";
}
