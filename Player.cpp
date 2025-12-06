#include "Player.h"
#include "Screen.h"
#include "Utils.h"
#include "Point.h"
#include "Game.h"



void Player::performAction(Player& player, Action action) {
	// CHeck for the correct player
	
	switch (action) {
	case Action::MOVE_UP:
		player.pos.setDirection(Direction::UP);
		break;
	case Action::MOVE_DOWN:
		player.pos.setDirection(Direction::DOWN);
		break;
	case Action::MOVE_LEFT:
		player.pos.setDirection(Direction::LEFT);
		break;
	case Action::MOVE_RIGHT:
		player.pos.setDirection(Direction::RIGHT);
		break;
	case Action::STAY:
		player.pos.setDirection(Direction::STAY);
		break;
	default:
		break;
	}
}

void Player::move() {
    Point currLoc = pos;
    pos.move();
	Object currObject = Screen::objectIs(pos);
    if (currObject.filled){
		pos = currLoc; // Revert to original position if out of bounds
    }
    pos.draw();
}

void addToInventory(Object item) {
	
    

		////// Need to create inventory to continue //////
    
}
void pickupItem(Object* item) {

}

static void handleInput() {

	if (check_kbhit()) {
		char pressed = get_single_char();

		if (pressed == (int)(Action::ESC)) {
			// Open Pause Menu

			return;
		}
		else {
			for (static constexpr PlayerKeyBinding binding : actions) {
				if (binding.key == pressed) {
					Player::performAction(binding.playerID, binding.action);
					return;
				}
			}
		}
	}
};
