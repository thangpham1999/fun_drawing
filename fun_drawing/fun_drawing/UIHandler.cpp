#include "UIHandler.h"

void UIHandler::showOption() {
    cout << "Menu:\n" << "1. Open file.\n" << "2. Draw.\n" << "3. Quit.\n";
    cout << "Please enter your option: ";
}

void UIHandler::showGuide(int16_t option) {
    switch (option) {
    case 1:
        cout << "Please enter your file path: ";
        break;
    case 3:
        cout << "Exiting...";
        break;
    }
}

void UIHandler::showMessage(int16_t messageCode) {
    switch (messageCode) {
    case 0:
        cout << "Your shape is created successfully\n\n";
        break;
    case -1:
        cout << "Error: Name must be inputted first.\n";
        break;
    case -2:
        cout << "Error: Type must be inputted right after Name and before Attributes\n";
        break;
    case -3:
        cout << "Error: Invalid shape type.\n";
        break;
    case -4:
        cout << "Error: Invalid attributes.\n";
        break;
    case -5:
        cout << "Error: Invalid attribute values.\n";
        break;
    case -6:
        cout << "Error: Name already exists. Please input another name.\n";
        break;
    case -7:
        cout << "Error: Wrong input format.\n";
        break;
    case -8:
        cout << "Cannot open your file!.\n";
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
}