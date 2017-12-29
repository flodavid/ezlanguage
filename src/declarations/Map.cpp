#include "Map.h"

using namespace std;

Map::Map(const string & nameC, const string & typeFirstE, const string & typeSecondE,
		Expression* size):
	Container(nameC, typeFirstE +", "+ typeSecondE, size)
{ }

Map::Map(const string & nameC, Expression* list, const string & typeE):
	Container(nameC, list, typeE)
{ }

Map::~Map()
{ }
