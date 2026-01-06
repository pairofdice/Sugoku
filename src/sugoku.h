#ifndef SUGOKU_H
#define SUGOKU_H

#include <SFML/Graphics.hpp>

struct Cell {
	int row;
	int col;
	// What this cell cannot be
	int constraints; // bitmask
	sf::RectangleShape rect;
};

struct Board {
	Cell rects[81];
	int nums[81];
	int row_constraints[9];
	int col_constraints[9];
	int box_constraints[9];
	bool good;
};
void draw_board(Board *board, float size, float x, float y);
void draw_freedoms();
void init_board(sf::RectangleShape bg,
				std::array<sf::RectangleShape, 81> &cells);

#endif
