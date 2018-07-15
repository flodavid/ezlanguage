#include "Import.h"

using namespace std;

Import::Import(const std::string & importName, ImportType importType):
    Node(nullptr, nullptr), mHeaderName(importName), mImportType(importType)
{ }

Import::~Import()
{

}


string Import::preTranslate() const
{
    string res="#include ";
    
    mImportType == EXTERNAL_LIBRARY ? res+= "<" : res+= "\"";
    res+= mHeaderName;
    mImportType == EXTERNAL_LIBRARY ? res+= ">" : res+= ".h\"";
    res+= "\n";

    return res;
}
