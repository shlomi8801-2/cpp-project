#pragma once
class Screen;
class Object;
#include "Screen.h"
using namespace std;
class Player
{
    char controlKeys[6];
    Object *inv; // when collecting an item make a copy of it in the heap and save it here after disposing copy it to the screen array and free it
    int vx = 0;  // velocity at x axis
    int vy = 0;  // velocity at y axis
    int x;
    int y;
    int level; // the level of the player currently
    bool canmove=true;
    Screen *grid = nullptr;
    char sprite = 'a';
    enum movement
    {
        right,
        down,
        left,
        up,
        stay,
        dropItem
    };

public:

    Player(int _x, int _y, char const keys[], Screen *_grid,char _sprite='a',int _level=1);
    void move();
    void keyCheck(char key);
    void draw();
    inline Object *getInv() { return inv; }
    void pickupItem(Object *onblock);
    void tick();
    void moveToLevel(int _level);
    int getLevel() {return level;} 
    void unlockMove() {canmove = true;}
    void emptyInv();
    inline int getX() {return x;}
    inline int getY() {return y;}
};


