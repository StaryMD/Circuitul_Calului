#pragma once
#include "data_types.hpp"

struct Option {
	uint8 perm[8];
	uint32 perm_count;

	Option();

	void init();
	void next();
	bool passed_max_perm();

	void print();

};
