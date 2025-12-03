#include "MainMenu.h"
#include "console.h"
#include <iostream>

namespace mainmenu
{

	const char *MAIN_MENU[] = {
		// 0123456789012345678901234567890123456789012345678901234567890123456789012345678
		"===============================================================================", // 0
		"|                                                                             |", // 1
		"|                                                                             |", // 2
		"|                                                                             |", // 3
		"|                            WELCOME TO THE GAME                              |", // 4
		"|                           ---------------------                             |", // 5
		"|                                                                             |", // 6
		"|                            (1) Start New Game                               |", // 7
		"|                           (8) View Instructions                             |", // 8
		"|                                 (9) Exit                                    |", // 9
		"|                                                                             |", // 10
		"|                                                                             |", // 11
		"|                                                                             |", // 12
		"|                                                                             |", // 13
		"|                                                                             |", // 14
		"|                                                                             |", // 15
		"|                                                                             |", // 16
		"|                                                                             |", // 17
		"|                                                                             |", // 18
		"|                                                                             |", // 19
		"|                                                                             |", // 20
		"|                                                                             |", // 21
		"|                                                                             |", // 22
		"|                                                                             |", // 23
		"==============================================================================="  // 24
	};
	const char* INSTRUCTIONS[] = {
		//0123456789012345678901234567890123456789012345678901234567890123456789012345678
		 "===============================================================================", // 0
		 "|                               INSTRUCTIONS                                  |", // 1
		 "|                           --------------------                              |", // 2
		 "|     GOAL: Both players must cooperate to reach the FINAL ROOM together.     |", // 3
		 "|  -------------------------------- | --------------------------------------  |", // 4
		 "|            CONTROLS (Auto - Move) | MAP LEGEND & ITEMS                      |", // 5
		 "|  -------------------------------- | --------------------------------------  |", // 6
		 "|     ACTION      P1($)    P2(&)    |   W    Wall      Blocks movement        |", // 7
		 "|     UP            W        I      |   #    Spring    Boosts speed           |", // 8
		 "|     DOWN          X        M      |   *    Obstacle  Pushable object        |", // 9
		 "|     LEFT          A        J      |   !    Torch     Lights dark rooms      |", // 10
		 "|     RIGHT         D        L      |   @    Bomb      Explodes (5 sec)       |", // 11
		 "|     STAY          S        K      |   K    Key       Unlocks Doors (1-9)    |", // 12
		 "|     DISPOSE       E        O      |   /    Switch    Toggles doors          |", // 13
		 "|                                   |   ?    Riddle    Must solve to pass     |", // 14
		 "|    * Characters move until STOP   |                                         |", // 15
		 "|      is pressed or hit a wall.    |                                         |", // 16
		 "|  -------------------------------- | --------------------------------------  |", // 17
		 "|     SYSTEM: [ESC] - Pause game                                              |", // 18
		 "|             H - From Pause menu, return to main menu                        |", // 19
		 "|            * Exiting back to main menu clears progress.                     |", // 20
		 "|     INVENTORY : Shown at top of screen.Lists items held by each player.     |", // 21
		 "|=============================================================================|", // 22
		 "|                          Press [ESC] to return                              |", // 23
		 "==============================================================================="  // 24
	};

	void showMainMenu(Screen *screen)
	{
		screen->draw_static(MAIN_MENU, 25);
	}

	int getMenuChoice()
	{
		while (true)
		{
			if (check_kbhit())
			{
				char c = get_single_char();

				if (c == '1')
					return 1; // New Game
				if (c == '8')
					return 8; // Instructions
				if (c == '9')
					return 9; // Quit
			}
			sleep_ms(50);
		}
	}
}