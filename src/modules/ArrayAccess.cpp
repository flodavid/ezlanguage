//@author : Ismail ELFAQIR
#include "ArrayAccess.h"

using namespace std;

ArrayAccess::ArrayAccess(Node * left, Node * right, const string & arrayN, int ind): Node(left, right), arrayName(arrayN), index(ind) 
{}

ArrayAccess::~ArrayAccess()
{}

string ArrayAccess::get_array() const{
	return arrayName;
}

int ArrayAccess::get_index() const{
	return index;
}

void ArrayAccess::set_array(const string & a) {
	arrayName=a;
}

void ArrayAccess::set_index(int i) {
	index=i;
}

string ArrayAccess::preTranslate() const {
	string result= arrayName+"["+to_string(index)+"]";
	return result;
}

