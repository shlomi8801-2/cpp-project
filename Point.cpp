#include "Point.h"
#include "Constants.h"

void Point::move() {
	x = (x + diff_x + ScreenSize::MAX_X) % ScreenSize::MAX_X;
	y = (y + diff_y + ScreenSize::MAX_Y) % ScreenSize::MAX_Y;
}

void Point::setDirection(Direction dir) {
	switch (dir) {
	case Direction::UP:
		diff_x = 0;
		diff_y = -1;
		break;
	case Direction::DOWN:
		diff_x = 0;
		diff_y = 1;
		break;
	case Direction::RIGHT:
		diff_x = 1;
		diff_y = 0;
		break;
	case Direction::LEFT:
		diff_x = -1;
		diff_y = 0;
		break;
	case Direction::STAY:
		diff_x = 0;
		diff_y = 0;
		break;
	}
}