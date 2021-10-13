#include "Shape.h"
#include "DataHandler.h"

#ifndef UIHandler_H
#define UIHandler_H

class UIHandler {
private:
    //static UIHandler instance;

public:
    //UIHandler(int y);
    //static UIHandler getInstance();
    static void draw(vector<Shape*> shapes);
    static void showOption();
    static void showGuide(int16_t opt);
    static void showMessage(int16_t i);
    static int16_t getOption();
    static void draw();
};

#endif