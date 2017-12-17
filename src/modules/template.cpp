#include "Template.h"

using namespace std;

Template::Template(Node * left):
	Node(left, nullptr)
{ }

Template::~Template()
{

}


string Template::preTranslate() const
{
    string res="";

    return res;
}


string Template::postTranslate() const
{
    return "}\n";
}
