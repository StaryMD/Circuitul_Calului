#pragma once

struct Option {
	int perm[8];
	int perm_count;

	Option();

	void init();
	void next();

	void print();
	int to_integer();
	void from_integer(int);

	bool exhausted_perm_count() {
		return perm_count == 40320;
	}

};
