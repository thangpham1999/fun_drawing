#include "fun_drawing.h"


vector<string> split(const string& str, const string& delim)
{
    vector<string> res;
    string s;

    if ("" == str)
        return res;
    char* strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char* d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char* p = strtok(strs, d);
    while (p) {
            s = p;
            res.push_back(s);
            p = strtok(NULL, d);
        }
    return res;
}

bool isNumber(const string& str) {
    char* ptr;
    strtol(str.c_str(), &ptr, 10);
    return *ptr == '\0';
}