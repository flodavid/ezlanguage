#include "List.h"

using namespace std;

List::List(const string & nameC, const string & typeE, Expression* size, bool isParameter):
	Container(nameC, typeE, size, isParameter)
{ }

List::List(const string & nameC, Expression* list, const string & typeE):
	Container(nameC, list, typeE)
{ }

List::~List()
{ }
