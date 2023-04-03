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
	void LoadingPlayers();

private:
	void save();
	Player first;
	Player second;
	Player current;
	void Conceded();
	void GameEnd();
	Board board;
	static string LoadedFile;
	

};


