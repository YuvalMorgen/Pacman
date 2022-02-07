#pragma once

#include "Point.h"
#include "Definitions.h"


class Ghost {
	Point pos;
	char figure = GHOST;
	int direction = LEFT;
	Color color = WHITE;

 public:
	void setPos(const int _x,const int _y) {
		pos.setPoint(_x, _y);
	}
	void setColor(const Color c) {
		color = c;
	}
	int getPointX() const { return pos.getX(); }
	int getPointY() const { return pos.getY(); }
	int getDirection() const { return direction; }
	void move(const char c);
	void setDirection(const int dir) { direction = dir; }
};
