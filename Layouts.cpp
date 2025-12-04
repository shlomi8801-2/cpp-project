#include "Layouts.h"
#include "Blocks.h"
#include "Constants.h"

// Maybe will be changed to a class later if neccessary. Didn't think it through yet.
namespace levels
{
	const char* level2map[80] = {
	 // 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
		"W                                                                             W", // 1
		"W                                                                             W", // 2
		"W                                                                             W", // 3
		"W                            WWWWWWWWWWWWWWWWWWW                              W", // 4
		"W                           WWWWWWWWWWWWWWWWWWWWW                             W", // 5
		"W                                              @W                             W", // 6
		"W                           WWWWWWWWWWWWWWWWWWWWW                             W", // 7
		"W                       #   WWWWWWWWWWWWWWWWWWWWW                             W", // 8
		"W                       *         WWWW   W                                    1", // 9
		"W                       /                                                     W", // 10
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
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" // 21
	};
	//in the levels functions dont use screen->draw it causes infinite recursion
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
		generateLayoutFromArr(level2map,screen);
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
	}
	void generateLayoutFromArr(const char* arr[MAX_Y-LEGEND_HEIGHT], Screen* screen)
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
		for (int y=0;y<MAX_Y-LEGEND_HEIGHT;y++)
		for (int x=0;x<MAX_X;x++){
			// std::cout<<(screen->getatxy(x,1))->getSprite()<<x<<std::flush;
			Object* targetedblock = (screen->getatxy(x,y));
			switch (arr[y][x]){ // idk why its backwards maybe because
				case '@':
					targetedblock->set(Blocks::Bomb);
					break;
				case 'W':
					targetedblock->set(Blocks::Wall);
					break;
				case '*':
					targetedblock->set(Blocks::Obstacle);
					break;
				case '/':
					targetedblock->set(Blocks::Switch);
					break;
				case ' ':
					targetedblock->set(Blocks::Air);
					break;
				case '1'://runs the same code for multiple cases
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					targetedblock->set(Blocks::Door);
					targetedblock->setDoorId(arr[y][x]);
					targetedblock->setSprite(arr[y][x]);
					break;

				default:
					(screen->getatxy(x,y))->set(arr[y][x],true,true);
					break;
			}
		
		}
	}

}
