#include "InputHandler.h"

//C:\Users\ADMIN\Desktop\TestData\TD3.txt

InputHandler* InputHandler::instance = NULL; //definition of static member.

InputHandler* InputHandler::getInstance() {
    if (instance == NULL) instance = new InputHandler();
    return instance;
}


int16_t InputHandler::splitLine(string userInput) {
    if (userInput[0] == '[') {
        if (name != "") {
            rawData.push_back(mapData);
            mapData.clear();
        }
        name.clear();
        type.clear();
        key.clear();
        value.clear();
        for (uint16_t i = 1; i < userInput.length() - 1; i++) {
            name += userInput[i];
        }
        mapData.insert(pair<string, string>("Name", name));
        return 1;
    }
    else {
        //If there is no name inputted at the beginning, ignore until [...] read.
        if (name.empty()) return -1;
        else {
            if (split(userInput, " = ").size() != 2)
                return -2;
            else {
                key = split(userInput, " = ")[0];
                value = split(userInput, " = ")[1];
                mapData.insert(pair<string, string>(key, value));
                return 0;
            }
        }
    }
}

void InputHandler::filterAndSaveData() {
    for (uint16_t i = 0; i < rawData.size(); i++) {
        shape = Factory::createShape(rawData[i]["Type"]);
        shape->setName(rawData[i]["Name"]);
        shape->setType(rawData[i]["Type"]);
        if (!Shape::isValidShapeType(rawData[i]["Type"]))
            continue;

        for (std::map<string, string>::iterator itr = rawData[i].begin(); itr != rawData[i].end(); itr++) {
            if (itr->first == "Name" || itr->first == "Type")
                continue;
            else {
                if (shape->isValidAttrb(itr->first))
                    if (shape->isValidValue(itr->first, itr->second))
                        shape->setAttrb(itr->first, itr->second);
            }
        }

        bool sameNameFlag = FALSE;

        if (shape->isValidShape()) {
            for (int j = 0; j < Storage::getShape().size(); j++) {
                if (Storage::getShape()[j]->getName() == rawData[i]["Name"]) {
                    sameNameFlag = TRUE;
                    char q = '\0';
                    while (q != 'Y' && q != 'N') {
                        cout << "'" << rawData[j]["Name"] << "' already exists. Do you want to overwrite? (Y/N)  ";
                        cin >> q;

                        if (q == 'Y') {
                            vector<Shape*>::iterator itr = Storage::getShape().begin() + j;
                            delete(Storage::getShape()[j]);
                            Storage::getShape().erase(itr);
                            rawData.erase(rawData.begin() + i);
                            Storage::addShape(shape);
                            i--;
                            j--;
                        }
                        else if (q == 'N')
                            rawData.erase(rawData.begin() + i);
                    }
                    break;
                }
            }
            if (!sameNameFlag) {
                rawData.erase(rawData.begin() + i);
                Storage::addShape(shape);
                i--;
            }
        }
    }
}

void InputHandler::handleInvalidShapes() {
    for (auto map : rawData) {
        cout << endl << map["Name"] << ": failed to draw due to following error(s):" << endl;
        if (Shape::isValidShapeType(map["Type"])) {
            shape = Factory::createShape(map["Type"]);
            for (std::map<string, string>::iterator itr = map.begin(); itr != map.end(); itr++) {
                if (itr->first == "Name" || itr->first == "Type")
                    continue;
                else {
                    if (!shape->isValidAttrb(itr->first));
                        //cout << "\t+ Warning: '" << itr->first << "' is not an attribute of type '" << map["Type"] << "'.";
                    else {
                        shape->setAttrb(itr->first, itr->second);
                        if (!shape->isValidValue(itr->first, itr->second))
                            cout << "\t+ Invalid value for '" << itr->first << "': " << itr->second << "." << endl; 
                            //cout << "'" << itr->first << "' must be a positive integer.\n";
                    }    
                }
            }
            if (shape->emptyAttrbs().size() > 0) {
                cout << "\t+ Attribute(s) is(are) missing value:    ";
                for (auto emptyAttrb : shape->emptyAttrbs()) {
                    cout << "'" << emptyAttrb << "'    ";
                }
                cout << endl;
            }
        }
        else {
            cout << "\t+ Invalid shape type: '" << map["Type"];
            cout << "'. Shape type must be one of the following types: Rectangle, Triangle, Ellipse or Line.\n";
        }
    }
}

void InputHandler::handleInputFile() {
    getline(cin, filePath);
    int16_t currentLine = 0; //track current reading line.
    int16_t status = 0; //status of current reading line.
    string preName; //name of previous shape.
    ifstream myFile;
    bool isValidShape = FALSE;
    myFile.open(filePath, ios::out);
    if (!myFile) cout << "Cannot open file!\n";
    else {
        cout << "\nOpen file successfully.\n\n";

        while (getline(myFile, fileLine)) {
            currentLine++;
            status = splitLine(fileLine);
            if (status == -1) cout << "Line " << currentLine << ": Name must be inputted first.\n";
            else if (status == -2) cout << "Line " << currentLine << ": Wrong format input.\n";
        }

        rawData.push_back(InputHandler::getInstance()->mapData);
        filterAndSaveData();
    }
}