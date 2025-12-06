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
	Object* itemsArr[5];

public:
	Room();
	static void drawMods();
	static void addMod(int x, int y, char modChar);
	static void saveMods();
	void showMainMenu() {
		screen = designs::MAIN_MENU;
		screen->draw();
	}
	void showInstructions() {
		*screen = &designs::INSTRUCTIONS;
		screen->draw();
	}
};