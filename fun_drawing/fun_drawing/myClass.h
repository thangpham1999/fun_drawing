#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

extern HANDLE hStdout;
extern COORD destCoord;
extern int currentY;

namespace T {

    struct Point {
        int16_t x;
        int16_t y;
    };

    class UIHandler {
    private:
        int currentY;
        static UIHandler instance;
    public:
        UIHandler(int y);
        static UIHandler getInstance();
        void draw(vector<Shape*> shapes);
        void showOption();
    };

    class InputHandler {
    private:
        string type;
        int16_t width = -1;
    public:
        void getInput();

    class Shape {
    protected:
        string name;
        string type;
        char drawSym;
    public:
        void setName(string str);
        void setType(string str);
        void setDrawSym(char c);
        string getName();
        string getType();
        char getDrawSym();
        //virtual void errorChecking();
        virtual void draw() { ; };
    };

    class Factory {
        public:
            Shape* createShape(string type);
    };

    class Storage {
        private:
            vector<Shape*> shapeList;
        public:
            void addShape(Shape* shape);
            vector<Shape*> getShape();
    };

    class System {
        public:
            void displayQuery();
            int16_t getQuery();
            void readConsole();
            void readFile();
    };

    class Rectangle : public Shape {
        private:
            int16_t width;
            int16_t height;
        public:
            Rectangle(int16_t a, int16_t b);
            Rectangle();
            void setWidth(int16_t w);
            void setHeight(int16_t h);
            int16_t getWidth();
            int16_t getHeight();
            void draw();
    };

    class Triangle : public Shape {
        private:
            int16_t width;
            int16_t height;
            string triType;
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
    };

    class Ellipse : public Shape {
        private:
            Point center;
            int16_t width;
            int16_t height;
        public:
            Ellipse();
            Ellipse(int16_t x, int16_t y, int16_t w, int16_t h);
            void setCenter(int16_t x, int16_t y);
            void setAxisLen(int16_t x, int16_t y);
            Point getCenter();
            int16_t getWidth();
            int16_t getHeight();
            void draw();
    };

    class Line : public Shape {
        private:
            int16_t len;
            string dir;
        public:
            Line();
            Line(int16_t l, string d);
            void setLen(int16_t num);
            void setDir(string str);
            int16_t getLen();
            string getDir();
            void draw();
    };
}