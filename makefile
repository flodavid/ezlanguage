# Compiler used
CC = g++-7
# Compilation flags
CC_FLAGS = -Wall -std=c++11 -ggdb
EXT_SRC = 
CC_MOD_FLAGS = -MM #-MP 

# Lex file extensions (.XXX)
LEX_EXT = lex
# Lex file interpreter : lexical analysis
LEX = flex
LEX_FlAGS =

# Yacc files extension (.XXX)
YACC_EXT = ypp
# interpréteur des fichiers Yacc : analyse syntaxique et sémantique
YACC = bison
YACC_FLAGS = -t --verbose


# cpp sources
# --- RAJOUTER CHAQUE FICHIER CPP DE MODULES ICI ! ---
# --- FAIRE UN FICHIER CPP POUR CHAQUE FICHIER H S'IL Y A UNE CLASSE DEDANS ---

# Core
MOD_CPP = Node.cpp Program.cpp TranslatedNode.cpp EmptyNode.cpp ConvertNode.cpp
# Conditional expression
MOD_CPP += Expression.cpp BooleanExpression.cpp BooleanValue.cpp ConditionalExpression.cpp
# Divers
MOD_CPP += ArrayAccess.cpp Operator.cpp FunctionCall.cpp FunctionCallExpression.cpp

# Instructions
INSTR_CPP = Instruction.cpp If.cpp Else.cpp
INSTR_CPP += For.cpp Repeat.cpp While.cpp
INSTR_CPP += Return.cpp FunctionCallInstruction.cpp Affectation.cpp Print.cpp CppCode.cpp

# Declarations
DEC_CPP = CommonDeclaration.cpp CommonVar.cpp
DEC_CPP += Container.cpp Variable.cpp Array.cpp Vector.cpp List.cpp Map.cpp Set.cpp
DEC_CPP += Parameter.cpp Import.cpp Method.cpp Function.cpp Procedure.cpp Class.cpp
DEC_CPP += Main.cpp

# Addons
ADDONS_CPP = String_addon.cpp log.cpp

# hash table sources
HT_CPP = HashElement.cpp HashTable.cpp ScopeHashTable.cpp ClassHashTable.cpp
# Hash elements corresponding to declarations
HT_CPP += ClassHashed.cpp FunctionHashed.cpp VariableHashed.cpp

ALL_CPP = ${MOD_CPP} ${DEC_CPP} ${INSTR_CPP} ${ADDONS_CPP} ${HT_CPP}

# Object files
MOD_OBJ = $(MOD_CPP:%.cpp=obj/%.o)
DEC_OBJ = $(DEC_CPP:%.cpp=obj/%.o)
INSTR_OBJ = $(INSTR_CPP:%.cpp=obj/%.o)
ADDONS_OBJ = $(ADDONS_CPP:%.cpp=obj/%.o)
HT_OBJ = $(HT_CPP:%.cpp=obj/%.o)

ALL_OBJ = ${MOD_OBJ} ${DEC_OBJ} ${INSTR_OBJ} ${ADDONS_OBJ} ${HT_OBJ}

# Dependency files
ALL_DPDCY = $(ALL_OBJ:%.o=%.d)

# Executables
# exe name, must have the same name as lex file
EXEC = EZ_language_compiler


#compiler
all: $(EXEC)

EZ_language_compiler: obj/lex.yy.c obj/EZ_language_compiler.tab.cpp obj/EZ_language_compiler.tab.hpp $(ALL_OBJ) 
	@echo -e "\033[1;33mCréation du compilateur en compilant les sources\033[0m"
	$(CC) -o bin/$@ obj/EZ_language_compiler.tab.cpp obj/lex.yy.c $(ALL_OBJ) -lfl $(CC_FLAGS)

obj/lex.yy.c: src/EZ_language_compiler.$(LEX_EXT) obj/EZ_language_compiler.tab.hpp
	@echo -e "\033[1;33mInterprétation du fichier Lex\033[0m"
	$(LEX) -o $@ $^ $(LEX_FLAGS)
	@echo ""

obj/EZ_language_compiler.tab.cpp obj/EZ_language_compiler.tab.hpp:  src/EZ_language_compiler.$(YACC_EXT)
	@echo -e "\033[1;33mInterprétation et compilation intermédiaire des fichiers Yacc\033[0m"
	$(YACC) $^ --defines=obj/EZ_language_compiler.tab.hpp --output=obj/EZ_language_compiler.tab.cpp $(YACC_FLAGS) 
	@echo ""


#dependencies
obj/%.d: src/declarations/%.cpp
	@echo -e "\033[1;33mDépendance pour le fichier $< créée : \033[0m"
	$(CC) $< -MT $@ -MT obj/$*.o -o $@ $(CC_MOD_FLAGS)
	@echo ""

