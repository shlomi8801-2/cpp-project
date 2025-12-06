#include "Screen.h"
#include "Point.h"

char Screen::getCharAt(const Point& p) const {
	return screen[p.getY()][p.getX()];
}

void Screen::draw() const {
	clrscr();
	gotoxy(0, 0);
	for (size_t i = 0; i < MAX_Y - 1; ++i) {
		cout << screen[i] << endl;
	}
	cout << screen[MAX_Y - 1];
	cout.flush();
}

Object Screen::objectIs(const Point& p) {
	char ch = Screen::getCharAt(p);
	switch (ch)
	{
	case ' ':
		return objects[0];
		break;
	case 'W':
		return objects[1];
		break;
	case '#':
		return objects[2];
		break;
	case '*':
		return objects[3];
		break;
	case '!':
		return objects[4];
		break;
	case '@':
		return objects[5];
		break;
	case 'K':
		return objects[6];
		break;
	case '\\':
		return objects[7];
		break;
	case '?':
		return objects[8];
		break;
	default:
		return objects[0]; // Default to AIR if unknown
		break;
	}
}

