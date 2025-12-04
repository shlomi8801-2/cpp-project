#pragma once
#include "Screen.h"
#include "Blocks.h"

using namespace layouts

class Room {
	int roomId;
	char** layout;
	char mods[ROWS][COLS];

public:
	Room(int id);
	void addMod(int x, int y, char modChar);
};
	
