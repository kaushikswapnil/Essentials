// Executable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "..\Essentials\SmartEnum.h"

SMARTENUM_T(Color, int, Red, Green, Blue);

int main()
{   
    Color color = Color::Red;
    int a = -1;
    switch (color)
    {
    case 0:
        a = 0;
        break;
    case 1:
        a = 1;
        break;
    case 2:
        a = 2;
        break;
    }
    std::cout << color << "\n" << Color::Green << "\n" << a << "\n";
}
