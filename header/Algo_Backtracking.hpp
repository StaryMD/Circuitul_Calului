#pragma once
#include <iostream>

namespace bck {
	struct Backtrack_c {
		Board board;
		Board ans_board;
		int max_depth;
		bool done;

		Backtrack_c(const int board_size) {
			board.copy_from(Board(board_size));
			max_depth = 0;
			done = false;
		}

		void back(Board::Position horse) {
			if (done) {
				return;
			}
			if (board.is_full()) {
				ans_board.copy_from(board);
				done = true;
				return;
			}
			for (Board::Position& move : Board::relative_moves) {
				if (board.is_inside(horse + move) && !board.is_visited(horse + move)) { 
					board.move_imaginary_horse(horse + move);

					back(horse + move);

					board.reset_square(horse + move);
				}
			}
		}
	};
};

void generate_backtracking(const int board_size, const int x, const int y) {
	std::cout << "Generating board by Backtracking\n"
	          << "For board of size " << board_size << '\n'
	          << "Starting at " << x << " and " << y << '\n';

	my::Timer timer;
	bck::Backtrack_c backtrack(board_size);
	backtrack.board.move_imaginary_horse(Board::Position(x - 1, y - 1));
	backtrack.back(Board::Position(x - 1, y - 1));

	std::cout << "Elapsed time: " << timer.elapsed_time() << '\n';
	if (backtrack.done == true) {
		std::cout << "The board:\n" << backtrack.ans_board;
	}
	else {
		std::cout << "Nu am gasit\n";
	}
}
