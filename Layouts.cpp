#include "Layouts.h"

// Maybe will be changed to a class later if neccessary. Didn't think it through yet.
namespace levels {

	// Not working properly yet
	void changeLayout(int levelNum, Screen* screen) {
		switch (levelNum) {
		case 1: level1(screen); break;
			// add future levels here
		default: level1(screen); break;
		}
	}

	void level1(Screen* screen) {
		screen->clearScreen();
		screen->drawDefaultWalls();

		for (int y = 5; y <= 7; y++) {
			object* obj = screen->getatxy(40, y);
			if (obj != nullptr) {
				obj->setSprite('|');
				obj->setvisible(true);
				obj->setfilled(true);
			}
		}

		screen->draw();
	}
}