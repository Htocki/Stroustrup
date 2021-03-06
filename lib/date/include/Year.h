#pragma once
#include <iostream>

 

class Year {
	static constexpr int min = 1800;
	static constexpr int max = 2200;

public:
	class Invalid {};

	Year(int);

	int getNumber() const { return number; }

	Year& operator++();

private:
	bool is_valid();

	int number;
};



std::ostream& operator<<(std::ostream&, const Year&);
bool operator==(const Year&, const Year&);
bool operator!=(const Year&, const Year&);