#pragma once
#include "Room.h"
#include "Screen.h"

class Levels {
    static const int MAX_ROOMS = 10;
    Room* rooms[MAX_ROOMS];  // Array of room pointers
    int roomCount;
    Room* currentRoom;
    int currentRoomId;

    Screen& currentScreen;

    gameState& currentState;

    // Player should have controls (maybe create a class in Player.h),
    // Inventory, current room (so he can be moved between rooms and "wait" if he moves to a different room),
    Player* player1;
    Player* player2;

public:
    Levels(Screen& screen, gameState& state);
    ~Levels();
    void initializeRooms();
    void changeRoom(int newRoomId, int spawnX, int spawnY);
    Room* getRoom(int id);
    void handlePlayerMovement(int newX, int newY);
    void playerPickupItem(int x, int y);
};
