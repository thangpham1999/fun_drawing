#include "Rectangle.h"

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