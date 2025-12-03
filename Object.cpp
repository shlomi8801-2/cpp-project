#include "Object.h"
void Object::set(const Object &_obj)
{
    // does not copy x and y values
    this->filled = _obj.filled;
    this->Sprite = _obj.Sprite;
    this->visible = _obj.visible;
    this->pickable = _obj.pickable;

    this->type = _obj.type;
    this->doorId = _obj.doorId;
    this->keyId = _obj.keyId;
    this->switchId = _obj.switchId;
    this->riddleId = _obj.riddleId;
}