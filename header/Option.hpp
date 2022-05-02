#pragma once
#include "data_types.hpp"

struct Option {
	uint8 perm[8];
	uint32 perm_count;

	Option();

	void init();
	void next();

	void print();

	inline bool exhausted_perm_count() {
		return perm_count == 40320u;
	}

};
