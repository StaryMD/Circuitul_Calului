#include <iostream>
#include "Board.hpp"
#include "Option.hpp"

int main() {
	Board board(8);

	for (int i = 0; i < 40320; i++) {
		board.init(3, 3);

		board.update_till_death();
		if (board.is_completed())
			std::cout << board << '\n';
		
		board.advance_option();
	}

	return 0;
}
