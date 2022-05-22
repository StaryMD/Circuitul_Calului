#include "Option.hpp"

#include <iostream>
#include <algorithm>

Option::Option() {
	init();
}

void Option::init() {
	// Initilizam cu permutarea 01234567
	for (int val = 0; int& elem: perm)
		elem = val++;
	
	perm_count = 0;
}

void Option::next() {
	int* last = perm + 8;
	int* it = last - 1;
	int* jt = last;

	while (*it < *--it);
	while (*it >= *--jt);

	std::swap(*it, *jt);
	for (++it, --last; it < last; ++it, --last)
		std::swap(*it, *last);
	perm_count++;
}

void Option::print() {
	for (const int i: perm)
		std::cout << i + 1;
	std::cout << '\n';
}

int Option::to_integer() {
	int ans = 0;
	
	for (int i = 0; int elem: perm)
		ans |= elem << (i++ * 3);
	
	return ans;
}

void Option::from_integer(int val) {
	for (int& elem: perm) {
		elem = val & 0b111;
		val >>= 3;
	}
}
