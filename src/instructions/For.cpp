//@author : GINISTY Valentin
#include "For.h"

#include <sstream>

using namespace std;

For::For(const string & iterator, Expression* start, Expression* end,
        Expression* step, Node * instructions, const string & type):
    Instruction(instructions), mIterator(new Variable(false, iterator, type, start)),
	mIndEnd(end), mStep(step), mContainerName("")
{}

For::For (Node * instructions, const string & iterator, const string & container):
    Instruction(instructions), mIterator(new Variable(false, iterator, "auto")),
	mIndEnd(nullptr), mStep(nullptr), mContainerName(container)
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

	string res = getIndentation() +"for (";

	// Using variable iteration
	if (mContainerName.empty()) {
	    oss << " " << mIterator->translate() << ' ' << mIterator->getVariableName() << " <= " << end << "; "
            << mIterator->getVariableName() << " += "<< step;
	}
	// Container "foreach"
	else {
		oss << mIterator->translate() << " : " << mContainerName;
	}

    res+= oss.str() + ") {\n";
	// Increment indentation of all instructions
	Instruction::indent();
	
	return res;
}

string For::postTranslate() const
{
	// Decrement indentation of all instructions
	Instruction::unindent();

    return "}\n";
}

