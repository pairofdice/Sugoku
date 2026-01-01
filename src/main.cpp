#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	std::cout << "Hello, Sugoku!\n";
	sf::Window window(sf::VideoMode({666, 666}), "Do we have a window?");
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
	}
	return 0;
}
