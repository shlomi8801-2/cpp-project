#include "console.h"
#include <cstddef>
#include <iostream>
#include "Screen.h"
#include "console.h"
#include "Blocks.h"
#include "Layouts.h"
#include "MainMenu.h"
#include "utils.h"
//later filter those includes


using namespace std;
// use array to store the screen background and have another array for players to draw

//Screen::Screen()
//{
//    // objarr = new Object[ScreenSize::MAX_X][ScreenSize::MAX_Y]; // already sets it in the screen.h file
//    //which saves it in the stack later will move to heap
//
//    // fill the screen with blank objects - no need because it has default values as Object types
//    
//}
Object *Screen::getatxy(const int x, const int y)
{
    // returns nullptr if out of screen
    int idx = y * gameWidth + x;
    return (idx >= 0 && (idx <= gameHeight * gameWidth)) ? &(objarr[x][y]) : nullptr;
}

void Screen::draw_static(const char *layout[], size_t lines)
{
    clrscr();
    for (size_t y = 0; y < lines && y < gameHeight; y++)
    {
        gotoxy(startx, starty + y);

        for (size_t x = 0; layout[y][x] != '\0' && x < gameWidth; x++)
        {
            cout << layout[y][x];
        }
    }
    cout.flush();
}



void Screen::drawDefaultWalls()
{
    // simple walls
    for (int i = 0; i < gameWidth; i++)
    {
        objarr[i][0].set(Blocks::Wall);
        objarr[i][gameHeight - 1].set(Blocks::Wall);
    }
    for (int i = 1; i < gameHeight - 1; i++)
    {
        objarr[0][i].set(Blocks::Wall);
        objarr[gameWidth - 1][i].set(Blocks::Wall);
    }
}

void Screen::setatxy(const int x, const int y, const Object *obj)
{
    // if out of screen doing nothing
    int idx = y * gameWidth + x;
    if (idx >= 0 && idx <= gameHeight * gameWidth) // checking if its in the screen
        objarr[x][y].set(*obj);
}
void Screen::draw()
{
    // draw the whole screen - dont use alot its not optimized only at the start or big object removal
    levels::changeLayout(*currLevel, this);
    clrscr();
    int idx;
    for (int y = 0; y < gameHeight; y++)
    {
        for (int x = 0; x < gameWidth; x++)
        {
            // cout<< x<<","<<y<<"\n";
            idx = y * gameWidth + x;
            if (objarr[x][y].getvisible())
            {
                gotoxy(startx + x, starty + y);
                cout << objarr[x][y].getSprite();
            }
        }
    }
    // don't forget to draw the legend first
    updateLegend();
    cout << flush; // clear the buffer of the screen in case cout missed some characters it forces it to print them somehow i think
}
bool Screen::inScreenBonds(const int x,const int y){
return ((x >= 0 && y >= 0 && x < ScreenSize::MAX_X && y <ScreenSize::MAX_Y - ScreenSize::LEGEND_HEIGHT));
}
bool Screen::canMoveTo(const int x, const int y, Player* p)
{
     //doesn't matter if its 2 if statements or switch case because the special objects that are not pickable are just 
    //door and obstacle
    bool inBonds = inScreenBonds(x,y);// y is -height because the screen starts at 0 0 and shows at x -y
    if (!inBonds)return false;
    Object* target = getatxy(x,y);
    if (target->getfilled()){
        //check here if door obstacle or just normal block
        switch (target->getType()){
            case 1://door
                if(target->canOpenDoor(p)){
                    //do not remove the door because after you dont know which screen to move to
                    //but open it for the rest of the game
                    target->clearRequirements();
                    //its already moving so why not switch the level also
                    // p->moveToLevel(target->getDoorId()); //changing approach
                    
                    return true; 
                }else {
                    return false;
                }
                break;
            case 5:
                //need work here
                break;
            default:
                return false; // if in bonds and filled but can not move
        }
    }else { // in bonds
        return true;
    }
    return false;
    return true;
}

void Screen::clearScreen()
{
    // Resets ALL objects in memory
    for (int y=0;y<gameHeight;y++)
    for (int i = 0; i < gameWidth; i++){
        objarr[i][y].set(' ', false, false);
    }
}
void Screen::updateLegend()
{
    // inventory for each player in parr
    // health points for each one
    // hints
    // etc
    // its displayed in the bottom of the screen with width * legendHeight size
    gotoxy(startx, starty + gameHeight);
    Object* pinv = parr[0]->getInv(); // by default its set to 0 because its on the stack so check it to avoid using function on nullptr(0)
    cout << "map:" << *currLevel <<" inventory:" << (!pinv ? ' ' : pinv->getSprite()) << "   x:"<<parr[0]->getX()<< " y:"<<parr[0]->getY()<<"             inventory:" << (!parr[1]->getInv() ? ' ' : parr[1]->getInv()->getSprite()) << "   x:"<<parr[1]->getX()<< " y:"<<parr[1]->getY(); // basically "if not pinv" to check if its nullptr == didn't work
}
void Screen::tick(){
    if (currState == gameState::inGame)
    for (Player* p : parr){
        // cout << p<<flush;
        
        p->tick();
    }
    Object* obj = 0;
    for (int i=0;i<10;i++){
        //for every object that should do something currently like bomb add to ticking
        obj = ticking[i];
        if (!obj) continue;
        int x= obj->getX(),y=obj->getY();
        switch (obj->getType()){
            case 3:
                if (obj->bombTick()){ // if fuse reached 0 - should expload
                    
                    for (int _x=x-3;_x<x+3;_x++){
                        for (int _y=y-3;_y<y+3;_y++){
                            if (Screen::inScreenBonds(_x,_y)){
                                setatxy(_x,_y,&Blocks::Air);
                                drawOneObjectAtxy(_x,_y);
                            }
                        }
                    }
                    setatxy(obj->getX(),obj->getY(),&Blocks::Air);
                    drawOneObjectAtxy(x,y);
                    ticking[i] = 0;
                }
        }
    }
    
}
void Screen::keyCheck(char c){
    for (Player* p : parr){
        // cout << p<<flush;
        p->keyCheck(c);
    }
    if (c == Keys::ESC){
        currState = gameState::paused;
        mainmenu::openMainMenu(this);
    }
}
void Screen::checkPlayersLevel(){
    if (parr[0]->getLevel() == parr[1]->getLevel()){
        *currLevel = parr[0]->getLevel();
        clrscr();
        draw();
        parr[0]->unlockMove();
        parr[1]->unlockMove();
    }
}
void Screen::startTicking(Object* obj){
    for (int i=0;i<10;i++){
        if (!ticking[i])
            ticking[i] = obj;
    }
}
void Screen::drawOneObjectAtxy(int x,int y){
    DrawAt(startx + x, starty + y,getatxy(x,y)->getSprite());
}