#include "Game.h"
#include "MainMenu.h"

enum class gameState;

// Constructor and Destructor
Game::Game() {
	currentState = mainMenu;
	currentScreen = new Screen;
	levels = nullptr;
};

Game::~Game() {
	if (currentScreen != nullptr) {
		delete currentScreen;
	}
	if (currentLevelItems != nullptr) {
		delete currentLevelItems;
	}
};

void static Game::launchGame() {

	Game newGame;
	gameState& currState = newGame.currentState;
	Screen*& currScreen = newGame.currentScreen;
	bool running = true;

	while (running) {
		switch (currState) {
		case gameState::mainMenu:
			// Show main menu
			MainMenu::showMainMenu(currScreen);
			// Handle menu choice
			handleMainMenuChoice(currState);
			break;
		
		case gameState::instructions:
			// Show instructions screen
			MainMenu::showInstructions(currScreen);
			// Handle return to main menu
			handleInstructionsChoice(currState);
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

void Game::initialize() {

	levels = new Levels(*currentScreen, currentState);
	rooms[0] = new Room(0);

}

void static Player::handleInput() {

	if (check_kbhit()) {
		char pressed = get_single_char();

		if (pressed == Action::ESC) {
			// Open Pause Menu

			return;
		}
		else {
			for (static constexpr PlayerKeyBinding& binding : movements) {
				if (binding.key == pressed) {
					Player::movePlayer(binding.playerID, binding.action);
					return;
				}
			}
			for (const& PlayerKeyBinding binding : actions) {
				if (binding.key == pressed) {
					Player::performAction(binding.playerID, binding.action);
					return;
				}
			}
		}
	}
};