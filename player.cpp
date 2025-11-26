#include "player.h"
player::player(int _x=0,int _y=0,char* keys = "waxdsq"){
    x=_x;
    y=_y;
    for (int i=0;i<6;i++)
        controlKeys[i] = keys[i];
    
}
void player::move(){

}
void player::keyCheck(char key=0){ // keyc - key char
    switch (key)
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
}