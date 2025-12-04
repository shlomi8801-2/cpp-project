#include "Room.h"

Room::Room(int id){
	roomId = id;
	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			mods[i][j] = ' ';
		}
	}
}


void addMod(int x, int y, char modChar);