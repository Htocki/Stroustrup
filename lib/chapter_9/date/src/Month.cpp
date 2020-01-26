#include "Month.h"



namespace Chrono
{
	Month::Month(int number)
		: number(number)
	{
		if (!is_valid()) throw Invalid{};
	}

	Month& Month::operator++() {
		if (number == max) number = min;
		else ++number;
		return *this;
	}

	Month::Month(::Month name)
		: number(static_cast<int>(name))
	{}

	std::ostream& operator<<(std::ostream& os, const Month& month) {
		os << month.number;
		return os;
	}

	std::istream& operator>>(std::istream& is, Month& month) {
		std::cout << "Input month number: ";
		is >> month.number;
		if (!month.is_valid()) throw Month::Invalid{};
		return is;
	}

	bool Month::is_valid() {
		if (number < min || number > max) return false;
		else return true;
	}

	bool operator==(const Month& left, const Month& right) {
		if (left.getNumber() == right.getNumber()) return true;
		else return false;
	}

	bool operator!=(const Month& left, const Month& right) {
		return !operator==(left, right);
	}
}