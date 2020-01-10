#include "Month.h"



namespace Chrono
{
	Month::Month(int number)
		: _number(number)
	{}

	std::ostream& operator<< (std::ostream& os, const Month& month) {
		os << month._number;
		return os;
	}
}