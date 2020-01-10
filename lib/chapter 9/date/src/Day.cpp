#include "Day.h"



namespace Chrono
{
	Day::Day(int day)
		: _day(day)
	{}

	std::ostream& operator<< (std::ostream& os, const Day& day) {
		os << day._day;
		return os;
	}
}