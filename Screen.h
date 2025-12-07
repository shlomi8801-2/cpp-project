#pragma once
#include <iostream>
#include "Layouts.h"
#include "Constants.h"
#include "Object.h"

enum class ObjectType;

class Point;

using std::cout, std::endl;

class Screen
{
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

	ObjectType objectIs(const Point& p);
};
