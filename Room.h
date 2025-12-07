#pragma once
#include "Screen.h"
#include "Constants.h"
#include "Game.h"
#include "Layouts.h"
#include "Object.h"

class Room {
	
	bool isActive;
	bool haveMods;
	Screen mods[MAX_Y][MAX_X];
	Object* objectsArr[5];

public:
	Room();
	static void drawMods();
	static void addMod(int x, int y, char modChar);
	static void saveMods();
};