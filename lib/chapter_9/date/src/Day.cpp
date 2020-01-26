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

	bool operator==(const Day& left, const Day& right) {
		if (left.getNumber() == right.getNumber()) return true;
		else false;
	}

	bool operator!=(const Day& left, const Day& right) {
		return !operator==(left, right);
	}
}