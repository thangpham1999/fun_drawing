#include <windows.h>

int main(void){
//initialize objects for cursor manipulation
    HANDLE hStdout;
    LPCTSTR c;
    DWORD len;
    COORD destCoord;
    LPDWORD p;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int a = 0;

    //position cursor at start of window
    len = 1;
    c = "*";
    destCoord.X = 1;
    destCoord.Y = 1;
    WriteConsoleOutputCharacter(hStdout, c, len, destCoord, p);
    c = "+";
    destCoord.X = 3;
    destCoord.Y = 3;
    WriteConsoleOutputCharacter(hStdout, c, len, destCoord, p);
}