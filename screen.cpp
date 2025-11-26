// #pragma once
#include "console.h"
#include <iostream>
#include "screen.h"
#include "console.h"
using namespace std;
//use array to store the screen background and have another array for players to draw    

void object::showinfo(){
    cout << "x:"<<x<<"\ny:"<<y<<"\nsprite:\'"<<Sprite<<"\'\nfilled:"<<visible;
}
    Screen::Screen(){
        int maxidx = height*width;
        objarr = new object[maxidx];// 25 arrays of 80 items(2d array will represent the same way in the memory as array)
        //fill the screen with blank objects - no need because it has default values as object types
        drawDefaultWalls();

    }
    object* Screen::getatxy(const int x,const int y){
        //returns nullptr if out of screen
        int idx = y*width+x;
        return idx>=0 && idx <=height*width ?&(objarr[idx]) : nullptr;
    }
    void Screen::drawDefaultWalls(){
        //simple walls
        for (int i=0;i<width;i++){
            objarr[i].setSprite('#');
            objarr[i].setfilled(true);
            objarr[i].setvisible(true);
            objarr[(height-1)*width+i].setSprite('#');
            objarr[(height-1)*width+i].setfilled(true);
            objarr[(height-1)*width+i].setvisible(true);
        }
        for (int i=1;i<height-1;i++){
            objarr[width*i].setSprite('#');
            objarr[width*i].setvisible(true);
            objarr[width*i].setfilled(true);
            objarr[width*i+width-1].setSprite('#');
            objarr[width*i+width-1].setvisible(true);
            objarr[width*i+width-1].setfilled(true);
        }
    }
    void Screen::setatxy(const int x, const int y,object* obj){
        //if out of screen doing nothing
        int idx = y*width+x;
        if (idx>=0 && idx <=height*width)
        objarr[idx] = *obj;
    }
    void Screen::draw(){
        //draw the whole screen - dont use alot its not optimized only at the start or big object removal
        clrscr();
        for (int y=0;y<height;y++){
            for (int x=0; x<width;x++){
                // cout<< x<<","<<y<<"\n";
                int idx =y*width+x;
                if (objarr[idx].getvisible()){
                    gotoxy(startx+x,starty+y);
                    cout<<objarr[y*width+x].getSprite();
                }
            }
        }
        cout << flush;
    }