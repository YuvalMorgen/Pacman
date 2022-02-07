#pragma once


enum Definitions {
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
	STAY = 4,
    PLAY = 1, // For the menu
    INSTRUCTIONS = 8, // For the menu
    EXIT = 9, // For the menu
    CAPITAL = 32, // The difference between a small char and a capital letter
	WALL1 = 35, // 35 = '#'
	WALL2 = 124, // 124 = '|'
	GHOST = 38, // 38 = '&'
	FOOD = 42, // 42 = '*'
	ROWS = 20,
	COLS = 51,
	ESC = 27
};
