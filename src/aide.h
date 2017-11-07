#ifndef AIDE_H
#define AIDE_H

std::string AIDE_PROG = "EZL \n\
	 \n\
SYNOPSIS \n\
	EZL [options] files.. \n\
	for the options list, see the options section below. \n\
	 \n\
DESCRIPTION \n\
	This is the EZ language compiler, a C based language for beginners. \n\
	 \n\
EXAMPLES \n\
	Some xamples of common usage : \n\
	EZL example1.ez example2.ez -o example.exe \n\
	 \n\
OPTIONS \n\
	--directinput			: Enable direct input for EZ language \n\
	-h, --help			: Displays this information \n\
	--noexec			: Do not launch the executable \n\
	-o <file>, --output=<file>	: Name the executable <file> \n\
	-O1, --optimisation=1		: Reduces the execution time, first level of optimization \n\
	-O2, --optimisation=2		: Same as O1 lvl2 \n\
	-O3, --optimisation=3		: Same as O2 lvl3 \n\
	--verbose			: Displays all the compilation steps in the command prompt \n\
	-w, --warning			: Displays all the warning messages \n\
 \n\
SEE ALSO \n\
   	Full documentation at ezlanguage.com \n\
   	 \n\
AUTHOR \n\
   	M2 SILI 2016 - 2017  \n\
   	 \n\
COPYRIGHT \n\
	Specify your copyright information.\n";
#endif
