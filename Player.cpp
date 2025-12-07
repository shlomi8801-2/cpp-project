#include "Player.h"
#include "Screen.h"
#include "Game.h"



void Player::performObjectAction(Object& obj) {
	// Implement object interaction logic here
	switch (objType) {
	case ObjectType::SPRING:
		// Implement spring logic
		break;
	case ObjectType::OBSTACLE:
		// Implement obstacle logic
		break;
	case ObjectType::TORCH:
		// Implement torch logic
		break;
	case ObjectType::BOMB:
		// Implement bomb logic
		break;
	case ObjectType::KEY:
		// Implement key logic
		break;
	case ObjectType::SWITCH_OFF:
		break;
	case ObjectType::SWITCH_ON:
		break;
	case ObjectType::RIDDLE:
		// Implement riddle logic
		break;
	default:
		break;
	}
}

void Player::performInputAction(Player& player, Action action) {
	
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
	case Action::DROP_ITEM:
		// Implement drop item logic here
		break;
	default:
		player.pos.setDirection(Direction::STAY);
		break;
	}
}

void Player::move() {
    Point currLoc = pos;
    pos.move();
	Object currObject = screen.objectIs(pos);
    if (currObject.filled){
		pos = currLoc; // Revert to original position if out of bounds
    }
    pos.draw();
}


void Player::pickupItem(Object* item, Room* room) {
	inv = *item;

	item->setPos(Point(-1, -1, 0, 0, ' ')); // Remove item from screen
	item->setType(ObjectType::AIR); // Set item type to AIR
	item->setSprite(' '); // Set item sprite to empty

	room->drawMods(); // Redraw room to reflect item pickup
}


void Player::dropItem(Object* item, Room* room) {
	if (inv.type != ObjectType::AIR) {
		inv.pos = Point(pos.getX(), pos.getY(), 0, 0, inv->sprite); // Place item at player's position
		for (int i = 0; i < 5; i++) {
			if (room->objectsArr[i]->getType() == ObjectType::AIR) {
				room->objectsArr[i] = *inv;
				room->objectsArr[i]->setPos(this->pos);
			}
			inv = Object(); // Remove item from inventory
			room->drawMods(); // Redraw room to reflect item drop
		}

	}
}

void Player::handleInput() {

	if (check_kbhit()) {
		char pressed = get_single_char();

		if (pressed == (int)(Action::ESC)) {
			// Open Pause Menu

			return;
		}
		else {
			for (static constexpr PlayerKeyBinding binding : actions) {
				if (binding.key == pressed) {
					Player::performInputAction(binding.playerID, binding.action);
					return;
				}
			}
		}
	}
};

