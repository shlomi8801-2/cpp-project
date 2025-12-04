#pragma once
#include <iostream>
#include 'Layouts.h'

class Point;

using std::cout, std::endl;

class Screen
{
public:
	enum { MAX_X = 80, MAX_Y = 25 };
private:
	const char* screen[MAX_Y];

	char getCharAt(const Point& p) const;

public:

	// Constructor that takes a screen layout
	Screen(const char* layout[MAX_Y]) {
		for (int i = 0; i < MAX_Y; i++) {
			screen[i] = layout[i];
		}
	}

	void draw() const;

	bool isWall(const Point& p) const {
		return getCharAt(p) == '#';
	}

};

// Screen layouts namespace
namespace Screens {

	// Main Menu Screen
	extern const char* MAIN_MENU[Screen::MAX_Y];
}
