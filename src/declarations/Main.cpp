#include "Main.h"

#include <string>
#include <algorithm>

using namespace std;

Main::Main(CommonVar * parameters, Instruction * prgm_intructions):
    Function("main", new Parameter("argc", "int"), prgm_intructions, "integer"),
    mMainOpts(parameters)
{
    addParameters(new Parameter("argv", "char **"));
}

Main::~Main()
{
    if (mMainOpts) delete mMainOpts;
}


unsigned Main::argumentsNumber() const
{
    const Node* currentParam= mMainOpts;
    unsigned arg_number= 0;
    while (currentParam) {
        ++arg_number;
        currentParam= currentParam->right_son;
    }
    return arg_number;
}

string Main::createParsingParameterCode(string * input_arguments_summary) const
{
    // Create each element
    if (mMainOpts != nullptr) {

        // Create program parameters
        string prgm_parameters= indentationText() + mMainOpts->translate();
        string opts_flags= "";
        // Initialize arguments_summary function
        string arguments_summary_decl= "void arguments_summary("+ prgm_parameters;
        string arguments_summary= "{\n";
        // Initialize opts_parsing
        string opts_parsing= 
            "    static struct option long_options[] = {\n"
            "        // flags\n";
        string &arguments_intro= *input_arguments_summary;
        // Initialize call_arguments_summary
        string call_arguments_summary= "    arguments_summary(";
        string call_arguments_summary_flags= "";
        string check_all_initialized= "    if (";

        // Add parameters parsing
        arguments_intro+= "#include <getopt.h>\n"
        "\n";

        // Replace commas by semicolons in program parameters
        size_t pos = prgm_parameters.find(", ");
        while( pos != std::string::npos)
        {
            // Replace this occurrence of Sub String
            prgm_parameters.replace(pos, 2, ";\n");
            // Get the next occurrence from the current position
            pos= prgm_parameters.find(", ", pos + 2);
        }
        prgm_parameters+= ";"; // Add final semicolon

        // Browse all parameters to create arguments_summary and opts_parsing
        const CommonVar* opt= mMainOpts;
        
        string switch_opts_parsing= "";
        string opts_short_names= "";
        int nb_to_initialize= 0; // Number of parameters that are mandatory
        int ind=0;
        
        // Handle each argument (opt)
        do {
            ++ind;
            string opt_name= opt->getDeclarationName();
            const string & opt_type= opt->translateType();
            bool hasDefault= opt->getAffectation() != nullptr;

            arguments_summary_decl+= ", bool "+ opt_name+ "_flag";
            arguments_summary+=
            "    std::cout << \""+ opt_name +" = \";\n"
            "    if("+ opt_name +"_flag) std::cout <<"+ opt_name + ";\n"
            "    std::cout << std::endl;\n";

            // Define parameters which we must check they have been initialized, with flags
            if (!hasDefault) {
                if (nb_to_initialize > 0) check_all_initialized+= " || ";
                opts_flags+= "    bool "+ opt_name +"_flag= false;\n";
                check_all_initialized+= "!"+ opt_name +"_flag";
                ++nb_to_initialize;
            }

            opts_parsing+=
            "        {\""+ opt_name +"\",\trequired_argument, 0, "+ to_string(ind) +"}";

            call_arguments_summary+= opt_name;
            call_arguments_summary_flags+= ", "+ opt_name +"_flag";
            

            // Add the short name for all options in a string
            opts_short_names+= to_string(ind);

            // Switch in loop parsing of options
            switch_opts_parsing+=
            "           case "+ to_string(ind) +":\n";

            if (opt_type == "int") {
                switch_opts_parsing+=
                "                "+ opt_name +"= atoi(optarg);\n";
            }
            else if (opt_type == "std::string") {
                switch_opts_parsing+=
                "                "+ opt_name +"= std::string(optarg);\n";
            }

            if (!hasDefault) switch_opts_parsing+= "            "+ opt_name +"_flag= true;\n";
            
            switch_opts_parsing+= //"optarg);\n"
            "                std::clog << \""+ opt_name +" initialized: \" << "+ opt_name +" << std::endl;\n"
            "                break;\n";

            // Loop incrementation
            //  Get next element and try to convert it to CommonVar for next parameter
            opt= dynamic_cast<CommonVar*>(opt->right_son);
            
            // Add commas where needed
            if (opt != nullptr) {
                opts_parsing+= ", ";
                call_arguments_summary+= ", ";
            }

            opts_parsing+= "\n";

        } while (opt != nullptr);

        // Finalize program parameters
        prgm_parameters+= "\n";

        // Finalize arguments_summary function
        arguments_summary+= "    std::cout << std::endl;\n}\n\n";
        arguments_intro+= arguments_summary_decl +")"+ arguments_summary;

        if (nb_to_initialize > 0) {
            check_all_initialized= "\n"+ check_all_initialized +") {\n"
            "        std::cerr << \"Not all "+ to_string(argumentsNumber()) +" parameters have been initialized\" << std::endl;\n"
            "        std::cerr << \"Initialize them with the '--<ARG_NAME>=<VALUE>' syntax\" << std::endl;\n"
            "        return EXIT_FAILURE;\n"
            "    }\n\n";
        }
        else check_all_initialized= "";

        // Finalize opts_parsing
        opts_parsing+= "    };\n\n"
        "    int option_index = 0;\n"
        "    int opt;\n"
        "    do {\n"
        "        opt= getopt_long_only(argc, argv, \""+ opts_short_names +"\", long_options, &option_index);\n"
        "        switch(opt){\n"
        "            //flags\n"
        "           case -1:\n"
        "                std::clog << \"<<Parameters parsing end>>\" << std::endl<< std::endl;\n"
        "                break;\n"
        "           case 0:\n"
        "                std::cerr << \"Options must have a corresponding value\"<< std::endl;\n"
        "                break;\n"
        + switch_opts_parsing +
        "           default:\n"
        "                std::cerr << \"Wrong option\"<< std::endl;\n"
        "                return EXIT_FAILURE;\n"
        "                break;\n"
        "        }\n"
        "    } while (opt != -1);\n";

        // Finalize call_arguments_summary
        call_arguments_summary+= call_arguments_summary_flags +");\n";

        return prgm_parameters + opts_flags +"\n"+ opts_parsing + call_arguments_summary + check_all_initialized;
    }
    else return "";
}

string Main::preTranslate() const {
    string res = "";
    string arguments_intro= "";
        
    // Put translated elements into translation result variable
    res+= Function::preTranslate();
    res+= createParsingParameterCode(&arguments_intro);

    res= arguments_intro + res;
    return res;
}

string Main::postTranslate() const
{
    return Function::postTranslate();
}
