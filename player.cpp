#include "player.h"
#include "utils.h"
#include "screen.h"



//dont use it its for debug just different way of using the keys


player::player(int _x,int _y,char const keys[],Screen* _grid){
    x=_x;
    y=_y;
    grid = _grid;
    for (int i=0;i<6;i++)
    //copying the keys to an array stored in the player object
        controlKeys[i] = keys[i];
}

void player::move(){
    //erase the previous player char by getting the block the player is on and checking if its visible if true draw it if not draw blank(space)
    object* onblock = grid->getatxy(x,y);
    DrawAt(grid->getstartx()+x,grid->getstarty()+y,onblock->getvisible() ? onblock->getSprite(): ' ');
    

    //to check:
    //currently the blocking will only work for 1 cord at a time
    x += grid->canMoveTo(x+vx,y)?vx:0;
    y -= grid->canMoveTo(x,y-vy)?vy:0; //y starts at 0 and goes to negative numbers in the screen
    
    //TODO make function to check if can move to in screen class - done

}

//just changes the way controls work(betterkeys just add the option to stop moving by trying to move the opposite direction)
#ifndef betterkeys
void player::keyCheck(char key=0){ // keyc - key char
    int i;
    for (i=0;i<6;i++){
        if (controlKeys[i]==key)
        {
            switch (i)//after each key reset the other axis velocity for it to not move diagonally
        {
            case movement::up:
                vy =1;
                vx = 0;
                break;
            case movement::down:
                vy=-1;
                vx=0;
                break;
            case movement::left:
                vx=-1;
                vy=0;
                break;
            case movement::right:
                vx=1;
                vy=0;
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
                vy=vy == 1 ? 0 :-1;
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
    //because the player is only 1 char using DrawAt function
    DrawAt(grid->getstartx()+x,grid->getstarty()+y,sprite);
}