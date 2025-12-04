#pragma once

enum class gameState
{
	mainMenu,
	instructions,
	quit,
	inGame,
	paused,
	gameOver,
	victory
};


enum Keys{

	ESC = 27

};

enum ScreenSize
{
	MAX_X = 80,
	MAX_Y = 25,
	LEGEND_HEIGHT = 3
};
