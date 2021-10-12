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
    string name;
    string type;
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
    virtual bool isValidShape() { return TRUE; }
    virtual bool isValidAttrb(string attrb) { return TRUE; }
    virtual bool isValidValue(string attrb, string value) { return TRUE; }
    virtual void setAttrb(string attrb, string value) { ; }
    //virtual string getAttrb(string attrb) { ; }
    virtual void draw() { ; }

    virtual int16_t getWidth() { return 0; }
    virtual int16_t getHeight() { return 0; }
    virtual string getTriType() { return ""; }
};

class Rectangle : public Shape {
private:
    int16_t width;
    int16_t height;
    const string attributes[3] = { "Width", "Height", "DrawSymbol" };
public:
    Rectangle(int16_t a, int16_t b);
    Rectangle();
    void setWidth(int16_t w);
    void setHeight(int16_t h);
    int16_t getWidth();
    int16_t getHeight();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
    void draw();
};

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
    void setWidth(int16_t w);
    void setHeight(int16_t h);
    void setTriType(string str);
    int16_t getWidth();
    int16_t getHeight();
    string getTriType();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
};

class Ellipse : public Shape {
private:
    Point center;
    int16_t width;
    int16_t height;
    const string attributes[5] = { "Width", "Height", "CenterX", "CenterY", "DrawSymbol" };
public:
    Ellipse();
    Ellipse(int16_t x, int16_t y, int16_t w, int16_t h);
    void setCenter(int16_t x, int16_t y);
    void setAxisLen(int16_t x, int16_t y);
    Point getCenter();
    int16_t getWidth();
    int16_t getHeight();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
};

class Line : public Shape {
private:
    int16_t len;
    string dir;
    const string attributes[3] = { "Length", "Direction", "DrawSymbol" };
    const string direction[2] = { "Horizontal", "Vertical" };
public:
    Line();
    Line(int16_t l, string d);
    void setLen(int16_t num);
    void setDir(string str);
    int16_t getLen();
    string getDir();
    void draw();
    bool isValidShape();
    bool isValidAttrb(string attrb);
    bool isValidValue(string attrb, string value);
    void setAttrb(string attrb, string value);
};

#endif