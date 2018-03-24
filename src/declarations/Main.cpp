#include "Main.h"

using namespace std;

Main::Main(Node * parameters, Node * left):
	Procedure("main", parameters, left)
{}

std::string Main::preTranslate() const {
    std::string res = "";
	
	res= "int main(int argc, char ** argv) {\n";

    return res;
}

string Main::postTranslate() const
{
    return "}\n";
}
