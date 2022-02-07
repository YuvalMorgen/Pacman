#ifndef _PACMAN_H_
#define _PACMAN_H_
#include "Point.h"
#include "Color.h"
#include "Definitions.h"


class Pacman {
	char arrowKeys[5];
	int direction = STAY;
	char figure;
	Point pos;
	int lives = 3;
	int score = 0;
	Color color = Color::WHITE;
public:
	void setKeys(const char* keys) {
		for (int i = 0; i < 5; i++)
			arrowKeys[i] = keys[i];
	}

	void setColor(const Color c) { color = c; }
	void setPos(const int x,const int y) { pos.setPoint(x, y); }

	//setter for direction
	void setDirection(const int dir) { direction = dir; }

	//getter and setter for figure
	char getFigure() const{ return figure; }
	void setFigure(const char _figure) { figure = _figure; }

	//getter and setter for score
	void setScore(const int _score) { score = _score; }
	int getScore() const { return score; }

	//getter and setter for lives
	void setLives(const int _lives) { lives = _lives; }
	int getLives() const { return lives; }

	int getPointX() const { return pos.getX(); }
	int getPointY() const { return pos.getY(); }

	//moves according to the user's input
	void move();

	//converts the key to a direction
	int getDirection(const char key) const;
};


#endif
