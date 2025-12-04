#include "Room.h"
#include "Layouts.h"


Room::Room(int id){
	roomId = id;
	
	currScreen = Screen(getLayout(id));

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			mods[i][j] = ' ';
		}
	}
}

void static Room::handleMainMenuChoice(gameState& state) {
	if (check_kbhit()) {
		char choice = get_single_char();
		if (choice == '1') {
			state = gameState::inGame;  // New Game
			return;  // New Game
		}
		if (choice == '8') {
			state = gameState::instructions;
			return;  // Instructions
		}
		if (choice == '9') {
			state = gameState::quit;
			return;  // Quit
		}
		sleep_ms(50);
	}

}

void static Room::handleInstructionsChioce(gameState& state) {
	if (check_kbhit()) {
		char choice = get_single_char();
		if (choice == 27) { // ESC key
			state = gameState::mainMenu;
			return;  // Return to main menu
		}
		sleep_ms(50);
	}
}


static void Room::drawMods() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (visible[i][j] && mods[i][j] != ' ') {
				// Assuming there's a method to draw on the screen
				drawAt(j, i, mods[i][j]);
			}
		}
	}
}

static void Room::addMod(int x, int y, char modChar) {
	mods[y][x] = modChar;
}

static void Room::saveMods() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			
			}
		}
	}
}
