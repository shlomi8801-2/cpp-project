#include "Game.h"
#include "Room.h"
#include "Layouts.h"
#include "Screen.h"

enum class gameState;

// Constructor and Destructor
Game::Game() {
	currentState = gameState::mainMenu;
	currentScreen = nullptr;
	currRoomId = -1;
	players[2] = {};
};

Game::~Game() {
	if (currentScreen != nullptr) {
		delete currentScreen;
	}

	
};

void Game::launchGame() { // no need for static its spacified in Game.h

	Game game;
	bool running = true;

	while (running) {
		switch (currentState) {
		case gameState::mainMenu:
			// Show main menu
			setScreen(-2);
			// Handle menu choice
			handleMainMenuChoice(currentState);
			break;
		
		case gameState::instructions:
			// Show instructions screen
			setScreen(-1);
			// Handle return to main menu
			handleInstructionsChioce(currentState);
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

void Game::handleMainMenuChoice(gameState& state) {
	if (check_kbhit()) {
		char choice = get_single_char();
		if (choice == '1') {
			state = gameState::inGame;  // New Game
			return;  // New Game
		}
		if (choice == '8') {
			state = gameState::instructions;
			return;  // Instructions
		}
		if (choice == '9') {
			state = gameState::quit;
			return;  // Quit
		}
		sleep_ms(50);
	}

}

void Game::handleInstructionsChioce(gameState& state) {
	if (check_kbhit()) {
		char choice = get_single_char();
		if (choice == 27) { // ESC key
			state = gameState::mainMenu;
			return;  // Return to main menu
		}
		sleep_ms(50);
	}
}


void Game::setScreen(int roomId) {
	// Set the current room based on room ID
	currentScreen = getLayout(roomId);
	currentScreen->draw();
}

void Game::setScreen(Room& room) {
	// Set the current room based on Room object
	currentScreen = room.mods;
	currentScreen->draw();
}

void Game::changeRoom(int newRoomId, Room newRoom, int spawnX, int spawnY) {
	currRoomId = newRoomId;
	if (newRoom.haveMods) { setScreen(newRoom); }
	else { 
		setScreen(currRoomId);
		newRoom.haveMods = true;
		newRoom.mods = *currentScreen;
	}
	player1->setPosition(spawnX, spawnY);
	player2->setPosition(spawnX + 2, spawnY);
}

void gameLoop(Game& game) {
	// Main game loop

	Player players[2] = {
		Player(Point(5, 7, 0, 0, 'a'), Object(), game.currentScreen, 1),
		Player(Point(5, 9, 0, 0, 'b'), Object(), game.currentScreen, 2)
	};

	Player* player1 = &players[0];
	Player* player2 = &players[1];

	Room** rooms = new Room*[TOTAL_ROOMS];  // Array of pointers to Room
	Object* doors[TOTAL_ROOMS];
	for (int i = 0; i < TOTAL_ROOMS; i++) {
		char doorNum = char('0' + i);
		doors[i](ObjectType::DOOR, Point(-1, -1, 0, 0, doorNum);
		doors[i]->setSprite(doorNum);

	}
	Room::initializeRooms(rooms);
	rooms[0]->active = true;
	game.changeRoom(0, *rooms[0], 5, 7);

	while (game.currentState == gameState::inGame) {
		
		// Handle player input
		Player::handleInput();

		player1->move();
		player2->move();

		sleep_ms(50); // Control game speed
	}

	// Clean up
	for (int i = 0; i < TOTAL_ROOMS; i++) {
		delete rooms[i];
	}
	delete[] rooms;
}

















