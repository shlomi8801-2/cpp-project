#pragma once
#include "Player.h"
#include "Screen.h"
// #include "Item.h"
#include "Constants.h"
#include "Room.h"

class Game {
	// Current state of the game
	gameState currentState;

	// Current screen - the idea is to have multiple screens for menus, game, etc. that can be switched.
	// This is because if the players move to a new screen and then return, we want to preserve the screen state.
	Screen* currentScreen;

	Player players[2];
	
	int currRoomId;
	
public:
	Game::Game();
	Game::~Game();

	void setState(gameState newState) { currentState = newState; }
	gameState getState() const { return currentState; }
	inline int getCurrentState() {return (int)currentState;}
	inline Screen* getCurrentScreen() {return currentScreen;}
	void setScreen(int roomId);
	void setScreen(Room& room);
	void static handleMainMenuChoice(gameState& state);
	void static handleInstructionsChioce(gameState& state);

	static void Game::launchGame();
	void Game::changeRoom(int newRoomId, Room newRoom, int spawnX, int spawnY);
};