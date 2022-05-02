#include <iostream>
#include "Board.hpp"
#include "Option.hpp"

int main() {
	Board board(8);

	while (!board.exhausted_options()) {
		board.init(1, 1);

		board.update_till_death();
		if (board.is_full()) {
			std::cout << board << '\n';
		}

		board.advance_option();
	}

	return 0;
}
