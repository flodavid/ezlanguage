# EzLanguage


|  Travis Compilation  |      License      |   Code quality   |    Hit counter   |
| :----------------------------: | :---------------------------: | :----------------------------: | :----------------------------: |
[![Build Status](https://travis-ci.org/flodavid/ezlanguage.svg)](https://travis-ci.org/flodavid/ezlanguage) | [![GPLv3 License](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://github.com/flodavid/Urbanisme/blob/master/COPYING.txt) | [![Codacy Badge](https://api.codacy.com/project/badge/Grade/f623f84ff30f43a4b0c3a93f74ca5329)](https://www.codacy.com/app/flodavid/ezlanguage?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=flodavid/ezlanguage&amp;utm_campaign=Badge_Grade) | [![ghit.me](https://ghit.me/badge.svg?repo=flodavid/ezlanguage)](https://ghit.me/repo/flodavid/ezlanguage) |

Repository of a project for the EZ language compiler.
A simple compiler for EZ-Language 

## To compile the compiler

Compilation of the compiler for EZ language is done with `make`
A makefile is present at the root of the project to help with the process.

In order to :
* add options to the YACC compiler : use the variable *YACC_FLAGS*
* add options to the LEX compiler : use the variable *YACC_FLAGS*
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
