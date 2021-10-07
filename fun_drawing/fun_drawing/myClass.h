#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

namespace T {

    struct Point {
        int16_t x;
        int16_t y;
    };

    class Factory {
        public:
            Shape* createShape(string) {};
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

    class Shape {
        private:
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
            virtual void errorChecking();
            virtual void draw();
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
            string type;
        public:
            void setWidth(int16_t w);
            void setHeight(int16_t h);
            void setType(string str);
            int16_t getWidth();
            int16_t getHeight();
            string getType();
    };

    class Ellipse : public Shape {
        private:
            Point center;
            int16_t a;
            int16_t b;
        public:
            void setCenter(int16_t x, int16_t y);
            void setAxisLen(int16_t x, int16_t y);
            Point getCenter();
            int16_t getMajor();
            int16_t getMinor();
    };

    class Line : public Shape {
        private:
            Point startPos;
            int16_t len;
            int16_t dir;
        public:
            void setStartPos(int16_t x, int16_t y);
            void setLen(int16_t num);
            void setDir(int16_t num);
            Point getStartPos();
            int16_t getLen();
            int16_t getDir();
    };
}