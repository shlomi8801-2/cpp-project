#pragma once
#include "Point.h"
#include "Player.h"

enum class ObjectType {
    AIR = ' ',
    WALL = 'W',
    SPRING = '#',
    OBSTACLE = '*',
    TORCH = '!',
    BOMB = '@',
    KEY = 'K',
    SWITCH_OFF = '\\',
	SWITCH_ON = '/',
	RIDDLE = '?'
};

class Object {
    char sprite;
    ObjectType type;
    Point pos;
    bool filled; // does it block the player?
    bool pickable;


public:
    Object(ObjectType _type, Point _pos) :
        sprite(_type), type(_type), pos(_pos), filled(false), pickable(false)
    {
    };
    Object() : sprite(ObjectType::AIR), type(ObjectType::AIR), filled(false), pickable(false) {};
    Object* Object::getObjectPosInArr(Object* objectArr, Point pos);
	ObjectType getType() const { return type; }
	Point getPos() const { return pos; }
    void interact(Player p);
    
	void setType(ObjectType _type) { type = _type; }
	void setSprite(char c) { sprite = c; }
	void setPos(Point _pos) { pos = _pos; }

private:
    void toggleSwitch();
	void explodeBomb();
	void lightTorch();
};
