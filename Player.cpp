#include "Player.h"
#include "Screen.h"
#include "Utils.h"
#include "Point.h"



void Player::performAction(int playerID, Action action) {
	// CHeck for the correct player
	Player* player = (playerID == 1) ? game.player1 : game.player2;
	
	switch (action) {
	case Action::MOVE_UP:
		player->pos.setDirection(Direction::UP);
		break;
	case Action::MOVE_DOWN:
		player->pos.setDirection(Direction::DOWN);
		break;
	case Action::MOVE_LEFT:
		player->pos.setDirection(Direction::LEFT);
		break;
	case Action::MOVE_RIGHT:
		player->pos.setDirection(Direction::RIGHT);
		break;
	case Action::STAY:
		player->pos.setDirection(Direction::STAY);
		break;
	default:
		break;
	}
}

void Player::move() {
    Point currLoc = pos;
    pos.move();
    if (Screen.isWall(currLoc)) {
        pos = currLoc; // Revert to original position if out of bounds
    }
    pos.draw();
}

void addToInventory(object& item) {
	if (item.getType() != 0 && item.getPickable()) { // assuming type 0 is air/general/wall
    

		////// Need to create inventory to continue //////
    }
}
void pickupItem(object* item) {
   
}
