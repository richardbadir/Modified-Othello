#pragma once
#include "Position.h"

class UnplayablePosition: public Position
{public:
	UnplayablePosition() {};
	UnplayablePosition(char piece) :Position(piece) {};
	static const char UNPLAYABLE = '*';
	bool canPlay() { return false; }
};

