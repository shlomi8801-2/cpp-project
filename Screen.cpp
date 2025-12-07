#include "Screen.h"
#include "Point.h"
#include "Layouts.h"

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

bool Screen::isObject(const Point& p) const { 
	if (getCharAt(p) != ' ' && getCharAt(p) != 'W') {
		return true;
	}
	return false;
}

ObjectType Screen::objectIs(const Point& p) {
	char ch = Screen::getCharAt(p);
	switch (ch)
	{
	case '#':
		return ObjectType::SPRING;
		break;
	case '*':
		return ObjectType::OBSTACLE;
		break;
	case '!':
		return ObjectType::TORCH;
		break;
	case '@':
		return ObjectType::BOMB;
		break;
	case 'K':
		return ObjectType::KEY;
		break;
	case '\\':
		return ObjectType::SWITCH_OFF;
		break;
	case '?':
		return ObjectType::RIDDLE;
		break;
	default:
		return ObjectType::AIR;
	}
}

