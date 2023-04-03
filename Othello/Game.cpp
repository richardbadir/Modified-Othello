#include "Game.h"
#include <iostream>
#include <fstream>
#include<string>
//using namespace std;
string Game::LoadedFile;


Game::Game(Player p1, Player p2)
{
	first = p1;
	second = p2;
}

void Game::start()
{
	bool Same = true;//we don't want both players to have teh same name, as this could not only cause confusion to the players, but in Game::load() too. 
	system("cls");
	
	string P1;
	string P2;


	while (Same == true) {
		 // initializing the two
		cout << "Please enter a name for P1." << endl;
		
		cin >> P1;
		
		
		

		system("cls");
		cout << "Please enter a name for P2." << endl;
		
		cin >> P2;
		
		

		Same = false;
		if (P1 == P2) {
			system("cls");
			cout << "Players can not have the same name." << endl;
			Same = true;
		}
	}

	first= Player(P1);
	second= Player(P2);
	first.setSymbol('B');
	second.setSymbol('W');
	
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
	bool gameEnd = false;
	
	while (!(gameEnd)) {
		system("cls");
		if (board.CanFlip(current.getSymbol())) {

			board.drawBoard();
			
			int choice;
			bool goodchoice=false;
			while (!goodchoice) {//where you choose what to do
				cout<<"\n" << current.getName() << " enter 1 to save, 2 to concede, or 3 to make a move." << endl;
				cin >> choice;

			
			

				switch (choice) {
				case 1: {
					this->save();
					goodchoice = true;
					break;
				}
				case 2: {
					this->Conceded();
					goodchoice = true;
					break;
				}
				case 3: {
					system("cls");
					board.takeTurn(current);
					goodchoice = true;
					break;

				}
				default: {
					cout << "That was not a valid option" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					break;
				}

				}
			}
			
		}

		else {

			if ((!board.CanFlip(first.getSymbol())) && (!board.CanFlip(second.getSymbol()))) {//if neither player can play th game ends

				gameEnd = true;
				this->GameEnd();
				break;

			}

			cout << current.getName() << " can't play on this turn, as they can not place a piece anywhere to flip an opponent's piece." << endl;

			bool GoodChoice = false;

			while(!GoodChoice) {
				cout  << current.getName() << " enter 0 to save, 1 to concede the game, or 2 to forfeit your turn." << endl;
				
				int choice;
			
				cin >> choice;

				switch (choice) {

				case 0: {
					this->save();
					GoodChoice = true;
					
					break;
				}
				  case 1: {
					  GoodChoice = true;
					  this->Conceded();
					  break;
				}

				  case 2:{
					  GoodChoice = true;
						break;
				}
				  default: {

					  cout << "That was not a valid option"<<endl;
					  cin.clear();
					  cin.ignore(10000, '\n');
					  break;
				  }

				}
			}


		}

		if (current.getName() == first.getName()) {
			current = second;
		}
		else {
			current = first;
		}
	}
	
	
	
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
		if (rowcounter <3) {
			// skip the first 3 lines as they are used to get the players names
		}
		else {
			positions.append(text);
		}
		
		rowcounter++;
	}
	ReadFile.close();
	return Board(positions);
}

void Game::LoadingPlayers()//when load is chosen this function will set current first and second players.
{
	
	string name;
	ifstream ReadFile(LoadedFile);

	



	
	

	// Process the first line
	if (getline(ReadFile, name)) {
		first = Player(name);
		first.setSymbol('B');
	}

		// Process the second line
	if (getline(ReadFile, name)) {
		second = Player(name);
		second.setSymbol('W');
	}

	// Process the third line
	if (getline(ReadFile, name)) {
		if (name == first.getName()) {
			current = first;
		}
		else {
			current = second;
		}
	}

	ReadFile.close();
	

	
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

void Game::Conceded()
{
	system("cls");
	board.drawBoard();
	cout <<"\n" << current.getName() << " conceded the game!" << endl;
	if (current.getName() == first.getName()) {
		cout << second.getName() << " has won!" << endl;
	}
	else {
		cout << first.getName() << " has won!" << endl;
	}
	
	exit(0);
}


void Game::GameEnd() {

	system("cls");
	board.drawBoard();

	cout <<"\n" << "The game has ended as no player can longer play." << endl;

	string winner;

	int P1 = 0;
	int P2 = 0;

	for (int i = 0; i < board.getSize(); i++) {// every piece in board is checked to count how many of each player

		for (int j = 0; j < board.getSize(); j++) {
			if (board.getBoard()[i][j].getPiece() == first.getSymbol()) {
				P1++;
			}
			if (board.getBoard()[i][j].getPiece() == second.getSymbol()) {
				P2++;
			}

		}

	}
	cout << "Game Over!" << endl;
	if (P1 == P2) {
		cout << "It's a Draw!" << endl;
	}
	else if (P1>P2) {
		cout << first.getName() << " has won!" << endl;
	}
	else {
		cout << second.getName() << " has won!" << endl;
	}
	exit(0);
}
	

