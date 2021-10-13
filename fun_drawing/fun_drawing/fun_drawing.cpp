// fun_drawing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "myClass.h"


using namespace std;
using namespace T;

int main(void)
{
    /*T::Rectangle rec(5, 3);
    rec.setName("Object 1");
    rec.setDrawSym('+');
    rec.draw();

    T::Ellipse ell(25, 5, 50, 10);
    ell.setName("Object 2");
    ell.setDrawSym('=');
    ell.draw();

    T::Line line(5, "Vertical");
    line.setName("Object 3");
    line.setDrawSym('-');
    line.draw();*/

    /*T::Triangle tri(9, 5, "Isosceles right");
    tri.setName("Object 4");
    tri.setDrawSym('*');
    tri.draw();*/

    /*string s;
    InputHandler IH;
    IH.handleInputFile();
    getline(cin, s);
    system("cls");
    UIHandler::draw();*/
    
    InputHandler IH;
    int16_t opt;
    string waiting;

    do {
        UIHandler::showOption();
        opt = UIHandler::getOption();
        cin.ignore();
        UIHandler::showGuide(opt);
        switch (opt) {
        case 1:
            IH.handleInputAll();
            break;
        case 2:
            UIHandler::draw();
            getline(cin, waiting);
            system("cls");
            break;
        case 3:
            IH.handleInputFile();
            break;
        case 4:
            break;
        default:
            cout << "Invalid option. Please re-enter your option.\n";
        }
    } while (opt != 4);


}


//