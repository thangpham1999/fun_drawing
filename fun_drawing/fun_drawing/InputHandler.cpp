#include "InputHandler.h"

InputHandler* InputHandler::instance = NULL; //definition of static member.

InputHandler* InputHandler::getInstance() {
    if (instance == NULL) instance = new InputHandler();
    return instance;
}


/*
* return 3: Attribute value is inputted successfully.
* return 2: Type is inputted succesfully
* return 1: Name is inputted successfully,
* return 0: Shape is created successfully.
* return -1: Error: Name must be inputted first.
* return -2: Error: Type must be inputted right after Name and before Attributes
* return -3: Error: Invalid shape type.
* return -4: Error: Invalid attributes.
* return -5: Error: Invalid attribute values.
* return -6: Error: This name already exists.
* return -7: Error: Wrong input format.
*/
int16_t InputHandler::handleInputLine(string in) {
    if (in[0] == '[') {
        name.clear();
        type.clear();
        key.clear();
        value.clear();
        for (uint16_t i = 1; i < in.length() - 1; i++) {
            name += in[i];  
        }
        for (auto shape : Storage::getShape()) {
            if (name == shape->getName()) {
                return -6;
            }
        }
        return 1;
    }
    else {
        if (name.empty()) return -1;
        else {
            if (in.find(" = ") == string::npos)
                return -7;
            else {
                key = split(in, " = ")[0];
                value = split(in, " = ")[1];
                if (key == "Type") {
                        if (Shape::isValidShapeType(value)) {
                            type = value;
                            shape = Factory::createShape(type);
                            shape->setName(name);
                            shape->setType(type);
                            return 2;
                        }
                        else return -3;
                }
                else {
                    if (type.empty()) return -2;
                    else {
                        if (shape->isValidAttrb(key)) {
                            if (shape->isValidValue(key, value)) {
                                shape->setAttrb(key, value);
                                if (shape->isValidShape()) {
                                    Storage::addShape(shape);
                                    END_OBJ = TRUE;
                                    shape = NULL;
                                    return 0;
                                }
                                else return 3;
                            }
                            else return -5;
                        }
                        else return -4;
                    }
                }
            }
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
    if (!myFile) UIHandler::showMessage(-8);
    else {
        cout << "\nOpen file successfully.\n\n";

        while (getline(myFile, fileLine)) {
            currentLine++;
            preName = name;
            status = handleInputLine(fileLine);
            if (status < 0)
                errors.insert(pair<int16_t, int16_t>(currentLine, status));
            else if (status == 0) {
                isValidShape = TRUE;
                shapeStatuses.insert(pair<string, bool>(preName, TRUE));
            }
            if (status == 1 && isValidShape == FALSE && preName != "") {
                shapeStatuses.insert(pair<string, bool>(preName, FALSE));
                isValidShape = FALSE;
            }
            
        }

        if (status == 0)
            shapeStatuses.insert(pair<string, bool>(preName, TRUE));
        else
            shapeStatuses.insert(pair<string, bool>(preName, FALSE));

        cout << "-Error:\n";

        for (map<int16_t, int16_t>::iterator errorItr = errors.begin(); errorItr != errors.end(); errorItr++) {
            cout << " \t Line " << errorItr->first << ": ";
            UIHandler::showMessage(errorItr->second);
        }

        cout << "\n\n" << "-Result:\n";

        for (map<string, bool>::iterator shapeStatusesItr = shapeStatuses.begin(); shapeStatusesItr != shapeStatuses.end(); shapeStatusesItr++) {
            if (shapeStatusesItr->second)
                cout << "\t" << shapeStatusesItr->first << " is created successfully.\n";
            else
                cout << "\t" << shapeStatusesItr->first << " cannot be created due to errors.\n";
        }

        cout << "\n\n";
    }
} 