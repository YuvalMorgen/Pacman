#include "Game.h"


//  This function presents the menu and initiates the game in case the user is choosing to.
int Game::init() {
	int choice = board.menu();
	if (choice == 9) return choice;
	//board.plantFood();
	if (choice==2) {
		board.printBoard(BLUE);
		player.setColor(GREEN);
		ghost1.setColor(RED);
		ghost2.setColor(RED);
	}
	
	else board.printBoard();
	
    board.displayPlayerStatus(player);
	player.setKeys("wsadx");
	player.setFigure('@');
	placeToDefault();
	hideCursor();
	
	return choice;
}


//Starts the game
void Game::run() {
	bool pause = false, win = false;
	char key = 0;
	int  dir, Ghostdir1 = ghost1.getDirection(), Ghostdir2 = ghost2.getDirection();
	
	//We check if ghostTurn is even for it to move, so one interaction it will move and one it doesnt.
	int ghostTurn = 0;
	
    while (gameContinue(board, player)) {
		if (_kbhit()) {
			key = _getch();
			if (key == ESC) changeGameStatus(pause); //If the user pressed ESC change the statment of the game

			setPacmanDirection(player, dir, key);
		}
        //Pauses the game depened on the statement of the game
        if (pause) Sleep(1);
        
		else {
			if (ghostTurn % 2 == 0){ // In this way the gohost move half the speed of the pacman. 
				moveGhost(board, ghost1, Ghostdir1);
				moveGhost(board, ghost2, Ghostdir2);
			}

			checkWalls(dir, board, player);
			player.move();
			updateLives(player, ghost1);
			updateLives(player, ghost2);
			updateScore(board, player);
			board.displayPlayerStatus(player);
			Sleep(150);
			ghostTurn++;
			
		}
	}
    while(!(_kbhit())) Sleep(1); //Awaits for any key to be pressed to end the game
}


//This function is checking if the player has won, lost or the game is on going.
bool Game::gameContinue (Board& board, Pacman& player) {
    bool lost = false, won = false, keepPlaying = true;
    int lives = player.getLives();
    int breadCrumbsNum = board.getBreadCrumbs();
    
    if(!lives) { // lives = 0
        board.playerLost(player);
        return lost;
    }
    
    if(lives && !breadCrumbsNum) { //lives > 0 and breadcrumbs = 0
        board.playerWon(player);
        return won;
    }
    else return keepPlaying;
}

// Once ESC was pressed this function will change the game status and presents it to the player
void Game::changeGameStatus(bool& pause) {
	if (pause) {
		gotoxy(1, 23);
		cout << "           " << endl; // printins space in order to disappear the message.
		pause = false;
	}
	else {
		gotoxy(1, 23);
        cout << "Game Paused" << endl;
		pause = true;
	}
}

bool Game::checkWallUp(Board& board, const int x, const int y) const {
	return board.getPoint(y - 1, x) == WALL1 || board.getPoint(y - 1, x) == WALL2;
}

bool Game::checkWallDown(Board& board, const int x, const int y) const {
	return board.getPoint(y + 1, x) == WALL1 || board.getPoint(y + 1, x) == WALL2;
}

bool Game::checkWallLeft(Board& board, const int x, const int y) const {
	return board.getPoint(y, x - 1) == WALL1 || board.getPoint(y, x - 1) == WALL2;
}

bool Game::checkWallRight(Board& board, const int x, const int y) const {
	return board.getPoint(y, x + 1) == WALL1 || board.getPoint(y, x + 1) == WALL2;
}


// Moves the pacman around the board
void Game::checkWalls(int& dir,Board& board, Pacman& player) {
    int x = player.getPointX();
    int y = player.getPointY();
	if (checkWallUp(board, x, y) && dir == UP) {
		dir = STAY;
		player.setDirection(dir);
	}
	else if (checkWallDown(board, x, y) && dir == DOWN) {
		dir = STAY;
		player.setDirection(dir);
	}
	else if (checkWallLeft(board, x, y) && dir == LEFT) {
		dir = STAY;
		player.setDirection(dir);
	}
	else if (checkWallRight(board, x, y) && dir == RIGHT) {
		dir = STAY;
		player.setDirection(dir);
	}
}



