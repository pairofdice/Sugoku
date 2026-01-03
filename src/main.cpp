#include <SFML/Graphics.hpp>
#include <iostream>

void draw_board(int size, int x, int y);
void init_board(sf::RectangleShape bg,
				std::array<sf::RectangleShape, 81> &cells);
struct Cell {
	int row;
	int col;
	// What this cell cannot be
	int constraints; // bitmask
	sf::RectangleShape rect;
};

int main() {
	unsigned int winw{666};
	unsigned int winh{666};
	float cellSize{32};

	// Drawing some Rectangles
	std::array<sf::RectangleShape, 81> cells;
	sf::RectangleShape bg;
	bg.setPosition({145, 145});
	bg.setSize({static_cast<float>(cellSize * 9 + 8 * 2 + 20 + 10),
				static_cast<float>(cellSize * 9 + 8 * 2 + 20 + 10)});
	bg.setFillColor({75, 60, 60});

	float x{0.0};
	float y{150.0};
	for (int row{0}; row < 9; row++) {
		x = 150.0;
		for (int col{0}; col < 9; col++) {
			int index{col * 9 + row};
			sf::RectangleShape *rectptr = &cells[index];
			cells[index].setSize({cellSize, cellSize});
			cells[index].setPosition({x, y});
			rectptr->setFillColor({195, 255, 195});
			// rectptr->setOutlineColor({0, 0, 0});
			// rectptr->setOutlineThickness(1.0);
			x += cellSize + 2.0;
			if (col % 3 == 2)
				x += 10;
		}
		y += cellSize + 2.0;
		if (row % 3 == 2)
			y += 10;
	}

	std::cout << "Hello, Sugoku!\n";
	sf::RenderWindow window(sf::VideoMode({winw, winh}),
							"Do we have a window?");

	while (window.isOpen()) {
		// 1. Handle events
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		// 2. Update game state

		// 3. Clear the scree
		window.clear();

		// 4. Draw everything

		draw_board(555, 100, 100);
		window.draw(bg);
		for (sf::RectangleShape i : cells) {
			window.draw(i);
		}

		// 5. Display result
		window.display();
	}
	return 0;
}

void draw_board(float cellSize, float x, float y) {
	std::array<sf::RectangleShape, 81> cells;
	sf::RectangleShape bg;
	bg.setPosition({145, 145});
	bg.setSize({static_cast<float>(cellSize * 9 + 8 * 2 + 20 + 10),
				static_cast<float>(cellSize * 9 + 8 * 2 + 20 + 10)});
	bg.setFillColor({75, 60, 60});

	for (int row{0}; row < 9; row++) {
		x = 150.0;
		for (int col{0}; col < 9; col++) {
			int index{col * 9 + row};
			sf::RectangleShape *rectptr = &cells[index];
			cells[index].setSize({cellSize, cellSize});
			cells[index].setPosition({x, y});
			rectptr->setFillColor({195, 255, 195});
			// rectptr->setOutlineColor({0, 0, 0});
			// rectptr->setOutlineThickness(1.0);
			x += cellSize + 2.0;
			if (col % 3 == 2)
				x += 10;
		}
		y += cellSize + 2.0;
		if (row % 3 == 2)
			y += 10;
	}
}

void init_board(sf::RectangleShape bg,
				std::array<sf::RectangleShape, 81> &cells) {}
