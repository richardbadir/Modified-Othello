#include "Game.h"
#include <iostream>
#include <fstream>
#include<string>
//using namespace std;
string Game::LoadedFile;

Player Game::first;
Player Game::second;
Player Game::current;

Game::Game(Player p1, Player p2)
{
	first = p1;
	second = p2;
}

void Game::start()
{
	bool Same = true;//we don't want both players to have teh same name, as this could not only cause confusion to the players, but in Game::load() too. 
	system("cls");
	Player Player1;
	Player Player2;

	while (Same == true) {
		 // initializing the two
		cout << "Please enter a name for P1." << endl;
		string P1;
		cin >> P1;
		
		first = Player1;
		Player1.setSymbol('W');

		system("cls");
		cout << "Please enter a name for P2." << endl;
		string P2;
		cin >> P2;
		
		second = Player2;
		Player2.setSymbol('B');

		Same = false;
		if (P1 == P2) {
			system("cls");
			cout << "Players can not have the same name." << endl;
			Same = true;
		}
	}

	system("cls");
	
	cout << "Please choose starting positions 1 or 2." << endl << "\n1" << endl;

	bool GoodValue = false;

	string startingFile;

	while (GoodValue == false) {

		string text;// outputting first starting positions


		ifstream ReadFile1("StartingPosition1.txt");

		cout << " ABCDEFGH" << endl;

		int row = 1;
		while (getline(ReadFile1, text)) {

			cout << row << text << endl;
			row++;
		}

		//outputting second starting positions
		cout << "\n2" << endl;

		ifstream ReadFile2("StartingPosition2.txt");


		cout << " ABCDEFGH" << endl;
		row = 1;
		while (getline(ReadFile2, text)) {

			cout << row << text << endl;
			row++;
		}


		int choice;//asking the user to choose a starting position
		cin >> choice;

		
		switch (choice) {

		case 1: {
			GoodValue = true;
			startingFile= "StartingPosition1.txt";
			break;
		}

		case 2: {
			GoodValue = true;
			startingFile = "StartingPosition2.txt";
			break;
		}

		default: {
			system("cls");
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is not a valid option. Please choose either 1, or 2." << endl;
			break;
		}
		}

	}

	

	string text;
	string positions;
	ifstream ReadFile(startingFile);

	 
	

	while (getline(ReadFile, text)) {//puts every line into positions
		
		
			positions.append(text); 
		
		
	}
	
	board = Board(positions);
	current = first;
		
	
}
		

	

void Game::play()
{
	system("cls");
	board.takeTurn(current);
	
	
	
}

Board Game::load()
{
	system("cls");

	bool FileExists = false;
	string Tempfilename;
	while (FileExists == false) {
		cout << "Please enter a filename." << endl;

		cin >> Tempfilename;
		ifstream file;
		file.open(Tempfilename);
		FileExists = true;

		if (!file) { // checks if the file exists and if it is not it makes the user put in a new file name
			system("cls");
			cout << "That file does not exist" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			FileExists = false;
		}
		file.close();
	}
	LoadedFile = Tempfilename;

	string text;
	string positions;
	ifstream ReadFile(Tempfilename);

	int rowcounter = 0;// to get the first 3 rows to be players

	while (getline(ReadFile, text)) {//puts every line into positions
		if (rowcounter ==0) {
				first = Player(text);
		}
		
		else if (rowcounter == 1) {
			second = Player(text);
		}
		
		else if (rowcounter == 2) {
			current = Player(text);
		}
		else {
			positions.append(text);
		}
		
		rowcounter++;
	}
	return Board(positions);
}

void Game::save()
{
	bool Override = false;
	string File;
	while (Override == false) {

		File = "";
		system("cls");
		cout << "Please enter a name for your new saved file. Do no include a dot. (No need for .txt)" << endl; //get the new file name from user

		if (LoadedFile != "") {//if a file was loaded then  tell the user what was the file name.
			cout << "The file you're currently playing on is called " << LoadedFile << endl;
		}
		bool Valid = false;


		while (Valid == false) {
			cin >> File;
			if (File.find('.') == string::npos) {
				Valid = true;
				break;
			}

			system("cls");
			cout << "File name not valid." << " Please enter a name for your new saved file. Do no include a dot. (No need for .txt)" << endl;
		}
		File += ".txt";

		
		ifstream file;
		file.open(File);


		Override = true;

		bool ValidAnswer = false;

		if (file) { // checks if the file exists and if it is not it makes the user put in a new file name
			system("cls");
			while (ValidAnswer == false) {
				cout << "That file already exists. Do you want to override it? (y/n)" << endl;

				char answer;

				cin >> answer;
				switch (answer) {
				case 'y': case'Y': {
					ValidAnswer = true;
					break;
				}
				case 'n': case 'N': {
					ValidAnswer = true;
					Override = false;
					break;

				}
				default: {
					system("cls");
					cout << "Please enter y,Y,n, or N" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					break;
				}
				}


			}
		}


		ofstream SavedFile(File);


		SavedFile << first.getName() << endl;
		SavedFile << second.getName() << endl;
		SavedFile << current.getName() << endl;


		for (int i = 0; i < board.getSize(); i++) {// write to the new file

			if (i != 0) {
				SavedFile << "\n";
			}

			for (int j = 0; j < board.getSize(); j++) {
				SavedFile << board.getBoard()[i][j].getPiece();
			}
		}
	}
}
	

