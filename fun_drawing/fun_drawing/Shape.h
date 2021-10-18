#include <windows.h>
#include <iostream>
#include "fun_drawing.h"

#ifndef Shape_H
#define Shape_H

extern HANDLE hStdout;
extern COORD destCoord;
extern int currentY;

class Shape {
protected:
    string name = "";
    string type = "";
    char drawSym = '\0';
public:
    static const string shapeType[4];
    void setName(string str);
    void setType(string str);
    void setDrawSym(char c);
    string getName();
    string getType();
    char getDrawSym();
    static bool isValidShapeType(string shapeType);
    virtual bool isValidShape() { return FALSE; }
    virtual bool isValidAttrb(string attrb) { return FALSE; }
    virtual bool isValidValue(string attrb, string value) { return FALSE; }

    virtual vector<string> emptyAttrbs() { vector<string> res; return res; }

    virtual void setAttrb(string attrb, string value) { ; }
    //virtual string getAttrb(string attrb) { ; }
    virtual void draw() { ; }

    virtual int16_t getWidth() { return 0; }
    virtual int16_t getHeight() { return 0; }
    virtual string getTriType() { return ""; }
};


#endif