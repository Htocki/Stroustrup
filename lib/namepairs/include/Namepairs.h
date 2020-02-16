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
	void Sort();

	friend std::ostream& operator<<(
		std::ostream& os, 
		const Namepairs& other
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
	auto Print(std::ostream& out) const->std::ostream&;

	std::vector<std::string> names;
	std::vector<double> ages;
};
