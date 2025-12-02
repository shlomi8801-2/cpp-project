#include "Screen.h"


using namespace std;

 

void drawDefaultWalls() {

    for (int i = 0; i < ScreenSize::MAX_X; i++) {
        DrawAt(i, 0, '#');
        DrawAt(i, 20, '#');
	}
    for (int i = 1; i < ScreenSize::MAX_Y - 6; i++) {
        DrawAt(0, i, '#');
        DrawAt(79, i, '#');
	}
}

char Screen::getCharAt(const Point& p) const {
    return screen[p.getY()][p.getX()];
}

bool isWall(const Point& p) const {
    return getCharAt(p) == '#';
}

