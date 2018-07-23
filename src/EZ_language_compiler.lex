%option nounput
%option yylineno

%{
/*
This is the lex file for the EZLanguage to C++ compiler project
As always, note the use of white-space before any C code.
*/

#include <stdlib.h> /* pour atoi - atof */
#include <string.h> /* pour strdup */
#include <iostream>
#include "../src/global.h" // on part du dossier ../obj car il y est necessaire
using namespace std;
#include "EZ_language_compiler.tab.hpp"

extern "C" int yylex(void);
extern int yylineno;

%}


separators      [ \t]+
number          [0-9]
integer         {number}+

reel            {integer}("."{integer})?

mot             [A-z]+

quote ["]

ID ([a-z]|[A-Z])([a-z]|[A-Z]|[0-9]|_)*

phrase (\\.|[^"])*

comment		(\/\*((.*)|(\n*))*\*\/)|(\/\/(.*))

backLine 	\n
minus     [-]

anythingexceptend ([^e])+e([^n])+n([^d])+d([^\n])+\n

end end
code code

%%

{separators}   	{ /* On ignore */ }
{comment}   	{ /* Ignore it */ cout << "Comment"<<endl; }
{integer}		{ yylval.text= yytext; return(NUM_INTEGER); }  // integer
{reel}      	{ yylval.text= yytext; return(NUM_REAL);}	// real

{backLine}	{ debugLex("BACK_LINE", AT); return(BACK_LINE); }

","		return COMMA;

"°"		return(DEGREE);
"%"		return(PERCENT);
"#"		return(SHARP);
"="		return(EQUALS);
"!="    return NE; 
"<"     return LT; 
"<="    return LE; 
">"     return GT; 
">="    return GE; 
"+"     return PLUS; 
{minus}     return MINUS; 
"*"     return MULT; 
"/"   	return DIVISE;

(&|and)		return (AND);
"or"		return (OR);
"^"	        return (XOR);
"!"	        return (NOT); 

"("		return (LEFT_PARENTHESIS);
")"		return (RIGHT_PARENTHESIS);

"{"		return (LEFT_ACCOLADE);
"}"		return (RIGHT_ACCOLADE);

"["		return (LEFT_BRACKET);
"]"		return (RIGHT_BRACKET);
".."		return (DOUBLE_DOT);
"."	        return (SIMPLE_DOT);


{quote}		return (QUOTE);


 /*Everything else
(code){anythingexceptend}{end}  { yylval.text= yytext; debugLex("Unrecognized char: "+ std::string(yytext), AT); yymore(); }
*/
{code}{anythingexceptend} {
    // Substract the "end" characters
    // yyless(3);
    std::string text= yytext;
    text= text.substr(5);
    yylval.text= text;
    debugLex("Chars: '"+ text +"'", AT);
    return(CODE_TEXT);
}

(import|IMPORT)     return(IMPORT);
(include|INCLUDE)   return(INCLUDE);
(library|LIBRARY)   return(LIBRARY);
(extern|EXTERN)     return(EXTERN);

(mod|MOD)           return(MOD);
(pow|POW)           return(POW);
(abs|ABS)           return(ABS);

(constant|CONSTANT) return(CONST);
(variable|VARIABLE) return(VARIABLE);
(global|GLOBAL)     return(GLOBAL);
(is|IS)             return(IS) ;
(are|ARE)           return(ARE) ;
(integer|INTEGER)   return(TYPE_INTEGER);
(real|REAL)         return(TYPE_REAL);
(string|STRING)     return(TYPE_STRING);
(boolean|BOOLEAN)   return(TYPE_BOOLEAN);
(shared|SHARED)     return(SHARED);

(if|IF)             return(IF);
(then|THEN)         return(THEN);
(else|ELSE)         return(ELSE);

(begin|BEGIN)       return(BEGINN);
(end|END)           return(END);

(when|WHEN)         return(WHEN);
(case|CASE)         return(CASE);
(default|DEFAULT)   return(DEFAULT);

(while|WHILE)       return(WHILE);
(do|DO)             return(DO);

(repeat|REPEAT)         return(REPEAT);
(until|UNTIL)           return(UNTIL);
(endrepeat|ENDREPEAT)   return(ENDREPEAT);

(for|FOR)        return(FOR);
(in|IN)          return(IN);
(step|STEP)      return(STEP);

(function|FUNCTION)     return(FUNCTION);
(procedure|PROCEDURE)   return(PROCEDURE);
(returns|RETURNS)       return(RETURNS);
(return|RETURN)         return(RETURN);
(true|TRUE)             return (TRUE);
(false|FALSE)           return (FALSE);

(operator|OPERATOR) return(OPERATOR);

(class|CLASS)       return(CLASS);
(program|PROGRAM)   return(PROGRAM);
(module|MODULE)     return(MODULE);
(destruct|DESTRUCT) return(DESTRUCT);


(print|PRINT)   return(PRINT);
(input|INPUT)   return(INPUT);

(parameters|PARAMETERS) return(PARAMETERS);
(as|AS)                 return(AS);

(length|LENGTH)                 { return(LENGTH);}
(toUpperCase|TOUPPERCASE)     	{ return(TOUPPERCASE);}
(toLowerCase|TOLOWERCASE)     	{ return(TOLOWERCASE);}
(substring|SUBSTRING)     	{ return(SUBSTRING);}
(split|SPLIT)     		{ return(SPLIT);}
(strip|STRIP)     		{ return(STRIP);}
(replace|REPLACE)     		{ return(REPLACE);}
(contains|CONTAINS)     	{ return(CONTAINS);}
(find|FIND)     		{ return(FIND);}
(findFirstOf|FINDFIRSTOF)     	{ return(FINDFIRSTOF);}
(findLastOf|FINDLASTOF)  	{ return(FINDLASTOF);}


(array|ARRAY)       return(ARRAY);
(vector|VECTOR)     return(VECTOR);
(list|LIST)        	return(LIST);
(set|SET)        	return(SET);
(map|MAP)        	return(MAP);
(of|OF)             return(OF);

(regex|REGEX)        	return(REGEX);
(match|MATCH)        	return(MATCH);
(search|SEARCH)         return(SEARCH);


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


{ID} {
    debugLex(std::string("Identifier: ")+ std::string(yytext), AT); 
    yylval.text= yytext;
    return (NAME);
}

{quote}{minus}{minus}{ID}{quote}  { yylval.text = yytext; return(STRING_PARAM); }
{quote}{phrase}{quote}  { debugLex("String", AT); yylval.text = yytext; return(STRING); }


<<EOF>>     return END_OF_FILE;

%%
