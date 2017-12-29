#include "Set.h"

using namespace std;

Set::Set(const string & nameC, const string & typeE, Expression* size):
	Container(nameC, typeE, size)
{ }

Set::Set(const string & nameC, Expression* listInit, const string & typeE):
	Container(nameC, listInit, typeE)
{ }

Set::~Set()
{ }
