#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Board.hpp"
#include "Option.hpp"

void generate_warnsdorff(const int board_size, const int horse_x, const int horse_y) {
	int options = 1;
	int last_pos = -1;
	constexpr int MAX_PERM_COUNT = 40320;
	auto update_progressbar = [&options, &last_pos](){
		float progress = 1.0f * options / MAX_PERM_COUNT;
		int barWidth = 70;
		int pos = barWidth * progress;

		if (pos != last_pos) {
			last_pos = pos;
			std::cout << "Progress: [";
			for (int i = 0; i < barWidth; ++i) {
				if (i < pos) std::cout << "=";
				else if (i == pos) std::cout << ">";
				else std::cout << " ";
			}
			std::cout << "] " << int(progress * 100.0) << " %\r";
			std::cout.flush();
		}
	};

	std::cout << "Generating Warnsdorff board\n"
	          << "For board of size " << board_size << '\n'
	          << "Starting at " << horse_x << " and " << horse_y << '\n';

	std::vector<Board> completed_boards;
	int good_opt_count = 0;
	int good_options[MAX_PERM_COUNT] = { 0 };

	my::Timer timer;
	Board board(board_size);
	while (!board.exhausted_options()) {
		options++;
		update_progressbar();
		board.init(horse_x - 1, horse_y - 1);

		board.update_till_death();
		if (board.is_full()) {
			bool is_unique = true;
			for (Board &board_it: completed_boards)
				if (board.is_equal(board_it))
					is_unique = false;
			
			if (is_unique)
				completed_boards.push_back(Board(board));
		}

		board.advance_option();
	}
	std::cout << '\n';

	std::cout << "Found " << completed_boards.size() << " good options in " << timer.elapsed_time() << " seconds" << '\n';
	if (completed_boards.size() == 0) {
		std::cout << "none found   i'm sad\n";
		return;
	}

	std::srand(time(NULL));
	int random_opt = rand() % completed_boards.size();
	std::cout << "A random board:\n" << completed_boards[random_opt];
}
