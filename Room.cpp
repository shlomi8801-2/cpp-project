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