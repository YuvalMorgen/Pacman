#include "Board.h"

using std::cout;
using std::cin;
using std::endl;

// prints the board to the screen.
void Board::printBoard(Color color) const {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (board[row][col] == WALL1 || board[row][col] == WALL2 || board[row][col] == '+') {
                setTextColor(color);
                cout << board[row][col];
                setTextColor(WHITE);
            }
               else cout << board[row][col];
        }
            cout << "\n";
    }   
}

// print to the screen the players score and live.
void Board::displayPlayerStatus(Pacman& player) {
    gotoxy(1, 25);
    cout << "Player 1: \n Score:" << player.getScore();
    gotoxy(16, 25);
    cout << "Lives: " << player.getLives();
}

//In case the player won this function will clear the screen and will print a message to the user
void Board::playerWon(Pacman& player) {
    system("cls");
    printEndGameMsg(player, true);
}

//In case the player lost this function will clear the screen and will print a message to the user
void Board::playerLost(Pacman& player){
    system("cls");
    printEndGameMsg(player, false);
}

// print to the screen a messege with the user name.
void Board::printEndGameMsg(Pacman& player, bool status) {
    gotoxy (30, 10);
    if (status) // if status = true, the player won
        cout << "hurray " << player.getFigure() << " has won" << endl;
    else cout << "You lost, try again? " << endl;
}



// Presenting the menu and instructions to the users.
int Board::menu() {
    int choice;
    bool validChoice = false;
    while (!validChoice) {
        gotoxy(1,1); // printing the menu in the top left of the screen.
        cout << "WELCOME TO Pacman" << endl;
        cout << "please chooce from the below menu:" << endl;
        cout << "(1) Start a new game" << endl;
        cout << "(8) Present instructions and keys" << endl;
        cout << "(9) EXIT" << endl;
        cin >> choice;
        system("cls");
        
        if (choice == PLAY) {
            validChoice = true;
            if (makeColor()) choice = 2; // If thep user choose a colorful board/
            else choice = 3; // If the user choose black and white board.
        }
        else if(choice == INSTRUCTIONS) presentInstructions();
        else if(choice == EXIT) validChoice = true;
        else cout << "please enter a valid choice" << endl;
    }
        system("cls");
        return choice;
}


//This function lets the user choose if he want to have a colorful board and return his choice.
bool Board ::makeColor() {
    bool validChoice = false;
    char choice;
    cout << "For colors enter 'Y', for black and white enter 'N' " << endl;
    while (!validChoice) {
        cin >> choice;
        if (choice == 'Y' || choice == 'y') return true;
        else if(choice == 'N' || choice == 'n')  return false;
           
        else cout << "please enter valid choice";
    }
    
}


// This functions presents the game instructions to the user. onces the user is done reading he can exit the instructions screen.
void Board::presentInstructions() const {
    bool understand = false;
    char ch = 'a';
    cout << "Instruction:\n1. Use 'W'/'w' for up\n 'S'/'s' for down\n 'A'/'a' for left\n 'D'/'d' for right\n 'X'/'x' to stop pacman\nESC to pause/continue the game 2. Eat the dots around the board to gain poins\n3. Don't get caught by the ghosts\n\n";
    cout << "once you are done reading the instructions please enter D for 'DONE' "<< endl;
    
    while(!understand) {
        cin >> ch;
        if(ch == 'D' || ch == 'd') understand = true;
        else cout << "please enter D";
    }
    system("cls");
}
