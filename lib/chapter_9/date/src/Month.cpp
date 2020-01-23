#include "Month.h"



namespace Chrono
{
	Month::Month(int number)
		: number(number)
	{
		if (number < min || number > max) throw Invalid{};
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
}