#pragma once

enum class gameState {
	mainMenu,
	instructions,
	quit,
	inGame,
	paused,
	gameOver,
	victory
};

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STAY
};

enum class Action {
    DROP_ITEM,
	ESC = 27
};

enum class ScreenSize { MAX_X = 80, MAX_Y = 25 };