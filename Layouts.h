#pragma once
#include "Screen.h"

Screen* getLayout(int id);



namespace designs
{
	static Screen mainMenu({
		//0123456789012345678901234567890123456789012345678901234567890123456789012345678
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
	});

	static Screen instructions({
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
		 "|     DISPOSE       E        O      |   / \  Switch    Toggles doors          |", // 13
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
	});

	static Screen room_0({
		//0123456789012345678901234567890123456789012345678901234567890123456789012345678
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
		"W                                                                             W", // 1
		"W                                                                             W", // 2
		"W             WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW         WWWW                     W", // 3
		"W             W                            W         WWWW                     W", // 4
		"W       \\     W                            W         WWWW                     0", // 5
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW            W         WWWW                     W", // 6
		"W                             W            W         WWWW                     W", // 7
		"W                             W            W         WWWW                     W", // 8
		"WWWWWWWWWWWWWWWWWWWWWWWW      W            W         WWWW                     W", // 9
		"W          WWWWWWW     W      W            W         WWWW                     W", // 10
		"W          W     W     W      W            W         WWWW                     W", // 11
		"W          W     W     W      W            W         WWWW                     W", // 12
		"W          W     W     W      W            W         WWWW                     W", // 13
		"W          W     W     W      W            W         WWWW                     W", // 14
		"W          W     W     W      W            W         WWWW       W***W         W", // 15
		"W          W     W  \\  W      WWWWWWWWWWWWWW         WWWW       W K W         W", // 16
		"W          WWWWWWWWWWWWW                             WWWW       WWWWW         W", // 17
		"W                                                    WWWW                     W", // 18
		"W                                                    WWWW                     W", // 19
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 20
		"W                          ------ INVENTORY ------                            W", // 21
		"W       PLAYER 1:                     |       PLAYER 2:                       W", // 22
		"W                                                                             W", // 23
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"  // 24
	});
}



