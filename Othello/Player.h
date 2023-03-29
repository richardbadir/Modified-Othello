#pragma once
#include <string>
using namespace std;

class Player
{public:
	
	Player(string name = " ") { Name = name; };
	void setName(string name) { Name:name; }
	string getName() { return Name; }
	char getSymbol() { return Symbol; }
	void setSymbol(char s) { Symbol = s; }

private:
	string Name;
	char Symbol;
};

