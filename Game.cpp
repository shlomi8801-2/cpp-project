#include "Game.h"
#include "MainMenu.h"
#include "Room.h"

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
	for (Room* room : rooms) {
		if (room != nullptr) {
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

void Game::launchGame() { // no need for static its spacified in Game.h

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
			MainMenu::handleMainMenuChoice(currState);
			break;
		
		case gameState::instructions:
			// Show instructions screen
			MainMenu::showInstructions(currScreen);
			// Handle return to main menu
			MainMenu::handleInstructionsChioce(currState);
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
		rooms[i]->setScreen(currentScreen);
		rooms[i]->initializeDefault();
	}

	currRoomId = 0;
	rooms[0]->activate();

	player1 = new Player(Point(5, 5, 0, 0, 'A'), nullptr, 1);
	player2 = new Player(Point(10, 5, 0, 0, 'B'), nullptr, 2);
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

