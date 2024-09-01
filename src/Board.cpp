#include "Board.hpp"

#include <algorithm>
#include "Vector2.hpp"

Board::Board() {
	static Position static_relative_moves[8] = {
		{ -1, -2 },
		{  1, -2 },
		{  2, -1 },
		{  2,  1 },
		{  1,  2 },
		{ -1,  2 },
		{ -2,  1 },
		{ -2, -1 },
	};
	for (int i = 0; Position& rel_move: relative_moves) {
		rel_move = static_relative_moves[i++];
	}
	move_count = 0;
}

Board::Board(int size_) : Board() {
	size = size_;
	move_count_max = size * size;

	table = std::vector<int>(size * size, 0);
	table_pos = std::vector<int>(size * size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Position idx(i, j);

			for (const Position rel_move : relative_moves)
				table_pos[idx.y * size + idx.x] += is_inside(idx + rel_move);
		}
	}
}

void Board::init(const int x, const int y) {
	// Initilizam tabla la 0
	move_count = 1;
	std::fill(table.begin(), table.end(), 0);

	// Marcam pozitia de inceput a calului
	table[y * size + x] = 1u;
	horse = { x, y };
}

bool Board::update() {
	// Calculeaza numarul minim de posibilitati dintre mutarile posibile

	int min = 8;
	for (const Position& move : relative_moves) {
		Position new_horse = horse + move;
		
		if (is_inside(new_horse) && !is_visited(new_horse))
			min = std::min(min, table_pos[new_horse.y * size + new_horse.x]);
	}

	// Incercam mutarea
	for (const int& idx : option.perm) {
		Position new_horse = horse + relative_moves[idx];

		if (is_inside(new_horse) && !is_visited(new_horse) && table_pos[new_horse.y * size + new_horse.x] == min) {
			horse = new_horse;
			table[horse.y * size + horse.x] = ++move_count;
			return true;
		}
	}
	return false;
}

void Board::copy_from(const Board &b) {
	size = b.size;
	move_count = b.move_count;
	move_count_max = b.move_count_max;
	table = b.table;
	table_pos = b.table_pos;
	horse = b.horse;
	option = b.option;
}

int Board::move_imaginary_horse(const Position& horse) {
	return table[horse.y * size + horse.x] = ++move_count;
}

void Board::reset_square(const Position& horse) {
	table[horse.y * size + horse.x] = 0;
	--move_count;
}
