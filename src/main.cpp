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

/**
 * Parse tous les fichiers ez contenus dans fic_ez en fichier cpp et les ajoute dans input_files 
 * @brief parse_to_cpp
 * @param fic_ezl
 * @param input_files
 */
bool parse_to_cpp(vector<char*> fic_ezl, string &input_files){
    for(unsigned int i=0; i<fic_ezl.size(); ++i) {
        cout << "\033[1;36mFile parsing : \033[1;37m" << fic_ezl[i] << endl;
        cout << "\033[1;36m=====================================\033[0m" << endl;
        yyin = fopen(fic_ezl[i], "r");

        if(!yyin){
            cerr <<  fic_ezl[i] << ": file opening failed." << endl;
        } else {
            // creation des fichiers cpp
            string tmp_file = string(fic_ezl[i]);

            tmp_file = tmp_file.substr(tmp_file.find_last_of("/")+1, tmp_file.find_last_of(".") - tmp_file.find_last_of("/"));
            tmp_file +="cpp";
            FILE * cpp_file = fopen(tmp_file.c_str(), "w");

            // cas où la création du fichier échoue
            if(cpp_file == NULL) {
                cerr << tmp_file << ": creation failed;" << endl;
                return false;
            }

            // parsing du fichiers ez en fichier cpp
            yyout = cpp_file;
            yyparse();

            // fermerture du fichier cpp
            fclose(cpp_file);
            input_files+= tmp_file + " ";

            cout << "\033[1;36m ====== Parsing of *"+ tmp_file +"* ended. ======\033[0m" << endl;
            cout << endl;
        }
    }
    return true;
}

void display(vector<char*> fic_ezl){
    for(unsigned int i = 0; i < fic_ezl.size(); i++){
        cout << fic_ezl[i] << endl;
    }
}

/**
 * Compile les fichiers cpp générés
 * @brief exec_cpp
 * @param gpp_command commande gpp execute
 * @param output_name nom de l'output
 */
int exec_cpp(std::string & gpp_command, std::string & output_name, const std::string & args){
    //cout << "commande cpp: " << gpp_command << endl;
    int system_return= EXIT_SUCCESS;
    if(help != 1){
        if(directinput != 1){
            cout << gpp_command << endl;
            system_return= system(gpp_command.c_str());
            if (system_return != 0) {
                cerr << "Return of system command * " << gpp_command.c_str()  <<"* : " << system_return<< endl;
            }
            
            // Compilation success is independant of execution success
            if(no_execution != 1){
                string tmp_output= "./";
                if(output_name != ""){
                    tmp_output+= output_name;
                } else {
                    tmp_output+= "a.run";
                }
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
            {"directinput",			no_argument,	&directinput,	1},
            
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
                gpp_command += " -o "+ string(optarg);
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
    const string ext_ez[nb_ext] = {".ez", ".ezl"};

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
       if (!parse_to_cpp(fic_ezl, input_files) || existing_parsing_error) {
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
