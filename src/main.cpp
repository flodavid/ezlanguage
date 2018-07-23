#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "aide.h"
#include "./hash_table/ScopeHashTable.h"

#define GPP_EXE "g++-7"

using namespace std;

extern FILE* yyin;
extern int yyparse();
extern FILE* yyout;
extern bool existing_parsing_error;
extern int yydebug;

ScopeHashTable symbolTable = ScopeHashTable(100);

//FLAGS
int verbose_flag;
int directinput = 0;
int no_execution = 0;
int no_cpp = 0;
int help = 0;

//functions
//arguments qui ne sont pas prévus, donc des fichiers si la bonne extension, erreur sinon
/**
 * Arguments qui ne sont pas prévus, donc des fichiers si la bonne extension, erreur sinon
 * @brief parse_argv_ext
 * @param ext_ez  chaine de caractères de la ligne de commandes
 * @param fic_ezl vector contenant l'emplacement des fichiers sources EZ
 * @param fic_cmp
 */
void parse_argv_ext(const char* ext_ez, vector<char*> &fic_ezl, char * fic_cmp){
    bool bonne_extension = true;
    for(unsigned int j = 0; j < strlen(ext_ez) && bonne_extension; ++j){
        //si l'extension est mauvaise
        if(ext_ez[j] != fic_cmp[strlen(fic_cmp)-strlen(ext_ez)+j]){
            bonne_extension = false;
            //cout << "mauvaise ext" << endl;
        }
        //si l'extension est bonne
        if(j == strlen(ext_ez)-1){
            //on garde le fichier sous le coude
            fic_ezl.push_back(fic_cmp);
            //cout << "bonne ext" << endl;
        }
	}
}

/**
 * Vérifie si le fichier en paramètre existe sur le disque et peut être ouvert
 * @brief file_test_exists
 * @param filename chemin du fichier à tester
 * @return vrai si le fichier existe et est lisible
 */
bool file_test_exists(string filename){
    ifstream stream(filename, ifstream::in);
    bool exists = stream.is_open();
    stream.close();
    return exists;
}

vector<pair<char*,string>>* orderFilesCompilation(vector<char*> ezlFiles, string & programName)
{
    vector<pair<char*,string>>* compiled_files = new vector<pair<char*,string>>;
    char* main_input;
    string main_output = "";
    for(char* filename : ezlFiles) {
        debug("File to compile: "+ string(filename),AT);
        ifstream infile(filename);
        string first_line;
        if (infile.good()) getline(infile, first_line);
        infile.close();

        // Output cpp filename defined by the name of the program        
        string output_file = first_line.substr(first_line.find_last_of(" ")+1);
        
        if (first_line[0] == 'p') {
            if (main_output == "") {
                cout << "Main: "<< output_file << endl;
                main_input = filename;
                main_output = output_file +".cpp";
                // If program name is not set, set a default value
                if (programName == "") programName= output_file +".run";
            } else {
                cerr << "You cannot compile two programs together, you must execute"
                " a disctinct compilation for each one";
                exit(EXIT_FAILURE);
            }
        } else {
            cout << "Module: "<< output_file << endl;
            compiled_files->push_back(make_pair(filename,output_file +".hpp"));
        }
    }
    if (main_output != "") {
        compiled_files->push_back(make_pair(main_input,main_output));
    } else {
        cerr << "Not any of the given files is a 'program' file";
        exit(EXIT_FAILURE);
    }
    return compiled_files;
}

/**
 * Parse EZ files from input to cpp files and add them as output file
 * @brief parse_to_cpp
 * @param fic_ezl: EZ files to be parsed
 * @param input_files: output
 */
