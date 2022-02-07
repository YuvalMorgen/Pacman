#pragma once

#include <windows.h>
#include <iostream>
#include "pacman.h"
#include "Board.h"
#include "Point.h"
#include "Ghost.h"
#include "Definitions.h"

using std::cout;
using std::cin;
using std::endl;

class Game {
	Board board;
	Pacman player;
	Ghost ghost1, ghost2;
	
	public:

		//places ghosts and player to thier default location
		void placeToDefault();

		void run();
		int init();
		
		//changes the game status acorrding to players ESC input.
		void changeGameStatus(bool& pause);

		//Check wall above
		bool checkWallUp(Board& board, int x, int y) const;

		//Check wall below
		bool checkWallDown(Board& board, const int x, const int y) const;

		//Check wall to the left
		bool checkWallLeft(Board& board, const int x, const int y) const;

		//Check wall to the right
		bool checkWallRight(Board& board, const int x, const int y) const;
		
		//Combining all the wall checks and changing the status accordingly. 
		void checkWalls(int& dir, Board& board, Pacman& player);

		//Moves the ghost
		void moveGhost(Board& board, Ghost& ghost, int& dir);

		//Finds new direction randomly.
		int findNewDirection(const int currentDir, const int badDir) const;

		// In case one of the player ate a breadcrumb, the score table will be updated
		void updateScore(Board& board, Pacman& player1);

		// In case one of the player ate a breadcrumb, the score table will be updated
		void updateLives(Pacman& player, Ghost& ghost);

		void setPacmanDirection(Pacman& player, int& dir, char key);
    
		bool gameContinue(Board& board, Pacman& player);
};
