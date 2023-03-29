#include "Board.h"
#include <iostream>

Board::Board(string positions)
{
    int len = size*size;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++) {// the positions in the array are filled with Positions
        board[row][col] = Position(positions[i]);
        col++;
        if (col == 8) {
            row++;
            col = 0;
        }
    }
}

void Board::drawBoard()
{
    cout << " ABCDEFGH";
    for (int i = 0; i < size; i++) {
        cout << "\n"<<i+1;
        for (int j = 0; j < size; j++) {
            cout << board[i][j].getPiece();
        }
    }
}

int asciiToNumber(char symbol) { return (int)symbol; };//  this function is used to cast char into int and then we will use this to know what position was wanted

void Board::takeTurn(Player current)
{
    
    this->drawBoard();
    cout << "\n"<<current.getName()<<" please enter the capital letter of the column you want to play on followed by the number of the row you want to play on." << endl;

    string input;
    
    cin >> input;

    if (input.length() != 2) {// if there were not 2 symbols entered there is a problem
        system("cls");
        cout << "Please enter exactly two symbols." << endl;
        takeTurn(current);
    }


    int Acolumn=asciiToNumber(input[0]); //Acolumn is the column "in ascii"

    int Bcolumn=Acolumn-65;//this is the actual column that was requested. 65 is because capital A is ascii code 65.


    int Arow = asciiToNumber(input[1]);//same as column
    int Brow = Arow - 49;//49 is Ascii code for 1

    if (Bcolumn > size || Bcolumn<0 || Brow>size || Brow < 0) {//checks if the input exists on the board
        system("cls");
        cout << "That was not a valid input as it is not on the board." << endl;
        takeTurn(current);
    }
    
    
    board[Brow][Bcolumn] = current.getSymbol();
    


    system("cls");
    this->drawBoard();
    

}


