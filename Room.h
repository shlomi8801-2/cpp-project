#pragma once
#include "Screen.h"
#include "Blocks.h"

// Design of modifications struct was improved using AI
struct Modifications {
	int x, y;
	object obj;
};

// Idea for door struct was taken from AI
struct Door {
	int x, y;
	int leadsToRoomNumber;
	int spawnX, spawnY; // where the player appears in the new room
}

class Room {
		int roomNum;
		Screen* screen;
		Door* doors;
		int doorCounter;
		Modifications* mods;
		int modCounter;
		int modCapacity;
		
		void addMod(int x, int y, const object& obj);


public:
	
	Room(int id);
	~Room();

	void initializeDefault();
	void activate();
	void Room:: addMod(int x, int y, const object& obj);
	void Room::modifyObject(int x, int y, const object & obj);
	void setScreen(Screen* s) { screen = s; }
	Door* Room::getDoorAt(int x, int y);
};