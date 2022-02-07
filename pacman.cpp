#include "pacman.h"


void Pacman::move() {
	pos.draw(' ');
	pos.move(direction);
	setTextColor(color);
	pos.draw(figure);
	setTextColor(WHITE);
}

int Pacman::getDirection(char key) const {
	for (int i = 0; i < 5; i++) {
		if (key == arrowKeys[i])
			return i;
	}
	return -1;
}
