#ifndef STRING_ADDON_H
#define STRING_ADDON_H

//@author : CHARLOT Rodolphe, ELFAQIR Ismail, LAHYANI Zakaria
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
/*
* This file is an add-on to the string in C++
* It's used to helping people manipulating the string class in C++
* Please ask Rodolphe or name him in your commit when you add or remove something here
*/

using namespace std;


//Add some help to add number inside a string
string operator+ (string s, int i);
string operator+ (string s, double i);
string operator+ (string s, float i);

//as the document of Morgan (Fonctions string.pdf) i added this functions 

/**
* @brief splitting an string by an character
* @param str : the string that we want to split
* @param delim : split the string with this character
* @return vector of string computed by splitting this string
* @author Ismail ELFAQIR
*/

std::vector<std::string> split(std::string const & str, char delim);

/**
* @brief splitting an string by an string
* @param str : the string that we want to split
* @param delim : split the string with this string
* @return vector of string computed by splitting this string
* @author Ismail ELFAQIR, Zakaria LAHYANI
*/

std::vector<std::string> split(std::string const & str, const std::string &delim);


/**
* @brief concat an vector of string
* @param array_of_string : vector of string
* @param join_with : string to separate the element of the vector
* @return string
* @author Ismail ELFAQIR
*/
string join(const std::vector<std::string> &array_of_string, const string &join_with="");

/**
* @brief concat an vector of string
* @param array_of_string : vector of string
* @param join_with : character to separate the element of the vector
* @return string
* @author Ismail ELFAQIR, Zakaria LAHYANI
*/
string join(const std::vector<std::string> &array_of_string, char join_with);

/**
* @brief simpler function to convert an string to upper case
* @param str : reference of the string 
* @return string
* @author Ismail ELFAQIR
*/
string toUpperCase(const string &str);

/**
* @brief simpler function to convert an string to lower case
* @param str : reference of the string 
* @return string
* @author Ismail ELFAQIR
*/
string toLowerCase(const string &str);

/**
* @brief function to replace all string an another one
* @param str : reference of the string
* @param to_replace : the string that we want to replace
* @param replace_with : replace with this string all occurent of to_replace
* @return string
* @author Ismail ELFAQIR, Zakaria LAHYANI
*/
string replace(const string &str, const string &to_replace, const string &replace_with );

/**
* @brief check if a string contains another one
* @param str : reference of the string
* @param str2 : string
* @return boolean
* @author Ismail ELFAQIR
*/
bool contains(const string &str, const string &str2);
#endif
