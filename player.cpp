#include "player.h"
#include "utils.h"
#include "screen.h"


#define betterkeys
//dont use it its for debug just different way of using the keys


player::player(int _x,int _y,char const keys[]){
    x=_x;
    y=_y;
    for (int i=0;i<6;i++)
        controlKeys[i] = keys[i];
}

void player::move(Screen* grid=nullptr){
    DrawAt(x,y,' ');
    //currently the blocking will only work for 1 cord at a time
    x += vx;
    y -= vy; //y starts at 0 and goes to negative numbers in the screen
    
    //does does not work properly
    //TODO make function to check if can move to in screen class
    // x +=((grid && !(grid->getatxy(grid->getstartx()+vx,-grid->getstarty()+y-vy)->getfilled())) ? vx:0); 
    // y -=((grid && !(grid->getatxy(grid->getstartx()+x+vx,-grid->getstarty()+y-vy)->getfilled())) ? vy:0);
}

#ifndef betterkeys
void player::keyCheck(char key=0){ // keyc - key char
    int i;
    for (i=0;i<6;i++){
        if (controlKeys[i]==key)
        {
            switch (i)
        {
            case movement::up:
                vy =1;
                break;
            case movement::down:
                vy=-1;
                break;
            case movement::left:
                vx=-1;
                break;
            case movement::right:
                vx=1;
                break;
            case movement::stay:
                vx = vy = 0;
                break;
            case movement::dropItem:
                break;
            default:
                break;
        }
        break;
        }
    }
}
#else
void player::keyCheck(char key=0){ // keyc - key char
    int i;
    for (i=0;i<6;i++){
        if (controlKeys[i]==key)
        {
            switch (i)
        {
            case movement::up:
                vy =vy == -1 ? 0 :1;
                break;
            case movement::down:
                vy=-vy == 1 ? 0 :-1;
                break;
            case movement::left:
                vx=vx==1?0:-1;
                break;
            case movement::right:
                vx=vx==-1?0:1;
                break;
            case movement::stay:
                vx = vy = 0;
                break;
            case movement::dropItem:
                break;
            default:
                break;
        }
        break;
        }
    }
}
#endif
void player::draw(){
    DrawAt(x,y,sprite);
}