#pragma once
class Screen;
class Object;
#include "screen.h"


class player{
    char controlKeys[6];
    Object* inv; // when collecting an item make a copy of it in the heap and save it here after disposing copy it to the screen array and free it
    int vx =0;//velocity at x axis
    int vy=0; //velocity at y axis
    int x;
    int y;
    Screen* grid = nullptr;
    char sprite = 'a';
    enum movement {
        right,
        down,
        left,
        up,
        stay,
        dropItem
    };
    public:
    player(int _x,int _y,char const keys[],Screen* _grid);
    void move();
    void keyCheck(char key);
    void draw();
    inline Object* getInv() {return inv;}
    void pickupItem(Object* onblock);
};