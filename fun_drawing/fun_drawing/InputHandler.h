#include "Shape.h"
#include "DataHandler.h"
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

    void handleInputFile();

    int16_t splitLine(string userInput);
    void filterAndSaveData();

    vector<map<string, string>> rawData;
    map<string, string> mapData;

    void handleInvalidShapes();
};

#endif