bool parse_to_cpp(const vector<char*> & fic_ezl, string &outputFiles, string & exeName)
{
    vector<pair<char*,string>>& compiled_files = *orderFilesCompilation(fic_ezl, exeName);

    for(pair<char*,string> output_file : compiled_files) {
        cout << "\033[1;36mFile parsing : \033[1;37m" << output_file.first << endl;
        cout << "\033[1;36m=====================================\033[0m" << endl;
        yyin = fopen(output_file.first, "r");

        if(!yyin){
            cerr << output_file.first << ": file opening failed." << endl;
        } else {
            // Translation and Cpp files creation
            FILE * cpp_file = fopen(output_file.second.c_str(), "w");

            // if file creation fails
            if(cpp_file == NULL) {
                cerr << output_file.second << ": creation failed;" << endl;
                return false;
            }

            // parsing du fichiers ez en fichier cpp
            yyout = cpp_file;
            yyparse();

            // fermerture du fichier cpp
            fclose(cpp_file);
            outputFiles+= output_file.second + " ";

            cout << "\033[1;36m ====== Parsing of *"+ output_file.second +"* ended. ======\033[0m" << endl;
            cout << endl;
        }
    }
    delete &compiled_files;
    return true;
}

void display(vector<char*> fic_ezl){
    for(unsigned int i = 0; i < fic_ezl.size(); i++){
        cout << fic_ezl[i] << endl;
    }
}

/**
 * Compile les fichiers cpp générés
 * @brief Run the generated program
 * @param gppCommand commande gpp execute
 * @param outputName nom de l'output
 */
int exec_cpp(std::string & gppCommand, std::string & outputName, const std::string & args){
    //cout << "commande cpp: " << gppCommand << endl;
    gppCommand+= " -o "+ outputName;
    int system_return= EXIT_SUCCESS;
    if(help != 1){
        if(directinput != 1){
            cout << gppCommand << endl;
            system_return= system(gppCommand.c_str());
            if (system_return != 0) {
                cerr << "Return of system command * " << gppCommand.c_str()  <<"* : " << system_return<< endl;
            }
            
            // Compilation success is independant of execution success
            if(no_execution != 1){
                string tmp_output= "./"+ outputName;
                system((tmp_output +" "+ args).c_str());
            }
        }
        cout << "\033[1;36mCompilation ended.\033[0m" << endl;
    }
    return system_return;
}

