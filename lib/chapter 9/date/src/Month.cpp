#include "Month.h"



namespace Chrono
{
	Month::Month(int number)
		: _number(number)
	{}

	Month::Month(::Month name)
		: _number(static_cast<int>(name))
	{}

	std::ostream& operator<< (std::ostream& os, const Month& month) {
		os << month._number;
		return os;
	}
}