obj/%.d: src/instructions/%.cpp
	@echo -e "\033[1;33mDépendance pour le fichier $< créée : \033[0m"
	$(CC) $< -MT $@ -MT obj/$*.o -o $@ $(CC_MOD_FLAGS)
	@echo ""

obj/%.d: src/modules/%.cpp
	@echo -e "\033[1;33mDépendance pour le fichier $< créée : \033[0m" 
	$(CC) $< -MT $@ -MT obj/$*.o -o $@ $(CC_MOD_FLAGS)
	@echo ""
	
obj/%.d: src/hash_table/%.cpp
	@echo -e "\033[1;33mDépendance pour le fichier $< créée : \033[0m" 
	$(CC) $< -MT $@ -MT obj/$*.o -o $@ $(CC_MOD_FLAGS)
	@echo ""
	
obj/%.d: src/addons/%.cpp
	@echo -e "\033[1;33mDépendance pour le fichier $< créée : \033[0m" 
	$(CC) $< -MT $@ -MT obj/$*.o -o $@ $(CC_MOD_FLAGS)
	@echo ""
	
#include ici  --- A NE PAS DEPLACER
-include $(ALL_DPDCY) 

#objects
obj/%.o: src/declarations/%.cpp
	@echo -e "\033[1;33mFichier objet pour le fichier $< créé : \033[0m"
	$(CC) -c $< -o $@ $(CC_FLAGS)
	@echo ""

obj/%.o: src/instructions/%.cpp
	@echo -e "\033[1;33mFichier objet pour le fichier $< créé : \033[0m"
	$(CC) -c $< -o $@ $(CC_FLAGS)
	@echo ""
	
obj/%.o: src/modules/%.cpp
	@echo -e "\033[1;33mFichier objet pour le fichier $< créé : \033[0m"
	$(CC) -c $< -o $@ $(CC_FLAGS)
	@echo ""
	
obj/%.o: src/hash_table/%.cpp
	@echo -e "\033[1;33mFichier objet pour le fichier $< créé : \033[0m"
	$(CC) -c $< -o $@ $(CC_FLAGS)
	@echo ""

obj/%.o: src/addons/%.cpp
	@echo -e "\033[1;33mFichier objet pour le fichier $< créé : \033[0m"
	$(CC) -c $< -o $@ $(CC_FLAGS)
	@echo ""

#clean  
clean:
	@echo -e "\033[1;33mSuppression des fichiers générés et des fichiers objets\033[0m"
	rm -rf obj/lex.yy.c
	rm -rf obj/*.tab.*
	rm -rf obj/*.d
	rm -rf obj/*.o
	rm -rf **.run
	rm -rf a.out
	
mrproper: clean
	@echo ""
	@echo -e "\033[1;33mSuppression de l'exécutable\033[0m"
	rm -rf bin/$(EXEC)
	rm -rf docs/html/*

launch: all
	@echo -e "\033[1;33mLancement du compilateur"
	@echo -e "\033[1;33m=============================="
	@echo ""
	@exec bin/$(EXEC) ""
	@echo -e "FIN\033[0m"
 	
basic_tests: all
	@echo -e "\n\033[1;33mExécution des tests ...\033[0m"
	bash tests/basic_tests.sh
 	
trace_tests: all
	@echo -e "\n\033[1;33mExécution des tests ...\033[0m"
	bash tests/basic_tests.sh -v
 	
# debug_tests: debug_yacc
# 	@echo -e "\n\033[1;33mExécution des tests en mode debug Yacc ...\033[0m"
# 	bash tests/basic_tests.sh
 	
full_tests: all
	@echo -e "\n\033[1;33mExécution des tests ...\033[0m"
	bash tests/full_tests.sh

debug: all
	valgrind bin/EZ_language_compiler tests/1_main_simple.ez -o 1_main_simple.run
 	
doc:
	doxygen Doxyfile
	@echo -e "\n\033[1;33mOuverture de la documentation ...\033[0m"
	@xdg-open  docs/html/index.html

#help
aide: help

help:
	@echo -e "\033[3mCompiler le projet : make\033[0m"	
	@echo -e "\033[3mNettoyer les fichier objets : clean\033[0m"	
	@echo -e "\033[3mNettoyer les fichier objets + executable : mrproper\033[0m"
	@echo -e "\033[3mGénérer la doc puis l'ouvrir : doc\033[0m"	
	@echo ""
	@echo -e "\033[3mVersions requises : g++ (5.4.0), lex (2.6.0), yacc (3.0.4)\033[0m"
	@echo "" 

