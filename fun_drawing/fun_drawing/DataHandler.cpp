#include "DataHandler.h"

Shape* Factory::createShape(string type) {
    if (type == "Triangle") return new Triangle;
    //else if (type == "Rectangle") return new Rectangle;
    //else if (type == "Ellipse") return new Ellipse;
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