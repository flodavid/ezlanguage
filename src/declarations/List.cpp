#include "List.h"

using namespace std;

List::List(const string & nameC, const string & typeE, Expression* size):
	Container(nameC, typeE, size)
{ }

List::List(const string & nameC, Expression* list, const string & typeE):
	Container(nameC, list, typeE)
{ }

List::~List()
{ }
