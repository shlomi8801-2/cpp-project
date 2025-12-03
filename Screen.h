#pragma once
#include "Console.h"
#include <cstddef>
#include <iostream>
#include "Blocks.h"
#include "Player.h"
#include <cstddef> // for size_t and other standard c things

class Screen {
    int startx, starty;
    int gameWidth, gameHeight;
    object screen[ScreenSize::MAX_X][ScreenSize::MAX_Y];

public:
    Screen(){
        // screen = new object[ScreenSize::MAX_X][ScreenSize::MAX_Y];
    }
    void clear();
    void drawAt(int x, int y, char sprite);
    void drawObject(int x, int y, const object& obj);
    void drawLegend(const std::string& inventoryInfo);
    void refresh();  // Flush output

    // Coordinate conversion helpers
    int getScreenX(int gameX) const { return startx + gameX; }
    int getScreenY(int gameY) const { starty + gameY; }
};
