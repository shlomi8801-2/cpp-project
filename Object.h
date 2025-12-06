#pragma once
#include "Point.h"

enum class ObjectType {
    AIR = ' ',
    WALL = 'W',
    SPRING = '#',
    OBSTACLE = '*',
    TORCH = '!',
    BOMB = '@',
    KEY = 'K',
    SWITCH_OFF = '\\',
	RIDDLE = '?'
};

//class Object {
//    char Sprite;
//	ObjectType type;
//    bool filled; // does it block the player?
//    bool visible; // visible
//    bool pickable;
//
//public:
//    Object(char ch) :
//		Sprite(ch), type(ObjectType::AIR), filled(false), visible(true), pickable(false)
//    {};
//    
//};

struct Object {
    char Sprite;
    ObjectType type;
    bool filled; // does it block the player?
    bool pickable;
};

static Object objects[] = {
    {' ', ObjectType::AIR, false, false},
    {'W', ObjectType::WALL, true, false},
    {'#', ObjectType::SPRING, true, false},
    {'*', ObjectType::OBSTACLE, true, false},
    {'!', ObjectType::TORCH, false, true},
    {'@', ObjectType::BOMB, false, true},
    {'K', ObjectType::KEY, false, true},
    {'\\', ObjectType::SWITCH_OFF, true, false},
    {'?', ObjectType::RIDDLE, false, false}
};
