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

//------------------------------------------------------------
//Methods of 'Rectangle' class
Rectangle::Rectangle(int16_t a, int16_t b) {
    width = a;
    height = b;
}

Rectangle::Rectangle() {
    width = 0;
    height = 0;
}
//void Rectangle::setWidth(int16_t w) { width = w; }

//void Rectangle::setHeight(int16_t h) { height = h; }

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

//------------------------------------------------------------
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
//void Triangle::setWidth(int16_t w) { width = w; }
//void Triangle::setHeight(int16_t h) { height = h; }
//void Triangle::setTriType(string str) { triType = str; }
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
            if (value == i) return TRUE;
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

//------------------------------------------------------------
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
/*void Ellipse::setCenter(int16_t x, int16_t y) {
    center.x = x;
    center.y = y;
}
void Ellipse::setAxisLen(int16_t x, int16_t y) {
    width = x;
    height = y;
}*/

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

//------------------------------------------------------------
//Methods of 'Line' class
Line::Line() {
    len = 0;
    dir = "Horizontal";
}
Line::Line(int16_t l, string d) {
    len = l;
    dir = d;
}
/*void Line::setLen(int16_t num) {
    len = num;
}
void Line::setDir(string str) {
    dir = str;
}*/

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
        for (auto i : direction)
            if (value == i) return TRUE;
        return FALSE;
    }
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}
void Line::setAttrb(string attrb, string value) {
    if (attrb == "Length") len = stoi(value);
    else if (attrb == "Direction") dir = value;
    else if (attrb == "DrawSymbol") drawSym = value[0];

}