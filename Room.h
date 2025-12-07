#pragma once
#include "Screen.h"
#include "Constants.h"
#include "Game.h"
#include "Layouts.h"
#include "Object.h"


class Room {
	int roomId;
	bool active;
	bool haveMods;
	Screen mods[MAX_Y][MAX_X];
	Object objectsArr[10];

public:
	Room(int id);
	
	void initializeRooms(Room** rooms);
	void loadObjectsFromLayout(const Screen& layout);

	Object* getObjectsArr() { return objectsArr; }
	int getRoomId() const { return roomId; }
};