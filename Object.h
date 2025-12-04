#pragma once
class Player; // required because of including each other


class Object
{
    // do we need those now?(we using array...)
    //  int x;
    //  int y;
    char Sprite;
    bool filled = false;  // does it block the player?
    bool visible = false; // visible
    bool pickable = false;
    // friend ostream& operator<<(ostream& out, const Object& s) {
    //     return out << s.sprite;
    // }
    // for the future(if needed) all of the block types in the game after all are less then 256 possibilites so can store in a unsigned char like so: type - door/wall/key/bomb/switch/obstacle/riddle/torch/spring sum: 8+1+8+1+32(possible button id's)+1+32(num of riddles) 1+1=85 = 0101 0101
    // but for now use alot of variables for readability
    int type = 0; // 0 - air/general/wall, 1 - door, 2 - key, 3 - bomb, 4 - switch, 5 - obstacle, 6 - riddle, 7 - torch, 8 - spring
    int doorId=0;
    //door only max 5 requirements
    Object* requirements[5] = {0,0,0,0,0};
    int keyId;
    bool switchState= false;
    int riddleId;
    
public:
    
    Object() {};
    Object(char _sprite, bool _filled = false, bool _pickable = false, bool _visible = false, int _type = 0, int _doorId = 0, int _keyId = 0, bool _switchState = 0, int _riddleId = 0)
    {
        set(_sprite,_filled,_pickable,_visible,_type,_doorId,_keyId,_switchState,_riddleId);
    }
    char getSprite() { return Sprite; }
    bool getvisible() { return visible; }
    bool getfilled() { return filled; }
    void showinfo();
    void setSprite(char c) { Sprite = c; }
    void setvisible(bool state) { visible = state; }
    void setfilled(bool state) { filled = state; }
    int setDoorId(int _doorId=0);
    void set(const Object &_obj);
    bool getPickable() const { return pickable; }
    inline int getType() { return type; }
    void setPickable(bool state) { pickable = state; }
    inline bool isAir() { return (Sprite == ' ') && (filled = false); }
    inline void set(char _sprite, bool _filled = false, bool _pickable = false, bool _visible = false, int _type = 0, int _doorId = 0, int _keyId = 0, bool _switchState = 0, int _riddleId = 0)
    {
        Sprite = _sprite;
        filled = _filled;
        pickable = _pickable;
        visible = _visible;
        type = _type;
        doorId = _doorId;
        keyId = _keyId;
        switchState = _switchState;
        riddleId = _riddleId;
    }
    Object(const Object &_obj) { this->set(_obj); }
    bool canOpenDoor(Player* p = 0);
    ~Object();
};
#include "Player.h"