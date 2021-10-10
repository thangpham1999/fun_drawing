#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

extern HANDLE hStdout;
extern COORD destCoord;
extern int currentY;

vector<string> split(const string& str, const string& delim);

namespace T {

    struct Point {
        int16_t x;
        int16_t y;
    };

    class Shape {
    protected:
        string name;
        string type;
        char drawSym;
    public:
        static const string shapeType[4];
        void setName(string str);
        void setType(string str);
        void setDrawSym(char c);
        string getName();
        string getType();
        char getDrawSym();
        static bool isValidShapeType(string shapeType);
        virtual bool isValidShape() { return TRUE; }
        virtual bool isValidAttrb(string attrb) { return TRUE; }
        virtual bool isValidValue(string attrb, string value) { return TRUE; }
        virtual void setAttrb(string attrb, string value) { ; }
        virtual void draw() { ; }
    };

    class Rectangle : public Shape {
    private:
        int16_t width;
        int16_t height;
        const string attributes[2] = {"Width", "Height"};
    public:
        Rectangle(int16_t a, int16_t b);
        Rectangle();
        void setWidth(int16_t w);
        void setHeight(int16_t h);
        int16_t getWidth();
        int16_t getHeight();
        bool isValidShape();
        bool isValidAttrb(string attrb);
        bool isValidValue(string attrb, string value);
        void setAttrb(string attrb, string value);
        void draw();
    };

    class Triangle : public Shape {
    private:
        int16_t width;
        int16_t height;
        string triType;
        const string attributes[3] = { "Width", "Height", "TriangleType"};
        const string triangleTypes[2] = { "Isosceles right", "Isosceles" };
    public:
        //Triangle(int16_t w, const string t = "Isosceles right");
        //Triangle(int16_t w, int16_t h, const string t = "Isosceles");
        Triangle(int16_t w, int16_t h, string t);
        Triangle();
        void setWidth(int16_t w);
        void setHeight(int16_t h);
        void setTriType(string str);
        int16_t getWidth();
        int16_t getHeight();
        string getTriType();
        void draw();
        bool isValidShape();
        bool isValidAttrb(string attrb);
        bool isValidValue(string attrb, string value);
        void setAttrb(string attrb, string value);
    };

    class Ellipse : public Shape {
    private:
        Point center;
        int16_t width;
        int16_t height;
        const string attributes[3] = { "Width", "Height", "Center"};
    public:
        Ellipse();
        Ellipse(int16_t x, int16_t y, int16_t w, int16_t h);
        void setCenter(int16_t x, int16_t y);
        void setAxisLen(int16_t x, int16_t y);
        Point getCenter();
        int16_t getWidth();
        int16_t getHeight();
        void draw();
        bool isValidShape();
        bool isValidAttrb(string attrb);
        bool isValidValue(string attrb, string value);
        void setAttrb(string attrb, string value);
    };

    class Line : public Shape {
    private:
        int16_t len;
        string dir;
        const string attributes[2] = { "Length", "Direction" };
        const string direction[2] = { "Horizontal", "Vertical" };
    public:
        Line();
        Line(int16_t l, string d);
        void setLen(int16_t num);
        void setDir(string str);
        int16_t getLen();
        string getDir();
        void draw();
        bool isValidShape();
        bool isValidAttrb(string attrb);
        bool isValidValue(string attrb, string value);
        void setAttrb(string attrb, string value);
    };
    
    //Presentation Layer
    class UIHandler {
    private:
        static UIHandler instance;
    public:
        UIHandler(int y);
        static UIHandler getInstance();
        void draw(vector<Shape*> shapes);
        void showOption();
        void showGuide(int16_t opt);
        static void showMessage(int16_t i);
        int16_t getOption();
        string getInputFile();
    };

    //Business Layer
    class InputHandler {
    private:
        string in;
        string name;
        string type;
        Shape* shape;
        string key;
        string value;
        int16_t status;
        int16_t handleInputTextLine(string in);
        bool END_OBJ = TRUE;
        bool END_TEXT = TRUE;
    public:
        void handleInputTextAll();
        void handleInputFile(string path);
    };

    //Data layer
    class Factory {
    public:
        static Shape* createShape(string type);
        static void deleteShape(Shape* shape);
    };

    class Storage {
    private:
        static vector<Shape*> shapeList;
    public:
        static void addShape(Shape* shape);
        static vector<Shape*> getShape();
    };
}