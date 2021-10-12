#include "InputHandler.h"

/*
* return 4: End of text.
* return 3: Attribute value is inputted successfully.
* return 2: Type is inputted succesfully
* return 1: Name is inputted successfully,
* return 0: Shape is created successfully.
* return -1: Error: Name must be inputted before Type.
* return -2: Error: Type must be inputted before Attributes.
* return -3: Error: Invalid shape type.
* return -4: Error: Invalid attributes.
* return -5: Error: Invalid attribute values.
* return -6: Error: Cannot input new object when not complete previous object.
* return -7: Warning: Your object is not completed. If you exit, your data will be lost? Do you still want to exit? (Y/N)
*/
int16_t InputHandler::handleInputLine(string in) {

    if (in == "ET") {
        if (shape != NULL) { return -7; }
        else {
            END_TEXT = TRUE;
            return 4;
        }
    }
    else {
        if (in[0] == '[') {
            if (END_OBJ) {
                for (uint16_t i = 1; i < in.length() - 1; i++) { name += in[i]; } //assign name
                END_OBJ = FALSE;
                //cout << "Object init: " << name << endl;
                return 1;
            }
            else return -6;
        }
        else {
            key = split(in, " = ")[0];
            value = split(in, " = ")[1];
            if (key == "Type") {
                if (name == "") return -1; //if no name is inputted previously
                else {
                    if (Shape::isValidShapeType(value)) {
                        type = value;
                        shape = Factory::createShape(type);
                        shape->setName(name);
                        shape->setType(type);
                        return 2;
                    }
                    else return -3;
                }
            }
            else {
                if (type == "") return -2;
                else {
                    if (shape->isValidAttrb(key)) {
                        if (shape->isValidValue(key, value)) {
                            shape->setAttrb(key, value);
                            //cout << "Attribute init: " << key << " = " << value << endl;
                            //cout << "Shape's attribute: " << shape->getHeight() << ' ' << shape->getWidth() << ' ' << shape->getTriType() << endl;
                            if (shape->isValidShape()) {
                                Storage::addShape(shape);
                                END_OBJ = TRUE;
                                name.clear();
                                type.clear();
                                key.clear();
                                value.clear();
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

void InputHandler::handleInputAll() {
    END_TEXT = FALSE;
    do {
        getline(cin, in);
        status = handleInputLine(in);
        if (status <= 0 && status >= -7) UIHandler::showMessage(status);
        if (status == -7) {
            getline(cin, in);
            if (in == "Y") {
                END_TEXT = TRUE;
                END_OBJ = TRUE;
                name.clear();
                type.clear();
                key.clear();
                value.clear();
                Factory::deleteShape(shape);
                system("cls");
                break;
            }
            else if (in == "N") { ; }
        }
    } while (status != 4);
}

/*void InputHandler::clearValue() {
    name.clear();
    type.clear();
    key.clear();
    value.clear();
    END_OBJ = TRUE;
    END_TEXT = TRUE;
    Factory::deleteShape(shape);
    for (auto i : shapes) { delete(i); }
    shape = NULL;
}*/


/*int16_t InputHandler::handleInputFile() {
    string path;
    getline(cin, path);
    fstream myFile;
    myFile.open(path, ios::out);
    if (!myFile)
        return -1;
    else {
        while (getline(myFile, in)) {
            if (in[0] == '[') {
                if (END_OBJ) {
                    for (uint16_t i = 1; i < in.length() - 1; i++) { name += in[i]; }
                    END_OBJ = FALSE;
                }
                else { clearValue(); return -2; }
            }
            else {
                key = split(in, " = ")[0];
                value = split(in, " = ")[1];
                if (key == "Type") {
                    if (name == "") { clearValue();  return -2; }
                    else {
                        if (Shape::isValidShapeType(value)) {
                            type = value;
                            shape = Factory::createShape(type);
                            shape->setName(name);
                            shape->setType(type);
                        }
                        else { clearValue(); return -2; }
                    }
                }
                else {
                    if (type == "") { clearValue();  return -2; }
                    else {
                        if (shape->isValidAttrb(key)) {
                            if (shape->isValidValue(key, value)) {
                                shape->setAttrb(key, value);
                                if (shape->isValidShape()) {
                                    shapes.push_back(shape);
                                    END_OBJ = TRUE;
                                    name.clear();
                                    type.clear();
                                    key.clear();
                                    value.clear();
                                    shape = NULL;
                                }
                            }
                            else { clearValue(); return -2; }
                        }
                        else { clearValue(); return -2; }
                    }
                }
            }
        }
        for (auto i : shapes) { Storage::addShape(i); }
        myFile.close();
        return 0;
    }
}*/

void InputHandler::handleInputFile() {
    string path;
    getline(cin, path);
    ifstream myFile;
    myFile.open(path, ios::out);
    if (!myFile) UIHandler::showMessage(-8);
    else {
        cout << "Read file successfully.\n\n";
        while (getline(myFile, in)) {
            handleInputLine(in);
        }
    }
}