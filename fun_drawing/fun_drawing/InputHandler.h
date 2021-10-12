#include "Shape.h"
#include "DataHandler.h"
#include "UIHandler.h"
#include <fstream>
using namespace std;

#ifndef InputHandler_H
#define InputHandler_H

class InputHandler {
private:
    string in;
    string name;
    string type;
    Shape* shape = NULL;
    vector<Shape*> shapes;
    string key;
    string value;
    int16_t status;
    int16_t handleInputLine(string in);
    bool END_OBJ = TRUE;
    bool END_TEXT = TRUE;
    //void clearValue();
public:
    void handleInputAll();
    //int16_t handleInputFile();
    void handleInputFile();
};

#endif