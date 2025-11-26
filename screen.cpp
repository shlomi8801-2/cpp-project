// #pragma once
#include "console.h"
#include <iostream>
#include "screen.h"
using namespace std;
//use array to store the screen background and have another array for players to draw    

void object::showinfo(){
    cout << "x:"<<x<<"\ny:"<<y<<"\nsprite:\'"<<Sprite<<"\'\nfilled:"<<filled;
}
    Screen::Screen(){
        int maxidx = height*width;
        arr = new object[maxidx];// 25 arrays of 80 items(2d array will represent the same way in the memory as array)
        //fill the screen with blank objects - no need because it has default values as object types
        //simple walls
        for (int i=0;i<width;i++){
            arr[i].setSprite('#');
            arr[i].setfilled(true);
            arr[(height-1)*width+i].setSprite('#');
            arr[(height-1)*width+i].setfilled(true);
        }
        for (int i=1;i<height-1;i++){
            arr[width*i].setSprite('#');
            arr[width*i].setfilled(true);
            arr[width*i+width-1].setSprite('#');
            arr[width*i+width-1].setfilled(true);
        }

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
                // cout<< x<<","<<y<<"\n";
                int idx =y*width+x;
                if (arr[idx].getfilled()){
                    gotoxy(x,y);
                    cout<<arr[y*width+x].getSprite();
                }
                
            }
        }
        cout << flush;
    }