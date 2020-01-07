#include "Month.h"



namespace Chrono
{
	Month::Month(int month)
		: _month(month)
	{}

	std::ostream& operator<< (std::ostream& os, const Month& month) {
		os << month._month;
		return os;
	}
}