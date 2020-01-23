#include "Day.h"



namespace Chrono
{
	// Intermediate constructor.
	Day::Day(int number)
		: number(number)
	{}

	Day::Day(int number, int max)
		: number(number)
		, max(max)
	{
		if (number < min || number > max) throw Invalid{};
	}

	Day& Day::operator++() {
		if (number == max) number = min;
		else ++number;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Day& day) {
		os << day.number;
		return os;
	}
}