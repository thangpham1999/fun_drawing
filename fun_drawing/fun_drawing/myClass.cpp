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

vector<string> split(const string& str, const string& delim)
{
    vector<string> res;
    if ("" == str)
        return res;
    char* strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char* d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char* p = strtok(strs, d);
    while (p) {
        string s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }
    return res;
}

bool isNumber(const string& str) {
    char* ptr;
    strtol(str.c_str(), &ptr, 10);
    return *ptr == '\0';
}

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


//Methods of 'Rectangle' class

Rectangle::Rectangle(int16_t a, int16_t b) {
    width = a;
    height = b;
}
Rectangle::Rectangle() {
    width = 0;
    height = 0;
}
void Rectangle::setWidth(int16_t w) { width = w; }

void Rectangle::setHeight(int16_t h) { height = h; }

int16_t Rectangle::getWidth() { return width; }

int16_t Rectangle::getHeight() { return height; }

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

bool Rectangle::isValidShape() {
    return (width > 0 && height > 0 && drawSym != '\0');
}

bool Rectangle::isValidAttrb(string attrb) {
    for (auto i : attributes) {
        if (i == attrb) return TRUE;
    }
    return FALSE;
}
bool Rectangle::isValidValue(string attrb, string value) {
    if (attrb == "Width" || attrb == "Height") return (isNumber(value) && stoi(value) > 0);
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}
void Rectangle::setAttrb(string attrb, string value) {
    if (attrb == "Width") width = stoi(value);
    else if (attrb == "Height") height = stoi(value);
    else if (attrb == "DrawSymbol") drawSym = value[0];
}

//Methods of 'Triangle' class
Triangle::Triangle() {
    width = 0;
    height = 0;
    triType = "";
}

