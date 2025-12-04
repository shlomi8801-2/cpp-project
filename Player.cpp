#include "Player.h"
#include "utils.h"
#include "Screen.h"
#include "Blocks.h"
#include <iostream>

// dont use it its for debug just different way of using the keys

Player::Player(int _x, int _y, char const keys[], Screen *_grid,char _sprite,int _level)
{
    x = _x;
    y = _y;
    level = _level;
    sprite=_sprite;
    grid = _grid;
    for (int i = 0; i < 6; i++)
        // copying the keys to an array stored in the player object
        controlKeys[i] = keys[i];
}
void Player::pickupItem(Object *onblock)
{
    // if its pickable make a copy of it in the heap and store it in the player's inventory
    this->inv = new Object(*onblock);
    grid->setatxy(x, y, &Blocks::Air);
    grid->updateLegend();
};

void Player::move()
{
    // erase the previous player char by getting the block the player is on and checking if its visible if true draw it if not draw blank(space)
    if (!canmove) return;
    Object *onblock = grid->getatxy(x, y);
    DrawAt(grid->getstartx() + x, grid->getstarty() + y, onblock->getvisible() ? onblock->getSprite() : ' ');

    // to check:
    //  - the can walk on the block in front
    //  - special for obstacle: calculate the force needed to move it
    //  - if the item in front is pickable and inventory is empty pick it up

   
    

    // currently the blocking will only work for 1 cord at a time
    x += grid->canMoveTo(x + vx, y) ? vx : 0;
    y -= grid->canMoveTo(x, y - vy) ? vy : 0; // y starts at 0 and goes to negative numbers in the screen
    
    // gets the block it stands on now
    onblock = grid->getatxy(x, y);

    if (onblock->isAir())
    {
        // if the block standing on is just air there is not much to do with it so skip the checks by returning
        return;
    }
    
    

    if (onblock->getPickable())
    {
        pickupItem(onblock); // no need to send but it takes one less call to getatxy might add it in the pickupItem func later
    }
}

// just changes the way controls work(betterkeys just add the option to stop moving by trying to move the opposite direction)
#ifndef betterkeys
void Player::keyCheck(char key)
{ // keyc - key char
    int i;
    for (i=0;i<6;i++)
    {
        if (controlKeys[i] == key)
        {
            switch (i) // after each key reset the other axis velocity for it to not move diagonally
            {
            case movement::up:
                vy = 1;
                vx = 0;
                break;
            case movement::down:
                vy = -1;
                vx = 0;
                break;
            case movement::left:
                vx = -1;
                vy = 0;
                break;
            case movement::right:
                vx = 1;
                vy = 0;
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
void player::keyCheck(char key = 0)
{ // keyc - key char
    int i;
    for (i = 0; i < 6; i++)
    {
        if (controlKeys[i] == key)
        {
            switch (i)
            {
            case movement::up:
                vy = vy == -1 ? 0 : 1;
                break;
            case movement::down:
                vy = vy == 1 ? 0 : -1;
                break;
            case movement::left:
                vx = vx == 1 ? 0 : -1;
                break;
            case movement::right:
                vx = vx == -1 ? 0 : 1;
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
void Player::draw()
{
    //check if the player is on the level first
    // because the player is only 1 char using DrawAt function
    if (canmove)
    DrawAt(grid->getstartx() + x, grid->getstarty() + y, sprite);
}
void Player::tick(){
    move();
    draw();
}
void Player::moveToLevel(int _level){
    //when moving to other level the move function can apply with strange behavior because the level is not loaded so setting it to not move
    level = _level;
    canmove = false;
    //now set the x and y to the opposite side like its really level by level
    vx = vy = 0;
    DrawAt(grid->getstartx() + x, grid->getstarty() + y,grid->getatxy(x,y)->getSprite());
    if (x == MAX_X){
        x=0;
    }else if (x == 0)
    {
        x=MAX_X;
    }else if (y= MAX_Y-LEGEND_HEIGHT){
        y=0;
    }else if (y==0){
        y=MAX_Y-LEGEND_HEIGHT;
    }
    
}
void Player::emptyInv(){
    //delete inv;
    inv = 0;
}