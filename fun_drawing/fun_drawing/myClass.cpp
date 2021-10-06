#include "myClass.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace T;

//Methods of Factory class
Shape* Factory::createShape(string type) {
    if (type == "Triangle") return new Triangle;
    if (type == "Rectangle") return new Rectangle;
    if (type == "Ellipse") return new Ellipse;
    if (type == "Line") return new Line;
}

//Methods of 'Storage' class
void Storage::addShape(Shape* shape) {shapeList.push_back(shape);}
vector<Shape*> Storage::getShape() {return shapeList;}

//Methods of 'System' class
void System::displayQuery() {
        cout << "Menu:\n" << endl << "1. Input text.\n" << "2. Draw.\n" << "3. Open file.\n" << "4. End session.\n";
        cout << "Please enter the number: ";
}
uint16_t System::getQuery() {
        uint16_t temp;
        cin >> temp;
        return temp;
}
void System::readConsole() {
    string s;
    getline(cin, s, static_cast<char>(EOF));
}
void System::readFile() {}

//Methods of 'Shape' class
void Shape::setName(string str) {name = str;}
void Shape::setType(string str) {type = str;}
void Shape::setDrawSym(char c) {drawSym = c;}
string Shape::getName() {return name;}
string Shape::getType() {return type;}
char Shape::getDrawSym() {return drawSym;}
virtual void Shape::errorChecking();
virtual void Shape::draw();
};

//Methods of 'Rectangle' class
Rectangle::Rectangle(uint16_t a, uint16_t b) {
    width = a;
    height = b;
}
Rectangle::Rectangle() {
    width = 0;
    height = 0;
}
void Rectangle::setWidth(uint16_t w) {width = w;}
void Rectangle::setHeight(uint16_t h) {height = h;}
uint16_t Rectangle::getWidth() {return width;}
uint16_t Rectangle::getHeight() {return height;}
void Rectangle::draw() {
    cout << getName() << " :" << endl;
    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            if (j == getWidth() - 1) cout << getDrawSym << endl;
            else if (i == 0 || i == getHeight() - 1 || j == 0) cout << getDrawSym;
            else cout << ' ';
        }
    }
}

//Methods of 'Triangle' class
void Triangle::setWidth(uint16_t w) {width = w;}
void Triangle::setHeight(uint16_t h) {height = h;}
void Triangle::setType(string str) {type = str;}
uint16_t Triangle::getWidth() {return width;}
uint16_t Triangle::getHeight() {return height;}
string Triangle::getType() {return type;}

//Methods of 'Ellipse' class
void Ellipse::setCenter(uint16_t x, uint16_t y) {
    center.x = x;
    center.y = y;
}
void Ellipse::setAxisLen(uint16_t x, uint16_t y) {
    a = x;
    b = y;
}
Point Ellipse::getCenter() {return center;}
uint16_t Ellipse::getMajor() {return a;}
uint16_t Ellipse::getMinor() {return b;}

//Methods of 'Line' class
void Line::setStartPos(uint16_t x, uint16_t y) {
    startPos.x = x;
    startPos.y = y;
}
void Line::setLen(uint16_t num) {
    len = num;
}
void Line::setDir(int16_t num) {
    dir = num;
}
Point Line::getStartPos() {return startPos;}
uint16_t Line::getLen() {return len;}
uint16_t Line::getDir() {return dir;}
