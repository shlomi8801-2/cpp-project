#include "console.h"
#include <cstddef>
#include <iostream>
#include "screen.h"
#include "console.h"
#include "blocks.h"

using namespace std;
//use array to store the screen background and have another array for players to draw    

    Screen::Screen(){
        int maxidx = height*width;
        //like that every 80 characters is a row in the screen so if you for example want to get 1,1 pos you need 80*1+1 in the array
        objarr = new object[maxidx];// 25 arrays of 80 items(2d array will represent the same way in the memory as array)
        //fill the screen with blank objects - no need because it has default values as object types
        drawDefaultWalls();

    }
    object* Screen::getatxy(const int x,const int y){
        //returns nullptr if out of screen
        int idx = y*width+x;
        return idx>=0 && idx <=height*width ?&(objarr[idx]) : nullptr;
    }

    void Screen::draw_static(const char* layout[], size_t lines) {
        clrscr();
        for (size_t y = 0; y < lines && y < height; y++) {
            gotoxy(startx, starty + y);

            for (size_t x = 0; layout[y][x] != '\0' && x < width; x++) {
                cout << layout[y][x];
            }
        }
        cout.flush();
    }
void object::set(const object& _obj){
    //does not copy x and y values
    this->filled = _obj.filled;
    this->Sprite = _obj.Sprite;
    this->visible = _obj.visible;

    this->type=_obj.type;
    this->doorId = _obj.doorId;
    this->keyId = _obj.keyId;
    this->switchId = _obj.switchId;
    this->riddleId = _obj.riddleId;
}

    void Screen::drawDefaultWalls(){
        //simple walls
        for (int i=0;i<width;i++){
            objarr[i].set(blocks::Wall);
            objarr[(height-1)*width+i].set(blocks::Wall);
        }
        for (int i=1;i<height-1;i++){
            objarr[width*i].set(blocks::Wall);
            objarr[width*i+width-1].set(blocks::Wall);
        }
    }
    void Screen::setatxy(const int x, const int y,const object* obj){
        //if out of screen doing nothing
        int idx = y*width+x;
        if (idx>=0 && idx <=height*width) //checking if its in the screen
        objarr[idx] = *obj;
    }
    void Screen::draw(){
        //draw the whole screen - dont use alot its not optimized only at the start or big object removal
        clrscr();
        int idx;
        for (int y=0;y<height;y++){
            for (int x=0; x<width;x++){
                // cout<< x<<","<<y<<"\n";
                idx =y*width+x;
                if (objarr[idx].getvisible()){
                    gotoxy(startx+x,starty+y);
                    cout<<objarr[y*width+x].getSprite();
                }
            }
        }
        cout << flush; // clear the buffer of the screen in case cout missed some characters it forces it to print them somehow i think
    }
    bool Screen::canMoveTo(const int x,const int y){
        return !((x>=0 && y>=0&&x<=width &&y<=-height)||getatxy(x,y)->getfilled()); // y is -height because the screen starts at 0 0 and shows at x -y
    }

    void Screen::clearScreen() {
        // Resets ALL objects in memory
        for (int i = 0; i < height * width; i++) {
            objarr[i].set(' ',false,false);
        }
    }