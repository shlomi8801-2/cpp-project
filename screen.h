#pragma once
#include "player.h"
class object{
    int x;
    int y;
    char Sprite;
    bool filled = false; // visible/cannot walk throgh
    // friend ostream& operator<<(ostream& out, const object& s) {
    //     return out << s.sprite;
    // }
    public:
        char getSprite() { return Sprite;}
        bool getfilled() { return filled;}
        void showinfo();
        void setSprite(char c){Sprite = c;}
        void setfilled(bool state){filled = state;}
};
class Screen{
    int startx=0;
    int starty=1;
    const int width = 80;
    const int height = 25;
    object* objarr;
    player* parr[2];
    public:
        Screen();
        void drawDefaultWalls();
        object* getatxy(const int x,const int y);
        void setatxy(const int x, const int y,object* obj);
        void draw();
};
