#include "Shape.h"

#ifndef Ellipse_H
#define Ellipse_H

class Ell : public Shape {
private:
    Point center = { -1, -1 };
    int16_t width = -1;
    int16_t height = -1;
    const string attributes[5] = { "Width", "Height", "CenterX", "CenterY", "DrawSymbol" };
public:
    Ell();
    Ell(int16_t x, int16_t y, int16_t w, int16_t h);
    //void setCenter(int16_t x, int16_t y);
    //void setAxisLen(int16_t x, int16_t y);
    Point getCenter();
    int16_t getWidth();
    int16_t getHeight();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    vector<string> emptyAttrbs();
    void setAttrb(string attrb, string value);
};

#endif


