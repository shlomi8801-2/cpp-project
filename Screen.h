#pragma once
#include "Console.h"
#include <cstddef>
#include <iostream>
#include "Blocks.h"
#include "Player.h"
#include <cstddef> // for size_t and other standard c things

class Player;

class Screen{
    int startx=0;
    int starty=1;
    const int width = 80;
    const int height = 25;
    const int legendHeight = 3;
    int gameWidth = 80;
    int gameHeight = height-legendHeight;
    object* objarr;
    Player* parr[2];
    public:
        inline int getstartx(){return startx;}
        inline int getstarty(){return starty;}
        Screen();
        void drawDefaultWalls();
        object* getatxy(const int x,const int y);
        void setatxy(const int x, const int y,const object* obj);
        void draw();
        bool canMoveTo(const int x,const int y);
        void draw_static(const char* layout[], size_t lines);
        void clearScreen();
        void updateLegend(); // also draws it
        inline void setPlayer(unsigned char idx,Player* p) {if (idx>2) return; parr[idx] = p;}
};
