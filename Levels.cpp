#include "Levels.h"

Levels::Levels(Screen& screen, gameState& state)
    : currentScreen(screen), currentState(state), roomCount(0), currentRoom(nullptr) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = nullptr;
    }
	Player& player1 = ;
	Player& player2 = ;
};

Levels::~Levels() {
    delete currentScreen;
    
    // Delete all rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i] != nullptr) {
            delete rooms[i];
        }
    }
}

void Levels::initializeRooms() {
    // Create rooms (IDs match array indices)
    rooms[0] = new Room(0);
    rooms[1] = new Room(1);
    rooms[2] = new Room(2);
    roomCount = 3;

    for (int i = 0; i < roomCount; i++) {
        rooms[i]->setScreen(&currScreen);
        rooms[i]->initializeDefault();
    }

    currentRoom = rooms[0];
    currentRoom->activate();
}

Room* Levels::getRoom(int id) {
    if (id >= 0 && id < MAX_ROOMS && rooms[id] != nullptr) {
        return rooms[id];
    }
    return nullptr;  // Room doesn't exist
}

void Levels::changeRoom(int newRoomId, int spawnX, int spawnY) {
	// Checks for possible invalid room change
    if (newRoomId < 0 || newRoomId >= roomCount || rooms[newRoomId] == nullptr) {
        return;
    }

    currentRoom = rooms[newRoomId];
    currentRoom->activate();  // Modifies currentScreen
}
