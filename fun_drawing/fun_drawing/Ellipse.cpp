#include "Ellipse.h"

Ell::Ell() {
    center.x = center.y = width = height = 0;
}
Ell::Ell(int16_t x, int16_t y, int16_t w, int16_t h) {
    center.x = x;
    center.y = y;
    width = w;
    height = h;
}

Point Ell::getCenter() { return center; }
int16_t Ell::getWidth() { return width; }
int16_t Ell::getHeight() { return height; }
void Ell::draw() {
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

bool Ell::isValidShape() {
    return (width > 0 && height > 0 && drawSym != '\0' && center.x > 0 && center.y > 0);
}

bool Ell::isValidAttrb(string attrb) {
    for (auto i : attributes) {
        if (i == attrb) return TRUE;
    }
    return FALSE;
}
bool Ell::isValidValue(string attrb, string value) {
    if (attrb == "Width" || attrb == "Height") return (isNumber(value) && stoi(value) > 0);
    else if (attrb == "CenterX") return (isNumber(value) && width <= 2 * stoi(value) && stoi(value) > 0);
    else if (attrb == "CenterY") return (isNumber(value) && height <= 2 * stoi(value) && stoi(value) > 0);
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}
void Ell::setAttrb(string attrb, string value) {
    if (attrb == "Width") width = stoi(value);
    else if (attrb == "Height") height = stoi(value);
    else if (attrb == "CenterX") center.x = stoi(value);
    else if (attrb == "CenterY") center.y = stoi(value);
    else if (attrb == "DrawSymbol") drawSym = value[0];
}