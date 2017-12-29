#include "ArrayAccess.h"

using namespace std;

ArrayAccess::ArrayAccess(const string & arrayN, int ind):
	Expression(), mArrayName(arrayN), mIndex(ind), mExpression(nullptr)
{}

ArrayAccess::ArrayAccess(const string & arrayN, Expression * expression):
	Expression(), mArrayName(arrayN), mIndex(0), mExpression(expression)
{}

ArrayAccess::~ArrayAccess()
{
	delete mExpression;
}


const string &ArrayAccess::get_array() const {
	return mArrayName;
}

int ArrayAccess::get_index() const{
	return mIndex;
}

void ArrayAccess::set_array(const string & a) {
	mArrayName=a;
}

void ArrayAccess::set_index(int i) {
	mIndex=i;
}

string ArrayAccess::preTranslate() const {
	string res= mArrayName +"[";

	if (nullptr != mExpression) {
		res+= mExpression->translate();
	} else {
		res+= to_string(mIndex);
	}

	res+= "]";

	return res;
}

