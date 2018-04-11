#include "Set.h"

using namespace std;

Set::Set(const string & nameC, const string & typeE, Expression* size, bool isParameter):
	Container(nameC, typeE, size, isParameter)
{ }

Set::Set(const string & nameC, Expression* listInit, const string & typeE):
	Container(nameC, listInit, typeE)
{ }

Set::~Set()
{ }
