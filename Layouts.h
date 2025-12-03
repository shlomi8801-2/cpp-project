#pragma once
#include "Screen.h"

namespace levels
{
    void changeLayout(int levelNum, Screen *screen);
    void level1(Screen *screen);
    void level2(Screen *screen);
    

    // Helper to load by number
    void changeLayout(int levelNum, Screen *screen);
    void generateLayoutFromArr(const char* arr[MAX_X], Object outArr[][22]);
}

