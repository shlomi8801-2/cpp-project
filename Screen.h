#pragma once
#include "Object.h"
#include "Player.h"
#include <cstddef> // for size_t and other standard c things
#include "Constants.h"

class Player;


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
    int* currLevel;
    Object* ticking[10] = {0};

public:
    
    inline int getstartx() { return startx; }
    inline int getstarty() { return starty; }
    Screen(int* clevel){currLevel = clevel;}
    void drawDefaultWalls();
    Object *getatxy(const int x, const int y);
    void setatxy(const int x, const int y, const Object *obj);
    void draw();
    bool canMoveTo(const int x, const int y, Player* p=0);
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
    void checkPlayersLevel(); // checking current pkayers levels to draw the new level if needed
    inline int getCurrentLevel() {return *currLevel;}
    inline gameState getGaneState() { return currState;}
    inline void setGameState(gameState state) {currState = state;}
    static bool inScreenBonds(const int x,const int y);
    void startTicking(Object* obj);
    void drawOneObjectAtxy(int x, int y);
};
