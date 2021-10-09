#include "myClass.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace T;

//Global object
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;
int currentY = 0;

//UIHandler
UIHandler::UIHandler(int y) { currentY = y; };
static UIHandler getInstance() {};
void UIHandler::draw(vector<Shape*> shapes) {
    for (auto shape : shapes) {
        shape->draw();
    }
    currentY = 0;
}

void UIHandler::showOption() {
    cout << "Menu:\n" << endl << "1. Input text.\n" << "2. Draw.\n" << "3. Open file.\n" << "4. End session.\n";
    cout << "Please enter your option: ";
}

void UIHandler::showGuide(int16_t opt) {
    switch (opt) {
    case 1:
        cout << "Please enter your text (press Ctrl+Z if when you finish): \n";
        break;
    case 3:
        cout << "Please enter your file path: \n";
        break;
    case 4:
        cout << "Exiting";
        break;
    }
}

int16_t UIHandler::getOption() {
    int16_t temp;
    cin >> temp;
    return temp;
}

string UIHandler::getInputText() {
    string str;
    getline(cin, str, static_cast<char>(EOF));
    return str;
}

//Input Handler
void InputHandler::handleInputText(string str) {
    for (int i = 0; i < str.end() - str.begin(); i++) {
        if (str[i] == '[') name = str.substr();
    }
}

//Methods of Factory class
Shape* Factory::createShape(string type) {
    if (type == "Triangle") return new Triangle;
    else if (type == "Rectangle") return new Rectangle;
    else if (type == "Ellipse") return new Ellipse;
    else if (type == "Line") return new Line;
    else return NULL;
}

//Methods of 'Storage' class
void Storage::addShape(Shape* shape) {shapeList.push_back(shape);}
vector<Shape*> Storage::getShape() {return shapeList;}


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
    cout << name << " :" << endl;
    currentY++;
    for (int i = currentY; i < height + currentY; i++) {
        destCoord.Y = i;
        for (int j = 0; j < width; j++) {
            destCoord.X = j;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << drawSym;
        }
    }
    cout << endl;
    currentY = destCoord.Y + 1;
}

//Methods of 'Triangle' class
Triangle::Triangle() {
    width = 0;
    height = 0;
    triType = "Isosceles right";
}
/*
Triangle::Triangle(int16_t w, const string t = "Isosceles right") {
    width = height = w;
    type = t;
}
Triangle::Triangle(int16_t w, int16_t h, const string t = "Isosceles") {
    width = w;
    height = h;
    type = t;
}
*/

Triangle::Triangle(int16_t w, int16_t h, string t) {
    width = w;
    height = h;
    triType = t;
}
void Triangle::setWidth(int16_t w) {width = w;}
void Triangle::setHeight(int16_t h) {height = h;}
void Triangle::setTriType(string str) {triType = str;}
int16_t Triangle::getWidth() {return width;}
int16_t Triangle::getHeight() {return height;}
string Triangle::getTriType() {return triType;}
void Triangle::draw() {
    cout << name << " :" << endl;
    currentY++;
    if (triType == "Isosceles right") {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < i + 1; j++) {
                destCoord.X = j;
                destCoord.Y = currentY + i;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << drawSym;
            }
        }
    }
    else if (triType == "Isosceles") {
        int mid = width / 2;
        for (int i = 0; i < height; i++) {
            for (int j = mid - i; j < mid + i + 1; j++) {
                destCoord.X = j;
                destCoord.Y = currentY + i;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << drawSym;
            }
        }
    }
    else cout << "Invalid triangle type" << endl;
    cout << endl;
    currentY = destCoord.Y + 1;
}

//Methods of 'Ellipse' class
Ellipse::Ellipse() {
    center.x = center.y = width = height = 0;
}
Ellipse::Ellipse(int16_t x, int16_t y, int16_t w, int16_t h) {
    center.x = x;
    center.y = y;
    width = w;
    height = h;
}
void Ellipse::setCenter(int16_t x, int16_t y) {
    center.x = x;
    center.y = y;
}
void Ellipse::setAxisLen(int16_t x, int16_t y) {
    width = x;
    height = y;
}
Point Ellipse::getCenter() {return center;}
int16_t Ellipse::getWidth() {return width;}
int16_t Ellipse::getHeight() {return height;}
void Ellipse::draw() {
    cout << name << " :" << endl;
    currentY++;
    for (int i = 0; i < width; i++)
    {
        int dx = i - width / 2;
        int x = center.x + dx;

        int h = (int)round(height * sqrt(width * width / 4.0 - dx * dx) / width);
        for (int dy = 1; dy <= h; dy++)
        {
            destCoord.X = x;
            destCoord.Y = center.y + dy + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << drawSym;
            destCoord.X = x;
            destCoord.Y = center.y - dy + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << drawSym;
        }

        if (h >= 0)
        {
            destCoord.X = x;
            destCoord.Y = center.y + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << drawSym;
        }
    }
    currentY += height + 1;
    destCoord.Y = currentY;
    destCoord.X = 0;
    SetConsoleCursorPosition(hStdout, destCoord);
}

//Methods of 'Line' class
Line::Line() {
    len = 0;
    dir = "Horizontal";
}
Line::Line(int16_t l, string d) {
    len = l;
    dir = d;
}
void Line::setLen(int16_t num) {
    len = num;
}
void Line::setDir(string str) {
    dir = str;
}
int16_t Line::getLen() {return len;}
string Line::getDir() {return dir;}
void Line::draw() {
    cout << name << " :";
    currentY++;
    destCoord.X = 0;
    destCoord.Y = currentY;
    if (dir == "Horizontal") {
        for (int x = 0; x < len; x++) {
            destCoord.X = x;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << drawSym;
        }
        currentY = destCoord.Y + 1;
    }
    else if (dir == "Vertical") {
        for (int y = 0; y < len; y++) {
            destCoord.Y = currentY + y;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << drawSym;
        }
        cout << endl;
        currentY = destCoord.Y + 1;
    }
    else cout << "Invalid direction";
    
}
