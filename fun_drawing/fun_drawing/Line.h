#include "Shape.h"

#ifndef Line_H
#define Line_H

class Line : public Shape {
private:
    int16_t len;
    string dir;
    const string attributes[3] = { "Length", "Direction", "DrawSymbol" };
    const string direction[2] = { "Horizontal", "Vertical" };
public:
    Line();
    Line(int16_t l, string d);
    //void setLen(int16_t num);
    //void setDir(string str);
    int16_t getLen();
    string getDir();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
};

#endif


