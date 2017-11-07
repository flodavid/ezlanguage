//@author : CHARLOT Rodolphe, ELFAQIR Ismail
#include "String_addon.h"

string operator+ (string s, int i)
{
    return s+to_string(i);
}
string operator+ (string s, double i)
{
    return s+to_string(i);
}
string operator+ (string s, float i)
{
    return s+to_string(i);
}

std::vector<std::string> split(std::string const & str, char delim){
    std::vector<std::string> result;
    std::istringstream iss(str);

    for (std::string token; std::getline(iss, token, delim); ){
        result.push_back(std::move(token));
    }
    return result;
}

std::vector<std::string> split(std::string const & str, const string &delim){
    vector<string> result;
 
    int strleng = str.length();
    int delleng = delim.length();
    if (delleng==0) return result;//no change
 
    int i=0;
    int k=0;
    while( i<strleng ){
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delim[j])
            j++;
        if (j==delleng) {//found delim
            result.push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        }
        else{
            i++;
        }
    }
    result.push_back(  str.substr(k, i-k) );
    return result;
}

string join(const std::vector<std::string> &array_of_string, const string &join_with){
	string result="";
	for(unsigned int i=0;i<array_of_string.size();i++){
		result+=array_of_string[i];
		if(i<array_of_string.size()-1) result+=join_with;
	}
	return result;
}

string join(const std::vector<std::string> &array_of_string, char join_with){
	string result="";
	for(unsigned int i=0;i<array_of_string.size();i++){
		result+=array_of_string[i];
		if(i<array_of_string.size()-1) result+=join_with;
	}
	return result;
}

string toUpperCase(const string &str){
	string result=str;
	transform(result.begin(), result.end(), result.begin(), ::toupper);
	return result;
}

string toLowerCase(const string &str){
	string result=str;
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

string replace(const string &str, const string &to_replace, const string &replace_with ){
	string result=str;
	std::size_t found=result.find(to_replace);
	while(found!=string::npos){
		string tmp = result.substr(found+to_replace.length());
		result=result.substr(0,found);
		result+=replace_with+tmp;
		found=result.find(to_replace);
	}
	return result;
}

bool contains(const string &str, const string &str2){
	return str.find(str2)!=string::npos;
}
