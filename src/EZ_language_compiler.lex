%option nounput
%option yylineno

%{
#include <stdlib.h> /* pour atoi - atof */
#include <string.h> /* pour strdup */
#include <iostream>
#include "../src/global.h" // on part du dossier ../obj car il y est necessaire
using namespace std;
#include "EZ_language_compiler.tab.hpp"

extern "C" int yylex(void);
extern int yylineno;


%}


separateurs     [ \t]+
number         [0-9]
entier          {number}+

reel			{entier}("."{entier})?

mot 		    [A-z]+

quote ["]

ID ([a-z]|[A-Z])([a-z]|[A-Z]|[0-9]|_)*

phrase (\\.|[^"])*

commentaire		(\/\*((.*)|(\n*))*\*\/)|(\/\/(.*))

backLine 	\n
minus     [-]

%%

{separateurs}   { /* On ignore */ }
{commentaire}   { /* On ignore */ cout << "Commentaire"<<endl; }
{entier}	{ yylval.numerical_value=atoi(yytext); return(NUM_INTEGER);}  // integer
{reel}      { yylval.reel_value=atof(yytext); return(NUM_REAL);}		 // reel

{backLine}	return(BACK_LINE);


","		return(COMMA);

"°"		return(DEGRE);
"%"		return(POURCENT);
"#"		return(DIESE);
"="		return(EGAL);
"!="    return NE; 
"<"     return LT; 
"<="    return LE; 
">"     return GT; 
">="    return GE; 
"+"     return PLUS; 
{minus}     return MINUS; 
"*"     return MULT; 
"/"   	return DIVISE;

"&"		return (AND);
"|"		return (OR);
"^"	        return (XOR);
"!"	        return (NOT); 

"("		return (LEFT_PARENTHESIS);
")"		return (RIGHT_PARENTHESIS);

"{"		return (LEFT_ACCOLADE);
"}"		return (RIGHT_ACCOLADE);

"["		return (LEFT_BRACKET);
"]"		return (RIGHT_BRACKET);
"."	        return (POINT);

{quote}		return (QUOTATION_MARKS);

(import|IMPORT)      return(IMPORT);
(include|INCLUDE)    return(INCLUDE);
(library|LIBRARY)    return(LIBRARY);
(extern|EXTERN)      return(EXTERN);

(mod|MOD)            return(MOD);
(pow|POW)            return(POW);
(abs|ABS)            return(ABS);

(constant|CONSTANT)  return(CONSTANT);
(variable|VARIABLE)  return(VARIABLE);
(global|GLOBAL)      return(GLOBAL);
(is|IS)              return(IS) ;
(are|ARE)            return(ARE) ;
(integer|INTEGER)    return(TYPE_INTEGER);
(real|REAL)          return(TYPE_REAL);
(string|STRING)      return(TYPE_STRING);
(boolean|BOOLEAN)    return(TYPE_BOOLEAN);
(shared|SHARED)      return(SHARED);

(if|IF)              return(IF);
(then|THEN)          return(THEN);
(else|ELSE)          return(ELSE);

(begin|BEGIN)        return(BEGINN);
(end|END)            return(END);

(when|WHEN)           return(WHEN);
(case|CASE)           return(CASE);
(default|DEFAULT)     return(DEFAULT);

(while|WHILE)         return(WHILE);
(do|DO)               return(DO);

(repeat|REPEAT)         return(REPEAT);
(until|UNTIL)           return(UNTIL);
(endrepeat|ENDREPEAT)   return(ENDREPEAT);

(for|FOR)        return(FOR);
(in|IN)          return(IN);
(step|STEP)      return(STEP);

(function|FUNCTION)         return(FUNCTION);
(procedure|PROCEDURE)       return(PROCEDURE);
(return|RETURN)             return(RETURN);

(operator|OPERATOR)         return(OPERATOR);

(class|CLASS)              return(CLASS);
(program|PROGRAM)          return(PROGRAM);
(destruct|DESTRUCT)        return(DESTRUCT);


(print|PRINT)     	        return(PRINT);

(arguments|ARGUMENTS)       return(ARGUMENTS);
(as|AS)     		        return(AS);

(length|LENGTH)     			{ return(LENGTH);}
(toUpperCase|TOUPPERCASE)     	{ return(TOUPPERCASE);}
(toLowerCase|TOLOWERCASE)     	{ return(TOLOWERCASE);}
(substring|SUBSTRING)     		{ return(SUBSTRING);}
(split|SPLIT)     				{ return(SPLIT);}
(strip|STRIP)     				{ return(STRIP);}
(replace|REPLACE)     			{ return(REPLACE);}
(contains|CONTAINS)     		{ return(CONTAINS);}
(find|FIND)     				{ return(FIND);}
(findFirstOf|FINDFIRSTOF)     	{ return(FINDFIRSTOF);}
(findLastOf|FINDLASTOF)  		{ return(FINDLASTOF);}


(array|ARRAY)        	return(ARRAY);
(vector|VECTOR)        	return(VECTOR);
(list|LIST)        		return(LIST);
(set|SET)        		return(SET);
(map|MAP)        		return(MAP);
(of|OF)             	return(OF);

(regex|REGEX)        	return(REGEX);
(match|MATCH)        	return(MATCH);
(search|SEARCH)         return(SEARCH);
(replace|REPLACE)       return(REPLACE);


(size|SIZE)             return(SIZE);
(is_empty|IS_EMPTY)     return(IS_EMPTY);
(clear|CLEAR)           return(CLEAR);

(fill|FILL)           	return(FILL);
(randomize|RANDOMIZE)   return(RANDOMIZE);
(count|COUNT)           return(COUNT);
(max|MAX)           	return(MAX);
(min|MIN)           	return(MIN);
(sort|SORT)           	return(SORT);
(sum|SUM)           	return(SUM);
(remove|REMOVE)         return(REMOVE);

(put_first|PUT_FIRST)           return(PUT_FIRST);
(put_last|PUT_LAST)           	return(PUT_LAST);
(remove_last|REMOVE_LAST)       return(REMOVE_LAST);
(remove_first|REMOVE_FIRST)     return(REMOVE_FIRST);
(average|AVERAGE)      			return(AVERAGE);
(store|STORE)      				return(STORE);
(restore|RESTORE)      			return(RESTORE);
(range|RANGE)      				return(RANGE);
(first|FIRST)      				return(FIRST);
(last|LAST)      				return(LAST);
(remove_at|REMOVE_AT)      		return(REMOVE_AT);
(put_at|PUT_AT)      			return(PUT_AT);
(insert|INSERT)      			return(INSERT);
(exist|EXIST)      				return(EXIST);


{ID}	{	yylval.texte= yytext;
	    		return (NAME);
	}

{quote}{minus}{minus}{ID}{quote}  {yylval.texte = yytext; return(STRING_PARAM);}
{quote}{phrase}{quote}  {yylval.texte = yytext; return(STRING);}


<<EOF>>     return END_OF_FILE;
%%
