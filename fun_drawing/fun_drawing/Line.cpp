#include "Line.h"

Line::Line() {
    len = -1000;
    dir = "\0";
}
Line::Line(int16_t l, string d) {
    len = l;
    dir = d;
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
        for (auto i : direction)
            if (value == i) return TRUE;
        return FALSE;
    }
    else if (attrb == "DrawSymbol") return (value.length() == 1);
    else return FALSE;
}

vector<string> Line::emptyAttrbs() {
    vector<string> res;
    if (len == -1000)
        res.push_back("Length");
    if (dir == "\0")
        res.push_back("Direction");
    if (drawSym == '\0')
        res.push_back("DrawSymbol");
    return res;
}

void Line::setAttrb(string attrb, string value) {
    if (attrb == "Length" && isNumber(value)) len = stoi(value);
    else if (attrb == "Direction" && (value == "Horizontal") || value == "Vertical") dir = value;
    else if (attrb == "DrawSymbol" && value.length() == 1) drawSym = value[0];

}