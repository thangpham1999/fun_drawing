#include "Rectangle.h"

Rec::Rec(int16_t a, int16_t b) {
    width = a;
    height = b;
}

Rec::Rec() {
    width = -1000;
    height = -1000;
    drawSym = '\0';
}
//void Rectangle::setWidth(int16_t w) { width = w; }

//void Rectangle::setHeight(int16_t h) { height = h; }

int16_t Rec::getWidth() { return width; }

int16_t Rec::getHeight() { return height; }

void Rec::draw() {
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

bool Rec::isValidShape() {
    return (width > 0 && height > 0 && drawSym != '\0');
}

bool Rec::isValidAttrb(string attrb) {
    for (auto i : attributes) {
        if (i == attrb) return TRUE;
    }
    return FALSE;
}

bool Rec::isValidValue(string attrb, string value) {
    if (attrb == "Width" || attrb == "Height") return (isNumber(value) && stoi(value) > 0);
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}

vector<string> Rec::emptyAttrbs() {
    vector<string> res;

    if (width == -1000)
        res.push_back("Width");
    if (height == -1000)
        res.push_back("Height");
    if (drawSym == '\0')
        res.push_back("DrawSymbol");
    return res;
}

void Rec::setAttrb(string attrb, string value) {
    if (attrb == "Width" && isNumber(value)) width = stoi(value);
    else if (attrb == "Height" && isNumber(value)) height = stoi(value);
    else if (attrb == "DrawSymbol" && value.length() == 1) drawSym = value[0];
}
