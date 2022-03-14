#include "Option.hpp"

#include <iostream>
#include <algorithm>
#include "data_types.hpp"

Option::Option() {
	init();
}

void Option::init() {
	// Initilizam cu permutarea 01234567
	for (int i = 0; i < 8; i++)
		perm[i] = i;
	perm_count = 0u;
}

void Option::next() {
	uint8* last = perm + 8;
	uint8* it = last - 1;
	uint8* jt = last;

	while (*it < *--it);
	while (*it >= *--jt);

	std::swap(*it, *jt);
	for (++it, --last; it < last; ++it, --last)
		std::swap(*it, *last);
	perm_count++;
}

void Option::print() {
	for (int i = 0; i < 8; i++)
		std::cout << perm[i] + 1;
	std::cout << '\n';
}

bool Option::passed_max_perm() {
	return perm_count >= 40320u;
}