Triangle::Triangle(int16_t w, int16_t h, string t) {
    width = w;
    height = h;
    triType = t;
}
void Triangle::setWidth(int16_t w) { width = w; }
void Triangle::setHeight(int16_t h) { height = h; }
void Triangle::setTriType(string str) { triType = str; }
int16_t Triangle::getWidth() { return width; }
int16_t Triangle::getHeight() { return height; }
string Triangle::getTriType() { return triType; }
void Triangle::draw() {
    cout << name << " :" << endl;
    currentY++;
    if (triType == "IsoscelesRight") {
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
    cout << endl;
    currentY = destCoord.Y + 1;
}

bool Triangle::isValidShape() {
    return (width > 0 && height > 0 && triType != "" && drawSym != '\0');
}

bool Triangle::isValidAttrb(string attrb) {
    for (auto i : attributes) {
        if (i == attrb) return TRUE;
    }
    return FALSE;
}
bool Triangle::isValidValue(string attrb, string value) {
    if (attrb == "Width" || attrb == "Height") return (isNumber(value) && stoi(value) > 0);
    else if (attrb == "TriangleType") {
        for (auto i : triangleTypes) { 
            if(value == i) return TRUE;
        }
        return FALSE;
    }
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}
void Triangle::setAttrb(string attrb, string value) {
    if (attrb == "Width") width = stoi(value);
    else if (attrb == "Height") height = stoi(value);
    else if (attrb == "TriangleType") triType = value;
    else if (attrb == "DrawSymbol") drawSym = value[0];
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
Point Ellipse::getCenter() { return center; }
int16_t Ellipse::getWidth() { return width; }
int16_t Ellipse::getHeight() { return height; }
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

bool Ellipse::isValidShape() {
    return (width > 0 && height > 0 && drawSym != '\0' && center.x > 0 && center.y > 0);
}

bool Ellipse::isValidAttrb(string attrb) {
    for (auto i : attributes) {
        if (i == attrb) return TRUE;
    }
    return FALSE;
}
bool Ellipse::isValidValue(string attrb, string value) {
    if (attrb == "Width" || attrb == "Height") return (isNumber(value) && stoi(value) > 0);
    else if (attrb == "CenterX") return (isNumber(value) && width <= 2 * stoi(value) && stoi(value) > 0);
    else if (attrb == "CenterY") return (isNumber(value) && height <= 2 * stoi(value) && stoi(value) > 0);
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}
void Ellipse::setAttrb(string attrb, string value) {
    if (attrb == "Width") width = stoi(value);
    else if (attrb == "Height") height = stoi(value);
    else if (attrb == "CenterX") center.x = stoi(value);
    else if (attrb == "CenterY") center.y = stoi(value);
    else if (attrb == "DrawSymbol") drawSym = value[0];
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
int16_t Line::getLen() { return len; }
string Line::getDir() { return dir; }
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
    }
    else if (dir == "Vertical") {
        for (int y = 0; y < len; y++) {
            destCoord.Y = currentY + y;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << drawSym;
        }
    }
    cout << endl;
    currentY = destCoord.Y + 1;

}

bool Line::isValidShape() {
    return (len > 0 && dir != "" && drawSym != '\0');
}

bool Line::isValidAttrb(string attrb) {
    for (auto i : attributes) {
        if (i == attrb) return TRUE;
    }
    return FALSE;
}
bool Line::isValidValue(string attrb, string value) {
    if (attrb == "Length") return (isNumber(value) && stoi(value) > 0);
    else if (attrb == "Direction") {
        for (auto i : direction) return (value == i);
    }
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}
void Line::setAttrb(string attrb, string value) {
    if (attrb == "Length") len = stoi(value);
    else if (attrb == "Direction") dir = value;
    else if (attrb == "DrawSymbol") drawSym = value[0];

}

//UIHandler
/*UIHandler::UIHandler(int y) { currentY = y; };
static UIHandler getInstance() {};
void UIHandler::draw(vector<Shape*> shapes) {
    for (auto shape : shapes) {
        shape->draw();
    }
    currentY = 0;
}*/

void UIHandler::showOption() {
    cout << "Menu:\n" << "1. Input text.\n" << "2. Draw.\n" << "3. Open file.\n" << "4. End session.\n";
    cout << "Please enter your option: ";
}

void UIHandler::showGuide(int16_t opt) {
    switch (opt) {
    case 1:
        cout << "Please enter your text. Remember these following rules: \n" << "1. Name of objects must be in []  \n2. Enter 'ET' at the end of your text\n";
        break;
    case 3:
        cout << "Please enter your file path: ";
        break;
    case 4:
        cout << "Exiting...";
        break;
    }
}

void UIHandler::showMessage(int16_t i) {
    switch (i) {
    case 0:
        cout << "Your shape is created successfully\n";
        break;
    case -1:
        cout << "Error: Name must be inputted before Type.\n";
        break;
    case -2:
        cout << "Error: Type must be inputted before Attributes.\n";
        break;
    case -3:
        cout << "Invalid shape type.\n";
        break;
    case -4:
        cout << "Error: Invalid attributes.\n";
        break;
    case -5:
        cout << "Error: Invalid attribute values.\n";
        break;
    case -6:
        cout << "Error: Cannot input new object when not complete previous object.\n";
        break;
    case -7:
        cout << "Warning: Your object is not completed. If you exit, your data will be lost? Do you still want to exit? (Y/N) ";
        break;
    case -8:
        cout << "Cannot open your file!.\n";
        break;
    case -9:
        cout << "Your file content is invalid. Please modify it. \n";
        break;
    default:
        cout << "Unknown error.\n";
    }
}

int16_t UIHandler::getOption() {
    int16_t temp;
    cin >> temp;
    return temp;
}


void UIHandler::draw() {
    system("cls");
    vector<Shape*> shapes = Storage::getShape();
    for (auto i : shapes) {
        i->draw();
    }
    currentY = 0;
    cout << "\nPress enter to return to menu.";
}

//Input Handler

/*
* return 4: End of text.
* return 3: Attribute value is inputted successfully.
* return 2: Type is inputted succesfully
* return 1: Name is inputted successfully,
* return 0: Shape is created successfully.
* return -1: Error: Name must be inputted before Type.
* return -2: Error: Type must be inputted before Attributes.
* return -3: Error: Invalid shape type.
* return -4: Error: Invalid attributes.
* return -5: Error: Invalid attribute values.
* return -6: Error: Cannot input new object when not complete previous object.
* return -7: Warning: Your object is not completed. If you exit, your data will be lost? Do you still want to exit? (Y/N)
*/
int16_t InputHandler::handleInputLine(string in) {

    if (in == "ET") {
        if (shape != NULL) {return -7; }
        else {
            END_TEXT = TRUE;
            return 4;
        }
    }
    else {
        if (in[0] == '[') {
            if (END_OBJ) {
                for (uint16_t i = 1; i < in.length() - 1; i++) { name += in[i]; } //assign name
                END_OBJ = FALSE;
                //cout << "Object init: " << name << endl;
                return 1;
            }
            else return -6;
        }
        else {
            key = split(in, " = ")[0];
            value = split(in, " = ")[1];
            if (key == "Type") {
                if (name == "") return -1; //if no name is inputted previously
                else {
                    if (Shape::isValidShapeType(value)) {
                        type = value;
                        shape = Factory::createShape(type);
                        shape->setName(name);
                        shape->setType(type);          
                        return 2;
                    }
                    else return -3;
                }
            }
            else {
                if (type == "") return -2;
                else {
                    if (shape->isValidAttrb(key)) {
                        if (shape->isValidValue(key, value)) {
                            shape->setAttrb(key, value);
                            cout << "Attribute init: " << key << " = " << value << endl;
                            cout << "Shape's attribute: " << shape->getHeight() << ' ' << shape->getWidth() << ' ' << shape->getTriType() << endl;
                            if (shape->isValidShape()) {
                                Storage::addShape(shape);
                                END_OBJ = TRUE;
                                name.clear();
                                type.clear();
                                key.clear();
                                value.clear();
                                shape = NULL;
                                return 0;
                            }
                            else return 3;
                        }
                        else return -5;
                    }
                    else return -4;
                }
            }
        }
    }
}

void InputHandler::handleInputAll() {
    END_TEXT = FALSE;
    do {
        getline(cin, in);
        status = handleInputLine(in);
        if (status <= 0 && status >= -7) UIHandler::showMessage(status);
        if (status == -7) {
            getline(cin, in);
            if (in == "Y") {
                END_TEXT = TRUE;
                END_OBJ = TRUE;
                name.clear();
                type.clear();
                key.clear();
                value.clear();
                Factory::deleteShape(shape);
                system("cls");
                break;
            }
            else if (in == "N") { ; }
        }
    } while (status != 4);
}

void InputHandler::clearValue() {
    name.clear();
    type.clear();
    key.clear();
    value.clear();
    END_OBJ = TRUE;
    END_TEXT = TRUE;
    Factory::deleteShape(shape);
    for (auto i : shapes) { delete(i); }
    shape = NULL;
}


/*int16_t InputHandler::handleInputFile() {
    string path;
    getline(cin, path);
    fstream myFile;
    myFile.open(path, ios::out);
    if (!myFile) 
        return -1;
    else {
        while (getline(myFile, in)) {
            if (in[0] == '[') {
                if (END_OBJ) {
                    for (uint16_t i = 1; i < in.length() - 1; i++) { name += in[i]; }
                    END_OBJ = FALSE;
                }
                else { clearValue(); return -2; }
            }
            else {
                key = split(in, " = ")[0];
                value = split(in, " = ")[1];
                if (key == "Type") {
                    if (name == "") { clearValue();  return -2; }
                    else {
                        if (Shape::isValidShapeType(value)) {
                            type = value;
                            shape = Factory::createShape(type);
                            shape->setName(name);
                            shape->setType(type);
                        }
                        else { clearValue(); return -2; }
                    }
                }
                else {
                    if (type == "") { clearValue();  return -2; }
                    else {
                        if (shape->isValidAttrb(key)) {
                            if (shape->isValidValue(key, value)) {
                                shape->setAttrb(key, value);
                                if (shape->isValidShape()) {
                                    shapes.push_back(shape);
                                    END_OBJ = TRUE;
                                    name.clear();
                                    type.clear();
                                    key.clear();
                                    value.clear();
                                    shape = NULL;
                                }
                            }
                            else { clearValue(); return -2; }
                        }
                        else { clearValue(); return -2; }
                    }
                }
            }
        }
        for (auto i : shapes) { Storage::addShape(i); }
        myFile.close();
        return 0;
    }
}*/

void InputHandler::handleInputFile() {
    string path;
    getline(cin, path);
    ifstream myFile;
    myFile.open(path, ios::out);
    if (!myFile) UIHandler::showMessage(-8);
    else {
        cout << "Read file successfully.\n\n";
        while (getline(myFile, in)) {
            handleInputLine(in);
        }
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

void Factory::deleteShape(Shape* shape) {
    delete shape;
}

//Methods of 'Storage' classs
vector<Shape*> Storage::shapeList;
void Storage::addShape(Shape* shape) { shapeList.push_back(shape); }
vector<Shape*> Storage::getShape() { return shapeList; }

//add function clearShape()