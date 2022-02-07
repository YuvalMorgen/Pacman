#include "Point.h"
#include "Definitions.h"

void Point::draw(const char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

//change the bounds
void Point::move(const int dir) {

	switch (dir) {
	case UP:
		--y;
		if (y < 1) {
			y = 18;
		}
		break;
	case DOWN:
		++y;
		if (y > 18) {
			y = 1;
		}
		break;
	case LEFT:
		--x;
		if (x < 1) {
			x = 48;
		}
		break;
	case RIGHT:
		++x;
		if (x > 48) {
			x = 1;
		}
		break;
	case STAY:
		break;
	}

}