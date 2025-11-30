#include "Layouts.h"
#include "blocks.h"

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
				// obj->set('|',true,true);
				obj->set(blocks::Wall);
			}
		}
		object* obj = screen->getatxy(40, 8);
		

		screen->draw();
	}
}
