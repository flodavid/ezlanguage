#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "aide.h"
#include "./hash_table/ScopeHashTable.h"

using namespace std;

extern FILE* yyin;
extern int yyparse();
extern FILE* yyout;
extern bool existing_parsing_error;

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
void parse_to_cpp(vector<char*> fic_ezl, string &input_files){
	if(!directinput){
		for(unsigned int i=0; i<fic_ezl.size(); ++i){
		    cout << "\033[1;36mFile parsing : \033[1;37m" << fic_ezl[i] << endl;
		    cout << "\033[1;36m=====================================\033[0m" << endl;
		    yyin = fopen(fic_ezl[i], "r");

	        if(!yyin){
	            cerr <<  fic_ezl[i] << ": file opening failed." << endl;
	        }else{
	            // creation des fichiers cpp
	            string fichier_tmp = string(fic_ezl[i]);

                fichier_tmp = fichier_tmp.substr(fichier_tmp.find_last_of("/")+1, fichier_tmp.find_last_of(".") - fichier_tmp.find_last_of("/"));
                fichier_tmp +="cpp";
                FILE * cpp_file = fopen(fichier_tmp.c_str(), "w");

		    	// cas où la création du fichier échoue
	            if(cpp_file == NULL) {
	                cerr << fichier_tmp << ": creation failed;" << endl;
	                break;
	            }

                // parsing du fichiers ez en fichier cpp
                yyout = cpp_file;
                yyparse();

                // fermerture du fichier cpp
                fclose(cpp_file);
                input_files+=fichier_tmp + " ";

                cout << "\033[1;36m=====================================\033[0m" << endl;
                cout << endl;
            }
        }
    }
}

void display(vector<char*> fic_ezl){
	for(unsigned int i = 0; i < fic_ezl.size(); i++){
		cout << fic_ezl[i] << endl;
	}
}

/**
 * Compiles les fichiers cpp générer
 * @brief exec_cpp
 * @param commande_gpp commande gpp execute
 * @param output_name nom de l'output
 */
void exec_cpp(std::string commande_gpp, std::string output_name){
	//cout << "commande cpp: " << commande_gpp << endl;
	if(help != 1){
		if(directinput != 1){
			cout << commande_gpp << endl;
			system(commande_gpp.c_str());
			if(no_execution != 1){
				if(output_name != ""){
					string tmp_output= "./" + output_name;
					system(tmp_output.c_str());
				}else{
					string tmp_output= "./a.out";
					system(tmp_output.c_str());
				}
			}
		}
		cout << "\033[1;36mParsing ended.\033[0m" << endl;
	}
}

/**
 * Point d'entrée
 * @param argc
 * @param argv
 * @return
 */
int main(int argc , char ** argv){
	int no_options = 0;
    int opt;
    string output_name = "";

    // Ligne de commande g++
    string commande_gpp = "g++ ";

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
			{"nocpp",			no_argument,	&no_cpp, 		1},
			{"directinput",		no_argument,	&directinput,	1},
			
			//autres
			{"help",			no_argument,		0, 	'h'},
			{"optimisation",	required_argument,	0, 	'O'},
			{"warning",			no_argument,		0, 	'w'},
			{"output",			required_argument,	0, 	'o'},
			{0, 0, 0, 0}
		};
		
		//getopt_long recupere l'option ici
		int option_index = 0;
		
		opt = getopt_long(argc, argv, "ho:f:O:w:v", long_options, &option_index);
		
		//fin des options
		if(opt == -1){
			break;
		}
		
		//options en cours
		switch(opt){
			//flags
			case 0:
				no_options = 1;
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
				no_options = 1;
				help = 1;
				// teste l'existence du fichier d'aide
				cout << AIDE_PROG << endl;
				break;

			// Ajoute le fichier de sortie au compilateur g++
			case 'o':
				no_options = 1;
				//cout << "Indicates the name of the output file" << endl;
				commande_gpp += "-o "+string(optarg)+" ";
				output_name = string(optarg);
				break;
			case 'v':
				no_options = 1;
				verbose_flag = 1;
				break;
			case 'w':
				//cout << "Displays warning messages" << endl;
				no_options = 1;
				commande_gpp += "-Wall ";
				break;

			// Ajoute l'option -o(1..3) au compilateur g++
			case 'O':
				no_options = 1;
				//cout << "Optimization option level: " << optarg << endl;
				if(atoi(optarg) >= 1 && atoi(optarg) <= 3){
					commande_gpp += "-O"+string(optarg)+" "; 
				}
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

	string input_files = "";

	// Parse tous les fichiers ez contenus dans fic_ez en fichier cpp et les ajoute dans input_files 
	parse_to_cpp(fic_ezl, input_files);

	commande_gpp += " " + input_files;

	//execution des cpp
	if(no_options == 0 && fic_ezl.size() == 0){
				cout << "Usage : EZ_language_compiler [OPTION]... FILE [FILES]..." << endl;
				cout << "Try « EZ_language_compiler --help » for more information." << endl;
				cout << endl;
	}
	if(fic_ezl.size() != 0)	exec_cpp(commande_gpp, output_name);

	if (existing_parsing_error == true) {
        cerr<< "Error encountered during compilation, correct them, then re-run";
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
