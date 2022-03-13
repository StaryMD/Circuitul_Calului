#pragma once
#include <iostream>
#include <iomanip>

#include "Option.hpp"
#include "Vector2.hpp"
#include "data_types.hpp"

class Board {
	typedef Vector2<int> Position;

	Option option;
	uint8 *table;
	uint32 size;
	Position horse;
	uint32 move_count;

public:
	Board(uint32);
	~Board();

	void init(const int, const int);
	void update();
	void advance_option();

	void update_till_death();

	friend std::ostream &operator <<(std::ostream &out, const Board &board) {
		for (uint32 y = 0u; y < board.size; y++) {
			for (uint32 x = 0u; x < board.size; x++) {
				out << std::setw(3) << (int)board.table[y * board.size + x];
			}
			out << '\n';
		}

		return out;
	}

	inline bool is_inside(const Position &new_horse) {
		return new_horse.x >= 0u && new_horse.x < size &&
			   new_horse.y >= 0u && new_horse.y < size;
	}

	inline bool is_visited(const Position &new_horse) {
		return table[new_horse.y * size + new_horse.x] != 0u;
	}

	inline bool is_full() {
		return move_count == size * size;
	}

	inline bool is_completed() {
		return option.passed_max_perm() == true;
	}

private:
	const Position possible_moves[8] = {
		{ -1, -2 },
		{  1, -2 },
		{  2, -1 },
		{  2,  1 },
		{  1,  2 },
		{ -1,  2 },
		{ -2,  1 },
		{ -2, -1 }
	};
};
