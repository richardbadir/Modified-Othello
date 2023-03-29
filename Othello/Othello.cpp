// Richard Badir 40249566

#include <iostream>
#include "Game.h"
#include< stdlib.h >
#include <fstream>
#include<string>
using namespace std;

int main()
{

	Player Player1;//the two players
	Player Player2;
	bool GoodValue = false;// to be true user input has to be 1, 2, or 3
	
	

	Game game(Player1, Player2);
	while (GoodValue == false) {
		cout << "1. Quit" << endl << "2. Load Game" << endl << "3. Start a New Game" << endl;

		cout << "Enter the corresponding number to the action you want to do" << endl;

		int choice;


		cin >> choice;
		GoodValue = true;

		switch (choice) {
		case 1: {
			exit(0);
			break;
		}
		case 2: {
			
			game.setBoard(Game::load());
			break;
		}

		case 3: {
			game.start();
			break;
		}
		default: {
			system("cls");
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is not a valid option. Please choose either 1, 2, or 3" << endl;
			GoodValue = false;
			break;
		}

		}

	}
	game.play();
	

	
}
