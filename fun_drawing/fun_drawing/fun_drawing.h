#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#ifndef fun_drawing_H
#define fun_drawing_H

struct Point {
    int16_t x;
    int16_t y;
};

vector<string> split(const string& str, const string& delim);
bool isNumber(const string& str);

#endif