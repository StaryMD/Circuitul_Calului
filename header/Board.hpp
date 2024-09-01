#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

#include "Option.hpp"
#include "Vector2.hpp"

class Board {
public:
	typedef Vector2<int> Position;

	Board();
	Board(int);

	void init(const int, const int);
	bool update();
	void copy_from(const Board&);

	void advance_option() {
		option.next();
	}

	void update_till_death() {
		while (update());
	}

	int move_imaginary_horse(const Position &);
	void reset_square(const Position &);

	friend std::ostream &operator <<(std::ostream &out, const Board &board) {
		for (int y = 0; y < board.size; y++) {
			for (int x = 0; x < board.size; x++) {
				out << std::setw(4) << (int)board.table[y * board.size + x];
			}
			out << '\n';
		}

		return out;
	}

	bool is_inside(const Position &position) {
		return position.x >= 0 && position.x < size &&
			   position.y >= 0 && position.y < size;
	}

	bool is_visited(const Position &position) {
		return table[position.y * size + position.x] != 0;
	}

	bool is_full() {
		return move_count == move_count_max;
	}

	bool exhausted_options() {
		return option.exhausted_perm_count();
	}

	bool is_equal(const Board& board) {
		return table == board.table;
	}

	int get_option_int() {
		return option.to_integer();
	}

	void set_option_int(int val) {
		return option.from_integer(val);
	}
	
	inline static Position relative_moves[8];

private:
	int size;
	std::vector<int> table;
	std::vector<int> table_pos;

	Option option;
	Position horse;
	int move_count_max;
	int move_count;
};
