#pragma once
#include "Console.h"
#include <iostream>
#include "Screen.h"
#include "Game.h"

namespace MainMenu {
	void showMainMenu(Screen* screen) {
		screen->draw_static(MAIN_MENU, 25);
	}

	void showInstructions(Screen* screen) {
		screen->draw_static(INSTRUCTIONS, 25);
	}

    
}