/**
 * Point d'entrée
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char ** argv) {
    bool no_options = true;
    string output_name = "";
    string exec_args= "";

    // Ligne de commande g++
    string gpp_command = GPP_EXE " -std=c++11";

    // vecteurs des fichiers EZ à traiter
    vector<char*> fic_ezl;

    //boucle pour les arguments en ligne de commande programmés
    while(1){
        //options
        static struct option long_options[] = {
            // flags
            {"verbose",			no_argument,	&verbose_flag, 	1},
            {"brief",			no_argument,	&verbose_flag, 	0},
            {"noexec",			no_argument,	&no_execution, 	1},
            {"nocpp",			no_argument,	&no_cpp, 	1},
            {"directinput",		no_argument,	&directinput,	1},
            
            //autres
            {"help",			no_argument,		0, 	'h'},
            {"optimisation",	required_argument,	0, 	'O'},
            {"warning",			no_argument,		0, 	'w'},
            {"output",			required_argument,	0, 	'o'},
            {"args",			required_argument,	0, 	'a'},
            {0, 0, 0, 0}
        };
        
        //getopt_long recupere l'option ici
        int option_index = 0;
        
        int opt = getopt_long(argc, argv, "ho:f:O:w:v", long_options, &option_index);
        
        //fin des options
        if(opt == -1){
            break;
        }
        
        //options en cours
        switch(opt){
            //flags
            case 0:
                no_options = false;
                // flag indiquant que l' exécutable ne doit pas être lancé après la compilation
                if (string(long_options[option_index].name) == "noexec"){
                    clog << "Not launching .exe file after compiling..." << endl;
                }
                if(string(long_options[option_index].name) == "directinput"){
                    no_execution = 1;
                    cout << "\033[1;36m Manual parsing begining : \033[1;37m" << endl;
                    cout << "\033[1;36m=====================================\033[0m" << endl;
                    yyparse();
                    cout << "\033[1;36m=====================================\033[0m" << endl;
                }
                break;

            // Compiler options computing
            // Affiche l'aide
            case 'h':
                no_options = false;
                help = 1;
                // teste l'existence du fichier d'aide
                cout << AIDE_PROG << endl;
                break;
            // Ajoute le fichier de sortie au compilateur g++
            case 'o':
                no_options = false;
                //cout << "Indicates the name of the output file" << endl;
                output_name = string(optarg);
                break;
            case 'v':
                no_options = false;
                verbose_flag = 1;
                yydebug = 1;
                break;
            case 'w':
                cout << "Warning messages will be displayed" << endl;
                no_options = false;
                gpp_command += " -Wall";
                break;
            // Ajoute l'option -o(1..3) au compilateur g++
            case 'O':
                no_options = false;
                //cout << "Optimization option level: " << optarg << endl;
                if(atoi(optarg) >= 1 && atoi(optarg) <= 3){
                    gpp_command += " -O"+string(optarg); 
                }
                break;
            // Défini les arguments passés au programme lors de l'exécution
            case 'a':
                no_options = false;
                exec_args = string(optarg);
                break;
            // Option inconnue, s'il y a une option avec un tiret ou deux, c'est forcement autre chose qu'un fichier donc erreur
            case '?':
                //exit(EXIT_FAILURE);
                break;
            //defaut
            default:
                //exit(EXIT_FAILURE);
                break;
        }
    }

    // tableaux des extensions des fichiers a traiter
    int nb_ext = 2;
    const string ext_ez[] = {".ez", ".ezl"};

    //ajout des fichiers a parser
    for(int i = 0; i < nb_ext; ++i){
        for(int j = optind; j < argc; ++j){
            parse_argv_ext(ext_ez[i].c_str(), fic_ezl, argv[j]);
            //cout << "ajout" << fic_ezl.size() << endl;
        }
    }
    
    //test des arguments restant
    for(int i=optind+1; i<argc; ++i){
        //cout<< "Parsing the "<< i<< " file : "<< argv[i]<< endl;
        if(!(find(fic_ezl.begin(), fic_ezl.end(), argv[i]) != fic_ezl.end())){
            cerr << "Invalid file or unknown option : " << argv[i] << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Parses all EZ files into CPP files and add them to input files, to compile them
    if(!directinput) {
        string input_files = "";
        // If parsing from EZ to CPP fails, we stop the program
       if (!parse_to_cpp(fic_ezl, input_files, output_name) || existing_parsing_error) {
            cerr<< "Error encountered during compilation, correct them, then re-run";
            exit(EXIT_FAILURE);
        }

        gpp_command += " " + input_files;
    }

    // cpp files compilation
    if(no_options && fic_ezl.size() == 0){
        cout << "Usage : EZ_language_compiler [OPTION]... FILE [FILES]..." << endl;
        cout << "Try « EZ_language_compiler --help » for more information." << endl;
        cout << endl;
    }
    if(fic_ezl.size() != 0) {
        // If we did not encountered any error(s) at this point, success depends on final
        // compilation

        int return_code= exec_cpp(gpp_command, output_name, exec_args);
        if (return_code != 0) {
            cerr << "\nParsing to C++ succeeded, but compilation failed. Report the problem."
            "\nHINT: Maybe you used undeclared variable of function, or do not have the correct"
            " version of g++ installed, the one expected is : '" GPP_EXE "'"<< endl;
            #if DEBUG
            cerr << "The g++ version is set by a pre-processor definition of 'GPP_EXE' into"
            " main.cpp, you may want to change it to correct the problem" << endl;
            #endif
            return EXIT_FAILURE;
        }
        else return return_code;
    } else return EXIT_FAILURE;
    
}
