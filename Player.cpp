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
    
    if (!canmove){
        return;
    }
    

    
    Object *onblock;
    onblock = grid->getatxy(x, y);
    DrawAt(grid->getstartx() + x, grid->getstarty() + y, onblock->getvisible() ? onblock->getSprite() : ' ');

    // to check:
    //  - the can walk on the block in front
    //  - special for obstacle: calculate the force needed to move it
    //  - if the item in front is pickable and inventory is empty pick it up

   
    
    
    // currently the blocking will only work for 1 cord at a time
    if (canmove && grid->canMoveTo(x + vx, y -vy)){
        x +=vx;
        y -= vy;
    }
    grid->updateLegend(); // for debugging
    // gets the block it stands on now
    onblock = grid->getatxy(x, y);

    if (onblock->isAir())
    {
        // if the block standing on is just air there is not much to do with it so skip the checks by returning
        return;
    }
    if (onblock->getType() == 1){
        moveToLevel(onblock->getDoorId());
    }
    

    if (onblock->getPickable())
    {
        pickupItem(onblock); // no need to send but it takes one less call to getatxy might add it in the pickupItem func later
    }
}

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
#
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
    // //when moving to other level the move function can apply with strange behavior because the level is not loaded so setting it to not move
    level = _level;
    canmove = false;
    //now set the x and y to the opposite side like its really level by level
    
    DrawAt(grid->getstartx() + x, grid->getstarty() + y,grid->getatxy(x,y)->getSprite()); // clear the last player position
    if (x == MAX_X-1){
        x=1; // one more to not stay on a door
    }else if (x == 0)
    {
        x=MAX_X-2;// one more to not stay on a door
    }else if (y== MAX_Y-LEGEND_HEIGHT){
        y=1; // one more to not stay on a door
    }else if (y==0){
        y=MAX_Y-LEGEND_HEIGHT-1; // one more to not stay on a door
    }
    // x -=1;
    grid->checkPlayersLevel(); // sends update to the screen so it will check if all the players have passed to the next level
}
void Player::emptyInv(){
    //delete inv;
    inv = 0;
}

