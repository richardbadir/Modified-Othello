#pragma once

class Position
{
public:
	Position() {}; //delete this
	Position(char Piece) {	piece = Piece;	}
	void setPiece(char character) { piece = character; }
	bool canPlay();
	static const char EMPTY = ' ';
	static const char WHITE = 'W';
	static const char BLACK = 'B';
	char getPiece() { return piece; }

private:
	char piece;
};

