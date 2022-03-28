#include "Board.hpp"

#include <algorithm>
#include "Vector2.hpp"
#include "data_types.hpp"

Board::Board(uint32 size_ = 8) {
	size = size_;
	table = new uint8[size * size];
	table_pos = new uint8[size * size];

	for (uint32 i = 0u; i < size; i++){
		for (uint32 j = 0u; j < size; j++){
			Position pos(i,j);
			table_pos[pos.y * size + pos.x] = 0u;

			for (const Position rel_move : relative_moves)
				if (is_inside(pos + rel_move))
					table_pos[pos.y * size + pos.x]++;
		}
	}
}

Board::~Board() {
	delete[] table;
	delete[] table_pos;
}

void Board::init(const int x, const int y) {
	// Initilizam tabla la 0
	move_count = 1;
	std::fill(table, table + size * size, 0u);

	// Marcam pozitia de inceput a calului
	table[y * size + x] = 1u;
	horse = { x, y };
}

bool Board::update() {
	// Calculeaza numarul minim de posibilitati dintre mutarile posibile
	uint8 min = 9u;
	for (const Position& move : relative_moves) {
		Position new_horse = horse + move;
		
		if (is_inside(new_horse) && !is_visited(new_horse))
			min = std::min(min, table_pos[new_horse.y * size + new_horse.x]);
	}

	// Incercam mutarea
	for (const uint8& pos : option.perm) {
		Position new_horse = horse + relative_moves[pos];

		if (is_inside(new_horse) && table_pos[new_horse.y * size + new_horse.x] == min) {
			horse = new_horse;
			table[horse.y * size + horse.x] = ++move_count;
			return true;
		}
	}
	return false;
}

void Board::update_till_death() {
	int i=0;
	while (i<10 && update()){
		++i;
	}
}

void Board::advance_option() {
	option.next();
}
