#include "Shape.h"

#ifndef Rectangle_H
#define Rectangle_H

class Rectangle : public Shape {
private:
    int16_t width;
    int16_t height;
    const string attributes[3] = { "Width", "Height", "DrawSymbol" };
public:
    Rectangle(int16_t a, int16_t b);
    Rectangle();
    //void setWidth(int16_t w);
    //void setHeight(int16_t h);
    int16_t getWidth();
    int16_t getHeight();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
    void draw();
};

#endif