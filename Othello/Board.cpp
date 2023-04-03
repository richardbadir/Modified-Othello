#include "Board.h"
#include <iostream>

const char UnplayablePosition::UNPLAYABLE;

Board::Board(string positions)
{
    int len = size*size;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++) {// the positions in the array are filled with Positions

        if (positions[i] == ' ') {
            board[row][col] = Position(positions[i]); 
        }

        else {
            board[row][col] = UnplayablePosition(positions[i]);
        }
        col++;
        if (col == 8) {
            row++;
            col = 0;
        }
    }
}

void Board::drawBoard()
{
    cout << " A B C D E F G H";
    for (int i = 0; i < size; i++) {
        cout << "\n"<<i+1;
        for (int j = 0; j < size; j++) {
            cout << board[i][j].getPiece()<<" ";
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
        return takeTurn(current);
    }


    int Acolumn=asciiToNumber(input[0]); //Acolumn is the column "in ascii"

    int Bcolumn=Acolumn-65;//this is the actual column that was requested. 65 is because capital A is ascii code 65.


    int Arow = asciiToNumber(input[1]);//same as column
    int Brow = Arow - 49;//49 is Ascii code for 1



    if (Bcolumn > size || Bcolumn<0 || Brow>size || Brow < 0) {//checks if the input exists on the board
        system("cls");
        cout << "That was not a valid input as it is not on the board." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return takeTurn(current);
    }
    
    if (board[Brow][Bcolumn].getPiece() == UnplayablePosition::UNPLAYABLE) {
        system("cls");
        cout << "That was not a valid input as this position is unplayable." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return takeTurn(current);
    }

    if (board[Brow][Bcolumn].getPiece() == 'W' || board[Brow][Bcolumn].getPiece() == 'B') {
        system("cls");
        cout << "That was not a valid input as this position is already taken." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return takeTurn(current);
    }
    if (current.getSymbol() == 'W') { // this part checks if the move you played flips an opponent's piece then plays your move

        if (checkLeft('B', Brow, Bcolumn, true) || checkRight('B', Brow, Bcolumn, true) || checkUp('B', Brow, Bcolumn, true) || checkDown('B', Brow, Bcolumn, true) || checkTopLeft('B', Brow, Bcolumn, true) || checkBottomLeft('B', Brow, Bcolumn, true) || checkBottomRight('B', Brow, Bcolumn, true) || checkTopRight('B', Brow, Bcolumn, true)) {

            board[Brow][Bcolumn] = UnplayablePosition(current.getSymbol());//placing the piece

            if (checkLeft('B', Brow, Bcolumn, true)) {// if you can flip in one direction then you flip in that direction
                FlipLeft('B', Brow, Bcolumn);
            }
            if (checkRight('B', Brow, Bcolumn, true)) {
                FlipRight('B', Brow, Bcolumn);
            }
            if (checkUp('B', Brow, Bcolumn, true)) {
                FlipUp('B', Brow, Bcolumn);
            }
            if (checkDown('B', Brow, Bcolumn, true)) {
                FlipDown('B', Brow, Bcolumn);
            }
            if (checkTopLeft('B', Brow, Bcolumn, true)) {
                FlipTopLeft('B', Brow, Bcolumn);
            }
            if (checkBottomLeft('B', Brow, Bcolumn, true)) {
                FlipBottomLeft('B', Brow, Bcolumn);
            }
            if (checkBottomRight('B', Brow, Bcolumn, true)) {
                FlipBottomRight('B', Brow, Bcolumn);
            }
            if (checkTopRight('B', Brow, Bcolumn, true)) {
                FlipTopRight('B', Brow, Bcolumn);
            }
        }

        else {
            system("cls");
            cout << "That was not a valid move. When playing a piece, you must flip at least one of your opponent's pieces." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return takeTurn(current);
        }
    }
    
    else {// same thing as earlier but if the current player is B
        if (checkLeft('W', Brow, Bcolumn, true) || checkRight('W', Brow, Bcolumn, true) || checkUp('W', Brow, Bcolumn, true) || checkDown('W', Brow, Bcolumn, true) || checkTopLeft('W', Brow, Bcolumn, true) || checkBottomLeft('W', Brow, Bcolumn, true) || checkBottomRight('W', Brow, Bcolumn, true) || checkTopRight('W', Brow, Bcolumn, true)) {

            board[Brow][Bcolumn] = UnplayablePosition(current.getSymbol());//placing the piece

            if (checkLeft('W', Brow, Bcolumn, true)) {// if you can flip in one direction then you flip in that direction
                FlipLeft('W', Brow, Bcolumn);
            }
            if (checkRight('W', Brow, Bcolumn, true)) {
                FlipRight('W', Brow, Bcolumn);
            }
            if (checkUp('W', Brow, Bcolumn, true)) {
                FlipUp('W', Brow, Bcolumn);
            }
            if (checkDown('W', Brow, Bcolumn, true)) {
                FlipDown('W', Brow, Bcolumn);
            }
            if (checkTopLeft('W', Brow, Bcolumn, true)) {
                FlipTopLeft('W', Brow, Bcolumn);
            }
            if (checkBottomLeft('W', Brow, Bcolumn, true)) {
                FlipBottomLeft('W', Brow, Bcolumn);
            }
            if (checkBottomRight('W', Brow, Bcolumn, true)) {
                FlipBottomRight('W', Brow, Bcolumn);
            }
            if (checkTopRight('W', Brow, Bcolumn, true)) {
                FlipTopRight('W', Brow, Bcolumn);
            }
        }
        else {
            system("cls");
            cout << "That was not a valid move. When playing a piece, you must flip at least one of your opponent's pieces." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return takeTurn(current);
        }
    
    }

    system("cls");
    

}


bool Board::CanFlip(char symbol)
{   

    Position* playable; // all positions wihtout an empty space on them are UnplayablePosition
    
    

    for (int row=0; row < size;row++) {

        for (int column=0; column < size; column++) {

            playable = &board[row][column];
            if (playable->canPlay()) {
                
                if (board[row][column].getPiece() == ' ') {//I don't understand why the pointer thing I did above this doesn't work 
                    if (symbol == 'W') {

                        if (checkLeft('B', row, column, true) || checkRight('B', row, column, true) || checkUp('B', row, column, true) || checkDown('B', row, column, true) || checkTopLeft('B', row, column, true) || checkBottomLeft('B', row, column, true) || checkBottomRight('B', row, column, true) || checkTopRight('B', row, column, true)) {
                            return true;
                        }
                    }

                    else {
                        if (checkLeft('W', row, column, true) || checkRight('W', row, column, true) || checkUp('W', row, column, true) || checkDown('W', row, column, true) || checkTopLeft('W', row, column, true) || checkBottomLeft('W', row, column, true) || checkBottomRight('W', row, column, true) || checkTopRight('W', row, column, true)) {

                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool Board::checkLeft(char c, const int row, int column, bool first) {//keeps checking to the left if it is the same character. if it is not and it's not the otehr player character (B or W) then returns false, but if it is then it returns true
    bool notfirst = false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) { //always put in true for first when passing the function manually.
        if (board[row][column - 1].getPiece() != c) {

            return false;

        }
    }

    if (column == 0) {
        return false;
    }

    if (board[row][column -1].getPiece() == c) {
        return checkLeft(c, row, column - 1, notfirst);
    }
    else if (board[row][column - 1].getPiece() == ' ' || board[row][column - 1].getPiece() == UnplayablePosition::UNPLAYABLE) {

        return false;

    }
    else {
        return true;
    }
}


void Board::FlipLeft(char c, const int row, int column) {//once we check if that position flips to the left, this function actually flips the pieces

    

    if (board[row][column - 1].getPiece() == c) {
        if (c == 'W') {
            board[row][column - 1].setPiece('B');
        }
        else {
            board[row][column - 1].setPiece('W');
        }
        return FlipLeft(c, row, column - 1);
    }
    
}

void Board::FlipRight(char c, const int row, int column) {



    if (board[row][column + 1].getPiece() == c) {
        if (c == 'W') {
            board[row][column + 1].setPiece('B');
        }
        else {
            board[row][column + 1].setPiece('W');
        }
        return FlipRight(c, row, column + 1);
    }

}

void Board::FlipUp(char c, int row, const int column) {




    if (board[row-1][column].getPiece() == c) {
        if (c == 'W') {
            board[row-1][column].setPiece('B');
        }
        else {
            board[row-1][column].setPiece('W');
        }
        return FlipUp(c, row-1, column);
    }

}

void Board::FlipBottomRight(char c, int row, int column) {




    if (board[row + 1][column+1].getPiece() == c) {
        if (c == 'W') {
            board[row + 1][column+1].setPiece('B');
        }
        else {
            board[row + 1][column+1].setPiece('W');
        }
        return FlipBottomRight(c, row + 1, column+1);
    }

}

void Board::FlipBottomLeft(char c, int row, int column) {




    if (board[row + 1][column - 1].getPiece() == c) {
        if (c == 'W') {
            board[row + 1][column - 1].setPiece('B');
        }
        else {
            board[row + 1][column - 1].setPiece('W');
        }
        return FlipBottomLeft(c, row + 1, column - 1);
    }

}

void Board::FlipTopLeft(char c, int row, int column) {




    if (board[row - 1][column - 1].getPiece() == c) {
        if (c == 'W') {
            board[row - 1][column - 1].setPiece('B');
        }
        else {
            board[row - 1][column - 1].setPiece('W');
        }
        return FlipTopLeft(c, row - 1, column - 1);
    }

}

void Board::FlipTopRight(char c, int row, int column) {




    if (board[row - 1][column + 1].getPiece() == c) {
        if (c == 'W') {
            board[row - 1][column + 1].setPiece('B');
        }
        else {
            board[row - 1][column + 1].setPiece('W');
        }
        return FlipTopRight(c, row - 1, column + 1);
    }

}

void Board::FlipDown(char c, int row, const int column) {




    if (board[row + 1][column].getPiece() == c) {
        if (c == 'W') {
            board[row + 1][column].setPiece('B');
        }
        else {
            board[row + 1][column].setPiece('W');
        }
        return FlipDown(c, row + 1, column);
    }

}



bool Board::checkRight(char c, const int row, int column,bool first) {//same thing but on the right and all the other functions are the same but in their respective directions
    
    
    bool notfirst=false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) {
       if (board[row][column + 1].getPiece() !=c ) {
           
            return false;

       }
    }

    if (column == size) {
        
        return false;
    }

    if (board[row][column + 1].getPiece() == c) {
        
        return checkRight(c, row, column + 1, notfirst);
    }
    else if (board[row][column + 1].getPiece() == ' ' || board[row][column + 1].getPiece() == UnplayablePosition::UNPLAYABLE) {
        
        return false;

    }
    else {
        
        return true;
    }
}

bool Board::checkUp(char c, int row,const int column, bool first) {//same thing but on the right and all the other functions are the same but in their respective directions
    bool notfirst = false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) {
        if (board[row-1][column].getPiece() != c) {

            return false;

        }
    }

    if (row == 0) {
        return false;
    }

    if (board[row-1][column].getPiece() == c) {
        return checkUp(c, row-1, column, notfirst);
    }
    else if (board[row-1][column].getPiece() == ' ' || board[row-1][column].getPiece() == UnplayablePosition::UNPLAYABLE) {

        return false;

    }
    else {
        return true;
    }
}

bool Board::checkDown(char c, int row, const int column, bool first) {//same thing but on the right and all the other functions are the same but in their respective directions
    bool notfirst = false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) {
        if (board[row + 1][column].getPiece() != c) {

            return false;

        }
    }

    if (row == size) {
        return false;
    }

    if (board[row + 1][column].getPiece() == c) {
        return checkDown(c, row+1, column, notfirst);
    }
    else if (board[row + 1][column].getPiece() == ' ' || board[row + 1][column].getPiece() == UnplayablePosition::UNPLAYABLE) {

        return false;

    }
    else {
        return true;
    }
}

bool Board::checkTopLeft(char c, int row, int column, bool first) {//same thing but on the right and all the other functions are the same but in their respective directions
    bool notfirst = false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) {
        if (board[row - 1][column-1].getPiece() != c) {

            return false;

        }
    }

    if (column == 0||row==0) {
        return false;
    }

    if (board[row - 1][column-1].getPiece() == c) {
        return checkTopLeft(c, row-1, column - 1, notfirst);
    }
    else if (board[row - 1][column-1].getPiece() == ' ' || board[row - 1][column-1].getPiece() == UnplayablePosition::UNPLAYABLE) {

        return false;

    }
    else {
        return true;
    }
}
bool Board::checkTopRight(char c, int row, int column, bool first) {//same thing but on the right and all the other functions are the same but in their respective directions
    bool notfirst = false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) {
        if (board[row - 1][column + 1].getPiece() != c) {

            return false;

        }
    }

    if (column == size || row == 0) {
        return false;
    }

    if (board[row - 1][column + 1].getPiece() == c) {
        return checkTopRight(c, row-1, column + 1, notfirst);
    }
    else if (board[row - 1][column + 1].getPiece() == ' ' || board[row - 1][column + 1].getPiece() == UnplayablePosition::UNPLAYABLE) {

        return false;

    }
    else {
        return true;
    }
}

bool Board::checkBottomRight(char c, int row, int column, bool first) {//same thing but on the right and all the other functions are the same but in their respective directions
    bool notfirst = false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) {
        if (board[row + 1][column +1].getPiece() != c) {

            return false;

        }
    }

    if (column == size || row == size) {
        return false;
    }

    if (board[row + 1][column + 1].getPiece() == c) {
        return checkBottomRight(c, row+1, column + 1, notfirst);
    }
    else if (board[row + 1][column + 1].getPiece() == ' ' || board[row + 1][column + 1].getPiece() == UnplayablePosition::UNPLAYABLE) {

        return false;

    }
    else {
        return true;
    }
}

bool Board::checkBottomLeft(char c, int row, int column, bool first) {//same thing but on the right and all the other functions are the same but in their respective directions
    bool notfirst = false;//if first passes without returning false will be used in the recursion to skip the first if statement
    if (first) {
        if (board[row + 1][column - 1].getPiece() != c) {

            return false;

        }
    }

    if (column == 0 || row == size) {
        return false;

    }

    if (board[row + 1][column - 1].getPiece() == c) {
        return checkBottomLeft(c, row + 1, column - 1, notfirst);
    }
    else if (board[row + 1][column - 1].getPiece() == ' ' || board[row + 1][column - 1].getPiece() == UnplayablePosition::UNPLAYABLE) {

        return false;

    }
    else {
        return true;
    }
}