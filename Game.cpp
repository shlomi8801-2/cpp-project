#include "Game.h"
#include "Room.h"

enum class gameState;

// Constructor and Destructor
Game::Game() {
	currentState = gameState::mainMenu;
	currentScreen = new Screen;
	currRoomId = -1;

	player1 = nullptr;
	player2 = nullptr;
};

Game::~Game() {
	if (currentScreen != nullptr) {
		delete currentScreen;
	}

	if (player1 != nullptr) {
		delete player1;
	}
	if (player2 != nullptr) {
		delete player2;
	}
};

void Game::launchGame() { // no need for static its spacified in Game.h

	Game game;
	bool running = true;

	while (running) {
		switch (currentState) {
		case gameState::mainMenu:
			// Show main menu
			Room::showMainMenu(currentScreen);
			// Handle menu choice
			Room::handleMainMenuChoice(currentState);
			break;
		
		case gameState::instructions:
			// Show instructions screen
			Room::showInstructions(currScreen);
			// Handle return to main menu
			Room::handleInstructionsChioce(currentState);
			break;
		
		case gameState::inGame:
			// Main game loop
			// Handle player input, update game state, render screen

			break;
		
		case gameState::paused:
			// Show pause menu
			// Handle resume or exit to main menu
			break;
		
		case gameState::gameOver:
			// Show game over screen
			// Handle return to main menu
			break;
		
		case gameState::victory:
			// Show victory screen
			// Handle return to main menu
			break;

		case gameState::quit:
			// Exit the game loop
			running = false;
			break;
		}
	}

}


void Game::changeRoom(int newRoomId, int spawnX, int spawnY) {
	currRoomId = newRoomId;
	rooms[newRoomId]->activate();
	player1->setPosition(spawnX, spawnY);
	player2->setPosition(spawnX + 2, spawnY);
}

static void handleInput() {

	if (check_kbhit()) {
		char pressed = get_single_char();

		if (pressed == (int)(Action::ESC)) {
			// Open Pause Menu

			return;
		}
		else {
			for (constexpr PlayerKeyBinding binding : actions) {
				if (binding.key == pressed) {
					Player::performAction(binding.playerID, binding.action);
					return;
				}
			}
		}
	}
};

void gameLoop(Game& game) {
	// Main game loop
	while (game.getCurrentState() == (int)gameState::inGame) {
		
		// Handle player input
		Player::handleInput();

		game.player1->move();
		game.player2->move();

		game.getCurrentScreen()->draw();

		sleep_ms(50); // Control game speed
	}
}

