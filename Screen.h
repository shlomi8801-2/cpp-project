#pragma once
#include "Player.h"
#include <cstddef> // for size_t and other standard c things
#include "Constants.h"
class Player;

class Object
{
    // do we need those now?(we using array...)
    //  int x;
    //  int y;
    char Sprite;
    bool filled = false;  // does it block the player?
    bool visible = false; // visible
    bool pickable = false;
    // friend ostream& operator<<(ostream& out, const Object& s) {
    //     return out << s.sprite;
    // }
    // for the future(if needed) all of the block types in the game after all are less then 256 possibilites so can store in a unsigned char like so: type - door/wall/key/bomb/switch/obstacle/riddle/torch/spring sum: 8+1+8+1+32(possible button id's)+1+32(num of riddles) 1+1=85 = 0101 0101
    // but for now use alot of variables for readability
    int type = 0; // 0 - air/general/wall, 1 - door, 2 - key, 3 - bomb, 4 - switch, 5 - obstacle, 6 - riddle, 7 - torch, 8 - spring
    int doorId;
    int keyId;
    int switchId;
    int riddleId;
    
public:
    Object() {};
    inline Object(char _sprite, bool _filled = false, bool _pickable = false, bool _visible = false, int _type = 0, int _doorId = 0, int _keyId = 0, int _switchId = 0, int _riddleId = 0)
    {
        Sprite = _sprite;
        filled = _filled;
        pickable = _pickable;
        visible = _visible;
        type = _type;
        doorId = _doorId;
        keyId = _keyId;
        switchId = _switchId;
        riddleId = _riddleId;
    }
    char getSprite() { return Sprite; }
    bool getvisible() { return visible; }
    bool getfilled() { return filled; }
    void showinfo();
    void setSprite(char c) { Sprite = c; }
    void setvisible(bool state) { visible = state; }
    void setfilled(bool state) { filled = state; }
    void set(const Object &_obj);
    bool getPickable() { return pickable; }
    void setPickable(bool state) { pickable = state; }
    inline bool isAir() { return (Sprite == ' ') && (filled = false); }
    inline void set(char _sprite, bool _filled, bool _visible)
    {
        Sprite = _sprite;
        filled = _filled;
        visible = _visible;
    }
    Object(const Object &_obj) { this->set(_obj); }
};

class Screen
{
    gameState currState = gameState::mainMenu;
    int startx = 0;
    int starty = 1; 
    const int legendHeight = ScreenSize::LEGEND_HEIGHT;
    const int gameWidth = ScreenSize::MAX_X;
    const int gameHeight = ScreenSize::MAX_Y - legendHeight;
    Object objarr[ScreenSize::MAX_X][ScreenSize::MAX_Y-3];
    Player *parr[2];

public:
    
    inline int getstartx() { return startx; }
    inline int getstarty() { return starty; }
    Screen();
    void drawDefaultWalls();
    Object *getatxy(const int x, const int y);
    void setatxy(const int x, const int y, const Object *obj);
    void draw();
    bool canMoveTo(const int x, const int y);
    void draw_static(const char *layout[], size_t lines);
    void clearScreen();
    void updateLegend(); // also draws it
    void setPlayer(unsigned char idx, Player *p)
    {
        if (idx > 2)
            return;
        parr[idx] = p;
    }
    void tick(); //game update
    void keyCheck(char c);
};
