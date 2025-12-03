#include "Layouts.h"
#include "Blocks.h"

// Maybe will be changed to a class later if neccessary. Didn't think it through yet.
namespace levels
{

	// Not working properly yet
	void changeLayout(int levelNum, Screen *screen)
	{
		switch (levelNum)
		{
		case 1:
			level1(screen);
			break;
			// add future levels here
		default:
			level1(screen);
			break;
		}
	}

	void level1(Screen *screen)
	{
		screen->clearScreen();
		screen->drawDefaultWalls();

		for (int y = 5; y <= 7; y++)
		{
			Object *obj = screen->getatxy(40, y);
			if (obj != nullptr)
			{
				// obj->set('|',true,true);
				obj->set(Blocks::Wall);
			}
		}
		Object *obj = screen->getatxy(40, 8);
		obj->set(Blocks::Bomb);
		obj->setPickable(true); // for some reason it doesnt work without adding it(it stays false)

		screen->draw();
	}
	void generateLayoutFromArr(char *arr[], Object **outArr)
	{
		// takes an array like the main menu and generates array of objects from the objects being saved chars for example: @ = bomb
	}

}
