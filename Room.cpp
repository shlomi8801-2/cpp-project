#include "Room.h"

Room::Room(int num) : roomNum(num), screen(nullptr) {
    modCapacity = 10;
    mods = new Mods[modCapacity];
    modCount = 0;

    doors = new Door[2];  // Max 2 doors per room
    doorCount = 0;
}

Room::~Room() {
    delete[] mods;
    delete[] doors;
}

void Room::setScreen(Screen* s) {
    screen = s;
}

void Room::initializeDefault() {
    // Set up doors for each room
    switch (roomNum) {
    case 0:  // Room 0: Starting room
        doors[doorCount++] = { 40, 11, 1, 2, 11 };
        break;

    case 1:  // Room 1: Middle room
        doors[doorCount++] = { 1, 11, 0, 38, 11 };
        doors[doorCount++] = { 78, 11, 2, 2, 11 };
        break;

    case 2:  // Room 2: End room
        doors[doorCount++] = { 1, 11, 1, 78, 11 };
        break;

    default:
        break;
    }
}

void Room::activate() {
    // Load this room into the shared screen
    screen->clearScreen();
    screen->drawDefaultWalls();

    // Place default objects for this room
    switch (roomNum) {
    case 0:  // Room 0
        screen->setatxy(40, 11, &Blocks::Door);
        screen->setatxy(10, 5, &Blocks::Key);
        screen->setatxy(15, 8, &Blocks::Torch);
        break;

    case 1:  // Room 1
        screen->setatxy(1, 11, &Blocks::Door);
        screen->setatxy(78, 11, &Blocks::Door);
        screen->setatxy(20, 10, &Blocks::Bomb);
        break;

    case 2:  // Room 2
        screen->setatxy(1, 11, &Blocks::Door);
        screen->setatxy(30, 12, &Blocks::Key);
        break;

    default:
        // Unknown room - do nothing or handle error
        break;
    }

    // Apply saved modifications
    for (int i = 0; i < modCount; i++) {
        screen->setatxy(mods[i].x,
                        mods[i].y,
                        &mods[i].obj);
    }

    screen->draw();
}

void Room::addMod(int x, int y, const object& obj) {
    // Check if this position already has a modification
    for (int i = 0; i < modCount; i++) {
        if (mods[i].x == x && mods[i].y == y) {
            // Update existing modification
            mods[i].obj = obj;
            return;
        }
    }

    // Need to add new modification - check capacity
    if (modCount >= modCapacity) {
        // Expand array
        modCapacity *= 2;
        Modifications* newMods = new Mods[modCapacity];

        // Copy old data
        for (int i = 0; i < modCount; i++) {
            newMods[i] = mods[i];
        }

        delete[] mods;
        mods = newMods;
    }

    // Add new modification
    mods[modCount].x = x;
    mods[modCount].y = y;
    mods[modCount].obj = obj;
    modCount++;
}

void Room::modifyObject(int x, int y, const object& obj) {
    // Save this modification
    addMod(x, y, obj);

    // Update screen immediately
    screen->setatxy(x, y, &obj);
}

Door* Room::getDoorAt(int x, int y) {
    for (int i = 0; i < doorCount; i++) {
        if (doors[i].x == x && doors[i].y == y) {
            return &doors[i];
        }
    }
    return nullptr;
};


