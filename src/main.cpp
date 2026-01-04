#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <print>

void init_board(sf::RectangleShape bg,
				std::array<sf::RectangleShape, 81> &cells);
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

Board Load(const std::string &filename) {
	std::println("Loading file: {}", filename);
	std::ifstream file("Sudokus\\" + filename);

	if (!file.is_open()) {
		std::cerr << "Error loading file " << filename << "\n";
		exit(1);
	}

	Board b;
	b.good = true;
	std::string line;
	int n;
	int count{0};
	while (file >> n) {
		if (count > 80) {
			std::println("Malformed input");
			break;
		}
		if (n >= 0 && n < 10) {
			b.nums[count] = n;
			count++;
		}
	}
	if (count != 81) {
		std::println("Malformed input");
		b.good = false;
	}
	std::println("{}", b.nums);
	return b;
}

void SetDigits(std::vector<sf::Text> *digits) {
	for (int i{0}; i < 10; i++) {
		digits->at(i).setPosition({100, static_cast<float>(100 + 30 * i)});
	}
}
int main(int argc, char **argv) {
	unsigned int winw{666};
	unsigned int winh{666};
	float cellSize{32};
	sf::Font font;
	if (!font.openFromFile("KleeOne-Regular.ttf")) {
		// error...
		std::println("Error loading font");
	}
	std::vector<sf::Text> digits;
	for (int i{0}; i < 10; i++) {
		digits.emplace_back(font, std::to_string(i));
	}
	SetDigits(&digits);

	sf::Text text(font); // a font is required to make a text object
	// set the string to display
	text.setString("Hello world");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	Board board;
	if (argc == 2)
		board = Load(argv[1]);
	if (!board.good) {
		std::println("Board is bad.");
		exit(1);
	}

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

		draw_board(&board, 5, 100, 100);
		window.draw(bg);
		for (sf::RectangleShape i : cells) {
			window.draw(i);
		}
		window.draw(text);
		for (int i{0}; i < 10; i++) {
			window.draw(digits.at(i));
		}

		// 5. Display result
		window.display();
	}
	return 0;
}

void draw_board(Board *board, float cellSize, float x, float y) {
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
