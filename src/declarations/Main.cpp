#include "Main.h"

// #include <string>
#include <algorithm>

using namespace std;

Main::Main(CommonVar * parameters, Node * prgm_intructions):
    Function("main", new Parameter("argc", "int"), prgm_intructions, "int"),
    mMainOpts(parameters)
{
    mParameters->addRightChild(new Parameter("argv", "char **"));
}

std::string Main::preTranslate() const {
    std::string res = "";
    
    res+= Function::preTranslate();
    string prgm_parameters= mMainOpts->translate();
    
    size_t pos = prgm_parameters.find(", ");
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        prgm_parameters.replace(pos, 2, ";\n");
        // Get the next occurrence from the current position
        pos =prgm_parameters.find(", ", pos + 2);
    }
    
    res+= prgm_parameters+"\n";
    // res= "int main(int argc, char ** argv) {\n";

    return res;
}

string Main::postTranslate() const
{
    return "}\n";
}
