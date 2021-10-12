#include "UIHandler.h"

void UIHandler::showOption() {
    cout << "Menu:\n" << "1. Input text.\n" << "2. Draw.\n" << "3. Open file.\n" << "4. End session.\n";
    cout << "Please enter your option: ";
}

void UIHandler::showGuide(int16_t opt) {
    switch (opt) {
    case 1:
        cout << "Please enter your text. Remember these following rules: \n" << "1. Name of objects must be in []  \n2. Enter 'ET' at the end of your text\n";
        break;
    case 3:
        cout << "Please enter your file path: ";
        break;
    case 4:
        cout << "Exiting...";
        break;
    }
}

void UIHandler::showMessage(int16_t i) {
    switch (i) {
    case 0:
        cout << "Your shape is created successfully\n";
        break;
    case -1:
        cout << "Error: Name must be inputted before Type.\n";
        break;
    case -2:
        cout << "Error: Type must be inputted before Attributes.\n";
        break;
    case -3:
        cout << "Invalid shape type.\n";
        break;
    case -4:
        cout << "Error: Invalid attributes.\n";
        break;
    case -5:
        cout << "Error: Invalid attribute values.\n";
        break;
    case -6:
        cout << "Error: Cannot input new object when not complete previous object.\n";
        break;
    case -7:
        cout << "Warning: Your object is not completed. If you exit, your data will be lost? Do you still want to exit? (Y/N) ";
        break;
    case -8:
        cout << "Cannot open your file!.\n";
        break;
    case -9:
        cout << "Your file content is invalid. Please modify it. \n";
        break;
    default:
        cout << "Unknown error.\n";
    }
}

int16_t UIHandler::getOption() {
    int16_t temp;
    cin >> temp;
    return temp;
}


void UIHandler::draw() {
    system("cls");
    vector<Shape*> shapes = Storage::getShape();
    for (auto i : shapes) {
        i->draw();
    }
    currentY = 0;
    cout << "\nPress enter to return to menu.";
}