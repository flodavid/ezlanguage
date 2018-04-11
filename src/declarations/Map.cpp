#include "Map.h"

using namespace std;

Map::Map(const string & nameC, const string & typeFirstE, const string & typeSecondE,
		Expression* size, bool isParameter):
	Container(nameC, typeSecondE, size, isParameter), mKeyType(typeFirstE)
{ }

Map::Map(const string & nameC, Expression* list, const string & typeE):
	Container(nameC, list, typeE)
{ }

Map::~Map()
{ }

string Map::translateType() const
{
    return "std::"+ getContainerType() +"<"+ translatePrimitiveType(mKeyType) +", "+ CommonVar::translateType() + ">";
}
