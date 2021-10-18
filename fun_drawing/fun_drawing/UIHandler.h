#include "Shape.h"
#include "DataHandler.h"

#ifndef UIHandler_H
#define UIHandler_H

class UIHandler {
private:

public:
    static void showOption();
    static void showGuide(int16_t option);
    static void showMessage(int16_t messageCode);
    static int16_t getOption();
    static void draw();
};

#endif