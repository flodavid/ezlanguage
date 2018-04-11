#include "Vector.h"

using namespace std;

Vector::Vector(const string & nameC, const string & typeE, Expression* size, bool isParameter):
	Container(nameC, typeE, size, isParameter)
{ }

Vector::Vector(const string & nameC, Expression* listInit, const string & typeE):
	Container(nameC, listInit, typeE)
{ }

Vector::~Vector()
{ }
