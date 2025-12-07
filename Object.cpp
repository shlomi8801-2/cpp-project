#include "Object.h"
#include "Screen.h"


void Object::interact(Player& p) {
	if (pickable && p.getInv().getType() == ObjectType::AIR) {
        p.pickupItem(this);
        return;
    }
    switch (type) {
    case ObjectType::SWITCH_OFF:
		this->toggleSwitch();
        break;
    case ObjectType::SWITCH_ON:
        break;
    case ObjectType::KEY:
		break;
	case ObjectType::BOMB:
        break;
    default:
        // Other object interactions can be handled here
        break;
    }
}


void Object::toggleSwitch() {
    // Toggle the switch state
    if (type == ObjectType::SWITCH_OFF) {
        type = ObjectType::SWITCH_ON;
        sprite = '/'; // Change sprite to ON
    }
}
