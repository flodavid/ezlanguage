# EzLanguage

[![Build Status](https://travis-ci.org/ezlanguage/ezlanguage.svg?branch=compilateur)](https://travis-ci.org/ezlanguage/ezlanguage)

Repository of a project for the EZ language compiler.
A simple compiler for EZ-Language 

## To compile the compiler

Compilation of the compiler for EZ language is done with `make`
A makefile is present at the root of the project to help with the process.

In order to :
* add options to the YACC compiler : use the variable *YACC_FLAGS*
* add options to the LEXX compiler : use the variable *YACC_FLAGS*
* add options for compilation : use the variable *YACC_FLAGS*
* add files for the compilation of the compiler : use the variable *YACC_FLAGS*

To obtain some help and see all avaibles options, use : `make help`

### Compiler usage at first sight

Once compiled, the compiler can be run easly.  
To do so, you need to run the file *EZ_language\_compiler* located in the *bin* directory.
Some EZLanguage files examples are available in the *test* folder.

In order to :
* get some help : `EZ_language_compiler --help`
* compile an EZLanguage file : `EZ_language_compiler myfile.ezl`
* test a file : `EZ_language_compiler --directinput`

Do not hesitate to create git *Issues* at the github website if you encounter an inopinate problem. 
	  
