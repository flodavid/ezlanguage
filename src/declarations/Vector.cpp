#include "Vector.h"

using namespace std;

Vector::Vector(const string & nameC, const string & typeE, Expression* size):
	Container(nameC, typeE, size)
{ }

Vector::Vector(const string & nameC, Expression* listInit, const string & typeE):
	Container(nameC, listInit, typeE)
{ }

Vector::~Vector()
{ }
