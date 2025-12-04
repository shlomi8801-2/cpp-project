#pragma once
#include "Screen.h"
#include "Constants.h"
#include "Game.h"
#include "Layouts.h"

class Room {
	int roomId;
	Screen* screen;
	static char mods[MAX_X][MAX_Y]; // Modifications to the base layout
public:
	Room(int id);
	static void drawMods();
	static void addMod(int x, int y, char modChar);
	static void saveMods();
	void showMainMenu() {
		*screen = &designs::MAIN_MENU;
		screen->draw();
	}
	void showInstructions() {
		*screen = &designs::INSTRUCTIONS;
		screen->draw();
	}
	void static handleMainMenuChoice(gameState& state);
	void static handleInstructionsChioce(gameState& state);
};