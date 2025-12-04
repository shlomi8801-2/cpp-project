#pragma once
#include "Screen.h"

using namespace layouts

class Room {
	int roomId;
	Screen currScreen;
	char mods[ROWS][COLS];

public:
	Room(int id);
	static void addMod(int x, int y, char modChar);
	static void drawMods();
	static void saveMods();
};
	
