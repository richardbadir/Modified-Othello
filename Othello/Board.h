#pragma once
#include <string>
#include "Position.h"
#include "UnplayablePosition.h"

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
	bool CanFlip(char symbol);


private:
	static const int size = 8;
	Position board[size][size];
	bool checkLeft(char c, const int row, int column,bool first);
	bool checkRight(char c, const int row, int column, bool first);
	bool checkUp(char c, int row, const int column, bool first);
	bool checkDown(char c, int row, const int column, bool first);
	bool checkTopLeft(char c, int row, int column, bool first);
	bool checkTopRight(char c, int row, int column, bool first);
	bool checkBottomLeft(char c, int row, int column, bool first);
	bool checkBottomRight(char c, int row, int column, bool first);
	void FlipLeft(char c, const int row, int column);
	void FlipRight(char c, const int row, int column);
	void FlipUp(char c, int row, const int column);
	void FlipDown(char c, int row, const int column);
	void FlipBottomRight(char c, int row, int column);
	void FlipBottomLeft(char c, int row, int column);
	void FlipTopLeft(char c, int row, int column);
	void FlipTopRight(char c, int row, int column);
	
};

