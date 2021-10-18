#include "Shape.h"

#ifndef Triangle_H
#define Triangle_H

class Triangle : public Shape {

private:
    int16_t width = -1;
    int16_t height = -1;
    string triType = "";
    const string attributes[4] = { "Width", "Height", "TriangleType", "DrawSymbol" };
    const string triangleTypes[2] = { "IsoscelesRight", "Isosceles" };

public:
    Triangle(int16_t w, int16_t h, string t);
    Triangle();
    int16_t getWidth();
    int16_t getHeight();
    string getTriType();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    vector<string> emptyAttrbs();
    void setAttrb(string attrb, string value);
};

#endif