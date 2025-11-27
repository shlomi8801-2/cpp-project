#pragma once
class player;
#include "player.h"
class object{
    int x;
    int y;
    char Sprite;
    bool filled = false; // does it block the player?
    bool visible = false; // visible
    // friend ostream& operator<<(ostream& out, const object& s) {
    //     return out << s.sprite;
    // }
    public:
        char getSprite() { return Sprite;}
        bool getvisible() { return visible;}
        bool getfilled() { return filled;}
        void showinfo();
        void setSprite(char c){Sprite = c;}
        void setvisible(bool state){visible = state;}
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
        inline int getstartx(){return startx;}
                inline int getstarty(){return starty;}

        Screen();
        void drawDefaultWalls();
        object* getatxy(const int x,const int y);
        void setatxy(const int x, const int y,const object* obj);
        void draw();
};
