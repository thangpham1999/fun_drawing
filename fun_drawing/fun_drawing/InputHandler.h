#include "Shape.h"
#include "DataHandler.h"
#include "UIHandler.h"
#include <fstream>
#include <map>
using namespace std;

#ifndef InputHandler_H
#define InputHandler_H

class InputHandler {
private:
    
    //Lazy init of Singleton
    static InputHandler* instance;
    InputHandler() { ; };

    string filePath;
    ifstream myFile;
    string fileLine;
    string name;
    string type;
    Shape* shape = NULL;
    vector<Shape*> shapes;
    string key = "";
    string value = "";
    map<int16_t, int16_t> errors;
    map<string, bool> shapeStatuses;
    
    bool END_OBJ = TRUE;
    //void clearValue();
public:

    static InputHandler* getInstance();
    int16_t handleInputLine(string in);
    void handleInputFile();
};

#endif