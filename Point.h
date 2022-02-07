#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"
using std::cout;
using std::endl;

class Point {
	int x = 1, y = 1;
public:
	void draw(const char ch);
	void move(const int dir);
	inline int getX() const { return x; }
	inline int getY() const { return y; }

	void setPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

#endif
