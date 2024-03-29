// Executable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SmartEnum.h"
#include "Assertion.h"
#include "LogSystem.h"
#include "Profiler.h"

SMARTENUM(Color, Red, Green, Blue);

int main()
{   
    SCOPEDPROFILE(main);
    Color color = Color::Red;
    int a = -1;
    switch (color)
    {
    case Color::Red:
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

	SOFTASSERT(a != 0, "Sup");
	LOG("TestLog from main");
}
