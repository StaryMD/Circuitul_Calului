#include "Board.hpp"

#include <algorithm>
#include "Vector2.hpp"
#include "data_types.hpp"

Board::Board(uint32 size_ = 8) {
	size = size_;
	table = new uint8[size * size];
}

Board::~Board() {
	delete[] table;
}

void Board::init(const int x, const int y) {
	// Initilizam tabla la 0
	move_count = 1;
	std::fill(table, table + size * size, 0u);

	// Marcam pozitia de inceput a calului
	table[y * size + x] = 1u;
	horse = { x, y };
}

void Board::update() {
	for (const auto idx : option.perm) {
		Position new_horse = horse + possible_moves[idx];

		if (is_inside(new_horse) && is_visited(new_horse) == false) {
			horse = new_horse;
			table[horse.y * size + horse.x] = ++move_count;
			
			break;
		}
	}
}

void Board::update_till_death() {
	for (bool go = true; go; ) {
		go = false;

		for (const auto idx : option.perm) {
			Position new_horse = horse + possible_moves[idx];

			if (is_inside(new_horse) && is_visited(new_horse) == false) {
				horse = new_horse;
				table[horse.y * size + horse.x] = ++move_count;
				go = true;
				
				break;
			}
		}
	}
}

void Board::advance_option() {
	option.next();
}
