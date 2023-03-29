#pragma once
#include <string>
#include "Position.h"
#include "Player.h"
#include<vector>

class Board
{
	
public:
	Board() {};//delete this
	Board(string positions);
	int getSize() { return size; }
	void drawBoard();
	auto getBoard() { return board; }
	void takeTurn(Player current);


private:
	static const int size = 8;
	Position board[size][size];
};

