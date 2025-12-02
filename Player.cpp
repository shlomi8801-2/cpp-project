#include "Player.h"
#include "Screen.h"
#include "Utils.h"
#include "Point.h"

//dont use it its for debug just different way of using the keys

//Player::Player(int _x,int _y,char const keys[],Screen* _grid){
//    x=_x;
//    y=_y;
//    grid = _grid;
//}



//void Player::pickupItem(object* onblock){
//    //if its pickable make a copy of it in the heap and store it in the Player's inventory
//        this->inv = new object(*onblock);
//        grid->setatxy(x,y,&Blocks::Air);
//        grid->updateLegend();
//    };

//void Player::move(){
//    //erase the previous player char by getting the block the player is on and checking if its visible if true draw it if not draw blank(space)
//    object* onblock = grid->getatxy(x,y);
//    DrawAt(grid->getstartx()+x,grid->getstarty()+y,onblock->getvisible() ? onblock->getSprite(): ' ');
//    

    //to check:
    // - the can walk on the block in front
    // - special for obstacle: calculate the force needed to move it
    // - if the item in front is pickable and inventory is empty pick it up    

    //currently the blocking will only work for 1 cord at a time
//    x += grid->canMoveTo(x+vx,y)?vx:0;
//    y -= grid->canMoveTo(x,y-vy)?vy:0; //y starts at 0 and goes to negative numbers in the screen
//
//    //gets the block it stands on now
//    onblock = grid->getatxy(x,y);
//    if (onblock->isAir()){
//        //if the block standing on is just air there is not much to do with it so skip the checks by returning
//        return;
//    }
//    
//    if (onblock->getPickable()){
//        pickupItem(onblock); // no need to send but it takes one less call to getatxy might add it in the pickupItem func later
//    }
//}
//
////just changes the way controls work(betterkeys just add the option to stop moving by trying to move the opposite direction)
//#ifndef betterkeys
//void Player::keyCheck(char key=0){ // keyc - key char
//    int i;
//    for (i=0;i<6;i++){
//        if (controlKeys[i]==key)
//        {
//            switch (i)//after each key reset the other axis velocity for it to not move diagonally
//        {
//            case movement::up:
//                vy =1;
//                vx = 0;
//                break;
//            case movement::down:
//                vy=-1;
//                vx=0;
//                break;
//            case movement::left:
//                vx=-1;
//                vy=0;
//                break;
//            case movement::right:
//                vx=1;
//                vy=0;
//                break;
//            case movement::stay:
//                vx = vy = 0;
//                break;
//            case movement::dropItem:
//                break;
//            default:
//                break;
//        }
//        break;
//        }
//    }
//}
//#else
//void Player::keyCheck(char key=0){ // keyc - key char
//    int i;
//    for (i=0;i<6;i++){
//        if (controlKeys[i]==key)
//        {
//            switch (i)
//        {
//            case movement::up:
//                vy =vy == -1 ? 0 :1;
//                break;
//            case movement::down:
//                vy=vy == 1 ? 0 :-1;
//                break;
//            case movement::left:
//                vx=vx==1?0:-1;
//                break;
//            case movement::right:
//                vx=vx==-1?0:1;
//                break;
//            case movement::stay:
//                vx = vy = 0;
//                break;
//            case movement::dropItem:
//                break;
//            default:
//                break;
//        }
//        break;
//        }
//    }
//}
//#endif
//void Player::draw(){
//    //because the player is only 1 char using DrawAt function
//    DrawAt(grid->getstartx()+x,grid->getstarty()+y,sprite);
//}
//
//




void Player::move() {
    Point currLoc = pos;
    pos.move();
    if (screen.isWall(pos)) {
        pos = body0orig; // Revert to original position if out of bounds
    }
    pos.draw();
}




void addToInventory(const object& item) {
	if (item.type != 0 && item.pickable) { // assuming type 0 is air/general/wall
    

		////// Need to create inventory to continue //////
    }
}
void pickupItem(object* item) {
   
}
