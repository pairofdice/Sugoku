#include "sugoku.h"
#include <fstream>
#include <iostream>
#include <print>

BoardS Load(const std::string &filename) {
	std::println("Loading file: {}", filename);
	std::ifstream file("Sudokus\\" + filename);

	if (!file.is_open()) {
		std::cerr << "Error loading file " << filename << "\n";
		exit(1);
	}

	BoardS b;
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
