#include "Shape.h"

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;
int currentY = 0;

//------------------------------------------------------------
//Methods of 'Shape' class
const string Shape::shapeType[4] = { "Rectangle", "Triangle", "Ellipse", "Line" };

void Shape::setName(string str) { name = str; }

void Shape::setType(string str) { type = str; }

void Shape::setDrawSym(char c) { drawSym = c; }

string Shape::getName() { return name; }

string Shape::getType() { return type; }

char Shape::getDrawSym() { return drawSym; }


bool Shape::isValidShapeType(string shapeType) {
    for (auto i : Shape::shapeType) {
        if (shapeType == i) return TRUE;
    }
    return FALSE;
}

