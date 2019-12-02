#pragma once
#include <iostream>


class Year {
	static constexpr int min = 1800;
	static constexpr int max = 2200;

public:
	class Invalid {};
	Year(int);
	int year() { return y; }

	friend std::ostream& operator<<(std::ostream&, const Year&);

private:
	int y;
};
