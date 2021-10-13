#include "Shape.h"

#ifndef Ellipse_H
#define Ellipse_H

class Ellipse : public Shape {
private:
    Point center;
    int16_t width;
    int16_t height;
    const string attributes[5] = { "Width", "Height", "CenterX", "CenterY", "DrawSymbol" };
public:
    Ellipse();
    Ellipse(int16_t x, int16_t y, int16_t w, int16_t h);
    //void setCenter(int16_t x, int16_t y);
    //void setAxisLen(int16_t x, int16_t y);
    Point getCenter();
    int16_t getWidth();
    int16_t getHeight();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
};

#endif


