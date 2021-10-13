#include "Triangle.h"

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