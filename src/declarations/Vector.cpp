#include "Vector.h"

using namespace std;

Vector::Vector(const string & nameC, const string & typeE, Expression* size):
	Container(nameC, typeE, size)
{ }

Vector::Vector(const string & nameC, Expression* list, const string & typeE):
	Container(nameC, list, typeE)
{ }

Vector::~Vector()
{ }
