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
		if (!is_valid()) throw Invalid{};
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

	std::istream& operator>>(std::istream& is, Day& day) {
		std::cout << "Input day number: ";
		is >> day.number;
		if (!day.is_valid()) throw Day::Invalid{};
		return is;
	}

	bool Day::is_valid() {
		if (number < min || number > max) return false;
		else return true;
	}

	bool operator==(const Day& left, const Day& right) {
		if (left.getNumber() == right.getNumber()) return true;
		else return false;
	}

	bool operator!=(const Day& left, const Day& right) {
		return !operator==(left, right);
	}
}