#include "Ellipse.h"

Ellipse::Ellipse() {
    center.x = center.y = width = height = 0;
}
Ellipse::Ellipse(int16_t x, int16_t y, int16_t w, int16_t h) {
    center.x = x;
    center.y = y;
    width = w;
    height = h;
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