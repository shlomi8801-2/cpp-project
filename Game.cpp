#include "Game.h"
#include "MainMenu.h"

enum class gameState;

// Constructor and Destructor
Game::Game() {
	currentState = gameState::mainMenu;
	currentScreen = new Screen;
	rooms[3] = nullptr;
	currRoomId = -1;

	player1 = nullptr;
	player2 = nullptr;
};

Game::~Game() {
	if (currentScreen != nullptr) {
		delete currentScreen;
	}
	for (Game& room : rooms) {
		if room != nullptr {
			delete room;
		}
	}
	if (player1 != nullptr) {
		delete player1;
	}
	if (player2 != nullptr) {
		delete player2;
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

	rooms[0] = new Room(0);
	rooms[1] = new Room(1);
	rooms[2] = new Room(2);

	for (int i = 0; i < 3; i++) {
		rooms[i]->setScreen(screen);
		rooms[i]->initializeDefault();
	}

	currentRoomIndex = 0;
	rooms[0]->activate();

	player1 = new Player(Point(5, 5, 0, 0, 'A'), nullptr, 1);
	player2 = new Player(Point(10, 5, 0, 0, 'B'), nullptr, 2);
}

void static Player::handleInput() {

	if (check_kbhit()) {
		char pressed = get_single_char();

		if (pressed == Action::ESC) {
			// Open Pause Menu

			return;
		}
		else {
			for (const PlayerKeyBinding& binding : movements) {
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

void changeRoom(int newRoomId, int spawnX, int spawnY) {
	currentRoomId = newRoomId;
	game.rooms[newRoomId]->activate();
	player1->setPosition(spawnX, spawnY);
	player2->setPosition(spawnX + 2, spawnY);
}

void gameLoop(Game& game) {
	// Main game loop
	while (game.currentState == gameState::inGame) {
		// Handle player input
		Player::handleInput();

		game.levels->Player1.move();
		// Update game state
		// ...
		// Render screen
		game.currentScreen->draw();
	}
}

