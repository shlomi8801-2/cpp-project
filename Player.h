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

static constexpr PlayerKeyBinding actions[] = {
    {'w', 1, Action::MOVE_UP},
    {'x', 1, Action::MOVE_DOWN},
    {'a', 1, Action::MOVE_LEFT},
    {'d', 1, Action::MOVE_RIGHT},
    {'s', 1, Action::STAY},
    {'e', 1, Action::DROP_ITEM},
    {'i', 2, Action::MOVE_UP},
    {'m', 2, Action::MOVE_DOWN},
    {'j', 2, Action::MOVE_LEFT},
    {'l', 2, Action::MOVE_RIGHT},
    {'k', 2, Action::STAY},
    {'o', 2, Action::DROP_ITEM }
};


class Screen;
class object;


class Player {
	Point pos;
    object* inv;
    int playerId;

public:
    Player::Player(Point _pos, object* _inv, int ID;)
        : pos(_pos), inv(nullptr), playerId(ID)
    {
    };
    Player::~Player() { delete inv; };

    Point getPosition() const { return pos; };
    int getX() const { return pos.x; };
    int getY() const { return pos.y; };
    object* getInv() { return inv; };
    char getSprite() const { return pos.sprite; };

    void setPosition(int x, int y) { pos.x = x; pos.y = y; };
    void setPosition(Point newPos) { pos = newPos; };
    
    void Player::performAction(int playerID, Action action)
    void move();
    void moveTo(int x, int y) { setPosition(x, y); } // In case we need it
    void draw() { pos.draw(); }
    void pickupItem(object* item) {
        if (item != nullptr) {
            addToInventory(*item);
        }
    }
    void addToInventory(const object& item);
};
