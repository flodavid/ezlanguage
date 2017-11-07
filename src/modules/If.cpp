//@author : Ismail ELFAQIR
#include "If.h"

using namespace std;



If::If(Node * left, Node * right, Node * condition, const string & bt): Node(left, right), cond(condition)
{
	if (bt == "elseif") block_type = 2;
	else if (bt == "else") block_type = 3;
	else block_type = 1;
}


If::If(Node * left, Node * right, const string & bt): Node(left, right)
{
	block_type = 3;
}

int If::get_block_type() const{
	return block_type;
}

void If::set_block_type(int bt){
	block_type = bt;
}


string If::preTranslate() const
{
    string res="", block;
    
    switch (block_type) {
	case block_if :
	    block="if(" + cond->translate() + ") ";
	    break;
	case block_else_if :
	    block= "else if(" + cond->translate() + ") ";
	    break;
	case block_else :
	    block= "else ";
	    break;	
    }
    
    res=block+"{";
    
    return res;
}


string If::postTranslate() const
{
    return "}";
}
