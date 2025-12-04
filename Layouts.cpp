#include 'Layouts.h'

void getLayout(int id) {
	switch (id) {
		case 1:
			return designs::room_1;
		// Add more cases for different layouts as needed
		default:
			return nullptr; // or some default layout
	}
}