#pragma once
#include "Player.h"
#include "Board.h"


class Game
{
public:
	Game(Player p1, Player p2);
	void start();
	void play();
	static Board load();
	void setBoard(Board a) { board = a; }

private:
	void save();
	static Player first;
	static Player second;
	static Player current;
	Board board;
	static string LoadedFile;
	

};


