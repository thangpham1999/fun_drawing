#include "DataHandler.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Line.h"

Shape* Factory::createShape(string type) {
    if (type == "Triangle") return new Triangle;
    else if (type == "Rectangle") return new Rec;
    else if (type == "Ellipse") return new Ell;
    else if (type == "Line") return new Line;
    else return NULL;
}
void Factory::deleteShape(Shape* shape) {
    delete shape;
}

//Methods of 'Storage' classs
vector<Shape*> Storage::shapeList;
void Storage::addShape(Shape* shape) { shapeList.push_back(shape); }
vector<Shape*> Storage::getShape() { return shapeList; }