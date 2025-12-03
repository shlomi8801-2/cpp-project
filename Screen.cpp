#include "console.h"
#include <cstddef>
#include <iostream>
#include "Screen.h"
#include "console.h"
#include "Blocks.h"

using namespace std;
// use array to store the screen background and have another array for players to draw

Screen::Screen()
{
    // objarr = new Object[ScreenSize::MAX_X][ScreenSize::MAX_Y]; // already sets it in the screen.h file
    //which saves it in the stack later will move to heap

    // fill the screen with blank objects - no need because it has default values as Object types
    drawDefaultWalls();
}
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

void Object::set(const Object &_obj)
{
    // does not copy x and y values
    this->filled = _obj.filled;
    this->Sprite = _obj.Sprite;
    this->visible = _obj.visible;

    this->type = _obj.type;
    this->doorId = _obj.doorId;
    this->keyId = _obj.keyId;
    this->switchId = _obj.switchId;
    this->riddleId = _obj.riddleId;
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
        objarr[x][y] = *obj;
}
void Screen::draw()
{
    // draw the whole screen - dont use alot its not optimized only at the start or big object removal
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
bool Screen::canMoveTo(const int x, const int y)
{
    return !((x >= 0 && y >= 0 && x <= gameWidth && y <= -gameHeight) || getatxy(x, y)->getfilled()); // y is -height because the screen starts at 0 0 and shows at x -y
}

void Screen::clearScreen()
{
    // Resets ALL objects in memory
    for (int y=0;y<gameHeight;y++)
    for (int i = 0; i < gameWidth; i++){
        objarr[i][0].set(' ', false, false);
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
    cout << "inventory:" << (!pinv ? ' ' : pinv->getSprite()); // basically "if not pinv" to check if its nullptr == didn't work
}