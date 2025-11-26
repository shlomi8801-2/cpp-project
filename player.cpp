#include "player.h"
#include "utils.h"
player::player(int _x,int _y,char keys[]){
    x=_x;
    y=_y;
    for (int i=0;i<6;i++)
        controlKeys[i] = keys[i];
}
void player::move(){
    DrawAt(x,y,' ');
    x +=vx;
    y -=vy;//y starts at 0 and goes to negative numbers in the screen
}
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
void player::draw(){
    DrawAt(x,y,sprite);
}