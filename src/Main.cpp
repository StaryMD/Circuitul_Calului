#include <iostream>
#include "timer.cpp"

#include "Algo_Warnsdorff.hpp"
#include "Algo_Backtracking.hpp"

int main(int cargs, char** args) {
	if (cargs == 1) {
		std::cout << "Usage: cal <board_size> <horse_x> <horse_y> <algorithm>\n";
		std::cout << "       cal algos\n";
		return 0;
	}

	if (cargs == 2) {
		std::string command(args[1]);
		if (command == "algos") {
			std::cout << "  w : warnsdorff\n";
			std::cout << "  b : backtracking\n";
		}
		return 0;
	}
	
	if (cargs == 5) {
		int board_size = std::stoi(args[1]);
		if (board_size == 0 || board_size >= 2147483647) {
			std::cout << "Invalid board size\n";
			std::cout << "  1 <= board_size < 2147483647\n";
			return 0;
		}

		int horse_x = std::stoi(args[2]);
		int horse_y = std::stoi(args[3]);
		if (horse_x < 1 || horse_y < 1 || horse_x > board_size || horse_y > board_size) {
			std::cout << "Invalid horse position\n";
			std::cout << "  1 <= horse_pos <= board_size\n";
			return 0;
		}

		if (args[4][0] == 'w') {
			generate_warnsdorff(board_size, horse_x, horse_y);
		}
		else if (args[4][0] == 'b') {
			generate_backtracking(board_size, horse_x, horse_y);
		}
		else {
			std::cout << "Unknown algorithm\n";
		}
		return 0;
	}
	std::cout << "Wrong list of parameters\n";
	
	return 0;
}
