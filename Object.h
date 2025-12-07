#pragma once
#include "Point.h"

class Player;

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
	RIDDLE = '?',
	DOOR = 'D'
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
    Object() : sprite(ObjectType::AIR), type(ObjectType::AIR), pos(Point(-1, -1, 0, 0, ' ')), filled(false), pickable(false) {};

	void setType(ObjectType _type) { type = _type; }
	void setSprite(char c) { sprite = c; }
	void setPos(Point _pos) { pos = _pos; }

    ObjectType getType() const { return type; }
    Point getPos() const { return pos; }
    char getSprite() const { return sprite; }
    bool isFilled() const { return filled; }
    bool isPickable() const { return pickable; }

    void setType(ObjectType _type) { type = _type; }
    void setSprite(char c) { sprite = c; }
    void setPos(Point _pos) { pos = _pos; }

    void interact(Player& p);

private:
    void toggleSwitch();
	void explodeBomb();
	void lightTorch();
};
