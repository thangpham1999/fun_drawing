#include "Shape.h"

#ifndef DataHandler_H
#define DataHandler_H

class Factory {
public:
    static Shape* createShape(string type);
    static void deleteShape(Shape* shape);
};

class Storage {
private:
    static vector<Shape*> shapeList;
public:
    static void addShape(Shape* shape);
    static vector<Shape*>& getShape();
};

#endif