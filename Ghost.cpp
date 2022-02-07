#include "Ghost.h"


void Ghost::move(const char c) {
	pos.draw(c);
	pos.move(direction);
	setTextColor(color);
	pos.draw(figure);
	setTextColor(WHITE);
}