// Moves and finds the right direction for the ghost
void Game::moveGhost(Board& board,Ghost& ghost, int& dir) {
    int x = ghost.getPointX();
    int y = ghost.getPointY();
	switch (dir) {
	case UP:
		if (y - 1 == 0 || checkWallUp(board, x, y)) {
			if (x - 1 == 0 || checkWallLeft(board, x, y)){
				dir = findNewDirection(dir,LEFT);
			}
			else if(x + 1 == COLS - 2 || checkWallRight(board, x, y))
				dir = findNewDirection(dir, RIGHT);
			else dir = findNewDirection(dir, -1);

			ghost.setDirection(dir);
		}
		break;
            
	case DOWN:
		if (y + 1 == ROWS - 1 || checkWallDown(board, x, y)) {
			if (x - 1 == 0 || checkWallLeft(board, x, y)) {
				dir = findNewDirection(dir, LEFT);
			}
			else if (x + 1 == COLS - 2 || checkWallRight(board, x, y))
				dir = findNewDirection(dir, RIGHT);
			else dir = findNewDirection(dir, -1);

			ghost.setDirection(dir);
		}
		break;
            
	case LEFT:
		if (x - 1 == 0 || checkWallLeft(board, x, y)) {
			if (y - 1 == 0 || checkWallUp(board, x, y)) {
				dir = findNewDirection(dir, UP);
			}
			else if (y + 1 == ROWS - 1 || checkWallDown(board, x, y))
				dir = findNewDirection(dir, DOWN);
			else dir = findNewDirection(dir, -1);

			ghost.setDirection(dir);
		}
		break;
            
	case RIGHT:
		if (x + 1 == COLS - 2 || checkWallRight(board, x, y)) {
			if (y - 1 == 0 || checkWallUp(board, x, y)) {
				dir = findNewDirection(dir, UP);
			}
			else if (y + 1 == ROWS - 1 || checkWallDown(board, x, y))
				dir = findNewDirection(dir, DOWN);
			else dir = findNewDirection(dir, -1);

			ghost.setDirection(dir);
		}
		break;
            
	default:
		break;
	}
	ghost.move(board.getPoint(y, x));
	updateLives(player, ghost);
}




//Finds a new direction in a random way
int Game::findNewDirection(const int currentDir, const int badDir) const {
	int newDir;
	srand(time(NULL));
	newDir = rand() % 4;
	while (currentDir == newDir || newDir == badDir) // this loop will run until we get a new valid direction
		newDir = rand() % 4;
	
	return newDir;
}


// In case the player ate a breadcrumb, the score table will be updated
void Game::updateScore(Board& board, Pacman& player) {
	int currCol = player.getPointX();
	int currRow = player.getPointY();
	int score = player.getScore() + 1;
	int breadCrumbs = board.getBreadCrumbs();
    
	if (board.getPoint(currRow, currCol) == FOOD) { //if the pacman is in the same location of a breadCrumb.
		player.setScore(score); // updates the player score.
		board.setPoint(currRow, currCol, ' ');
		breadCrumbs--;
        board.setBreadCrumbs(breadCrumbs);
	}

}


// Update the lives of the pacman in case needed
void Game::updateLives(Pacman& player, Ghost& ghost) {
	int currColP = player.getPointX();
	int currRowP = player.getPointY();
	int currColG = ghost.getPointX();
	int currRowG = ghost.getPointY();
	if (currColG == currColP && currRowG == currRowP){ //if the pacman is in the same location of a ghost
		int updateLive = player.getLives() - 1;
        player.setLives(updateLive); // updates the player lives.
		
		placeToDefault();
		Sleep(1000);
		player.setDirection(STAY);
    }
}


// Place the pacman and the ghosts in their starting position
void Game::placeToDefault() {
	gotoxy(ghost1.getPointX(), ghost1.getPointY());
	cout << board.getPoint(ghost1.getPointY(), ghost1.getPointX());
	gotoxy(ghost2.getPointX(), ghost2.getPointY());
	cout << board.getPoint(ghost2.getPointY(), ghost2.getPointX());
	gotoxy(player.getPointX(), player.getPointY());
	cout << board.getPoint(player.getPointY(), player.getPointX());
	player.setPos(15, 1);
	ghost1.setPos(28, 14);
	ghost2.setPos(10, 10);
}


// Set pacman direction
void Game::setPacmanDirection(Pacman& player, int& dir, char key) {
	
	if ((dir = player.getDirection(key + CAPITAL)) != -1) {
		player.setDirection(dir);
	}
	else if ((dir = player.getDirection(key)) != -1) {
		player.setDirection(dir);
	}
}
