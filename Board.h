#pragma once

#include <iostream>
#include <windows.h>
#include "pacman.h"
#include "Definitions.h"


class Board {
	int breadcrumbs = 474;
	char board[ROWS][COLS] = {
	"+#####################       ####################+",
	"|*********************        *******************|",
	"|*********************       ********************|",
	"|###############*************        #####       |",
	"|              |*********************|***********|",
	"               |*********************|            ",
	"         ***** #### *************    |            ",
	"         *************               ###          ",
	"         *************            ************    ",
	"|*********   ######    ************   ***********|",
	"|   ************  |                   ****  *****|",
	"| *************   ########           ************|",
	"| *************          |         ##############|",
	"| *************          |         | ************|",
	"|                        |         | ************|",
	"|************************########### ************|",
	"|**********       ****************         ******|",
	"|**************************            **********|",
	"|***********         ****************************|",
	"+#####################       ####################+",
	};


public:

	//Presents the menu
    int menu();

	//Presents the instructions
	void presentInstructions() const;


	void printBoard(const Color color = WHITE) const;

	//Display player's status and lives.
    void displayPlayerStatus(Pacman& player) ;

    //In case the player won this function will clear the screen and will print a message to the user
	void playerWon(Pacman& player1);
    
    //In case the player lost this function will clear the screen and will print a message to the user
    void playerLost(Pacman& player1);
    
    // print to the screen a messege with the user name.
    void printEndGameMsg(Pacman& player, bool status);
	
	//Game will print in color or black and white according to his input.
	bool makeColor();

    //Return a specific point in the board
	char getPoint(const int row, const int col) const { return board[row][col]; }
    
    //changes a specific point in the board.
	void setPoint(const int row, const int col, const char c) { board[row][col] = c; }
	
    // Return the number of breadcrumbs left.
    int getBreadCrumbs() const { return breadcrumbs; }
    
    // Changes the number of breadcrumbs in case needed.
    void setBreadCrumbs(const int _breadcrumbs) { breadcrumbs = _breadcrumbs; }
};
