#include <iostream>
#include "Board.hpp"
#include "Option.hpp"

#define MAXCOMB 40320
int main() {
	Board board(8);

	for (int i = 0; i < 10; i++) {
		board.init(3, 3);

		board.update_till_death();
		//if (board.is_completed())
			std::cout << board << '\n';
		
		board.advance_option();
	}

	return 0;
}
