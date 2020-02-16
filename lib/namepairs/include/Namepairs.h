#pragma once

#include <cstring>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

class Namepairs {
public:
	Namepairs() = default;
	explicit Namepairs(
		std::initializer_list<std::pair<std::string, int>>
	);
	void ReadNames();
	void ReadAges();
	void Print();
	void Sort();

	friend std::ostream& operator<<(
		std::ostream& os, 
		const Namepairs& pairs
	);

	friend bool operator==(
		const Namepairs& lhs,
		const Namepairs& rhs
	);

	friend bool operator!=(
		const Namepairs& lhs, 
		const Namepairs& rhs
	);

private:
	std::vector<std::string> names;
	std::vector<double> ages;
};
