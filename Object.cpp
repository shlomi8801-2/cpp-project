#include "Object.h"
#include "Screen.h"


Object* Object::getObjectPosInArr(Object* objectArr, Point pos) {
    for (Object& obj : objectArr) {
        if (obj.pos.getX() == pos.getX() && obj.pos.getY() == pos.getY()) {
            return &obj;
        }
    }
}

void Object::interact(Player p) {
	if (pickable && p.getInv() == nullptr) { 
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
