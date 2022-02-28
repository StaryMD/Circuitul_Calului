#include <iostream>
#include <algorithm>
#include "int_types.hpp"

class Option {
	uint32 opt;

public:
	uint32 perm_count;

	Option() {
		// Initilizam cu permutarea 12345678
		opt = 0b111110101100011010001000u;
		perm_count = 0u;
	}

	void get_array(uint8 *a) {
		a[0] =  opt        & 0b111u;
		a[1] = (opt >> 3)  & 0b111u;
		a[2] = (opt >> 6)  & 0b111u;
		a[3] = (opt >> 9)  & 0b111u;
		a[4] = (opt >> 12) & 0b111u;
		a[5] = (opt >> 15) & 0b111u;
		a[6] = (opt >> 18) & 0b111u;
		a[7] = (opt >> 21) & 0b111u;
	}

	void next_opt() {
		uint8 a[8];
		get_array(a);
		
		std::next_permutation(a, a + 8);

		opt = a[0] |
			  a[1] << 3 |
			  a[2] << 6 |
			  a[3] << 9 |
			  a[4] << 12 |
			  a[5] << 15 |
			  a[6] << 18 |
			  a[7] << 21;
		
		perm_count++;
	}

	void print() {
		uint8 a[8];
		get_array(a);

		for (int i = 0; i < 8; i++)
			std::cout << (int)(a[i] + 1);
		std::cout << '\n';
	}

	bool passed_max_perm() {
		return perm_count >= 40320u;
	}

};

class Board {
	bool *table;
	uint32 size;

	Board(uint32 size_ = 8) {
		size = size_;
		table = new bool[size * size];
	}

	~Board() {
		delete[] table;
	}



};

int main() {
	Option opt;

	while (opt.passed_max_perm() == false) {
		opt.print();
		opt.next_opt();
	}

	return 0;
}
