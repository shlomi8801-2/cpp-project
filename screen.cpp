// #pragma once
#include "console.h"
#include <iostream>
#include "screen.h"
using namespace std;
//use array to store the screen background and have another array for players to draw    
    Screen::Screen(){
        arr = new object[height*width];// 25 arrays of 80 items(2d array will represent the same way in the memory as array)
        //fille the screen with blank objects
    }
    object* Screen::getatxy(const int x,const int y){
        //returns nullptr if out of screen
        int idx = y*width+x;
        return idx>=0 && idx <=height*width ?&(arr[idx]) : nullptr;
    }
    void Screen::setatxy(const int x, const int y,object* obj){
        //if out of screen doing nothing
        int idx = y*width+x;
        if (idx>=0 && idx <=height*width)
        arr[idx] = *obj;
    }
    void Screen::draw(){
        for (int y=0;y<height;y++){
            for (int x=0; x<width;x++){
                
                gotoxy(x,y);
                cout<<arr[y*width+x].getSprite();
            }
        }
        cout << flush;
    }