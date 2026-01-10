#ifndef SUGOKU_H
#define SUGOKU_H

#include <SFML/Graphics.hpp>

enum Game {
	Sudoku,
	Go,
};

struct Cell {
	int row;
	int col;
	// What this cell cannot be
	int constraints; // bitmask
	sf::RectangleShape rect;
	int freedoms{0};
};

struct BoardS {
	Cell cells[81];
	int nums[81];
	// int row_constraints[9]{0};
	// int col_constraints[9];
	// int box_constraints[9];
	bool good;
	bool displayFreedoms{0};

	// Oh, structs can have constructors and stuff
	// BoardS(bool h) : displayFreedoms(h) {}
};

struct BoardG {};

struct state {
	Game game;
	BoardS Sudoku;
};

void draw_board(BoardS *board, float size, float x, float y);
void draw_freedoms();
void init_board(sf::RectangleShape bg,
				std::array<sf::RectangleShape, 81> &cells);
BoardS Load(const std::string &filename);

#endif
