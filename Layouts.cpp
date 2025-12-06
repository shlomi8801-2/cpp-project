#include "Layouts.h"


Screen* getLayout(int id) {
	switch (id) {
		case -2:
			return &designs::mainMenu;
		case -1:
			return &designs::instructions;
		case 0:
			return &designs::room_0;
		// Add more cases for different layouts as needed
		default:
			return &designs::room_0; // or some default layout
	}
}