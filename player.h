#pragma once
#include "Console.h"
#include "Utils.h"
#include "Blocks.h"
#include <iostream>
#include "Constants.h"
#include "Point.h"
#include "Object.h"

// Map for key binding handling - made using AI
struct PlayerKeyBinding {
    char key;
    int playerID;
    Action action;
};

static constexpr PlayerKeyBinding movements[] = {
    {'w', 1, Action::MOVE_UP},
    {'x', 1, Action::MOVE_DOWN},
    {'a', 1, Action::MOVE_LEFT},
    {'d', 1, Action::MOVE_RIGHT},
    {'i', 2, Action::MOVE_UP},
    {'m', 2, Action::MOVE_DOWN},
    {'j', 2, Action::MOVE_LEFT },
    {'l', 2, Action::MOVE_RIGHT}
};

static constexpr PlayerKeyBinding actions[] = {
    {'s', 1, Action::STAY},
    {'e', 1, Action::DROP_ITEM},
    {'k', 2, Action::STAY},
    {'o', 2, Action::DROP_ITEM},
};

class Screen;
class object;

//class Player{
//    object* inv; // when collecting an item make a copy of it in the heap and save it here after disposing copy it to the screen array and free it
//    int vx =0;//velocity at x axis
//    int vy=0; //velocity at y axis
//    int x;
//    int y;
//    Screen* grid = nullptr;
//    char sprite = 'a';
//    enum movement {
//        right,
//        down,
//        left,
//        up,
//        stay,
//        dropItem
//    };
//    public:
//    Player(int _x,int _y,char const keys[],Screen* _grid);
//    void move();
//    void keyCheck(char key);
//    void draw();
//    inline object* getInv() {return inv;}
//    void pickupItem(object* onblock);
//    void movePlayer(binding.playerID, binding.action);
//    void performAction(binding.playerID, binding.action);
//};

class Player {
	Point pos;
    object* inv;
    char sprite;

public:
    Player::Player(Point _pos, object* _inv, char _sprite)
        : pos(_pos), inv(nullptr), sprite(_sprite)
    {
    }
    Player::~Player() { delete inv; }

    Point getPosition() const { return pos; }
    int getX() const { return pos.x; }
    int getY() const { return pos.y; }
    object* getInv() { return inv; }
    char getSprite() const { return sprite; }

    void setPosition(int x, int y) { pos.x = x; pos.y = y; }
    void setPosition(Point newPos) { pos = newPos; }
    
    void Player::move();
    void moveTo(int x, int y) { setPosition(x, y); } // In case we need it
    void draw() { pos.draw(sprite); }
    void pickupItem(object* item) {
        if (item != nullptr) {
            addToInventory(*item);
        }
    }
    void addToInventory(const object& item);
};