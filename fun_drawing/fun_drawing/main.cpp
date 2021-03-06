// fun_drawing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Shape.h"
#include "UIHandler.h"
#include "InputHandler.h"
#include "fun_drawing.h"


using namespace std;
//using namespace T;

int main(void)
{
    
    int16_t opt;
    string waiting;

    do {
        UIHandler::showOption();
        opt = UIHandler::getOption();
        cin.ignore();
        UIHandler::showGuide(opt);
        switch (opt) {
        case 1:
            InputHandler::getInstance()->handleInputFile();
            cout << "\n\n\n\nPress enter to return to menu.";
            getline(cin, waiting);
            system("cls");
            break;
        case 2:
            UIHandler::draw();
            cout << "\n\n\n\nPress enter to return to menu.";
            getline(cin, waiting);
            system("cls");
            break;
        case 3:
            break;
        default:
            cout << "Invalid option. Please re-enter your option.\n";
        }
    } while (opt != 3);

    /*ifstream myFile;
    string filePath;
    string inputLine;
    int currentLine = 0;
    int status = 0;
    getline(cin, filePath);
    myFile.open(filePath, ios::out);

    while (getline(myFile, inputLine)) {
        currentLine++;
        status = InputHandler::getInstance()->splitLine(inputLine);
        //cout << "Line " << currentLine << " : " << status << endl;
    }

    InputHandler::getInstance()->rawData.push_back(InputHandler::getInstance()->mapData);

    for (auto shape : InputHandler::getInstance()->rawData) {
        for (map<string, string>::iterator itr = shape.begin(); itr != shape.end(); itr++) {
            cout << itr->first << " " << itr->second << endl;
        }
    }*/
}


//