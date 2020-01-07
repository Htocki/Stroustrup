#include "Year.h"



namespace Chrono
{
	Year::Year(int year)
		: _year(year)
	{}

	std::ostream& operator<< (std::ostream& os, const Year& year) {
		os << year._year;
		return os;
	}
}