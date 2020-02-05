#pragma once
#include <iostream>



class Month {
public:
	enum class Name {
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

private:
	static constexpr int min = 1;
	static constexpr int max = 12;

public:
	class Invalid {};

	Month(int);
	Month(Month::Name);

	int getNumber() const { return number; }

	Month& operator++();

private:
	bool is_valid();
	int number;
};



std::ostream& operator<<(std::ostream&, const Month&);
bool operator==(const Month&, const Month&);
bool operator!=(const Month&, const Month&);
