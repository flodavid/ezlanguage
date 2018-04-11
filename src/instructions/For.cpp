//@author : GINISTY Valentin
#include "For.h"

#include <sstream>

using namespace std;

For::For(const string & iterator, Expression* start, const Expression* end,
        const Expression* step, Node * instructions, const string & type):
    Node(instructions, nullptr), mIterator(new Variable(iterator, type, start)), mIndEnd(end), mStep(step),
	mContainerName("")
{}

For::For (Node * instructions, const string & iterator, const string & container):
    Node(instructions, nullptr), mIterator(new Variable(iterator, "auto")), mIndEnd(nullptr),
	mStep(nullptr), mContainerName(container)
{}

For::~For()
{	
    delete mIterator;
    delete mIndEnd;
    delete mStep;
}

//forall i in 1..10 (step X)
string For::preTranslate() const
{
	ostringstream oss;
	const string& end= mIndEnd->translate();
	const string& step= mStep->translate();

	string res = "for (";
	if (mContainerName.empty()) {
	    oss << " " << mIterator->translate() << mIterator->getVariableName() << " <= " << end << "; "
            << mIterator->getVariableName() << " += "<< step;
	}
	else {
		oss << mIterator->translate() << " : " << mContainerName;
	}

    res+= oss.str() + ") {\n";
	return res;
}

string For::postTranslate() const
{
    return "}\n";
}

