#pragma once

enum gameState
{
	mainMenu,
	instructions,
	quit,
	inGame,
	paused,
	gameOver,
	victory
};

enum class Direction // leave as class because its not used as int as much and also defined STAY twice
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STAY
};

enum Action
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	STAY,
	DROP_ITEM,
	ESC = 27
};

enum ScreenSize
{
	MAX_X = 80,
	MAX_Y = 25
};
