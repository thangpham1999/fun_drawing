#include "Shape.h"

#ifndef Triangle_H
#define Triangle_H

class Triangle : public Shape {
private:
    int16_t width;
    int16_t height;
    string triType;
    const string attributes[4] = { "Width", "Height", "TriangleType", "DrawSymbol" };
    const string triangleTypes[2] = { "IsoscelesRight", "Isosceles" };
public:
    //Triangle(int16_t w, const string t = "Isosceles right");
    //Triangle(int16_t w, int16_t h, const string t = "Isosceles");
    Triangle(int16_t w, int16_t h, string t);
    Triangle();
    //void setWidth(int16_t w);
    //void setHeight(int16_t h);
    //void setTriType(string str);
    int16_t getWidth();
    int16_t getHeight();
    string getTriType();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
};

#endif