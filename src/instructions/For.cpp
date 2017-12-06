//@author : GINISTY Valentin
#include "For.h"

#include <sstream>

using namespace std;

For::For(const string & iterator, const Expression* start, const Expression* end,
        const Expression* step, Node * left, const string & type):
    Node(left, nullptr), mIteratorName(iterator), mIndStart(start), mIndEnd(end), mStep(step),
	mType(type), mContainerName("")
{}

For::For (Node * left, const string & iterator, const string & container):
    Node(left, nullptr), mIteratorName(iterator), mIndStart(nullptr), mIndEnd(nullptr),
	mStep(nullptr), mType(""), mContainerName(container)
{}

For::~For()
{	
    delete mIndStart;
    delete mIndEnd;
    delete mStep;
}

//forall i in 1..10 (step X)
string For::preTranslate() const
{
	ostringstream oss;
	const string& start= mIndStart->translate();
	const string& end= mIndEnd->translate();
	const string& step= mStep->translate();

	string res = "for (";
	if (mContainerName.empty()) {
		// Type definition
		if (!mType.empty()) oss << mType;
		else oss << "auto";

	    oss << " " << mIteratorName << " = " << start << "; " << mIteratorName << " <= " << end << "; "
            << mIteratorName << " += "<< step;
	}
	else {
		oss << "auto " << mIteratorName << " : " << mContainerName;
	}

    res+= oss.str() + ") {\n";
	return res;
}

string For::postTranslate() const
{
    return "}\n";
}

