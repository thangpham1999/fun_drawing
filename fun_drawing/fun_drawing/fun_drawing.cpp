// fun_drawing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "myClass.h"


using namespace std;
using namespace T;

int main(void)
{
    T::Rectangle rec(5,3);
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
    line.draw();

    T::Triangle tri(9, 5, "Isosceles");
    tri.setName("Object 4");
    tri.setDrawSym('*');
    tri.draw();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
