#include "EmptyNode.h"

using namespace std;

EmptyNode::EmptyNode():
	Node(nullptr, nullptr)
{ }

EmptyNode::~EmptyNode()
{ }


string EmptyNode::preTranslate() const
{
    return "";
}
