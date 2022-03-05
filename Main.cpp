#include <iostream>
#include <algorithm>
#include "int_types.hpp"

class Option {
	uint8 opt[8];

public:
	uint32 perm_count;

	Option() {
		// Initilizam cu permutarea 12345678
		for(int i = 0;i <= 7;i++)
			opt[i] = i;
		perm_count = 0u;
	}

	void next_opt() {
		uint8* last = opt + 8;
		uint8* it = last - 1;
    	uint8* jt = last;

    	while (*it < *--it);
    	while (*it >= *--jt);

    	std::swap(*it, *jt);
    	for (++it, --last; it < last; ++it, --last)
        	std::swap(*it, *last);
		perm_count++;
	}

	void print() {
		for (int i = 0; i < 8; i++)
			std::cout << (opt[i] + 1);
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
