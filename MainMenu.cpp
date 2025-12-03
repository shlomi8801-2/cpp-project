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