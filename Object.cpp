#include "Object.h"
#include "Player.h"
void Object::set(const Object &_obj) // ctor
{
    // does not copy x and y values
    this->filled = _obj.filled;
    this->Sprite = _obj.Sprite;
    this->visible = _obj.visible;
    this->pickable = _obj.pickable;

    this->type = _obj.type;
    this->doorId = _obj.doorId;
    this->keyId = _obj.keyId;
    this->switchState = _obj.switchState;
    this->riddleId = _obj.riddleId;
}
int Object::setDoorId(int _doorId){
    //if gets number sets and returns if not just gets
    if (!_doorId) return doorId;
    return this->doorId = _doorId;
}
bool Object::canOpenDoor(Player* p){
    // it will use the requirements array to check for example if it needs a key and a switch
    //first it will check if the item in the array is 0 if not great continue
    //second will check its type if its a key will check if the player has it if yess i will delete the key from his invenrory and array
    //third if a switch will check its state
    Object* obj;
    for (int i;i<5;i++){
        obj = requirements[i];
        if (!obj) continue;
        switch (obj->type){
            case 0:
            case 1:
            case 3:
            case 5:
            case 6:
            case 7:
            case 8:
            continue;
            case 2:
            //key
            if (!(p->getInv())) return false; // doesnt have the key if doesnt have inventory
            if(p->getInv() == obj);//checks for the same pointer
                {
                    requirements[i] = 0;
                    p->emptyInv();
                }
            break;
            //switch
            case 4:
            if (!obj->switchState) // its in the same class so you can access it like so altho its another object
                return false;
            break;
            default:
                break;
        }
    }
    return true;
}
 Object::~Object(){
    
}