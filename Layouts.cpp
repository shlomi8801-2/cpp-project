#include "Layouts.h"
#include "Blocks.h"
#include "Constants.h"
#include <iostream>

// Maybe will be changed to a class later if neccessary. Didn't think it through yet.
namespace levels
{
	const char* level2map[80] = {
		// 0123456789012345678901234567890123456789012345678901234567890123456789012345678
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
		"W                                                                             W", // 1
		"W                                                                             W", // 2
		"W                                                                             W", // 3
		"W                            WWWWWWWWWWWWWWWWWWW                              W", // 4
		"W                           WWWWWWWWWWWWWWWWWWWWW                             W", // 5
		"W                                              @W                             W", // 6
		"W                           WWWWWWWWWWWWWWWWWWWWW                             W", // 7
		"W                           WWWWWWWWWWWWWWWWWWWWW                             W", // 8
		"W                                 WWWW   W                                    W", // 9
		"W                                                                             W", // 10
		"W                                                                             W", // 11
		"W                                                                             W", // 12
		"W                                                                             W", // 13
		"W                                                                             W", // 14
		"W                                                                             W", // 15
		"W                                                                             W", // 16
		"W                                                                             W", // 17
		"W                                                                             W", // 18
		"W                                                                             W", // 19
		"W                                                                             W", // 20
		"W                                                                             W", // 21
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" // 22
	};

	// Not working properly yet
	void changeLayout(int levelNum, Screen *screen)
	{
		switch (levelNum)
		{
		case 1:
			level1(screen);
			break;
			// add future levels here
		case 2:
			level2(screen);
			break;
		default:
			level1(screen);
			break;
		}
	}
	void level2(Screen *screen){
		screen->clearScreen();
		generateLayoutFromArr(level2map,screen->objarr);
		screen->draw();
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
	void generateLayoutFromArr(const char* arr[MAX_Y-LEGEND_HEIGHT], Object outArr[][22])
	{
		// takes an array like the main menu and generates array of objects from the objects being saved chars for example: @ = bomb
		// torch - !
		// Bomb - @
		// Wall - W
		// obstacle - *
		// Spring #
		// Switch On/Off "/\"
		// Door - a digit 1-9
		// key - K
		// Riddle ?
		//outArr MUST be enough in size!
		for (int y=0;y<22;y++)
		for (int x=0;x<MAX_X;x++){
			std::cout<<arr[x][y];
			// switch (arr[x][y]){
			// 	case '@':
			// 		outArr[x][y].set(Blocks::Bomb);
			// 		break;
			// 	case 'W':
			// 		outArr[x][y].set(Blocks::Wall);
			// 		break;
			// 	case '*':
			// 		outArr[x][y].set(Blocks::Obstacle);
			// 		break;
			// 	case '/':
			// 		outArr[x][y].set(Blocks::Switch);
			// 		break;
			// 	case ' ':
			// 		outArr[x][y].set(Blocks::Air);
			// 		break;
			// 	default:
			// 		outArr[x][y].set(arr[x][y],true,true);
			// }
		}

	}

}
