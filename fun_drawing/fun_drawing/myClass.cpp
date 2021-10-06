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
int16_t System::getQuery() {
        int16_t temp;
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


//Methods of 'Rectangle' class
Rectangle::Rectangle(int16_t a, int16_t b) {
    width = a;
    height = b;
}
Rectangle::Rectangle() {
    width = 0;
    height = 0;
}
void Rectangle::setWidth(int16_t w) {width = w;}
void Rectangle::setHeight(int16_t h) {height = h;}
int16_t Rectangle::getWidth() {return width;}
int16_t Rectangle::getHeight() {return height;}
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
void Triangle::setWidth(int16_t w) {width = w;}
void Triangle::setHeight(int16_t h) {height = h;}
void Triangle::setType(string str) {type = str;}
int16_t Triangle::getWidth() {return width;}
int16_t Triangle::getHeight() {return height;}
string Triangle::getType() {return type;}

//Methods of 'Ellipse' class
void Ellipse::setCenter(int16_t x, int16_t y) {
    center.x = x;
    center.y = y;
}
void Ellipse::setAxisLen(int16_t x, int16_t y) {
    a = x;
    b = y;
}
Point Ellipse::getCenter() {return center;}
int16_t Ellipse::getMajor() {return a;}
int16_t Ellipse::getMinor() {return b;}

//Methods of 'Line' class
void Line::setStartPos(int16_t x, int16_t y) {
    startPos.x = x;
    startPos.y = y;
}
void Line::setLen(int16_t num) {
    len = num;
}
void Line::setDir(int16_t num) {
    dir = num;
}
Point Line::getStartPos() {return startPos;}
int16_t Line::getLen() {return len;}
int16_t Line::getDir() {return dir;}
