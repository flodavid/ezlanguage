//@author : Ismail ELFAQIR
#include "ArrayAccess.h"

using namespace std;

ArrayAccess::ArrayAccess(Node * left, Node * right, const string & arrayN, int ind):
	Node(left, right), mArrayName(arrayN), index(ind) 
{}

ArrayAccess::~ArrayAccess()
{}

const string &ArrayAccess::get_array() const {
	return mArrayName;
}

int ArrayAccess::get_index() const{
	return index;
}

void ArrayAccess::set_array(const string & a) {
	mArrayName=a;
}

void ArrayAccess::set_index(int i) {
	index=i;
}

string ArrayAccess::preTranslate() const {
	string result= mArrayName+"["+to_string(index)+"]";
	return result;
}

